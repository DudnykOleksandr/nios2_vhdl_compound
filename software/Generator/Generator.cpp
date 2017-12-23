#include "system.h"
#include "math.h"
#include "alt_types.h"
#include "stdbool.h"
#include "stdio.h"
#include "unistd.h"

#define _arrayMax 4095
#define _indexMax 4095
#define _indexMin 0

#define calibrateDacIndexMax 16383

#define fibonachiN 18
#define binaryN 12
#define calibrateDacN 14

#include "altera_avalon_pio_regs.h"

class Dac
{
	bool isInitialisationDone;
	alt_u32 arrayOfCodes[2][_arrayMax];
	int point_index;

	int currentMode;

	int arrayMax;
	int indexMax;
	int indexMin;

	alt_u64* weightsCombinationsArray;
	double* fibonachiArray;
	int* binaryArray;

	double zeroOffset;
	double maxValue;

	int comparatorValue;


	public: Dac(alt_u64* _weightsCombinationsArray,double* _fibonachiArray,int* _binaryArray)
	{
		weightsCombinationsArray=_weightsCombinationsArray;
		fibonachiArray=_fibonachiArray;
		binaryArray=_binaryArray;

		isInitialisationDone=false;
		point_index=0;
		zeroOffset=0;
		maxValue=0;

		currentMode=0;

		indexMax=_indexMax;
		indexMin=_indexMin;

		IOWR_ALTERA_AVALON_PIO_DATA(LATCH_PIO_BASE,0);
		IOWR_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE,8);
		IOWR_ALTERA_AVALON_PIO_DATA(SAMPLE_AND_HOLD_PIO_BASE,1);

		CalibrateWeightsOfDac();

		CalibrateMaxOfDac();

		CalibrateZeroOfDac();

		//CorrectWeightsArray();

		PrepareArrayOfCodes();

		SwitchTheMode();

