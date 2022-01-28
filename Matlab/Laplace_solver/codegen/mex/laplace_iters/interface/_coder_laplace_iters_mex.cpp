/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_laplace_iters_mex.cpp
 *
 * Code generation for function '_coder_laplace_iters_mex'
 *
 */

/* Include files */
#include "_coder_laplace_iters_mex.h"
#include "_coder_laplace_iters_api.h"
#include "laplace_iters.h"
#include "laplace_iters_data.h"
#include "laplace_iters_initialize.h"
#include "laplace_iters_terminate.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void laplace_iters_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs, const mxArray *prhs[7]);

/* Function Definitions */
void laplace_iters_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[7])
{
  const mxArray *outputs[2];
  int32_T nOutputs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        13, "laplace_iters");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "laplace_iters");
  }

  /* Call the function. */
  laplace_iters_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    nOutputs = 1;
  } else {
    nOutputs = nlhs;
  }

  emlrtReturnArrays(nOutputs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(laplace_iters_atexit);

  /* Module initialization. */
  laplace_iters_initialize();

  /* Dispatch the entry-point. */
  laplace_iters_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  laplace_iters_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_laplace_iters_mex.cpp) */
