//###########################################################################
//
// FILE:   F2837xD_Adc_defines.h
//
// TITLE:  #defines used in ADC examples
//
//###########################################################################
// $TI Release: F2837xD Support Library v200 $
// $Release Date: Tue Jun 21 13:00:02 CDT 2016 $
// $Copyright: Copyright (C) 2013-2016 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xD_ADC_DEFINES_H
#define F2837xD_ADC_DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

//
// Defines
//

//
//definitions for specifying an ADC
//
#define ADC_ADCA 0
#define ADC_ADCB 1
#define ADC_ADCC 2
#define ADC_ADCD 3

//
//definitions for selecting ADC resolution
//
#define ADC_RESOLUTION_12BIT 0
#define ADC_RESOLUTION_16BIT 1

//
//definitions for selecting ADC signal mode
//(single-ended mode is only a valid mode for 12-bit resolution)
//
#define ADC_SIGNALMODE_SINGLE 0
#define ADC_SIGNALMODE_DIFFERENTIAL 1

//Configures which trigger will start a burst conversion sequence.
#define TRIG_SEL_SOFT	0x00
#define TRIG_SEL_TIM0	0x01
#define TRIG_SEL_TIM1	0x02
#define TRIG_SEL_TIM2	0x03
#define TRIG_SEL_GPIO	0x04
#define TRIG_SEL_ePWM1_SOCA	0x05
#define TRIG_SEL_ePWM1_SOCB	0x06
#define TRIG_SEL_ePWM2_SOCA	0x07
#define TRIG_SEL_ePWM2_SOCB	0x08
#define TRIG_SEL_ePWM3_SOCA	0x09
#define TRIG_SEL_ePWM3_SOCB	0x0A
#define TRIG_SEL_ePWM4_SOCA	0x0B
#define TRIG_SEL_ePWM4_SOCB	0x0C
#define TRIG_SEL_ePWM5_SOCA	0x0D
#define TRIG_SEL_ePWM5_SOCB	0x0E
#define TRIG_SEL_ePWM6_SOCA	0x0F
#define TRIG_SEL_ePWM6_SOCB	0x10
#define TRIG_SEL_ePWM7_SOCA	0x11
#define TRIG_SEL_ePWM7_SOCB	0x12
#define TRIG_SEL_ePWM8_SOCA	0x13
#define TRIG_SEL_ePWM8_SOCB	0x14
#define TRIG_SEL_ePWM9_SOCA	0x15
#define TRIG_SEL_ePWM9_SOCB	0x16
#define TRIG_SEL_ePWM10_SOCA	0x17
#define TRIG_SEL_ePWM10_SOCB	0x18
#define TRIG_SEL_ePWM11_SOCA	0x19
#define TRIG_SEL_ePWM11_SOCB	0x1A
#define TRIG_SEL_ePWM12_SOCA	0x1B
#define TRIG_SEL_ePWM12_SOCB	0x1C
#define TRIG_SEL_CPU2_TIM0	0x1D
#define TRIG_SEL_CPU2_TIM1	0x1E
#define TRIG_SEL_CPU2_TIM2	0x1F

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F2837xD_ADC_DEFINES_H

//
// End of file
//
