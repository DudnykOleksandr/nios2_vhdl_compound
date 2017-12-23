library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity Switch is
	port
	(
	data	: in STD_LOGIC_VECTOR (3 DOWNTO 0);
	
		in1		: out std_logic;
		in2 		: out std_logic;
		in3		: out std_logic;
		in4		: out std_logic
	);
end entity;

architecture switch_inst of Switch is
begin
		
		in1<=data(0);
		in2<=data(1);
		in3<=data(2);
		in4<=data(3);

end switch_inst;