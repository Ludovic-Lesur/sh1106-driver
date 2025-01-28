/*
 * sh1106_hw.c
 *
 *  Created on: 27 aug. 2024
 *      Author: Ludo
 */

#include "sh1106_hw.h"

#ifndef SH1106_DRIVER_DISABLE_FLAGS_FILE
#include "sh1106_driver_flags.h"
#endif
#include "sh1106.h"
#include "types.h"

#ifndef SH1106_DRIVER_DISABLE

/*** SH1106 HW functions ***/

/*******************************************************************/
SH1106_status_t __attribute__((weak)) SH1106_HW_init(void) {
    // Local variables.
    SH1106_status_t status = SH1106_SUCCESS;
    /* To be implemented */
    return status;
}

/*******************************************************************/
SH1106_status_t __attribute__((weak)) SH1106_HW_de_init(void) {
    // Local variables.
    SH1106_status_t status = SH1106_SUCCESS;
    /* To be implemented */
    return status;
}

/*******************************************************************/
SH1106_status_t __attribute__((weak)) SH1106_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag) {
    // Local variables.
    SH1106_status_t status = SH1106_SUCCESS;
    /* To be implemented */
    UNUSED(i2c_address);
    UNUSED(data);
    UNUSED(data_size_bytes);
    UNUSED(stop_flag);
    return status;
}

#endif /* SH1106_DRIVER_DISABLE */
