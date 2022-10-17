/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd1.h
 *
 * Code generation for function 'svd1'
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
void b_svd(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *U,
           emxArray_real_T *s, emxArray_real_T *V);

/* End of code generation (svd1.h) */
