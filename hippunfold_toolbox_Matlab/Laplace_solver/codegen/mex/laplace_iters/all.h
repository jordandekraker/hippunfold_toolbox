/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * all.h
 *
 * Code generation for function 'all'
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
boolean_T all(const boolean_T x[3]);
boolean_T b_all(const emlrtStack *sp, const emxArray_boolean_T *x);

/* End of code generation (all.h) */
