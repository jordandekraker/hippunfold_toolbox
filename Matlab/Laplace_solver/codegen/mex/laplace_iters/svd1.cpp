/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd1.cpp
 *
 * Code generation for function 'svd1'
 *
 */

/* Include files */
#include "svd1.h"
#include "lapacke.h"
#include "laplace_iters.h"
#include "laplace_iters_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo tb_emlrtRSI = { 53, /* lineNo */
  "svd",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 83, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 75, /* lineNo */
  "callLAPACK",                        /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/svd.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 209,/* lineNo */
  "xgesdd",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 179,/* lineNo */
  "xgesdd",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 68, /* lineNo */
  "xgesdd",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 61, /* lineNo */
  "xgesdd",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 58, /* lineNo */
  "xgesdd",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesdd.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 31, /* lineNo */
  "xgesvd",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 196,/* lineNo */
  "ceval_xgesvd",                      /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = { 105,/* lineNo */
  5,                                   /* colNo */
  "callLAPACK",                        /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 45,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 48,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 75,/* lineNo */
  63,                                  /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 217,/* lineNo */
  5,                                   /* colNo */
  "xgesvd",                            /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 31,/* lineNo */
  33,                                  /* colNo */
  "xgesvd",                            /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 31,/* lineNo */
  5,                                   /* colNo */
  "xgesvd",                            /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 75,/* lineNo */
  14,                                  /* colNo */
  "svd",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/svd.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 120,/* lineNo */
  9,                                   /* colNo */
  "xgesvd",                            /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pName */
};

