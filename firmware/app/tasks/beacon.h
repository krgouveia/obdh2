/*
 * beacon.h
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
 * \brief Beacon task definition.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.3.1
 * 
 * \date 27/10/2019
 * 
 * \defgroup beacon Beacon
 * \ingroup tasks
 * \{
 */

#ifndef BEACON_H_
#define BEACON_H_

#include <FreeRTOS.h>
#include <task.h>

#define TASK_BEACON_NAME                    "Beacon"            /**< Task name. */
#define TASK_BEACON_STACK_SIZE              2000                /**< Stack size in bytes. */
#define TASK_BEACON_PRIORITY                5                   /**< Task priority. */
#define TASK_BEACON_PERIOD_MS               60000               /**< Task period in milliseconds. */
#define TASK_BEACON_INITIAL_DELAY_MS        1000                /**< Delay, in milliseconds, before the first execution. */

/**
 * \brief Beacon handle.
 */
extern xTaskHandle xTaskBeaconHandle;

/**
 * \brief Beacon task.
 *
 * \param[in] pvParameters is a value that will passed as the task's parameter.
 *
 * \return None.
 */
void vTaskBeacon(void *pvParameters);

#endif /* BEACON_H_ */

/** \} End of beacon group */