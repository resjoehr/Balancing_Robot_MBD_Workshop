
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE
# define ARDUINO 10605
# include <Arduino.h>
# include <Wire.h>
# include <Wire.cpp>
# include <twi.c>
# include <twi.h>
# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 8
#define y_width 8

int t[8]; //empty array where to put the numbers going to the master
int Val[8]; // variable used by the master to sent data to the slave
//int L_Byte;
//int H_Byte;

// function: what to do when asked for data
extern "C" void requestEvent() {
  for (int i=0; i<8; i++)
  {
    Wire.write(t[i]);
  }
}

// what to do when receiving data from master
extern "C" void receiveEvent(int howMany)
{
    for (int i=0; i<howMany; i++)
    {   
        Val[i]=Wire.read();
        //delay(1); // see if it works...
    }
}

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void RpArdComm_Outputs_wrapper(const uint8_T *a_data,
			uint8_T *rp_data,
			const real_T *xD,
			const uint8_T *pin, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* wait until after initialization is done */
if (xD[0]==1){
 
    /* don't do anything for the mex file generation */
    # ifndef MATLAB_MEX_FILE
    for (int i=0; i<=7; i++)
    {
    rp_data[i]=Val[i];
    t[i]=a_data[i];
    }
    # endif

}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void RpArdComm_Update_wrapper(const uint8_T *a_data,
			uint8_T *rp_data,
			real_T *xD,
			const uint8_T *pin, const int_T p_width0)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {
    /* don't do anything for MEX-file generation */
    #ifndef MATLAB_MEX_FILE
    /* pinMode(pin[0],INPUT); */
    Wire.begin(10);
    Wire.onRequest(requestEvent); // fucntion to run when asking for data
    Wire.onReceive(receiveEvent); // what to do when receiving data
    /*Wire.beginTransmission(107);
    Wire.write(16);
    Wire.write(132);
    Wire.endTransmission();
    Wire.beginTransmission(107);
    Wire.write(17);
    Wire.write(136);
    Wire.endTransmission();*/
    # endif
    /* initialization done */
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