		//GenerateTestSignal();
	}

	void CorrectWeightsArray()
	{
		double max=_arrayMax;

		double m=(maxValue-zeroOffset)/max;

		maxValue/=m;
		zeroOffset/=m;

		int i;
		for(i=0; i<fibonachiN;i++)
		{

			fibonachiArray[i]/=m;
			printf("%f\n",fibonachiArray[i]);
		}
		printf("maxValue %f\n",maxValue);
		printf("zeroOffset %f\n",zeroOffset);
	}

	void TrackAnalogSignal()
	{
		point_index=0;

		SendToDacADacValue(0);

		usleep(100);

		IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE,0);

		do
		{
			if(IORD_ALTERA_AVALON_PIO_DATA(COMPARATOR_PIO_BASE)==1)
			{
				//add one
				if(point_index<indexMax)
					point_index++;
				//else
					//point_index=indexMin;
			}
			else
			{
				//dec one
				if(point_index>indexMin)
					point_index--;
				//else
					//point_index=indexMax;
			}

			SendToDacACodeNumber(point_index);

			SendToUsbACode(point_index);



			//printf("%07u\n",point_index);
			usleep(1);
			//usleep(1250);
		}
		while(!IsMainModeChanged());

		SwitchTheMode();
	}

	void SendToDacACodeNumber(int codeNumber)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(GEN_CODE_STROBE_BASE,0);
		IOWR_ALTERA_AVALON_PIO_DATA(GEN_CODE_VALUE_PIO_0_BASE,arrayOfCodes[0][codeNumber]);
		IOWR_ALTERA_AVALON_PIO_DATA(GEN_CODE_VALUE_PIO_1_BASE,arrayOfCodes[1][codeNumber]);
		IOWR_ALTERA_AVALON_PIO_DATA(GEN_CODE_STROBE_BASE,1);
	}

	void SendToUsbACode(int code)
	{
		//codeNumber-=zeroOffset;

		IOWR_ALTERA_AVALON_PIO_DATA(USB_CODE_PIO_BASE,code);
	}

	void SendToDacADacValue(alt_u64 dacValue)
	{
		alt_u64 maskLower=16777215;
		alt_u64 maskHigher=281474959933440ULL;

		alt_u32 dacValueHigh,dacValueLow;

		dacValueLow=dacValue & maskLower;
		dacValueHigh= (dacValue & maskHigher ) >> 24;


		IOWR_ALTERA_AVALON_PIO_DATA(GEN_CODE_STROBE_BASE,0);
		IOWR_ALTERA_AVALON_PIO_DATA(GEN_CODE_VALUE_PIO_0_BASE,dacValueLow);
		IOWR_ALTERA_AVALON_PIO_DATA(GEN_CODE_VALUE_PIO_1_BASE,dacValueHigh);
		IOWR_ALTERA_AVALON_PIO_DATA(GEN_CODE_STROBE_BASE,1);
	}

	void SendToCalibrateDacADacValue(int dacValue)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(CAL_DAC_CODE_PIO_BASE,dacValue);
	}

	void GetDacBitsArrayForANumber(int number, int* bitValuesArray )
	{
		double sum=0;

		int i;

		for (i = fibonachiN - 1; i >= 0; i--)
		{

			// врівноваження відбувається реальними вагами розрядів, допоки не визначені калібровані ваги
			if (sum+fibonachiArray[i] <= number)
			{
				sum+=fibonachiArray[i];
				bitValuesArray[i]=1;
			}
			else
			{
				bitValuesArray[i]=0;
			}
		}
	}

	alt_u64 GetDacValueForDacBitsArray(int* dacBits)
	{
		alt_u64 result=0;
		int i=0;

		for (i = fibonachiN - 1; i >= 0; i--)
		{
			if (dacBits[i]==1)
			{
				result=result|weightsCombinationsArray[i];

			}
		}

		return result;
	}

	void PrepareArrayOfCodes()
	{
		IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE,0xFF);

		alt_u64 maskLower=16777215;
		alt_u64 maskHigher=281474959933440ULL;

		int i;

		int tempBits[fibonachiN];

		int offsetInt=(int)zeroOffset;

		for (i = 0; i <= _arrayMax; i++)
		{
			//in this place offset is taken into consideration
			GetDacBitsArrayForANumber(i+offsetInt,tempBits);

			alt_u64 tempDacValue;

			tempDacValue= GetDacValueForDacBitsArray(tempBits);

			//whole 32 bits is used
			arrayOfCodes[1][i]= (tempDacValue & maskHigher ) >> 24;
			arrayOfCodes[0][i]=tempDacValue & maskLower;
		}

		IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE,0);
	}

	bool IsMainModeChanged()
	{
		int tempMode;
		tempMode=IORD_ALTERA_AVALON_PIO_DATA(MODE_SELECT_BASE);

		if(tempMode!=currentMode)
		{
			currentMode=tempMode;
			return true;
		}
		return false;
	}

	void SaveComparatorValue()
	{
		comparatorValue=IORD_ALTERA_AVALON_PIO_DATA(COMPARATOR_PIO_BASE);
	}
	bool isComparatorChanged()
	{
		int newComparatorValue=IORD_ALTERA_AVALON_PIO_DATA(COMPARATOR_PIO_BASE);

		if(newComparatorValue!=comparatorValue)
		{
			return true;
		}
		return false;
	}
	void CalibrateWeightsOfDac()
	{
		int i;
		double calibratedWeight=0;

		IOWR_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE,4);

		//start calibrating bit
		for(i=6; i<fibonachiN;i++)
		{
			calibratedWeight=CalibrateOneWeight(i);

			fibonachiArray[i]=calibratedWeight;
		}

		IOWR_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE,1);
	}

	double CalibrateOneWeight(int numOfBitWithThisWeight)
	{
		double calibratedWeight=0;

		SendToCalibrateDacADacValue(0);

		PutOneBitOfDacWithWROn(numOfBitWithThisWeight);

		ApproximateAnalogInputWithCalibrateDac();

		calibratedWeight=ApproximateAnalogInputSARWithMainDac(numOfBitWithThisWeight-1);

		printf("%f \n",calibratedWeight);

		return calibratedWeight;

	}

	void ApproximateAnalogInputWithCalibrateDac()
	{
		int i;

		SendToCalibrateDacADacValue(0);

		usleep(50);

		SaveComparatorValue();

		for(i=0; i<=calibrateDacIndexMax;i++)
		{
			SendToCalibrateDacADacValue(i);

			usleep(50);

			if(isComparatorChanged())
			{
			return;
			}
		}
	}


	double ApproximateAnalogInputSARWithMainDac(int startBit)
	{
		int i;
		int bitValuesArray[fibonachiN]={0};
		double res=0;

		SendToDacADacValue(0);

		usleep(100);

		SaveComparatorValue();

		for(i=startBit; i>=0;i--)
		{
			bitValuesArray[i]=1;
			res+=fibonachiArray[i];

			SendToDacADacValue(GetDacValueForDacBitsArray(bitValuesArray));

			usleep(100);

			if(isComparatorChanged())
			{
				bitValuesArray[i]=0;
				res-=fibonachiArray[i];
			}
		}

		return res;
	}

	int ApproximateAnalogInputTrackingWithMainDac()
	{
		int i=0;

		SendToDacADacValue(0);

		usleep(50);

		SaveComparatorValue();

		for(i=0; i<indexMax;i++)
		{
			SendToDacACodeNumber(i);

			usleep(50);

			if(isComparatorChanged())
			{
				break;
			}
		}

		return i;
	}

	void PutOneBitOfDacWithWROn(int number)
	{
		int bitValuesArray[fibonachiN]={0};
		bitValuesArray[number]=1;

		alt_u64 tempValue=GetDacValueForDacBitsArray(bitValuesArray);

		SendToDacADacValue(tempValue);
	}

	void CalibrateZeroOfDac()
	{

		SendToDacADacValue(0);

		IOWR_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE,8);

		usleep(10000);

		//zeroOffset=ApproximateAnalogInputTrackingWithMainDac();
		zeroOffset=ApproximateAnalogInputSARWithMainDac(fibonachiN-1);

		printf("zero %f \n",zeroOffset);

		IOWR_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE,1);
	}
	void CalibrateMaxOfDac()
	{
		IOWR_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE,2);

		usleep(1000);

		//maxValue=ApproximateAnalogInputTrackingWithMainDac();
		maxValue=ApproximateAnalogInputSARWithMainDac(fibonachiN-1);

		printf("maxValue %f \n",maxValue);

		IOWR_ALTERA_AVALON_PIO_DATA(SWITCH_PIO_BASE,1);
	}

	void SwitchTheMode()
	{

		do
		{
			printf ("Сode is: %u \n", currentMode);


			if(currentMode==0)
			{
				TrackAnalogSignal();
			}

			if(currentMode==1)
			{
				IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE,0x01);

				CalibrateWeightsOfDac();

				PrepareArrayOfCodes();

				TrackAnalogSignal();
			}
			if(currentMode==2)
			{
				IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE,0x02);

				CalibrateZeroOfDac();

				TrackAnalogSignal();
			}
			if(currentMode==3)
			{
				//CalibrateMaxOfDac();
				TrackAnalogSignalSAR();
			}
		}
		while(true);
	}

	void TrackAnalogSignalSAR()
	{
		IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE,0);

		int result,i;

		do
		{
			result=0;

			SendToDacADacValue(0);

			IOWR_ALTERA_AVALON_PIO_DATA(SAMPLE_AND_HOLD_PIO_BASE,0);

			usleep(50);

			SaveComparatorValue();

			for(i=binaryN-1; i>=0;i--)
			{
				result+=binaryArray[i];

				SendToDacADacValue(result);

				usleep(100);

				if(isComparatorChanged())
				{
					result-=binaryArray[i];
				}
			}

			IOWR_ALTERA_AVALON_PIO_DATA(SAMPLE_AND_HOLD_PIO_BASE,1);

			SendToUsbACode(result);

		}
		while(!IsMainModeChanged());

		SwitchTheMode();
	}

	void GenerateTestSignal()
	{

		int i=0;
		do
		{
			SendToDacACodeNumber(i);
			SendToUsbACode(i);

			//SendToDacADacValue(weightsCombinationsArray[i]);

			//SendToCalibrateDacADacValue(i);

			i++;

			IORD_ALTERA_AVALON_PIO_DATA(COMPARATOR_PIO_BASE);
			IsMainModeChanged();
			usleep(10);

			if(i==indexMax+1)
			//if(i==fibonachiN)
			//if(i==calibrateDacIndexMax)
			{i=0;}
		}
		while(true);
	}

};

