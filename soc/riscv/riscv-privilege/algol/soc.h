#ifndef RISCV32_ALGOL_SOC_H
#define RISCV32_ALGOL_SOC_H

#include <soc_common.h>

// UART configuration
#define RISCV_UART_BAUD_CONFIG 0x20010000
#define RISCV_UART_TX          0x20010004
#define RISCV_UART_RX          0x20010008
#define RISCV_UART_STATUS      0x2001000c

// Timer configuration
#define RISCV_MTIME_BASE       0x20000008
#define RISCV_MTIMECMP_BASE    0x20000000

#define RISCV_RAM_BASE         CONFIG_RISCV_RAM_BASE_ADDR
#define RISCV_RAM_SIZE         CONFIG_RISCV_RAM_SIZE

#endif
