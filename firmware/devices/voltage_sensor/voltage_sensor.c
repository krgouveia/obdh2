/*
 * voltage_sensor.c
 * 
 * Copyright (C) 2020, SpaceLab.
 * 
 * This file is part of OBDH 2.0.
 * 
 * OBDH 2.0 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * OBDH 2.0 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with OBDH 2.0. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \brief Voltage sensor device implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.4.0
 * 
 * \date 11/07/2020
 * 
 * \addtogroup voltage_sensor
 * \{
 */

#include <drivers/adc/adc.h>

#include <system/sys_log/sys_log.h>

#include "voltage_sensor.h"

int voltage_sensor_init()
{
    sys_log_print_event_from_module(SYS_LOG_INFO, VOLTAGE_SENSOR_MODULE_NAME, "Initializing voltage sensor...");
    sys_log_new_line();

    return -1;
}

int voltage_sensor_read_raw(uint16_t *val)
{
    return -1;
}

int voltage_sensor_read(uint16_t *volt)
{
    return -1;
}

/** \} End of voltage_sensor group */