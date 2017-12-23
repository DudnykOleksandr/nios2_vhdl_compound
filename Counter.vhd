library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity addr_counter is
Generic (Cnt_Res: natural := 5; Max_Addr: natural := 33);
	port
	(
		clk		: in std_logic;
		updown		: in std_logic;
		reset	: in std_logic;
		enable 	: in std_logic;
		q		: out STD_LOGIC_VECTOR(Cnt_Res downto 0)
	);
end entity;

architecture rtl of addr_counter is
begin
	process (clk)
		variable   cnt	: integer range 0 to Max_Addr;
	begin
		if (rising_edge(clk)) then
			if reset = '1' then
				-- Reset the counter to 0
				cnt := 0;
			elsif enable = '1' then
				if updown = '1' then 
					
					if 	cnt=Max_Addr then
						cnt:=0;
					else
						-- Increment the counter if counting is up
						cnt := cnt + 1;
					end if;
				else
				-- Decrement the counter if counting is down
					cnt := cnt - 1;
				end if;
			end if;
		end if;
		
		-- Output the current count
		q <= std_logic_vector(to_unsigned( cnt, Cnt_Res+1));
	end process;

end rtl;