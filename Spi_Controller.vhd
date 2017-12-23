				  library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Spi_Controller is
Generic (fullBusRes: natural := 13);

	port
	(
	data	: in STD_LOGIC_VECTOR (fullBusRes DOWNTO 0);
	clk		: in std_logic;
	
		sclk		: out std_logic;
		nsync 		: out std_logic;
		sdin		: out std_logic;
		nldac		: out std_logic;
		nclr		: out std_logic;
		npd		: out std_logic;
		sdo		: out std_logic;
		nrben		: out std_logic
	);
end entity;

architecture spi_inst of Spi_Controller is
begin
	process (clk) 
	
	variable temp: integer := 0;
	variable tempData: STD_LOGIC_VECTOR (fullBusRes DOWNTO 0);
	
	variable refres: integer:= 14;
	
	begin
		
		nclr<='1';
		
		--needed to be in 0
		npd<='1';
		
		sdo<='0';
		nrben<='1';
		
		sclk<=clk;
		
		if ( rising_edge( clk )) then
			
			if not(tempData=data) then	
				tempData:=data;
				temp:=0;
				nsync<= '1';
				nldac<='1';
					
			elsif ( temp < 15 ) then
				nsync<= '0';
				sdin<=data(refres-temp);
			
			elsif ( temp = 15 ) then
				nsync<= '1';
				
			elsif ( temp = 16 ) then
				nldac<= '0';
				
			elsif ( temp = 17 ) then
				nldac<= '1';
				
			-- f-clk=7Mhz f-data-400kHz
				
			end if;
				
			temp := temp + 1;
		
		end if;

	end process;
end spi_inst;