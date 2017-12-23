library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity FibonachiDacTest is
Generic (fullBusRes: natural := 63; dataBusRes: natural := 47; dacRes: natural := 11; addrRes: natural := 1);

	port
	(
	data	: in STD_LOGIC_VECTOR (fullBusRes DOWNTO 0);
	clk		: in std_logic;
	
		nreset		: out std_logic;
		nldac 		: out std_logic;
		db				: out STD_LOGIC_VECTOR (dacRes DOWNTO 0);
		randw			: out std_logic;
		a				: out STD_LOGIC_VECTOR (addrRes DOWNTO 0);
		ncs			: out std_logic;
		
		test 		: out std_logic
	);
end entity;

architecture rtl of FibonachiDacTest is
begin
	process (clk) 
	
	variable temp: integer := 0;
	variable tempData: STD_LOGIC_VECTOR (fullBusRes DOWNTO 0);
	
	type  dacAdressesType is array(3 downto 0) of STD_LOGIC_VECTOR (addrRes DOWNTO 0);
	type  dacValuesType is array(3 downto 0) of STD_LOGIC_VECTOR (dacRes DOWNTO 0);
	
	variable dacAdresses: dacAdressesType :=("11","10","01","00");
	variable dacValues: dacValuesType;
	
	variable reftime: time:= 10ns;
	
	variable twds: time:= 20ns;
	variable twcs: time:= 80ns;
	variable tls: time:= 70ns;
	variable tlwd: time:= 170ns;
	
	begin
				
		dacValues(0):=data(dacRes downto 0);
		dacValues(1):=data(dacRes*2+1 downto dacRes+1);
		dacValues(2):=data(dacRes*3+2 downto dacRes*2+2);
		dacValues(3):=data(dataBusRes downto dacRes*3+3);
		
		nreset<='1';
		
		if ( rising_edge( clk )) then
			
			if not(tempData=data) then	
				tempData:=data;
				temp:=0;				
			end if;
			
			if ( temp = 0 ) then
				db<= dacValues(0);
			elsif ( temp = twds/reftime)  then 
				a<= dacAdresses(0);
				randw<='0';
				ncs<= '0';
			
				-- first dac	
			elsif ( temp = (twds+twcs)/reftime)  then
				db<= dacValues(1);
				ncs<= '1';
			elsif ( temp = (twds+twcs+twds)/reftime)  then
				a<= dacAdresses(1);
				ncs<= '0';
				-- second dac
			elsif ( temp = (2*(twds+twcs))/reftime)  then
				db<= dacValues(2);
				ncs<= '1';
			elsif ( temp = (2*(twds+twcs+twds))/reftime)  then
				a<= dacAdresses(2);
				ncs<= '0';
				-- third dac
			elsif ( temp = (3*(twds+twcs))/reftime)  then
				db<= dacValues(3);
				ncs<= '1';
			elsif ( temp = (3*(twds+twcs+twds))/reftime)  then
				a<= dacAdresses(3);
				ncs<= '0';
			
				-- fourth dac
			elsif ( temp = (4*(twds+twcs)-tls)/reftime)  then
				nldac<='0';
			elsif (temp = (4*(twds+twcs))/reftime)	then
				randw<='1';
				ncs<= '1';
			elsif (temp = (4*(twds+twcs)+tlwd-tls)/reftime) then
				nldac<='1';
			-- temp:=0;
			end if;
				
			temp := temp + 1;
		
		end if;
		
		test<=clk;

	end process;
end rtl;