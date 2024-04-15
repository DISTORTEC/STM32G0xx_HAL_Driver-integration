/**
 * \file
 * \brief APBPrescTable definition
 *
 * \author Copyright (C) 2021 Michal Bohdal
 * \author Copyright (C) 2024 Kamil Szczygiel https://distortec.com https://freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "stm32g0xx_hal.h"

/*---------------------------------------------------------------------------------------------------------------------+
| global objects
+---------------------------------------------------------------------------------------------------------------------*/

/// APB prescaler table
const uint32_t APBPrescTable[8] {0, 0, 0, 0, 1, 2, 3, 4};
