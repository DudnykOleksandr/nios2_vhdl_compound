/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu_0' in SOPC Builder design 'nios2'
 * SOPC Builder design path: D:/Quartus/Projects/nios2_vhdl_compound/nios2.sopcinfo
 *
 * Generated: Fri Sep 28 16:54:02 EEST 2012
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x1010820
#define ALT_CPU_CPU_FREQ 100000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x0
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x19
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x1008020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 100000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 2048
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x19
#define ALT_CPU_NAME "cpu_0"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x1008000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x1010820
#define NIOS2_CPU_FREQ 100000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x0
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x19
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x1008020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 2048
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x19
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x1008000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2
#define __ALTPLL


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "CYCLONEIII"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x10110e0
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x10110e0
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x10110e0
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios2"


/*
 * altpll_0 configuration
 *
 */

#define ALTPLL_0_BASE 0x1011020
#define ALTPLL_0_IRQ -1
#define ALTPLL_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ALTPLL_0_NAME "/dev/altpll_0"
#define ALTPLL_0_SPAN 16
#define ALTPLL_0_TYPE "altpll"
#define ALT_MODULE_CLASS_altpll_0 altpll


/*
 * cal_dac_code_pio configuration
 *
 */

#define ALT_MODULE_CLASS_cal_dac_code_pio altera_avalon_pio
#define CAL_DAC_CODE_PIO_BASE 0x10110a0
#define CAL_DAC_CODE_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define CAL_DAC_CODE_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define CAL_DAC_CODE_PIO_CAPTURE 0
#define CAL_DAC_CODE_PIO_DATA_WIDTH 14
#define CAL_DAC_CODE_PIO_DO_TEST_BENCH_WIRING 0
#define CAL_DAC_CODE_PIO_DRIVEN_SIM_VALUE 0x0
#define CAL_DAC_CODE_PIO_EDGE_TYPE "NONE"
#define CAL_DAC_CODE_PIO_FREQ 50000000u
#define CAL_DAC_CODE_PIO_HAS_IN 0
#define CAL_DAC_CODE_PIO_HAS_OUT 1
#define CAL_DAC_CODE_PIO_HAS_TRI 0
#define CAL_DAC_CODE_PIO_IRQ -1
#define CAL_DAC_CODE_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CAL_DAC_CODE_PIO_IRQ_TYPE "NONE"
#define CAL_DAC_CODE_PIO_NAME "/dev/cal_dac_code_pio"
#define CAL_DAC_CODE_PIO_RESET_VALUE 0x0
#define CAL_DAC_CODE_PIO_SPAN 16
#define CAL_DAC_CODE_PIO_TYPE "altera_avalon_pio"


/*
 * comparator_pio configuration
 *
 */

#define ALT_MODULE_CLASS_comparator_pio altera_avalon_pio
#define COMPARATOR_PIO_BASE 0x1011060
#define COMPARATOR_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define COMPARATOR_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define COMPARATOR_PIO_CAPTURE 0
#define COMPARATOR_PIO_DATA_WIDTH 1
#define COMPARATOR_PIO_DO_TEST_BENCH_WIRING 0
#define COMPARATOR_PIO_DRIVEN_SIM_VALUE 0x0
#define COMPARATOR_PIO_EDGE_TYPE "NONE"
#define COMPARATOR_PIO_FREQ 100000000u
#define COMPARATOR_PIO_HAS_IN 1
#define COMPARATOR_PIO_HAS_OUT 0
#define COMPARATOR_PIO_HAS_TRI 0
#define COMPARATOR_PIO_IRQ -1
#define COMPARATOR_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define COMPARATOR_PIO_IRQ_TYPE "NONE"
#define COMPARATOR_PIO_NAME "/dev/comparator_pio"
#define COMPARATOR_PIO_RESET_VALUE 0x0
#define COMPARATOR_PIO_SPAN 16
#define COMPARATOR_PIO_TYPE "altera_avalon_pio"


/*
 * gen_code_strobe configuration
 *
 */

