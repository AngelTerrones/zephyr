/*
 * Copyright (c) 2018 Ángel Terrones
 */

#include <kernel.h>
#include <arch/cpu.h>
#include <uart.h>
#include <sys_io.h>
#include <board.h>

static unsigned char uart_algol_poll_out(struct device *dev, unsigned char c) {
        volatile int *uart_status = (int *)RISCV_UART_STATUS;
        volatile int *uart_tx     = (int *)RISCV_UART_TX;
        while(!(uart_status[0] & 0x1));
        uart_tx[0] = c;
        return c;
}

static int uart_algol_poll_in(struct device *dev, unsigned char *c) {
        return -1;
}

static int uart_algol_init(struct device *dev) {
        // Configure the UART for BAUD_RATE
        volatile int *uart_status = (int *)RISCV_UART_BAUD_CONFIG;
        uart_status[0] = sys_clock_hw_cycles_per_sec/1000000; // hardcoded, for now...
        return 0;
}


static const struct uart_driver_api uart_algol_driver_api = {
        .poll_in = uart_algol_poll_in,
        .poll_out = uart_algol_poll_out,
        .err_check = NULL,
};


DEVICE_AND_API_INIT(uart_algol_0, "uart0",
                    uart_algol_init, NULL,
                    NULL, //&uart_algol_dev_cfg_0,
                    PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
                    (void *)&uart_algol_driver_api);
