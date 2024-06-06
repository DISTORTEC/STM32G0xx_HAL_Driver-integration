#
# file: CMakeLists.txt
#
# This is the main CMakeLists.txt for STM32G0xx_HAL_Driver integration with distortos
#
# author: Copyright (C) 2020-2024 Kamil Szczygiel https://distortec.com https://freddiechopin.info
#
# This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
# distributed with this file, You can obtain one at https://mozilla.org/MPL/2.0/.
#

cmake_minimum_required(VERSION 3.8)
project(STM32G0xx_HAL_Driver-integration)

if(NOT DEFINED STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY)
	message(SEND_ERROR "Variable with path to STM32G0xx_HAL_Driver-configuration.h - "
			"STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY - is not defined")
endif()
if(NOT IS_DIRECTORY "${STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY}")
	message(SEND_ERROR "Path to STM32G0xx_HAL_Driver-configuration.h - "
			"STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY = ${STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY} - is "
			"not valid")
endif()
if(NOT EXISTS "${STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY}/STM32G0xx_HAL_Driver-configuration.h")
	message(SEND_ERROR "Path to STM32G0xx_HAL_Driver-configuration.h - "
			"STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY = ${STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY} - does "
			"not contain STM32G0xx_HAL_Driver-configuration.h")
endif()

if(NOT DEFINED STM32G0XX_HAL_DRIVER_DIRECTORY)
	message(SEND_ERROR "Variable with path to STM32G0xx_HAL_Driver directory - STM32G0XX_HAL_DRIVER_DIRECTORY - is not "
			"defined")
endif()
if(NOT IS_DIRECTORY "${STM32G0XX_HAL_DRIVER_DIRECTORY}")
	message(SEND_ERROR "Path to STM32G0xx_HAL_Driver directory - "
			"STM32G0XX_HAL_DRIVER_DIRECTORY = ${STM32G0XX_HAL_DRIVER_DIRECTORY} - is not valid")
endif()
if(NOT EXISTS "${STM32G0XX_HAL_DRIVER_DIRECTORY}/Inc/stm32g0xx_hal.h")
	message(SEND_ERROR "Path to STM32G0xx_HAL_Driver directory - "
			"STM32G0XX_HAL_DRIVER_DIRECTORY = ${STM32G0XX_HAL_DRIVER_DIRECTORY} - does not contain Inc/stm32g0xx_hal.h")
endif()

if(STM32G0xx_HAL_Driver_ADC)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's ADC")
endif()

if(STM32G0xx_HAL_Driver_DAC)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's DAC")
endif()

if(STM32G0xx_HAL_Driver_I2C)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's I2C")
endif()

if(STM32G0xx_HAL_Driver_I2S)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's I2S")
endif()

if(STM32G0xx_HAL_Driver_IRDA)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's IRDA")
endif()

if(STM32G0xx_HAL_Driver_SMARTCARD)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's SMARTCARD")
endif()

if(STM32G0xx_HAL_Driver_SPI)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's SPI")
endif()

if(STM32G0xx_HAL_Driver_TIM)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's TIM")
endif()

if(STM32G0xx_HAL_Driver_UART)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's UART")
endif()

if(STM32G0xx_HAL_Driver_USART)
	list(APPEND STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS "STM32G0xx_HAL_Driver's USART")
endif()

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_Full_LL_driver
		OFF
		HELP "Enable \"full\" LL driver."
		OUTPUT_NAME USE_FULL_LL_DRIVER)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_ADC
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's ADC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_CEC
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's CEC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_COMP
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's COMP module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_CRC
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's CRC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_CRYP
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's CRYP module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_DAC
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's DAC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_DMA
		OFF
		DEPENDENTS ${STM32G0XX_HAL_DRIVER_DMA_DEPENDENTS}
		HELP "Enable STM32G0xx_HAL_Driver's DMA module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_EXTI
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's EXTI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_FDCAN
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's FDCAN module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_HCD
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's HCD module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_I2C
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's I2C module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_I2S
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's I2S module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_IRDA
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's IRDA module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_IWDG
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's IWDG module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_LPTIM
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's LPTIM module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_PCD
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's PCD module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_RNG
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's RNG module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_RTC
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's RTC module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_SMARTCARD
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's SMARTCARD module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_SMBUS
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's SMBUS module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_SPI
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's SPI module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_TIM
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's TIM module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_UART
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's UART module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_USART
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's USART module."
		NO_OUTPUT)

distortosSetConfiguration(BOOLEAN
		STM32G0xx_HAL_Driver_WWDG
		OFF
		HELP "Enable STM32G0xx_HAL_Driver's WWDG module."
		NO_OUTPUT)

message(STATUS "Generating ${CMAKE_CURRENT_BINARY_DIR}/include/stm32g0xx_hal_conf.h")
string(TIMESTAMP timestamp "%Y-%m-%d %H:%M:%S")
configure_file(stm32g0xx_hal_conf.h.in
		${CMAKE_CURRENT_BINARY_DIR}/include/stm32g0xx_hal_conf.h)

add_library(STM32G0xx_HAL_Driver STATIC
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_cortex.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_flash.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_flash_ex.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_gpio.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_pwr.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_pwr_ex.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_rcc.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_rcc_ex.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_adc.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_comp.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_crc.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_crs.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_dac.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_dma.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_exti.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_gpio.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_i2c.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_lptim.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_lpuart.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_pwr.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_rcc.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_rng.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_rtc.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_spi.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_tim.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_ucpd.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_usart.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_usb.c
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_ll_utils.c)
target_compile_options(STM32G0xx_HAL_Driver PRIVATE
		-Wno-old-style-declaration)
