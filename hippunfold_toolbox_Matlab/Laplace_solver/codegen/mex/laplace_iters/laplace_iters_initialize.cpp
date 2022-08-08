/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * laplace_iters_initialize.cpp
 *
 * Code generation for function 'laplace_iters_initialize'
 *
 */

/* Include files */
#include "laplace_iters_initialize.h"
#include "_coder_laplace_iters_mex.h"
#include "laplace_iters.h"
#include "laplace_iters_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void laplace_iters_initialize()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "Image_Toolbox", 2);
  emlrtLicenseCheckR2012b(&st, "Statistics_Toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (laplace_iters_initialize.cpp) */
