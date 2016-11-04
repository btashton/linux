/*
 * platform_bt.c: Bluetooth platform data initilization file
 *
 * (C) Copyright 2016 Intel Corporation
 * Author: Andy Shevchenko <andriy.shevchenko@linux.intel.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <linux/gpio/machine.h>
#include <linux/platform_device.h>

#include <asm/intel-mid.h>

#define BT_SFI_GPIO_DEVICE_WAKEUP	"bt_wakeup"
#define BT_SFI_GPIO_SHUTDOWN		"BT-reset"
#define BT_SFI_GPIO_HOST_WAKEUP		"bt_uart_enable"

static struct gpiod_lookup_table bt_sfi_gpio_table = {
	.dev_id	= "hci_bcm",
	.table	= {
		GPIO_LOOKUP("0000:00:0c.0", ~0, "device-wakeup", GPIO_ACTIVE_HIGH),
		GPIO_LOOKUP("0000:00:0c.0", ~0, "shutdown", GPIO_ACTIVE_HIGH),
		GPIO_LOOKUP("0000:00:0c.0", ~0, "host-wakeup", GPIO_ACTIVE_HIGH),
		{ },
	},
};

static struct platform_device bt_sfi_device = {
	.name	= "hci_bcm",
	.id	= PLATFORM_DEVID_NONE,
};

static int __init bt_sfi_init(void)
{
	struct gpiod_lookup_table *table = &bt_sfi_gpio_table;

	table->table[0].chip_hwnum = get_gpio_by_name(BT_SFI_GPIO_DEVICE_WAKEUP);
	table->table[1].chip_hwnum = get_gpio_by_name(BT_SFI_GPIO_SHUTDOWN);
	table->table[2].chip_hwnum = get_gpio_by_name(BT_SFI_GPIO_HOST_WAKEUP);

	gpiod_add_lookup_table(table);

	return platform_device_register(&bt_sfi_device);
}
device_initcall(bt_sfi_init);
