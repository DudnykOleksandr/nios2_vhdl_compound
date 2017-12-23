--IP Functional Simulation Model
--VERSION_BEGIN 10.1 cbx_mgl 2010:11:29:22:19:52:SJ cbx_simgen 2010:11:29:22:18:02:SJ  VERSION_END


-- Copyright (C) 1991-2010 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- You may only use these simulation model output files for simulation
-- purposes and expressly not for synthesis or any other purposes (in which
-- event Altera disclaims all warranties of any kind).


--synopsys translate_off

 LIBRARY cycloneiii;
 USE cycloneiii.cycloneiii_components.all;

--synthesis_resources = cycloneiii_pll 1 lut 6 
 LIBRARY ieee;
 USE ieee.std_logic_1164.all;

 ENTITY  altpll_0 IS 
	 PORT 
	 ( 
		 address	:	IN  STD_LOGIC_VECTOR (1 DOWNTO 0);
		 c0	:	OUT  STD_LOGIC;
		 c1	:	OUT  STD_LOGIC;
		 clk	:	IN  STD_LOGIC;
		 locked	:	OUT  STD_LOGIC;
		 phasedone	:	OUT  STD_LOGIC;
		 read	:	IN  STD_LOGIC;
		 readdata	:	OUT  STD_LOGIC_VECTOR (31 DOWNTO 0);
		 reset	:	IN  STD_LOGIC;
		 write	:	IN  STD_LOGIC;
		 writedata	:	IN  STD_LOGIC_VECTOR (31 DOWNTO 0)
	 ); 
 END altpll_0;

 ARCHITECTURE RTL OF altpll_0 IS

	 ATTRIBUTE synthesis_clearbox : natural;
	 ATTRIBUTE synthesis_clearbox OF RTL : ARCHITECTURE IS 1;
	 SIGNAL  wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_clk	:	STD_LOGIC_VECTOR (4 DOWNTO 0);
	 SIGNAL  wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_fbout	:	STD_LOGIC;
	 SIGNAL  wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_inclk	:	STD_LOGIC_VECTOR (1 DOWNTO 0);
	 SIGNAL  wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_locked	:	STD_LOGIC;
	 SIGNAL	altpll_0_altpll_0_altpll_mpa2_sd1_pll_lock_sync_118q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_0_pfdena_reg_23q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe4a_0_106q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe5a_0_109q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe6a_0_110q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_0_prev_reset_19q	:	STD_LOGIC := '0';
	 SIGNAL  wire_nO_w_lg_altpll_0_prev_reset_19q85w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w_lg_w20w21w22w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w_lg_w14w16w17w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w20w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w14w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_s_wire_altpll_0_w_select_status_16_dataout15w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w_address_range2w5w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_reset10w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w_address_range3w4w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w20w21w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w14w16w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  s_wire_altpll_0_altpll_0_altpll_mpa2_sd1_locked_116_dataout :	STD_LOGIC;
	 SIGNAL  s_wire_altpll_0_w_select_control_15_dataout :	STD_LOGIC;
	 SIGNAL  s_wire_altpll_0_w_select_status_16_dataout :	STD_LOGIC;
	 SIGNAL  s_wire_altpll_0_wire_pfdena_reg_ena_12_dataout :	STD_LOGIC;
	 SIGNAL  s_wire_vcc :	STD_LOGIC;
	 SIGNAL  wire_w_address_range2w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_address_range3w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
 BEGIN

	wire_w_lg_w_lg_w20w21w22w(0) <= wire_w_lg_w20w21w(0) AND read;
	wire_w_lg_w_lg_w14w16w17w(0) <= wire_w_lg_w14w16w(0) AND read;
	wire_w20w(0) <= s_wire_altpll_0_w_select_control_15_dataout AND altpll_0_pfdena_reg_23q;
	wire_w14w(0) <= s_wire_altpll_0_w_select_control_15_dataout AND altpll_0_prev_reset_19q;
	wire_w_lg_s_wire_altpll_0_w_select_status_16_dataout15w(0) <= s_wire_altpll_0_w_select_status_16_dataout AND altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe6a_0_110q;
	wire_w_lg_w_address_range2w5w(0) <= wire_w_address_range2w(0) AND wire_w_lg_w_address_range3w4w(0);
	wire_w_lg_reset10w(0) <= NOT reset;
	wire_w_lg_w_address_range3w4w(0) <= NOT wire_w_address_range3w(0);
	wire_w_lg_w20w21w(0) <= wire_w20w(0) OR s_wire_altpll_0_w_select_status_16_dataout;
	wire_w_lg_w14w16w(0) <= wire_w14w(0) OR wire_w_lg_s_wire_altpll_0_w_select_status_16_dataout15w(0);
	c0 <= wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_clk(0);
	c1 <= wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_clk(1);
	locked <= s_wire_altpll_0_altpll_0_altpll_mpa2_sd1_locked_116_dataout;
	phasedone <= '0';
	readdata <= ( "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & wire_w_lg_w_lg_w20w21w22w & wire_w_lg_w_lg_w14w16w17w);
	s_wire_altpll_0_altpll_0_altpll_mpa2_sd1_locked_116_dataout <= (altpll_0_altpll_0_altpll_mpa2_sd1_pll_lock_sync_118q AND wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_locked);
	s_wire_altpll_0_w_select_control_15_dataout <= wire_w_lg_w_address_range2w5w(0);
	s_wire_altpll_0_w_select_status_16_dataout <= ((NOT address(0)) AND wire_w_lg_w_address_range3w4w(0));
	s_wire_altpll_0_wire_pfdena_reg_ena_12_dataout <= (s_wire_altpll_0_w_select_control_15_dataout AND write);
	s_wire_vcc <= '1';
	wire_w_address_range2w(0) <= address(0);
	wire_w_address_range3w(0) <= address(1);
	wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_inclk <= ( "0" & clk);
	altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128 :  cycloneiii_pll
	  GENERIC MAP (
		BANDWIDTH_TYPE => "auto",
		CLK0_DIVIDE_BY => 1,
		CLK0_DUTY_CYCLE => 50,
		CLK0_MULTIPLY_BY => 2,
		CLK0_PHASE_SHIFT => "0",
		CLK1_DIVIDE_BY => 1,
		CLK1_DUTY_CYCLE => 50,
		CLK1_MULTIPLY_BY => 2,
		CLK1_PHASE_SHIFT => "-1667",
		COMPENSATE_CLOCK => "clk0",
		INCLK0_INPUT_FREQUENCY => 20000,
		OPERATION_MODE => "normal",
		PLL_TYPE => "auto"
	  )
	  PORT MAP ( 
		areset => altpll_0_prev_reset_19q,
		clk => wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_clk,
		fbin => wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_fbout,
		fbout => wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_fbout,
		inclk => wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_inclk,
		locked => wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_locked
	  );
	PROCESS (wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_locked, altpll_0_prev_reset_19q)
	BEGIN
		IF (altpll_0_prev_reset_19q = '1') THEN
				altpll_0_altpll_0_altpll_mpa2_sd1_pll_lock_sync_118q <= '0';
		ELSIF (wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_locked = '1' AND wire_altpll_0_altpll_0_altpll_mpa2_sd1_cycloneiii_pll_pll7_128_locked'event) THEN
				altpll_0_altpll_0_altpll_mpa2_sd1_pll_lock_sync_118q <= s_wire_vcc;
		END IF;
	END PROCESS;
	PROCESS (clk, reset)
	BEGIN
		IF (reset = '1') THEN
				altpll_0_pfdena_reg_23q <= '1';
		ELSIF (clk = '1' AND clk'event) THEN
			IF (s_wire_altpll_0_wire_pfdena_reg_ena_12_dataout = '1') THEN
				altpll_0_pfdena_reg_23q <= writedata(1);
			END IF;
		END IF;
		if (now = 0 ns) then
			altpll_0_pfdena_reg_23q <= '1' after 1 ps;
		end if;
	END PROCESS;
	PROCESS (clk, reset)
	BEGIN
		IF (reset = '1') THEN
				altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe4a_0_106q <= '0';
				altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe5a_0_109q <= '0';
				altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe6a_0_110q <= '0';
				altpll_0_prev_reset_19q <= '0';
		ELSIF (clk = '1' AND clk'event) THEN
				altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe4a_0_106q <= s_wire_altpll_0_altpll_0_altpll_mpa2_sd1_locked_116_dataout;
				altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe5a_0_109q <= altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe4a_0_106q;
				altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe6a_0_110q <= altpll_0_altpll_0_stdsync_sv6_stdsync2_altpll_0_dffpipe_l2c_dffpipe3_dffe5a_0_109q;
				altpll_0_prev_reset_19q <= (s_wire_altpll_0_wire_pfdena_reg_ena_12_dataout AND writedata(0));
		END IF;
	END PROCESS;
	wire_nO_w_lg_altpll_0_prev_reset_19q85w(0) <= NOT altpll_0_prev_reset_19q;

 END RTL; --altpll_0
--synopsys translate_on
--VALID FILE