#define ALT_MODULE_CLASS_gen_code_strobe altera_avalon_pio
#define GEN_CODE_STROBE_BASE 0x1011080
#define GEN_CODE_STROBE_BIT_CLEARING_EDGE_REGISTER 0
#define GEN_CODE_STROBE_BIT_MODIFYING_OUTPUT_REGISTER 0
#define GEN_CODE_STROBE_CAPTURE 0
#define GEN_CODE_STROBE_DATA_WIDTH 1
#define GEN_CODE_STROBE_DO_TEST_BENCH_WIRING 0
#define GEN_CODE_STROBE_DRIVEN_SIM_VALUE 0x0
#define GEN_CODE_STROBE_EDGE_TYPE "NONE"
#define GEN_CODE_STROBE_FREQ 50000000u
#define GEN_CODE_STROBE_HAS_IN 0
#define GEN_CODE_STROBE_HAS_OUT 1
#define GEN_CODE_STROBE_HAS_TRI 0
#define GEN_CODE_STROBE_IRQ -1
#define GEN_CODE_STROBE_IRQ_INTERRUPT_CONTROLLER_ID -1
#define GEN_CODE_STROBE_IRQ_TYPE "NONE"
#define GEN_CODE_STROBE_NAME "/dev/gen_code_strobe"
#define GEN_CODE_STROBE_RESET_VALUE 0x0
#define GEN_CODE_STROBE_SPAN 16
#define GEN_CODE_STROBE_TYPE "altera_avalon_pio"


/*
 * gen_code_value_pio_0 configuration
 *
 */

#define ALT_MODULE_CLASS_gen_code_value_pio_0 altera_avalon_pio
#define GEN_CODE_VALUE_PIO_0_BASE 0x1011030
#define GEN_CODE_VALUE_PIO_0_BIT_CLEARING_EDGE_REGISTER 0
#define GEN_CODE_VALUE_PIO_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define GEN_CODE_VALUE_PIO_0_CAPTURE 0
#define GEN_CODE_VALUE_PIO_0_DATA_WIDTH 24
#define GEN_CODE_VALUE_PIO_0_DO_TEST_BENCH_WIRING 0
#define GEN_CODE_VALUE_PIO_0_DRIVEN_SIM_VALUE 0x0
#define GEN_CODE_VALUE_PIO_0_EDGE_TYPE "NONE"
#define GEN_CODE_VALUE_PIO_0_FREQ 100000000u
#define GEN_CODE_VALUE_PIO_0_HAS_IN 0
#define GEN_CODE_VALUE_PIO_0_HAS_OUT 1
#define GEN_CODE_VALUE_PIO_0_HAS_TRI 0
#define GEN_CODE_VALUE_PIO_0_IRQ -1
#define GEN_CODE_VALUE_PIO_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define GEN_CODE_VALUE_PIO_0_IRQ_TYPE "NONE"
#define GEN_CODE_VALUE_PIO_0_NAME "/dev/gen_code_value_pio_0"
#define GEN_CODE_VALUE_PIO_0_RESET_VALUE 0x0
#define GEN_CODE_VALUE_PIO_0_SPAN 16
#define GEN_CODE_VALUE_PIO_0_TYPE "altera_avalon_pio"


/*
 * gen_code_value_pio_1 configuration
 *
 */

#define ALT_MODULE_CLASS_gen_code_value_pio_1 altera_avalon_pio
#define GEN_CODE_VALUE_PIO_1_BASE 0x1011040
#define GEN_CODE_VALUE_PIO_1_BIT_CLEARING_EDGE_REGISTER 0
#define GEN_CODE_VALUE_PIO_1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define GEN_CODE_VALUE_PIO_1_CAPTURE 0
#define GEN_CODE_VALUE_PIO_1_DATA_WIDTH 24
#define GEN_CODE_VALUE_PIO_1_DO_TEST_BENCH_WIRING 0
#define GEN_CODE_VALUE_PIO_1_DRIVEN_SIM_VALUE 0x0
#define GEN_CODE_VALUE_PIO_1_EDGE_TYPE "NONE"
#define GEN_CODE_VALUE_PIO_1_FREQ 100000000u
#define GEN_CODE_VALUE_PIO_1_HAS_IN 0
#define GEN_CODE_VALUE_PIO_1_HAS_OUT 1
#define GEN_CODE_VALUE_PIO_1_HAS_TRI 0
#define GEN_CODE_VALUE_PIO_1_IRQ -1
#define GEN_CODE_VALUE_PIO_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define GEN_CODE_VALUE_PIO_1_IRQ_TYPE "NONE"
#define GEN_CODE_VALUE_PIO_1_NAME "/dev/gen_code_value_pio_1"
#define GEN_CODE_VALUE_PIO_1_RESET_VALUE 0x0
#define GEN_CODE_VALUE_PIO_1_SPAN 16
#define GEN_CODE_VALUE_PIO_1_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK SYS_CLK_TIMER
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x10110e0
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * latch_pio configuration
 *
 */

