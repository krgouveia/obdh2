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
 * \version 0.4.2
 * 
 * \date 11/07/2020
 * 
 * \addtogroup voltage_sensor
 * \{
 */

#include <system/sys_log/sys_log.h>

#include "voltage_sensor.h"

int voltage_sensor_init()
{
    sys_log_print_event_from_module(SYS_LOG_INFO, VOLTAGE_SENSOR_MODULE_NAME, "Initializing the voltage sensor...");
    sys_log_new_line();

    if (adc_init(VOLTAGE_SENSOR_ADC_PORT, (adc_config_t){}) != 0)
    {
        sys_log_print_event_from_module(SYS_LOG_ERROR, VOLTAGE_SENSOR_MODULE_NAME, "Error initializing the voltage sensor!");
        sys_log_new_line();

        return -1;
    }

    uint16_t volt = 0;
    if (voltage_sensor_read(&volt) != 0)
    {
        sys_log_print_event_from_module(SYS_LOG_ERROR, VOLTAGE_SENSOR_MODULE_NAME, "Error reading the voltage value!");
        sys_log_new_line();

        return -1;
    }

    sys_log_print_event_from_module(SYS_LOG_INFO, VOLTAGE_SENSOR_MODULE_NAME, "Current input voltage: ");
    sys_log_print_uint(volt);
    sys_log_print_msg(" mV");
    sys_log_new_line();

    return 0;
}

int voltage_sensor_read_raw(uint16_t *val)
{
    return adc_read(VOLTAGE_SENSOR_ADC_PORT, val);
}

int voltage_sensor_read(uint16_t *volt)
{
    uint16_t raw_volt = 0;

    if (voltage_sensor_read_raw(&raw_volt) != 0)
    {
        sys_log_print_event_from_module(SYS_LOG_ERROR, VOLTAGE_SENSOR_MODULE_NAME, "Error reading the raw voltage value!");
        sys_log_new_line();

        return -1;
    }

    *volt = (uint16_t)(1000*(float)raw_volt*ADC_AVCC*VOLTAGE_SENSOR_DIV/ADC_RANGE);

    return 0;
}

/** \} End of voltage_sensor group */
