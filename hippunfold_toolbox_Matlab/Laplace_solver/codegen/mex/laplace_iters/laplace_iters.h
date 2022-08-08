/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * laplace_iters.h
 *
 * Code generation for function 'laplace_iters'
 *
 */

#pragma once

/* Include files */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "laplace_iters_types.h"

/* Function Declarations */
CODEGEN_EXPORT_SYM void laplace_iters(const emlrtStack *sp, const
  emxArray_real_T *fg, const emxArray_real_T *source, const emxArray_real_T
  *sink, const emxArray_real_T *init, real_T maxiters, const real_T sz[3],
  real_T neighbourhoodradius, emxArray_real_T *LP, emxArray_real_T *iter_change);

/* End of code generation (laplace_iters.h) */
