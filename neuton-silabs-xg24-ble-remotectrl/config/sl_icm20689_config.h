/*****************************CS**********************************************//**
 * @file
 * @brief ICM20689 Config
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef SL_ICM20689_CONFIG_H
#define SL_ICM20689_CONFIG_H


#define SL_ICM20689_SPI_EUSART_PERIPHERAL               EUSART1
#define SL_ICM20689_SPI_EUSART_PERIPHERAL_NO            1

#define SL_ICM20689_SPI_EUSART_TX_PORT                  gpioPortC
#define SL_ICM20689_SPI_EUSART_TX_PIN                   3

#define SL_ICM20689_SPI_EUSART_RX_PORT                  gpioPortC
#define SL_ICM20689_SPI_EUSART_RX_PIN                   2

#define SL_ICM20689_SPI_EUSART_SCLK_PORT                gpioPortC
#define SL_ICM20689_SPI_EUSART_SCLK_PIN                 1

#define SL_ICM20689_SPI_EUSART_CS_PORT                  gpioPortA
#define SL_ICM20689_SPI_EUSART_CS_PIN                   7


#define SL_ICM20689_INT_PORT                            gpioPortB
#define SL_ICM20689_INT_PIN                             1


#endif // SL_ICM20689_CONFIG_H
