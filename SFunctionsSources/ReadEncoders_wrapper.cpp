
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
# include <Balboa32U4.h>
# include <Balboa32U4Encoders.cpp>
# include <FastGPIO.h> 
# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
#define y_1_width 1
Balboa32U4Encoders encoders;

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
extern "C" void ReadEncoders_Outputs_wrapper(real32_T *left,
			real32_T *right,
			const real_T *xD);

void ReadEncoders_Outputs_wrapper(real32_T *left,
			real32_T *right,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1){
 
    /* don't do anything for the mex file generation */
    # ifndef MATLAB_MEX_FILE
    left[0] = encoders.getCountsLeft();
    right[0] = encoders.getCountsRight();
    # endif

}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void ReadEncoders_Update_wrapper(real32_T *left,
			real32_T *right,
			real_T *xD);

void ReadEncoders_Update_wrapper(real32_T *left,
			real32_T *right,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]!=1) {
    /* don't do anything for MEX-file generation */
    #ifndef MATLAB_MEX_FILE
    
    # endif
    /* initialization done */
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