target_include_directories(STM32G0xx_HAL_Driver BEFORE PUBLIC
		include)
target_include_directories(STM32G0xx_HAL_Driver PUBLIC
		${CMAKE_CURRENT_BINARY_DIR}/include
		${STM32G0XX_HAL_DRIVER_CONFIGURATION_H_DIRECTORY}
		${STM32G0XX_HAL_DRIVER_DIRECTORY}/Inc)
target_link_libraries(STM32G0xx_HAL_Driver PUBLIC
		distortos::distortos)

if(STM32G0xx_HAL_Driver_Full_LL_driver)
	target_compile_definitions(STM32G0xx_HAL_Driver PRIVATE
			USE_FULL_LL_DRIVER)
	target_compile_options(STM32G0xx_HAL_Driver PRIVATE
			-Wno-unused-parameter)
endif()

if(STM32G0xx_HAL_Driver_ADC)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_adc.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_adc_ex.c)
endif(STM32G0xx_HAL_Driver_ADC)

if(STM32G0xx_HAL_Driver_CEC)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_cec.c)
endif(STM32G0xx_HAL_Driver_CEC)

if(STM32G0xx_HAL_Driver_COMP)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_comp.c)
endif(STM32G0xx_HAL_Driver_COMP)

if(STM32G0xx_HAL_Driver_CRC)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_crc.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_crc_ex.c)
endif(STM32G0xx_HAL_Driver_CRC)

if(STM32G0xx_HAL_Driver_CRYP)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_cryp.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_cryp_ex.c)
endif(STM32G0xx_HAL_Driver_CRYP)

if(STM32G0xx_HAL_Driver_DAC)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_dac.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_dac_ex.c)
endif(STM32G0xx_HAL_Driver_DAC)

if(STM32G0xx_HAL_Driver_DMA)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_dma.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_dma_ex.c)
endif(STM32G0xx_HAL_Driver_DMA)

if(STM32G0xx_HAL_Driver_EXTI)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_exti.c)
endif(STM32G0xx_HAL_Driver_EXTI)

if(STM32G0xx_HAL_Driver_FDCAN)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_fdcan.c)
endif(STM32G0xx_HAL_Driver_FDCAN)

if(STM32G0xx_HAL_Driver_HCD)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_hcd.c)
endif(STM32G0xx_HAL_Driver_HCD)

if(STM32G0xx_HAL_Driver_I2C)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_i2c.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_i2c_ex.c)
endif(STM32G0xx_HAL_Driver_I2C)

if(STM32G0xx_HAL_Driver_I2S)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_i2s.c)
endif(STM32G0xx_HAL_Driver_I2S)

if(STM32G0xx_HAL_Driver_IRDA)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_irda.c)
endif(STM32G0xx_HAL_Driver_IRDA)

if(STM32G0xx_HAL_Driver_IWDG)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_iwdg.c)
endif(STM32G0xx_HAL_Driver_IWDG)

if(STM32G0xx_HAL_Driver_LPTIM)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_lptim.c)
endif(STM32G0xx_HAL_Driver_LPTIM)

if(STM32G0xx_HAL_Driver_PCD)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_pcd.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_pcd_ex.c)
endif(STM32G0xx_HAL_Driver_PCD)

if(STM32G0xx_HAL_Driver_RNG)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_rng.c)
endif(STM32G0xx_HAL_Driver_RNG)

if(STM32G0xx_HAL_Driver_RTC)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_rtc.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_rtc_ex.c)
endif(STM32G0xx_HAL_Driver_RTC)

if(STM32G0xx_HAL_Driver_SMARTCARD)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_smartcard.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_smartcard_ex.c)
endif(STM32G0xx_HAL_Driver_SMARTCARD)

if(STM32G0xx_HAL_Driver_SMBUS)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_smbus.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_smbus_ex.c)
endif(STM32G0xx_HAL_Driver_SMBUS)

if(STM32G0xx_HAL_Driver_SPI)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_spi.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_spi_ex.c)
endif(STM32G0xx_HAL_Driver_SPI)

if(STM32G0xx_HAL_Driver_TIM)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_tim.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_tim_ex.c)
endif(STM32G0xx_HAL_Driver_TIM)

if(STM32G0xx_HAL_Driver_UART)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_uart.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_uart_ex.c)
endif(STM32G0xx_HAL_Driver_UART)

if(STM32G0xx_HAL_Driver_USART)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_usart.c
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_usart_ex.c)
endif(STM32G0xx_HAL_Driver_USART)

if(STM32G0xx_HAL_Driver_WWDG)
	target_sources(STM32G0xx_HAL_Driver PRIVATE
			${STM32G0XX_HAL_DRIVER_DIRECTORY}/Src/stm32g0xx_hal_wwdg.c)
endif(STM32G0xx_HAL_Driver_WWDG)

add_library(STM32G0xx_HAL_Driver-object-library OBJECT
		APBPrescTable.cpp
		HAL_Delay.cpp
		HAL_GetTick.cpp
		SystemCoreClock.cpp)
target_include_directories(STM32G0xx_HAL_Driver-object-library PRIVATE
		$<TARGET_PROPERTY:STM32G0xx_HAL_Driver,INTERFACE_INCLUDE_DIRECTORIES>)

target_sources(STM32G0xx_HAL_Driver INTERFACE
		$<TARGET_OBJECTS:STM32G0xx_HAL_Driver-object-library>)
