#include <mega32.h>
#include <stdlib.h>
#include <stdio.h>
#include <delay.h>
#include <alcd.h> // Alphanumeric LCD functions

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                              //
//                                                                                                                                              //
//                                                                                                                                              //
//                                                                                                                                              //
//                                                                     Matin                                                                    //
//                                                                     Monshizadeh                                                              //
//                                                                     9932122                                                                  //
//                                                                                                                                              //
//                                                                                                                                              //
//                                                                                                                                              //
//                                                                                                                                              //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ADCChannel 0 // Read voltage from PORTA0(ADC0)

void ADCInit()
{
    // Enable ADC, Prescaler : 2 ,Free running mode
    ADCSRA = 0xe0;

    // Select ADC channel
    ADMUX = 0x40 | ADCChannel;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int readADC()
{
    // Read 8 lower bit.
    int ADC_value = ADCL;

    // Read 2 upper bit and add it to ADC_value.
    ADC_value += (ADCH & 0x03) << 8;
    return ADC_value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float readVoltage()
{
    int ADC_value = readADC();

    // ADC_value is between 0 and 1023.voltage_value is between 0 and 5;
    float voltage_value = ADC_value / 201.37;
    return voltage_value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main(void)
{
    // Alphanumeric LCD initialization
    // Connections are specified in the
    // Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
    // RS - PORTD Bit 0
    // RD - PORTD Bit 1
    // EN - PORTD Bit 2
    // D4 - PORTD Bit 4
    // D5 - PORTD Bit 5
    // D6 - PORTD Bit 6
    // D7 - PORTD Bit 7
    float voltage_value;
    char voltage_string[10];
    char lcd_string[16];
    lcd_init(16);
    lcd_gotoxy(0, 0);
    lcd_puts("Matin");
    delay_ms(2000);
    lcd_clear();
    ADCInit();

    // Move cursor to second line and first column
    lcd_gotoxy(0, 1);
    .
        // Write "  DC Voltmeter" on lcd.
        lcd_puts("Elec project");
    while (1)
    {
        // Move cursor to first line and first column.
        lcd_gotoxy(0, 0);

        // Use 33Kohm and 270Kohm to divide voltage.( 9.1818 = (270+33)/33 ).
        voltage_value = readVoltage() * 8.43; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        // convert float to char array.
        ftoa(voltage_value, 2, voltage_string);
        sprintf(lcd_string, "Voltage : %s", voltage_string);
        lcd_puts(lcd_string);
        delay_ms(500); ////Refresh lcd every 100 ms.
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////