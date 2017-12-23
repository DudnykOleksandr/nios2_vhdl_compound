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

 ENTITY  altpll_sdram IS 
	 PORT 
	 ( 
		 address	:	IN  STD_LOGIC_VECTOR (1 DOWNTO 0);
		 c0	:	OUT  STD_LOGIC;
		 clk	:	IN  STD_LOGIC;
		 locked	:	OUT  STD_LOGIC;
		 phasedone	:	OUT  STD_LOGIC;
		 read	:	IN  STD_LOGIC;
		 readdata	:	OUT  STD_LOGIC_VECTOR (31 DOWNTO 0);
		 reset	:	IN  STD_LOGIC;
		 write	:	IN  STD_LOGIC;
		 writedata	:	IN  STD_LOGIC_VECTOR (31 DOWNTO 0)
	 ); 
 END altpll_sdram;

 ARCHITECTURE RTL OF altpll_sdram IS

	 ATTRIBUTE synthesis_clearbox : natural;
	 ATTRIBUTE synthesis_clearbox OF RTL : ARCHITECTURE IS 1;
	 SIGNAL  wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_clk	:	STD_LOGIC_VECTOR (4 DOWNTO 0);
	 SIGNAL  wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_fbout	:	STD_LOGIC;
	 SIGNAL  wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_inclk	:	STD_LOGIC_VECTOR (1 DOWNTO 0);
	 SIGNAL  wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_locked	:	STD_LOGIC;
	 SIGNAL	altpll_sdram_altpll_sdram_altpll_c842_sd1_pll_lock_sync_117q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_sdram_pfdena_reg_23q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe4a_0_105q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe5a_0_108q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe6a_0_109q	:	STD_LOGIC := '0';
	 SIGNAL	altpll_sdram_prev_reset_19q	:	STD_LOGIC := '0';
	 SIGNAL  wire_nO_w_lg_altpll_sdram_prev_reset_19q84w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w_lg_w19w20w21w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w_lg_w13w15w16w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w19w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w13w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w14w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w_address_range2w5w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_reset10w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w_address_range3w4w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w19w20w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_lg_w13w15w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  s_wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_locked_115_dataout :	STD_LOGIC;
	 SIGNAL  s_wire_altpll_sdram_w_select_control_15_dataout :	STD_LOGIC;
	 SIGNAL  s_wire_altpll_sdram_w_select_status_16_dataout :	STD_LOGIC;
	 SIGNAL  s_wire_altpll_sdram_wire_pfdena_reg_ena_12_dataout :	STD_LOGIC;
	 SIGNAL  s_wire_vcc :	STD_LOGIC;
	 SIGNAL  wire_w_address_range2w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
	 SIGNAL  wire_w_address_range3w	:	STD_LOGIC_VECTOR (0 DOWNTO 0);
 BEGIN

	wire_w_lg_w_lg_w19w20w21w(0) <= wire_w_lg_w19w20w(0) AND read;
	wire_w_lg_w_lg_w13w15w16w(0) <= wire_w_lg_w13w15w(0) AND read;
	wire_w19w(0) <= s_wire_altpll_sdram_w_select_control_15_dataout AND altpll_sdram_pfdena_reg_23q;
	wire_w13w(0) <= s_wire_altpll_sdram_w_select_control_15_dataout AND altpll_sdram_prev_reset_19q;
	wire_w14w(0) <= s_wire_altpll_sdram_w_select_status_16_dataout AND altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe6a_0_109q;
	wire_w_lg_w_address_range2w5w(0) <= wire_w_address_range2w(0) AND wire_w_lg_w_address_range3w4w(0);
	wire_w_lg_reset10w(0) <= NOT reset;
	wire_w_lg_w_address_range3w4w(0) <= NOT wire_w_address_range3w(0);
	wire_w_lg_w19w20w(0) <= wire_w19w(0) OR s_wire_altpll_sdram_w_select_status_16_dataout;
	wire_w_lg_w13w15w(0) <= wire_w13w(0) OR wire_w14w(0);
	c0 <= wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_clk(0);
	locked <= s_wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_locked_115_dataout;
	phasedone <= '0';
	readdata <= ( "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & "0" & wire_w_lg_w_lg_w19w20w21w & wire_w_lg_w_lg_w13w15w16w);
	s_wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_locked_115_dataout <= (altpll_sdram_altpll_sdram_altpll_c842_sd1_pll_lock_sync_117q AND wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_locked);
	s_wire_altpll_sdram_w_select_control_15_dataout <= wire_w_lg_w_address_range2w5w(0);
	s_wire_altpll_sdram_w_select_status_16_dataout <= ((NOT address(0)) AND wire_w_lg_w_address_range3w4w(0));
	s_wire_altpll_sdram_wire_pfdena_reg_ena_12_dataout <= (s_wire_altpll_sdram_w_select_control_15_dataout AND write);
	s_wire_vcc <= '1';
	wire_w_address_range2w(0) <= address(0);
	wire_w_address_range3w(0) <= address(1);
	wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_inclk <= ( "0" & clk);
	altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127 :  cycloneiii_pll
	  GENERIC MAP (
		BANDWIDTH_TYPE => "auto",
		CLK0_DIVIDE_BY => 1,
		CLK0_DUTY_CYCLE => 50,
		CLK0_MULTIPLY_BY => 1,
		CLK0_PHASE_SHIFT => "-3333",
		COMPENSATE_CLOCK => "clk0",
		INCLK0_INPUT_FREQUENCY => 20000,
		OPERATION_MODE => "normal",
		PLL_TYPE => "auto"
	  )
	  PORT MAP ( 
		areset => altpll_sdram_prev_reset_19q,
		clk => wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_clk,
		fbin => wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_fbout,
		fbout => wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_fbout,
		inclk => wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_inclk,
		locked => wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_locked
	  );
	PROCESS (wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_locked, altpll_sdram_prev_reset_19q)
	BEGIN
		IF (altpll_sdram_prev_reset_19q = '1') THEN
				altpll_sdram_altpll_sdram_altpll_c842_sd1_pll_lock_sync_117q <= '0';
		ELSIF (wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_locked = '1' AND wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_cycloneiii_pll_pll7_127_locked'event) THEN
				altpll_sdram_altpll_sdram_altpll_c842_sd1_pll_lock_sync_117q <= s_wire_vcc;
		END IF;
	END PROCESS;
	PROCESS (clk, reset)
	BEGIN
		IF (reset = '1') THEN
				altpll_sdram_pfdena_reg_23q <= '1';
		ELSIF (clk = '1' AND clk'event) THEN
			IF (s_wire_altpll_sdram_wire_pfdena_reg_ena_12_dataout = '1') THEN
				altpll_sdram_pfdena_reg_23q <= writedata(1);
			END IF;
		END IF;
		if (now = 0 ns) then
			altpll_sdram_pfdena_reg_23q <= '1' after 1 ps;
		end if;
	END PROCESS;
	PROCESS (clk, reset)
	BEGIN
		IF (reset = '1') THEN
				altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe4a_0_105q <= '0';
				altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe5a_0_108q <= '0';
				altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe6a_0_109q <= '0';
				altpll_sdram_prev_reset_19q <= '0';
		ELSIF (clk = '1' AND clk'event) THEN
				altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe4a_0_105q <= s_wire_altpll_sdram_altpll_sdram_altpll_c842_sd1_locked_115_dataout;
				altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe5a_0_108q <= altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe4a_0_105q;
				altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe6a_0_109q <= altpll_sdram_altpll_sdram_stdsync_sv6_stdsync2_altpll_sdram_dffpipe_l2c_dffpipe3_dffe5a_0_108q;
				altpll_sdram_prev_reset_19q <= (s_wire_altpll_sdram_wire_pfdena_reg_ena_12_dataout AND writedata(0));
		END IF;
	END PROCESS;
	wire_nO_w_lg_altpll_sdram_prev_reset_19q84w(0) <= NOT altpll_sdram_prev_reset_19q;

 END RTL; --altpll_sdram
--synopsys translate_on
--VALID FILE