/* Function Definitions */
void b_svd(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *U,
           emxArray_real_T *s, emxArray_real_T *V)
{
  emxArray_real_T *b_A;
  int32_T m;
  int32_T n;
  int32_T i;
  int32_T loop_ub;
  emxArray_real_T *Vt;
  int32_T i1;
  ptrdiff_t info_t;
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 's', 'd', 'd' };

  emxArray_real_T *superb;
  static const char_T b_fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_',
    'd', 'g', 'e', 's', 'v', 'd' };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_A, 3, &xb_emlrtRTEI, true);
  st.site = &tb_emlrtRSI;
  m = A->size[0];
  n = A->size[1];
  b_st.site = &vb_emlrtRSI;
  i = b_A->size[0] * b_A->size[1] * b_A->size[2];
  b_A->size[0] = A->size[0];
  b_A->size[1] = A->size[1];
  b_A->size[2] = A->size[2];
  emxEnsureCapacity_real_T(&b_st, b_A, i, &xb_emlrtRTEI);
  loop_ub = A->size[0] * A->size[1] * A->size[2];
  for (i = 0; i < loop_ub; i++) {
    b_A->data[i] = A->data[i];
  }

  emxInit_real_T(&b_st, &Vt, 2, &dc_emlrtRTEI, true);
  i = U->size[0] * U->size[1];
  U->size[0] = A->size[0];
  U->size[1] = A->size[0];
  emxEnsureCapacity_real_T(&b_st, U, i, &yb_emlrtRTEI);
  i = Vt->size[0] * Vt->size[1];
  Vt->size[0] = A->size[1];
  Vt->size[1] = A->size[1];
  emxEnsureCapacity_real_T(&b_st, Vt, i, &yb_emlrtRTEI);
  i = s->size[0];
  s->size[0] = muIntScalarMin_sint32(n, m);
  emxEnsureCapacity_real_T(&b_st, s, i, &yb_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  if ((A->size[0] != 0) && (A->size[1] != 0) && (A->size[2] != 0)) {
    c_st.site = &ac_emlrtRSI;
    c_st.site = &yb_emlrtRSI;
    c_st.site = &xb_emlrtRSI;
    info_t = LAPACKE_dgesdd(102, 'A', (ptrdiff_t)A->size[0], (ptrdiff_t)A->size
      [1], &b_A->data[0], (ptrdiff_t)A->size[0], &s->data[0], &U->data[0],
      (ptrdiff_t)A->size[0], &Vt->data[0], (ptrdiff_t)A->size[1]);
    m = (int32_T)info_t;
    c_st.site = &wb_emlrtRSI;
    if (m < 0) {
      if (m == -1010) {
        emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, m);
      }
    }
  } else {
    m = 0;
  }

  if (m > 0) {
    b_st.site = &ub_emlrtRSI;
    c_st.site = &fc_emlrtRSI;
    i = b_A->size[0] * b_A->size[1] * b_A->size[2];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    b_A->size[2] = A->size[2];
    emxEnsureCapacity_real_T(&c_st, b_A, i, &bc_emlrtRTEI);
    loop_ub = A->size[0] * A->size[1] * A->size[2];
    for (i = 0; i < loop_ub; i++) {
      b_A->data[i] = A->data[i];
    }

    m = A->size[0];
    n = A->size[1];
    m = muIntScalarMin_sint32(n, m);
    i = U->size[0] * U->size[1];
    U->size[0] = A->size[0];
    U->size[1] = A->size[0];
    emxEnsureCapacity_real_T(&c_st, U, i, &cc_emlrtRTEI);
    i = Vt->size[0] * Vt->size[1];
    Vt->size[0] = A->size[1];
    Vt->size[1] = A->size[1];
    emxEnsureCapacity_real_T(&c_st, Vt, i, &cc_emlrtRTEI);
    i = s->size[0];
    s->size[0] = m;
    emxEnsureCapacity_real_T(&c_st, s, i, &cc_emlrtRTEI);
    if ((A->size[0] != 0) && (A->size[1] != 0) && (A->size[2] != 0)) {
      emxInit_real_T(&c_st, &superb, 1, &ec_emlrtRTEI, true);
      if (m > 1) {
        i = superb->size[0];
        superb->size[0] = m - 1;
        emxEnsureCapacity_real_T(&c_st, superb, i, &cc_emlrtRTEI);
      } else {
        i = superb->size[0];
        superb->size[0] = 1;
        emxEnsureCapacity_real_T(&c_st, superb, i, &cc_emlrtRTEI);
      }

      info_t = LAPACKE_dgesvd(102, 'A', 'A', (ptrdiff_t)A->size[0], (ptrdiff_t)
        A->size[1], &b_A->data[0], (ptrdiff_t)A->size[0], &s->data[0], &U->data
        [0], (ptrdiff_t)A->size[0], &Vt->data[0], (ptrdiff_t)A->size[1],
        &superb->data[0]);
      m = (int32_T)info_t;
      emxFree_real_T(&superb);
    } else {
      m = 0;
    }

    i = V->size[0] * V->size[1];
    V->size[0] = Vt->size[1];
    V->size[1] = Vt->size[0];
    emxEnsureCapacity_real_T(&c_st, V, i, &ac_emlrtRTEI);
    loop_ub = Vt->size[0];
    for (i = 0; i < loop_ub; i++) {
      n = Vt->size[1];
      for (i1 = 0; i1 < n; i1++) {
        V->data[i1 + V->size[0] * i] = Vt->data[i + Vt->size[0] * i1];
      }
    }

    d_st.site = &gc_emlrtRSI;
    if (m < 0) {
      if (m == -1010) {
        emlrtErrorWithMessageIdR2018a(&d_st, &l_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&d_st, &m_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, b_fname, 12, m);
      }
    }
  } else {
    i = V->size[0] * V->size[1];
    V->size[0] = Vt->size[1];
    V->size[1] = Vt->size[0];
    emxEnsureCapacity_real_T(&st, V, i, &ac_emlrtRTEI);
    loop_ub = Vt->size[0];
    for (i = 0; i < loop_ub; i++) {
      n = Vt->size[1];
      for (i1 = 0; i1 < n; i1++) {
        V->data[i1 + V->size[0] * i] = Vt->data[i + Vt->size[0] * i1];
      }
    }
  }

  emxFree_real_T(&b_A);
  emxFree_real_T(&Vt);
  if (m > 0) {
    emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
      "Coder:MATLAB:svd_NoConvergence", "Coder:MATLAB:svd_NoConvergence", 0);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (svd1.cpp) */
