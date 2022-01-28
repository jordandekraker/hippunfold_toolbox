/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.cpp
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include "svd.h"
#include "eml_int_forloop_overflow_check.h"
#include "laplace_iters.h"
#include "laplace_iters_data.h"
#include "laplace_iters_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "svd1.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = { 12, /* lineNo */
  "svd",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 25, /* lineNo */
  "svd",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 33, /* lineNo */
  "svd",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 29, /* lineNo */
  "anyNonFinite",                      /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/anyNonFinite.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 44, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 103,/* lineNo */
  "flatVectorAllOrAny",                /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 39,/* lineNo */
  5,                                   /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 32,/* lineNo */
  14,                                  /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 34,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 36,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 25,/* lineNo */
  12,                                  /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/matfun/svd.m"/* pName */
};

/* Function Definitions */
void svd(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *U,
         emxArray_real_T *S, emxArray_real_T *V)
{
  int32_T nx;
  boolean_T p;
  boolean_T overflow;
  int32_T k;
  emxArray_real_T *s;
  emxArray_real_T *r;
  uint32_T unnamed_idx_0;
  uint32_T unnamed_idx_1;
  int32_T i;
  uint32_T unnamed_idx_2;
  emxArray_real_T *U1;
  emxArray_real_T *V1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &nb_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  c_st.site = &rb_emlrtRSI;
  nx = A->size[0] * A->size[1] * A->size[2];
  p = true;
  d_st.site = &sb_emlrtRSI;
  overflow = ((1 <= nx) && (nx > 2147483646));
  if (overflow) {
    e_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < nx; k++) {
    if ((!p) || (muDoubleScalarIsInf(A->data[k]) || muDoubleScalarIsNaN(A->
          data[k]))) {
      p = false;
    }
  }

  emxInit_real_T(sp, &s, 1, &vb_emlrtRTEI, true);
  if (p) {
    st.site = &ob_emlrtRSI;
    b_svd(&st, A, U, s, V);
  } else {
    emxInit_real_T(sp, &r, 3, &sb_emlrtRTEI, true);
    unnamed_idx_0 = static_cast<uint32_T>(A->size[0]);
    unnamed_idx_1 = static_cast<uint32_T>(A->size[1]);
    unnamed_idx_2 = static_cast<uint32_T>(A->size[2]);
    i = r->size[0] * r->size[1] * r->size[2];
    r->size[0] = static_cast<int32_T>(unnamed_idx_0);
    r->size[1] = static_cast<int32_T>(unnamed_idx_1);
    r->size[2] = static_cast<int32_T>(unnamed_idx_2);
    emxEnsureCapacity_real_T(sp, r, i, &sb_emlrtRTEI);
    nx = static_cast<int32_T>(unnamed_idx_0) * static_cast<int32_T>
      (unnamed_idx_1) * static_cast<int32_T>(unnamed_idx_2);
    for (i = 0; i < nx; i++) {
      r->data[i] = 0.0;
    }

    emxInit_real_T(sp, &U1, 2, &wb_emlrtRTEI, true);
    emxInit_real_T(sp, &V1, 2, &wb_emlrtRTEI, true);
    st.site = &pb_emlrtRSI;
    b_svd(&st, r, U1, s, V1);
    i = U->size[0] * U->size[1];
    U->size[0] = U1->size[0];
    U->size[1] = U1->size[1];
    emxEnsureCapacity_real_T(sp, U, i, &tb_emlrtRTEI);
    nx = U1->size[0] * U1->size[1];
    emxFree_real_T(&r);
    emxFree_real_T(&U1);
    for (i = 0; i < nx; i++) {
      U->data[i] = rtNaN;
    }

    nx = s->size[0];
    for (i = 0; i < nx; i++) {
      s->data[i] = rtNaN;
    }

    i = V->size[0] * V->size[1];
    V->size[0] = V1->size[0];
    V->size[1] = V1->size[1];
    emxEnsureCapacity_real_T(sp, V, i, &ub_emlrtRTEI);
    nx = V1->size[0] * V1->size[1];
    emxFree_real_T(&V1);
    for (i = 0; i < nx; i++) {
      V->data[i] = rtNaN;
    }
  }

  i = S->size[0] * S->size[1];
  S->size[0] = U->size[1];
  S->size[1] = V->size[1];
  emxEnsureCapacity_real_T(sp, S, i, &rb_emlrtRTEI);
  nx = U->size[1] * V->size[1];
  for (i = 0; i < nx; i++) {
    S->data[i] = 0.0;
  }

  i = s->size[0] - 1;
  for (k = 0; k <= i; k++) {
    S->data[k + S->size[0] * k] = s->data[k];
  }

  emxFree_real_T(&s);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (svd.cpp) */
