library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity DacCodesGen is
	port
	(
	clk		: in std_logic;
	cnt		: in std_logic;
	data	: out STD_LOGIC_VECTOR (63 DOWNTO 0);
	led	: out std_logic
	);
end entity;

architecture codeGen of DacCodesGen is
begin
	process (clk) 
	
	begin
		
			if(cnt='1') then
				data<="0000000011111111111111111111111100000000111111111111111111111111";
				led<='1';
			else
				data<="0000000000000000000000000000000000000000000000000000000000000000";
				led<='0';
			end if;
	   	 
	end process;
end codeGen;