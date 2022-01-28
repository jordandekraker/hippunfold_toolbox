/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.cpp
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "laplace_iters.h"
#include "laplace_iters_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo bd_emlrtRSI = { 28, /* lineNo */
  "repmat",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pathName */
};

static emlrtRTEInfo r_emlrtRTEI = { 49,/* lineNo */
  19,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 64,/* lineNo */
  15,                                  /* colNo */
  "assertValidSizeArg",                /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/assertValidSizeArg.m"/* pName */
};

static emlrtDCInfo r_emlrtDCI = { 31,  /* lineNo */
  14,                                  /* colNo */
  "repmat",                            /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/repmat.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRTEInfo pc_emlrtRTEI = { 53,/* lineNo */
  9,                                   /* colNo */
  "repmat",                            /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/repmat.m"/* pName */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, const real_T varargin_1[3], emxArray_real_T *b)
{
  int32_T k;
  boolean_T guard1 = false;
  int32_T exitg2;
  boolean_T exitg1;
  real_T n;
  int32_T i;
  int32_T i1;
  int32_T i2;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bd_emlrtRSI;
  k = 0;
  guard1 = false;
  do {
    exitg2 = 0;
    if (k < 3) {
      if ((varargin_1[k] != varargin_1[k]) || muDoubleScalarIsInf(varargin_1[k]))
      {
        guard1 = true;
        exitg2 = 1;
      } else {
        k++;
        guard1 = false;
      }
    } else {
      k = 0;
      exitg2 = 2;
    }
  } while (exitg2 == 0);

  if (exitg2 != 1) {
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (varargin_1[k] > 2.147483647E+9) {
        guard1 = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (guard1) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
      "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector",
      "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  if (varargin_1[0] <= 0.0) {
    n = 0.0;
  } else {
    n = varargin_1[0];
  }

  if (varargin_1[1] <= 0.0) {
    n = 0.0;
  } else {
    n *= varargin_1[1];
  }

  if (varargin_1[2] <= 0.0) {
    n = 0.0;
  } else {
    n *= varargin_1[2];
  }

  if (!(n <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI, "Coder:MATLAB:pmaxsize",
      "Coder:MATLAB:pmaxsize", 0);
  }

  if (!(varargin_1[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1[0], &r_emlrtDCI, sp);
  }

  if (!(varargin_1[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1[1], &r_emlrtDCI, sp);
  }

  if (!(varargin_1[2] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1[2], &r_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(varargin_1[0]);
  k = b->size[0] * b->size[1] * b->size[2];
  b->size[0] = i;
  i1 = static_cast<int32_T>(varargin_1[1]);
  b->size[1] = i1;
  i2 = static_cast<int32_T>(varargin_1[2]);
  b->size[2] = i2;
  emxEnsureCapacity_real_T(sp, b, k, &pc_emlrtRTEI);
  k = i * i1 * i2;
  for (i = 0; i < k; i++) {
    b->data[i] = 0.0;
  }
}

/* End of code generation (repmat.cpp) */
