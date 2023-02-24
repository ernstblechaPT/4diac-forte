/*******************************************************************************
 * Copyright (c) 2019 fortiss GmbH
 *               2023 Martin Erich Jobst
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *  Jose Cabral - Adds getNanoSecondsMonotonic
 *  Martin Jobst - add high-resolution realtime clock fallback
 *******************************************************************************/

#include <FreeRTOS.h>
#include <task.h>

#include "forte_architecture_time.h"
#include "forte_constants.h"

#ifndef FORTE_FAKE_TIME
uint_fast64_t getNanoSecondsMonotonic() {
  return (static_cast<uint_fast64_t>(xTaskGetTickCount()) * (forte::core::constants::cNanosecondsPerSecond / static_cast<uint_fast64_t>(configTICK_RATE_HZ)));
}

uint_fast64_t getNanoSecondsRealtime() {
  return static_cast<uint_fast64_t>(forte_time())*1000000000LL;
}
#endif
