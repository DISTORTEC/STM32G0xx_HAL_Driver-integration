/**
 * \file
 * \brief SystemCoreClock definition
 *
 * \author Copyright (C) 2019-2024 Kamil Szczygiel https://distortec.com https://freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "stm32g0xx_hal.h"

#include "distortos/chip/clocks.hpp"

/*---------------------------------------------------------------------------------------------------------------------+
| global objects
+---------------------------------------------------------------------------------------------------------------------*/

/// system core clock
uint32_t SystemCoreClock {distortos::chip::sysclkFrequency};
