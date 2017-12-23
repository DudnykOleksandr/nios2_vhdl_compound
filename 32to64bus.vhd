library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity busExpander is
Generic (inRes: natural := 31; effectiveRes: natural := 23; outRes: natural:=63);

	port
	(
	clk : in STD_LOGIC;
	data0	: in STD_LOGIC_VECTOR (inRes DOWNTO 0);
	data1	: in STD_LOGIC_VECTOR (inRes DOWNTO 0);
	res		: out STD_LOGIC_VECTOR (outRes DOWNTO 0)
	);
end entity;

architecture exp of busExpander is
begin
	process (clk)
	
	begin
	
		if ( rising_edge( clk )) then
		res<= "0000000000000000" & data1(effectiveRes downto 0) & data0(effectiveRes downto 0);
		end if;
		
	end process;

end exp;