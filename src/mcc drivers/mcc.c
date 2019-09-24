#include "../../inc/MCC Drivers/mcc.h"
#include "../../inc/MCC Drivers/adc.h"
#include "../../inc/MCC Drivers/i2c.h"

void MCU_Initialize(){
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    //ADC_Initialize();
    I2C_Initialize();
}

void OSCILLATOR_Initialize(){
    // NOSC HFINTOSC; NDIV 1; 
    OSCCON1 = 0x60;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x00;
    // HFFRQ 32_MHz; 
    OSCFRQ = 0x06;
    // HFTUN 0; 
    OSCTUNE = 0x00;
}

void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0x3F;
    TRISC = 0x37;

    /**
    ANSELx registers
    */
    ANSELC = 0x0F;
    ANSELA = 0x27;

    /**
    WPUx registers
    */
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONA = 0x00;
    ODCONC = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0x37;
    SLRCONC = 0x3F;

    /**
    INLVLx registers
    */
    INLVLA = 0x3F;
    INLVLC = 0x3F;
	
    SSP1CLKPPS = 0x15;   //RC5->MSSP1:SCL1;    
    RC3PPS = 0x0F;   //RC3->EUSART1:TX1;    
    RC4PPS = 0x14;   //RC4->MSSP1:SDA1;    
    RC5PPS = 0x13;   //RC5->MSSP1:SCL1;    
    SSP1DATPPS = 0x14;   //RC4->MSSP1:SDA1;    
}
