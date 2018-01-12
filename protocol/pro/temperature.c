/*
 * This file is part of OpenCorsairLink.
 * Copyright (C) 2017  Sean Nelson <audiohacked@gmail.com>

 * OpenCorsairLink is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * any later version.

 * OpenCorsairLink is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with OpenCorsairLink.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <libusb.h>
#include "../../lowlevel/asetek4.h"
#include "../../device.h"
#include "../../driver.h"
#include "../../print.h"

int corsairlink_pro_get_temp_setup_mask(struct corsair_device_info *dev,
			struct libusb_device_handle *handle, uint8_t port, struct color *color_led)
{
	int rr;
	uint8_t response[32];
	uint8_t commands[32] ;
	memset(response, 0, sizeof(response));
	memset(commands, 0, sizeof(commands));

	commands[0] = 0x30;
	commands[1] = port;

	rr = dev->driver->write(handle, dev->write_endpoint, commands, 19);
	rr = dev->driver->read(handle, dev->read_endpoint, response, 32);

	return rr;
}

int corsairlink_pro_get_temp_reading(struct corsair_device_info *dev,
			struct libusb_device_handle *handle, uint8_t port, struct color *color_led)
{
	int rr;
	uint8_t response[32];
	uint8_t commands[32] ;
	memset(response, 0, sizeof(response));
	memset(commands, 0, sizeof(commands));

	commands[0] = 0x30;

	rr = dev->driver->write(handle, dev->write_endpoint, commands, 19);
	rr = dev->driver->read(handle, dev->read_endpoint, response, 32);

	return rr;
}

int corsairlink_pro_get_volt_reading(struct corsair_device_info *dev,
			struct libusb_device_handle *handle, uint8_t port, struct color *color_led)
{
	int rr;
	uint8_t response[32];
	uint8_t commands[32] ;
	memset(response, 0, sizeof(response));
	memset(commands, 0, sizeof(commands));

	commands[0] = 0x30;

	rr = dev->driver->write(handle, dev->write_endpoint, commands, 19);
	rr = dev->driver->read(handle, dev->read_endpoint, response, 32);

	return rr;
}

