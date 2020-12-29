/** \file hshbme280.h
 *  \brief function prototypes and constants for hshbme280
 *  \author Created: Harshit Walia, Sahil Sahil
 *  \date 24JAN2019
*/
#ifndef BME280_H
#define BME280_H
#include <stdint.h>

#define I2C_MODE 1
#define I2CADDRESS 0x76
#define CHIPSELECTPIN 10
#define RMODE 3
#define TOVRSAMP 1
#define POVRSAMP 1
#define HOVRSAMP 1
#define TSTANDBY 0
#define CTRLMEASBME280 ((TOVRSAMP << 0x05) & 0xE0) | ((POVRSAMP << 0x02) & 0x1c) | ((RMODE) & 0x11)
#define FILTER 0

//Register names:
#define BME280_DIG_T1_LSB_REG			0x88
#define BME280_DIG_T1_MSB_REG			0x89
#define BME280_DIG_T2_LSB_REG			0x8A
#define BME280_DIG_T2_MSB_REG			0x8B
#define BME280_DIG_T3_LSB_REG			0x8C
#define BME280_DIG_T3_MSB_REG			0x8D
#define BME280_DIG_P1_LSB_REG			0x8E
#define BME280_DIG_P1_MSB_REG			0x8F
#define BME280_DIG_P2_LSB_REG			0x90
#define BME280_DIG_P2_MSB_REG			0x91
#define BME280_DIG_P3_LSB_REG			0x92
#define BME280_DIG_P3_MSB_REG			0x93
#define BME280_DIG_P4_LSB_REG			0x94
#define BME280_DIG_P4_MSB_REG			0x95
#define BME280_DIG_P5_LSB_REG			0x96
#define BME280_DIG_P5_MSB_REG			0x97
#define BME280_DIG_P6_LSB_REG			0x98
#define BME280_DIG_P6_MSB_REG			0x99
#define BME280_DIG_P7_LSB_REG			0x9A
#define BME280_DIG_P7_MSB_REG			0x9B
#define BME280_DIG_P8_LSB_REG			0x9C
#define BME280_DIG_P8_MSB_REG			0x9D
#define BME280_DIG_P9_LSB_REG			0x9E
#define BME280_DIG_P9_MSB_REG			0x9F
#define BME280_DIG_H1_REG				0xA1
#define BME280_CHIP_ID_REG				0xD0 //Chip ID
#define BME280_RST_REG				0xE0 //Softreset Reg
#define BME280_DIG_H2_LSB_REG			0xE1
#define BME280_DIG_H2_MSB_REG			0xE2
#define BME280_DIG_H3_REG				0xE3
#define BME280_DIG_H4_MSB_REG			0xE4
#define BME280_DIG_H4_LSB_REG			0xE5
#define BME280_DIG_H5_MSB_REG			0xE6
#define BME280_DIG_H6_REG				0xE7
#define BME280_CTRL_HUMIDITY_REG			0xF2 //Ctrl Humidity Reg
#define BME280_STAT_REG				0xF3 //Status Reg
#define BME280_CTRL_MEAS_REG			0xF4 //Ctrl Measure Reg
#define BME280_CONFIG_REG				0xF5 //Configuration Reg
#define BME280_PRESSURE_MSB_REG			0xF7 //Pressure MSB
#define BME280_PRESSURE_LSB_REG			0xF8 //Pressure LSB
#define BME280_PRESSURE_XLSB_REG			0xF9 //Pressure XLSB
#define BME280_TEMPERATURE_MSB_REG		0xFA //Temperature MSB
#define BME280_TEMPERATURE_LSB_REG		0xFB //Temperature LSB
#define BME280_TEMPERATURE_XLSB_REG		0xFC //Temperature XLSB
#define BME280_HUMIDITY_MSB_REG			0xFD //Humidity MSB
#define BME280_HUMIDITY_LSB_REG			0xFE //Humidity LSB

//Used to hold the calibration constants.  These are used
// by the driver as measurements are being taking

/** \brief Structure for SensorCalibration
 * \author Harshit Walia, Sahil Sahil
 * \date 24JAN2019
 */
struct SensorCalibration
{
	uint16_t dig_T1;		///dig_T1 uint16_t
	int16_t dig_T2;			///dig_T2 int16_t
	int16_t dig_T3;			///dig_T3 init16_t

	uint16_t dig_P1;		///dig_P1 uint16_t
	int16_t dig_P2;			///dig_P2 init16_t
	int16_t dig_P3;			///dig_P3 init16_t
	int16_t dig_P4;			///dig_P4 init16_t
	int16_t dig_P5;			///dig_P5 init16_t
	int16_t dig_P6;			///dig_P6 init16_t
	int16_t dig_P7;			///dig_P7 init16_t
	int16_t dig_P8;			///dig_P8 init16_t
	int16_t dig_P9;			///dig_P9 init16_t

	uint8_t dig_H1;			///dig_H1 uint8_t
	int16_t dig_H2;			///dig_H2 init16_t
	uint8_t dig_H3;			///dig_H3 uint16_t
	int16_t dig_H4;			///dig_H4 init16_t
	int16_t dig_H5;			///dig_H5 init16_t
	uint8_t dig_H6;			///dig_H6 uint8_t
};

///\cond INTERNAL
// Function Prototypes


void BME280Setup(void);

void BME280Reset(void);

//Returns the values as floats.

double GetBME280Pressure(void);


double GetBME280Humidity(void);

double GetBME280TempC(void);
///\endcond
#endif
