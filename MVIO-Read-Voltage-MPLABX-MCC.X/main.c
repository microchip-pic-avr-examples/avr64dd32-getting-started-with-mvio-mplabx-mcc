 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
� [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
/*
    Main application
*/

#define ADC_VREF                        1.024
#define VALUE_TO_VOLTAGE(x)             ((float)( (x) * ADC_VREF * 10.0) / 4096.0) 
#define DELAY                           500

int main(void)
{
    SYSTEM_Initialize();
    
    static uint16_t ADCValue = 0;
    
    while(1)
    {
        ADCValue = ADC0_GetConversion(ADC_MUXPOS_VDDIO2DIV10_gc);                   // Get conversion for VDDIO2DIV10 
        ADCValue = ADCValue >> 4;                                                   // Right-shifting with 4 bits (12bit ADC res with left adjustment)
        printf("The value of VDDIO2 is: %fV \r\n", VALUE_TO_VOLTAGE(ADCValue));     // Print the message
        DELAY_milliseconds(DELAY);                                                  // Wait for next conversion
    }    
}