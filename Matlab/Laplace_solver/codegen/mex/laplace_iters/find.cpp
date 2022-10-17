/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.cpp
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "laplace_iters.h"
#include "laplace_iters_data.h"
#include "laplace_iters_emxutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = { 153, /* lineNo */
  "eml_find",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 377, /* lineNo */
  "find_first_indices",                /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 397, /* lineNo */
  "find_first_indices",                /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = { 130,/* lineNo */
  23,                                  /* colNo */
  "eml_find",                          /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 387,/* lineNo */
  1,                                   /* colNo */
  "find_first_indices",                /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 153,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 153,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

/* Function Definitions */
void eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
              emxArray_int32_T *i)
{
  int32_T nx;
  int32_T idx;
  int32_T ii;
  boolean_T overflow;
  boolean_T exitg1;
  int32_T iv[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[0] * x->size[1] * x->size[2];
  if (((x->size[0] == 1) || (x->size[1] == 1)) && (x->size[2] == 1) && (x->size
       [0] == 1) && (x->size[1] > 1)) {
    emlrtErrorWithMessageIdR2018a(sp, &g_emlrtRTEI,
      "Coder:toolbox:find_incompatibleShape",
      "Coder:toolbox:find_incompatibleShape", 0);
  }

  st.site = &r_emlrtRSI;
  idx = 0;
  ii = i->size[0];
  i->size[0] = nx;
  emxEnsureCapacity_int32_T(&st, i, ii, &pb_emlrtRTEI);
  b_st.site = &s_emlrtRSI;
  overflow = ((1 <= nx) && (nx > 2147483646));
  if (overflow) {
    c_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x->data[ii]) {
      idx++;
      i->data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (idx > nx) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (nx == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    if (1 > idx) {
      idx = 0;
    }

    iv[0] = 1;
    iv[1] = idx;
    b_st.site = &t_emlrtRSI;
    indexShapeCheck(&b_st, i->size[0], iv);
    ii = i->size[0];
    i->size[0] = idx;
    emxEnsureCapacity_int32_T(&st, i, ii, &qb_emlrtRTEI);
  }
}

/* End of code generation (find.cpp) */
