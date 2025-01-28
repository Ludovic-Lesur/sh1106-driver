/*
 * sh1106_hw.h
 *
 *  Created on: 27 aug. 2024
 *      Author: Ludo
 */

#ifndef __SH1106_HW_H__
#define __SH1106_HW_H__

#ifndef SH1106_DRIVER_DISABLE_FLAGS_FILE
#include "sh1106_driver_flags.h"
#endif
#include "sh1106.h"
#include "types.h"

#ifndef SH1106_DRIVER_DISABLE

/*** SH1106 HW functions ***/

/*!******************************************************************
 * \fn SH1106_status_t SH1106_HW_init(void)
 * \brief Init SH1106 hardware interface.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
SH1106_status_t SH1106_HW_init(void);

/*!******************************************************************
 * \fn SH1106_status_t SH1106_HW_de_init(void)
 * \brief Release SH1106 hardware interface.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
SH1106_status_t SH1106_HW_de_init(void);

/*!******************************************************************
 * \fn SH1106_status_t SH1106_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag)
 * \brief Write data to chip over I2C bus.
 * \param[in]   i2c_address: 7-bits chip address.
 * \param[in]   data: Byte array to send.
 * \param[in]   data_size_bytes: Number of bytes to send.
 * \param[in]   stop_flag: Generate stop condition at the end of the transfer if non zero.
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
SH1106_status_t SH1106_HW_i2c_write(uint8_t i2c_address, uint8_t* data, uint8_t data_size_bytes, uint8_t stop_flag);

#endif /* SH1106_DRIVER_DISABLE */

#endif /* __SH1106_HW_H__ */