#define ALT_MODULE_CLASS_latch_pio altera_avalon_pio
#define LATCH_PIO_BASE 0x10110d0
#define LATCH_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define LATCH_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LATCH_PIO_CAPTURE 0
#define LATCH_PIO_DATA_WIDTH 1
#define LATCH_PIO_DO_TEST_BENCH_WIRING 0
#define LATCH_PIO_DRIVEN_SIM_VALUE 0x0
#define LATCH_PIO_EDGE_TYPE "NONE"
#define LATCH_PIO_FREQ 50000000u
#define LATCH_PIO_HAS_IN 0
#define LATCH_PIO_HAS_OUT 1
#define LATCH_PIO_HAS_TRI 0
#define LATCH_PIO_IRQ -1
#define LATCH_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LATCH_PIO_IRQ_TYPE "NONE"
#define LATCH_PIO_NAME "/dev/latch_pio"
#define LATCH_PIO_RESET_VALUE 0x0
#define LATCH_PIO_SPAN 16
#define LATCH_PIO_TYPE "altera_avalon_pio"


/*
 * led_pio configuration
 *
 */

#define ALT_MODULE_CLASS_led_pio altera_avalon_pio
#define LED_PIO_BASE 0x1011070
#define LED_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define LED_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_PIO_CAPTURE 0
#define LED_PIO_DATA_WIDTH 8
#define LED_PIO_DO_TEST_BENCH_WIRING 0
#define LED_PIO_DRIVEN_SIM_VALUE 0x0
#define LED_PIO_EDGE_TYPE "NONE"
#define LED_PIO_FREQ 50000000u
#define LED_PIO_HAS_IN 0
#define LED_PIO_HAS_OUT 1
#define LED_PIO_HAS_TRI 0
#define LED_PIO_IRQ -1
#define LED_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_PIO_IRQ_TYPE "NONE"
#define LED_PIO_NAME "/dev/led_pio"
#define LED_PIO_RESET_VALUE 0x0
#define LED_PIO_SPAN 16
#define LED_PIO_TYPE "altera_avalon_pio"


/*
 * mode_select configuration
 *
 */

#define ALT_MODULE_CLASS_mode_select altera_avalon_pio
#define MODE_SELECT_BASE 0x1011050
#define MODE_SELECT_BIT_CLEARING_EDGE_REGISTER 0
#define MODE_SELECT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define MODE_SELECT_CAPTURE 1
#define MODE_SELECT_DATA_WIDTH 2
#define MODE_SELECT_DO_TEST_BENCH_WIRING 0
#define MODE_SELECT_DRIVEN_SIM_VALUE 0x0
#define MODE_SELECT_EDGE_TYPE "ANY"
#define MODE_SELECT_FREQ 100000000u
#define MODE_SELECT_HAS_IN 1
#define MODE_SELECT_HAS_OUT 0
#define MODE_SELECT_HAS_TRI 0
#define MODE_SELECT_IRQ -1
#define MODE_SELECT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MODE_SELECT_IRQ_TYPE "NONE"
#define MODE_SELECT_NAME "/dev/mode_select"
#define MODE_SELECT_RESET_VALUE 0x0
#define MODE_SELECT_SPAN 16
#define MODE_SELECT_TYPE "altera_avalon_pio"


