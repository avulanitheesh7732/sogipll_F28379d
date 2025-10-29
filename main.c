#include "Peripheral_Setup.h"
#include "math.h"
#include "sogi.h"
uint32_t count = 0, index= 0;

SPLL_SOGI v_pll;
float vrede = 0;
float vsync = 0;
float phase = 0;
float ampl = 0.5;


__interrupt void isr_cpu_timer0(void);
__interrupt void isr_adc(void);

int main(void){
    InitSysCtrl();                          // Initialize System Control:

    EALLOW;
    CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;
    EDIS;

    DINT;                                   // Disable CPU interrupts
    InitPieCtrl();                          // Initialize the PIE control registers to their default state
    IER = 0x0000;                           // Disable CPU interrupts
    IFR = 0x0000;                           // Clear all CPU interrupt flags:
    InitPieVectTable();                     // Initialize the PIE vector table

    Setup_GPIO();
    Setup_ePWM();
    Setup_ADC();
    Setup_DAC();

    EALLOW;
    PieVectTable.TIMER0_INT = &isr_cpu_timer0;
    PieVectTable.ADCA1_INT = &isr_adc;
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;      //Timer 0
    PieCtrlRegs.PIEIER1.bit.INTx1 = 1;      //ADC
    EDIS;
    IER |= M_INT1;

    InitCpuTimers();
    ConfigCpuTimer(&CpuTimer0, 200, 1000000);
    CpuTimer0Regs.TCR.all = 0x4001;

    SOGI_init(50, 8.3333333E-06, &v_pll);
    SOGI_coeff_update(8.3333333E-06,314.15926, 0.7,&v_pll);

    EINT;                                   // Enable Global interrupt INTM
    ERTM;                                   // Enable Global realtime interrupt DBGM
    GpioDataRegs.GPBDAT.bit.GPIO34 = 1;
    GpioDataRegs.GPADAT.bit.GPIO31 = 0;
    while(1){
        for(count = 0; count < 0x00FFFFFF; count++){

        }
        GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
        //GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
    }
   // return 0;
}

__interrupt void isr_cpu_timer0(void){
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

__interrupt void isr_adc(void){
    GpioDataRegs.GPADAT.bit.GPIO14 = 1;

    vrede =  0.000805*((int)AdcaResultRegs.ADCRESULT0 - 0x4D9);  //3.3/4095=0.0008 and for 1v = 1241(0x4d9)*0.0008=1v
    //AdcaResultRegs.ADCRESULT1;

    v_pll.u[0] = vrede;
    SPLL_SOGI_CALC(&v_pll);

    vsync = v_pll.sin_;

    //EPwm7Regs.CMPA.bit.CMPA = (uint16_t) (1627.0 * (1.0 + ampl * __sin( v_pll.theta[1] + phase)));
   EPwm7Regs.CMPA.bit.CMPA = (uint16_t) (1627.0 * (1.0 + ampl * sin( v_pll.theta[0] + phase)));  //1627=tbprd/2

    EALLOW;
 // DacaRegs.DACVALS.bit.DACVALS = (uint16_t) (2047.0 * (1.0 + ampl * __sin( v_pll.theta[1] + phase)));
    //DacaRegs.DACVALS.bit.DACVALS = (uint16_t) (2047 * (1.0 + ampl * sin( v_pll.theta[0] + phase)));   //4095/2=2047
    DacaRegs.DACVALS.bit.DACVALS = (uint16_t)((ampl*v_pll.theta[0]/ (2.0*M_PI)) * 4095.0);

    EDIS;


    AdcaRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;      //clear INT1 flag
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    GpioDataRegs.GPADAT.bit.GPIO14 = 0;
}