static void initial_message()
{
    printf("NiosII is UP!\n");
}

int main(void)
{
 	IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE,0x01);

    initial_message();

    Dac* dacInst;

    alt_u64 weightsCombinationsArray[fibonachiN]={
    		1,
    		549755813888ULL,
    		1099511627776ULL,
    		16384,
    		343597383684ULL,
    		50372608,
    		137439023104ULL,
    		268435472,
    		17592186044416ULL,
    		2199157735424ULL,
    		1140850754ULL,
    		70368744177664ULL,
    		1179648,
    		35184372089088ULL,
    		512,
    		4194432,
    		140743930807304ULL,
    		13194676930560ULL
    		};

    double fibonachiArray[fibonachiN]={
    		0.986908387,
    		0.933333376,
    		1.866666751,
    		2.693232554,
    		4.530966909,
    		7.223081384,
    		11.6795717,
    		18.40386753,
    		29.86666802,
    		48.13172103,
    		76.24262024,
    		119.4666721,
    		193.9127439,
    		312.3818832,
    		505.2970944,
    		815.7918074,
    		1320.1428,
    		2134.998487
};

    int binaryArray[binaryN]={
        		1,2,4,8,16,32,64,128,256,512,1024,2048};

    dacInst=new Dac(weightsCombinationsArray,fibonachiArray,binaryArray);

    return 0;
}