/*
 * onchip_mem configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_mem altera_avalon_onchip_memory2
#define ONCHIP_MEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEM_BASE 0x1008000
#define ONCHIP_MEM_CONTENTS_INFO ""
#define ONCHIP_MEM_DUAL_PORT 0
#define ONCHIP_MEM_GUI_RAM_BLOCK_TYPE "Automatic"
#define ONCHIP_MEM_INIT_CONTENTS_FILE "onchip_mem"
#define ONCHIP_MEM_INIT_MEM_CONTENT 1
#define ONCHIP_MEM_INSTANCE_ID "NONE"
#define ONCHIP_MEM_IRQ -1
#define ONCHIP_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEM_NAME "/dev/onchip_mem"
#define ONCHIP_MEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEM_RAM_BLOCK_TYPE "Auto"
#define ONCHIP_MEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEM_SIZE_MULTIPLE 1
#define ONCHIP_MEM_SIZE_VALUE 32768u
#define ONCHIP_MEM_SPAN 32768
#define ONCHIP_MEM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEM_WRITABLE 1


/*
 * sample_and_hold_pio configuration
 *
 */

#define ALT_MODULE_CLASS_sample_and_hold_pio altera_avalon_pio
#define SAMPLE_AND_HOLD_PIO_BASE 0x10110c0
#define SAMPLE_AND_HOLD_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define SAMPLE_AND_HOLD_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SAMPLE_AND_HOLD_PIO_CAPTURE 0
#define SAMPLE_AND_HOLD_PIO_DATA_WIDTH 1
#define SAMPLE_AND_HOLD_PIO_DO_TEST_BENCH_WIRING 0
#define SAMPLE_AND_HOLD_PIO_DRIVEN_SIM_VALUE 0x0
#define SAMPLE_AND_HOLD_PIO_EDGE_TYPE "NONE"
#define SAMPLE_AND_HOLD_PIO_FREQ 50000000u
#define SAMPLE_AND_HOLD_PIO_HAS_IN 0
#define SAMPLE_AND_HOLD_PIO_HAS_OUT 1
#define SAMPLE_AND_HOLD_PIO_HAS_TRI 0
#define SAMPLE_AND_HOLD_PIO_IRQ -1
#define SAMPLE_AND_HOLD_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SAMPLE_AND_HOLD_PIO_IRQ_TYPE "NONE"
#define SAMPLE_AND_HOLD_PIO_NAME "/dev/sample_and_hold_pio"
#define SAMPLE_AND_HOLD_PIO_RESET_VALUE 0x0
#define SAMPLE_AND_HOLD_PIO_SPAN 16
#define SAMPLE_AND_HOLD_PIO_TYPE "altera_avalon_pio"


/*
 * sdram_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sdram_0 altera_avalon_new_sdram_controller
#define SDRAM_0_BASE 0x800000
#define SDRAM_0_CAS_LATENCY 2
#define SDRAM_0_CONTENTS_INFO ""
#define SDRAM_0_INIT_NOP_DELAY 0.0
#define SDRAM_0_INIT_REFRESH_COMMANDS 2
#define SDRAM_0_IRQ -1
#define SDRAM_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_0_IS_INITIALIZED 1
#define SDRAM_0_NAME "/dev/sdram_0"
#define SDRAM_0_POWERUP_DELAY 100.0
#define SDRAM_0_REFRESH_PERIOD 31.25
#define SDRAM_0_REGISTER_DATA_IN 1
#define SDRAM_0_SDRAM_ADDR_WIDTH 0x16
#define SDRAM_0_SDRAM_BANK_WIDTH 2
#define SDRAM_0_SDRAM_COL_WIDTH 8
#define SDRAM_0_SDRAM_DATA_WIDTH 16
#define SDRAM_0_SDRAM_NUM_BANKS 4
#define SDRAM_0_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_0_SDRAM_ROW_WIDTH 12
#define SDRAM_0_SHARED_DATA 0
#define SDRAM_0_SIM_MODEL_BASE 0
#define SDRAM_0_SPAN 8388608
#define SDRAM_0_STARVATION_INDICATOR 0
#define SDRAM_0_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_0_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_0_T_AC 5.4
#define SDRAM_0_T_MRD 3
#define SDRAM_0_T_RCD 20.0
#define SDRAM_0_T_RFC 70.0
#define SDRAM_0_T_RP 20.0
#define SDRAM_0_T_WR 14.0


/*
 * switch_pio configuration
 *
 */

