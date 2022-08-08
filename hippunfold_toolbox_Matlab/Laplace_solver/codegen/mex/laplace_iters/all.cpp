/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * all.cpp
 *
 * Code generation for function 'all'
 *
 */

/* Include files */
#include "all.h"
#include "eml_int_forloop_overflow_check.h"
#include "laplace_iters.h"
#include "laplace_iters_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = { 13, /* lineNo */
  "all",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/ops/all.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 143,/* lineNo */
  "allOrAny",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pathName */
};

/* Function Definitions */
boolean_T all(const boolean_T x[3])
{
  boolean_T y;
  int32_T k;
  boolean_T exitg1;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!x[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return y;
}

boolean_T b_all(const emlrtStack *sp, const emxArray_boolean_T *x)
{
  boolean_T y;
  boolean_T overflow;
  int32_T ix;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = true;
  b_st.site = &mb_emlrtRSI;
  overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x->size[0])) {
    if (!x->data[ix - 1]) {
      y = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

/* End of code generation (all.cpp) */