#define ALT_MODULE_CLASS_switch_pio altera_avalon_pio
#define SWITCH_PIO_BASE 0x1011090
#define SWITCH_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCH_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCH_PIO_CAPTURE 0
#define SWITCH_PIO_DATA_WIDTH 4
#define SWITCH_PIO_DO_TEST_BENCH_WIRING 0
#define SWITCH_PIO_DRIVEN_SIM_VALUE 0x0
#define SWITCH_PIO_EDGE_TYPE "NONE"
#define SWITCH_PIO_FREQ 50000000u
#define SWITCH_PIO_HAS_IN 0
#define SWITCH_PIO_HAS_OUT 1
#define SWITCH_PIO_HAS_TRI 0
#define SWITCH_PIO_IRQ -1
#define SWITCH_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCH_PIO_IRQ_TYPE "NONE"
#define SWITCH_PIO_NAME "/dev/switch_pio"
#define SWITCH_PIO_RESET_VALUE 0x0
#define SWITCH_PIO_SPAN 16
#define SWITCH_PIO_TYPE "altera_avalon_pio"


/*
 * sys_clk_timer configuration
 *
 */

#define ALT_MODULE_CLASS_sys_clk_timer altera_avalon_timer
#define SYS_CLK_TIMER_ALWAYS_RUN 0
#define SYS_CLK_TIMER_BASE 0x1011000
#define SYS_CLK_TIMER_COUNTER_SIZE 32
#define SYS_CLK_TIMER_FIXED_PERIOD 0
#define SYS_CLK_TIMER_FREQ 50000000u
#define SYS_CLK_TIMER_IRQ 1
#define SYS_CLK_TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SYS_CLK_TIMER_LOAD_VALUE 49999ull
#define SYS_CLK_TIMER_MULT 0.0010
#define SYS_CLK_TIMER_NAME "/dev/sys_clk_timer"
#define SYS_CLK_TIMER_PERIOD 1
#define SYS_CLK_TIMER_PERIOD_UNITS "ms"
#define SYS_CLK_TIMER_RESET_OUTPUT 0
#define SYS_CLK_TIMER_SNAPSHOT 1
#define SYS_CLK_TIMER_SPAN 32
#define SYS_CLK_TIMER_TICKS_PER_SEC 1000u
#define SYS_CLK_TIMER_TIMEOUT_PULSE_OUTPUT 0
#define SYS_CLK_TIMER_TYPE "altera_avalon_timer"


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid
#define SYSID_BASE 0x10110e8
#define SYSID_ID 0u
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1348839678u
#define SYSID_TYPE "altera_avalon_sysid"


/*
 * usb_code_pio configuration
 *
 */

#define ALT_MODULE_CLASS_usb_code_pio altera_avalon_pio
#define USB_CODE_PIO_BASE 0x10110b0
#define USB_CODE_PIO_BIT_CLEARING_EDGE_REGISTER 0
#define USB_CODE_PIO_BIT_MODIFYING_OUTPUT_REGISTER 0
#define USB_CODE_PIO_CAPTURE 0
#define USB_CODE_PIO_DATA_WIDTH 21
#define USB_CODE_PIO_DO_TEST_BENCH_WIRING 0
#define USB_CODE_PIO_DRIVEN_SIM_VALUE 0x0
#define USB_CODE_PIO_EDGE_TYPE "NONE"
#define USB_CODE_PIO_FREQ 50000000u
#define USB_CODE_PIO_HAS_IN 0
#define USB_CODE_PIO_HAS_OUT 1
#define USB_CODE_PIO_HAS_TRI 0
#define USB_CODE_PIO_IRQ -1
#define USB_CODE_PIO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define USB_CODE_PIO_IRQ_TYPE "NONE"
#define USB_CODE_PIO_NAME "/dev/usb_code_pio"
#define USB_CODE_PIO_RESET_VALUE 0x0
#define USB_CODE_PIO_SPAN 16
#define USB_CODE_PIO_TYPE "altera_avalon_pio"

#endif /* __SYSTEM_H_ */
