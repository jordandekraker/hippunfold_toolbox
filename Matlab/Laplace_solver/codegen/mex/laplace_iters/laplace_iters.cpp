/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * laplace_iters.cpp
 *
 * Code generation for function 'laplace_iters'
 *
 */

/* Include files */
#include "laplace_iters.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "imfilter.h"
#include "indexShapeCheck.h"
#include "laplace_iters_data.h"
#include "laplace_iters_emxutil.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "sum.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 3,     /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 9,   /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 17,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 22,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 29,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 33,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 39,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 45,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 46,  /* lineNo */
  "laplace_iters",                     /* fcnName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 45,  /* lineNo */
  "mpower",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 55,  /* lineNo */
  "power",                             /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 41,  /* lineNo */
  "find",                              /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pathName */
};

static emlrtRSInfo md_emlrtRSI = { 18, /* lineNo */
  "abs",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo nd_emlrtRSI = { 75, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo od_emlrtRSI = { 7,  /* lineNo */
  "nansum",                            /* fcnName */
  "/export01/local/matlab19b/toolbox/stats/eml/nansum.m"/* pathName */
};

static emlrtRSInfo pd_emlrtRSI = { 74, /* lineNo */
  "nan_sum_or_mean",                   /* fcnName */
  "/export01/local/matlab19b/toolbox/stats/eml/private/nan_sum_or_mean.m"/* pathName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  14,                                  /* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 20,  /* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "nan_sum_or_mean",                   /* fName */
  "/export01/local/matlab19b/toolbox/stats/eml/private/nan_sum_or_mean.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 19,    /* lineNo */
  23,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 19,  /* lineNo */
  23,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 7,   /* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 7,   /* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  8,                                   /* lineNo */
  1,                                   /* colNo */
  "hl",                                /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 8,   /* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 14,  /* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 15,  /* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  15,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 16,  /* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  16,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  5,                                   /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 19,  /* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  21,                                  /* colNo */
  "insulate_correction",               /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  11,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  11,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  11,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  41,                                  /* colNo */
  "vel",                               /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  51,                                  /* colNo */
  "velup",                             /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  5,                                   /* colNo */
  "iter_change",                       /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  76,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "nan_sum_or_mean",                   /* fName */
  "/export01/local/matlab19b/toolbox/stats/eml/private/nan_sum_or_mean.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  41,                                  /* lineNo */
  8,                                   /* colNo */
  "iter_change",                       /* aName */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 13,  /* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 13,  /* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 20,  /* lineNo */
  29,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo u_emlrtRTEI = { 7, /* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 14,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 17,/* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 19,/* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 20,/* lineNo */
  1,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 21,/* lineNo */
  21,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 29,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 34,/* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 35,/* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 36,/* lineNo */
  11,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 39,/* lineNo */
  37,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elfun/abs.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 40,/* lineNo */
  5,                                   /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 33,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/find.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 39,/* lineNo */
  33,                                  /* colNo */
  "laplace_iters",                     /* fName */
  "/host/percy/local_raid/jordand/opt/matlab/hippunfold_toolbox/Laplace_solver/laplace_iters.m"/* pName */
};

/* Function Definitions */
void laplace_iters(const emlrtStack *sp, const emxArray_real_T *fg, const
                   emxArray_real_T *source, const emxArray_real_T *sink, const
                   emxArray_real_T *init, real_T maxiters, const real_T sz[3],
                   real_T neighbourhoodradius, emxArray_real_T *LP,
                   emxArray_real_T *iter_change)
{
  real_T y;
  real_T d;
  emxArray_real_T *hl;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T nx;
  emxArray_real_T b_hl;
  int32_T iv[1];
  real_T d1;
  int32_T idx;
  int32_T loop_ub_tmp;
  emxArray_int32_T *ii;
  int32_T k;
  int32_T b_LP;
  emxArray_boolean_T *r;
  emxArray_int32_T *bg;
  real_T d2;
  emxArray_real_T *insulate_correction;
  uint32_T iters;
  emxArray_real_T *velup;
  emxArray_real_T *b_y;
  emxArray_real_T *x;
  boolean_T exitg1;
  int32_T varargin_1[3];
  int32_T varargin_2[3];
  boolean_T p;
  boolean_T overflow;
  boolean_T exitg2;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &emlrtRSI;
  b_st.site = &j_emlrtRSI;
  c_st.site = &k_emlrtRSI;

  /*  filter set-up  */
  y = neighbourhoodradius * 2.0 + 1.0;
  if (!(y >= 0.0)) {
    emlrtNonNegativeCheckR2012b(y, &c_emlrtDCI, sp);
  }

  d = static_cast<int32_T>(muDoubleScalarFloor(y));
  if (y != d) {
    emlrtIntegerCheckR2012b(y, &d_emlrtDCI, sp);
  }

  emxInit_real_T(sp, &hl, 3, &u_emlrtRTEI, true);
  i = static_cast<int32_T>(y);
  i1 = hl->size[0] * hl->size[1] * hl->size[2];
  hl->size[0] = i;
  hl->size[1] = i;
  hl->size[2] = i;
  emxEnsureCapacity_real_T(sp, hl, i1, &u_emlrtRTEI);
  loop_ub = i * i * i;
  for (i1 = 0; i1 < loop_ub; i1++) {
    hl->data[i1] = 1.0;
  }

  y = static_cast<int32_T>(muDoubleScalarFloor(neighbourhoodradius + 1.0));
  if (neighbourhoodradius + 1.0 != y) {
    emlrtIntegerCheckR2012b(neighbourhoodradius + 1.0, &e_emlrtDCI, sp);
  }

  i1 = static_cast<int32_T>((neighbourhoodradius + 1.0));
  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &b_emlrtBCI, sp);
  }

  if (neighbourhoodradius + 1.0 != y) {
    emlrtIntegerCheckR2012b(neighbourhoodradius + 1.0, &e_emlrtDCI, sp);
  }

  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &b_emlrtBCI, sp);
  }

  if (neighbourhoodradius + 1.0 != y) {
    emlrtIntegerCheckR2012b(neighbourhoodradius + 1.0, &e_emlrtDCI, sp);
  }

  if ((i1 < 1) || (i1 > i)) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, i, &b_emlrtBCI, sp);
  }

  hl->data[((i1 + hl->size[0] * (i1 - 1)) + hl->size[0] * hl->size[1] * (i1 - 1))
    - 1] = 0.0;
  nx = hl->size[0] * hl->size[1] * hl->size[2];
  b_hl = *hl;
  iv[0] = nx;
  b_hl.size = &iv[0];
  b_hl.numDimensions = 1;
  st.site = &b_emlrtRSI;
  y = sum(&st, &b_hl);
  loop_ub = hl->size[0] * hl->size[1] * hl->size[2];
  for (i = 0; i < loop_ub; i++) {
    hl->data[i] /= y;
  }

  /* set up all requisite variables */
  if (!(sz[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(sz[0], &k_emlrtDCI, sp);
  }

  y = static_cast<int32_T>(muDoubleScalarFloor(sz[0]));
  if (sz[0] != y) {
    emlrtIntegerCheckR2012b(sz[0], &j_emlrtDCI, sp);
  }

  if (!(sz[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(sz[1], &k_emlrtDCI, sp);
  }

  d = static_cast<int32_T>(muDoubleScalarFloor(sz[1]));
  if (sz[1] != d) {
    emlrtIntegerCheckR2012b(sz[1], &j_emlrtDCI, sp);
  }

  if (!(sz[2] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(sz[2], &k_emlrtDCI, sp);
  }

  d1 = static_cast<int32_T>(muDoubleScalarFloor(sz[2]));
  if (sz[2] != d1) {
    emlrtIntegerCheckR2012b(sz[2], &j_emlrtDCI, sp);
  }

  i = static_cast<int32_T>(sz[0]);
  i1 = LP->size[0] * LP->size[1] * LP->size[2];
  LP->size[0] = i;
  nx = static_cast<int32_T>(sz[1]);
  LP->size[1] = nx;
  idx = static_cast<int32_T>(sz[2]);
  LP->size[2] = idx;
  emxEnsureCapacity_real_T(sp, LP, i1, &v_emlrtRTEI);
  loop_ub_tmp = i * nx * idx;
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    LP->data[i1] = rtNaN;
  }

  emxInit_int32_T(sp, &ii, 1, &nb_emlrtRTEI, true);
  i1 = ii->size[0];
  ii->size[0] = fg->size[0];
  emxEnsureCapacity_int32_T(sp, ii, i1, &w_emlrtRTEI);
  loop_ub = fg->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    if (fg->data[i1] != static_cast<int32_T>(muDoubleScalarFloor(fg->data[i1])))
    {
      emlrtIntegerCheckR2012b(fg->data[i1], &f_emlrtDCI, sp);
    }

    k = static_cast<int32_T>(fg->data[i1]);
    if ((k < 1) || (k > loop_ub_tmp)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, loop_ub_tmp, &c_emlrtBCI, sp);
    }

    ii->data[i1] = k;
  }

  i1 = init->size[0] * init->size[1];
  if (ii->size[0] != i1) {
    emlrtSubAssignSizeCheck1dR2017a(ii->size[0], i1, &emlrtECI, sp);
  }

  loop_ub = ii->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    LP->data[ii->data[i1] - 1] = init->data[i1];
  }

  b_LP = LP->size[0] * LP->size[1] * LP->size[2];
  i1 = ii->size[0];
  ii->size[0] = source->size[0];
  emxEnsureCapacity_int32_T(sp, ii, i1, &x_emlrtRTEI);
  loop_ub = source->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    if (source->data[i1] != static_cast<int32_T>(muDoubleScalarFloor
         (source->data[i1]))) {
      emlrtIntegerCheckR2012b(source->data[i1], &g_emlrtDCI, sp);
    }

    k = static_cast<int32_T>(source->data[i1]);
    if ((k < 1) || (k > b_LP)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, b_LP, &d_emlrtBCI, sp);
    }

    ii->data[i1] = k;
  }

  loop_ub = ii->size[0] - 1;
  for (i1 = 0; i1 <= loop_ub; i1++) {
    LP->data[ii->data[i1] - 1] = 0.0;
  }

  b_LP = LP->size[0] * LP->size[1] * LP->size[2];
  i1 = ii->size[0];
  ii->size[0] = sink->size[0];
  emxEnsureCapacity_int32_T(sp, ii, i1, &y_emlrtRTEI);
  loop_ub = sink->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    if (sink->data[i1] != static_cast<int32_T>(muDoubleScalarFloor(sink->data[i1])))
    {
      emlrtIntegerCheckR2012b(sink->data[i1], &h_emlrtDCI, sp);
    }

    k = static_cast<int32_T>(sink->data[i1]);
    if ((k < 1) || (k > b_LP)) {
      emlrtDynamicBoundsCheckR2012b(k, 1, b_LP, &e_emlrtBCI, sp);
    }

    ii->data[i1] = k;
  }

  loop_ub = ii->size[0] - 1;
  for (i1 = 0; i1 <= loop_ub; i1++) {
    LP->data[ii->data[i1] - 1] = 1.0;
  }

  emxInit_boolean_T(sp, &r, 3, &ab_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  i1 = r->size[0] * r->size[1] * r->size[2];
  r->size[0] = LP->size[0];
  r->size[1] = LP->size[1];
  r->size[2] = LP->size[2];
  emxEnsureCapacity_boolean_T(&st, r, i1, &ab_emlrtRTEI);
  loop_ub = LP->size[0] * LP->size[1] * LP->size[2];
  for (i1 = 0; i1 < loop_ub; i1++) {
    r->data[i1] = muDoubleScalarIsNaN(LP->data[i1]);
  }

  emxInit_int32_T(&st, &bg, 1, &bb_emlrtRTEI, true);
  b_st.site = &q_emlrtRSI;
  eml_find(&b_st, r, ii);
  i1 = bg->size[0];
  bg->size[0] = ii->size[0];
  emxEnsureCapacity_int32_T(&st, bg, i1, &bb_emlrtRTEI);
  loop_ub = ii->size[0];
  emxFree_boolean_T(&r);
  for (i1 = 0; i1 < loop_ub; i1++) {
    bg->data[i1] = ii->data[i1];
  }

  b_LP = LP->size[0] * LP->size[1] * LP->size[2];
  i1 = ii->size[0];
  ii->size[0] = bg->size[0];
  emxEnsureCapacity_int32_T(sp, ii, i1, &cb_emlrtRTEI);
  loop_ub = bg->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    if ((bg->data[i1] < 1) || (bg->data[i1] > b_LP)) {
      emlrtDynamicBoundsCheckR2012b(bg->data[i1], 1, b_LP, &f_emlrtBCI, sp);
    }

    ii->data[i1] = bg->data[i1];
  }

  loop_ub = ii->size[0] - 1;
  for (i1 = 0; i1 <= loop_ub; i1++) {
    LP->data[ii->data[i1] - 1] = 0.0;
  }

  /* must be insulated after filtering */
  i1 = iter_change->size[0] * iter_change->size[1];
  iter_change->size[0] = 1;
  emxEnsureCapacity_real_T(sp, iter_change, i1, &db_emlrtRTEI);
  if (!(maxiters >= 0.0)) {
    emlrtNonNegativeCheckR2012b(maxiters, &b_emlrtDCI, sp);
  }

  d2 = static_cast<int32_T>(muDoubleScalarFloor(maxiters));
  if (maxiters != d2) {
    emlrtIntegerCheckR2012b(maxiters, &emlrtDCI, sp);
  }

  i1 = iter_change->size[0] * iter_change->size[1];
  loop_ub = static_cast<int32_T>(maxiters);
  iter_change->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, iter_change, i1, &db_emlrtRTEI);
  if (maxiters != d2) {
    emlrtIntegerCheckR2012b(maxiters, &i_emlrtDCI, sp);
  }

  for (i1 = 0; i1 < loop_ub; i1++) {
    iter_change->data[i1] = 0.0;
  }

  if (sz[0] != y) {
    emlrtIntegerCheckR2012b(sz[0], &l_emlrtDCI, sp);
  }

  if (sz[1] != d) {
    emlrtIntegerCheckR2012b(sz[1], &l_emlrtDCI, sp);
  }

  if (sz[2] != d1) {
    emlrtIntegerCheckR2012b(sz[2], &l_emlrtDCI, sp);
  }

  emxInit_real_T(sp, &insulate_correction, 3, &eb_emlrtRTEI, true);
  i1 = insulate_correction->size[0] * insulate_correction->size[1] *
    insulate_correction->size[2];
  insulate_correction->size[0] = i;
  insulate_correction->size[1] = nx;
  insulate_correction->size[2] = idx;
  emxEnsureCapacity_real_T(sp, insulate_correction, i1, &eb_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    insulate_correction->data[i] = 0.0;
  }

  i = ii->size[0];
  ii->size[0] = (fg->size[0] + source->size[0]) + sink->size[0];
  emxEnsureCapacity_int32_T(sp, ii, i, &fb_emlrtRTEI);
  loop_ub = fg->size[0];
  for (i = 0; i < loop_ub; i++) {
    i1 = static_cast<int32_T>(fg->data[i]);
    if ((i1 < 1) || (i1 > loop_ub_tmp)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub_tmp, &g_emlrtBCI, sp);
    }

    ii->data[i] = i1;
  }

  loop_ub = source->size[0];
  for (i = 0; i < loop_ub; i++) {
    i1 = static_cast<int32_T>(source->data[i]);
    if ((i1 < 1) || (i1 > loop_ub_tmp)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub_tmp, &g_emlrtBCI, sp);
    }

    ii->data[i + fg->size[0]] = i1;
  }

  loop_ub = sink->size[0];
  for (i = 0; i < loop_ub; i++) {
    i1 = static_cast<int32_T>(sink->data[i]);
    if ((i1 < 1) || (i1 > loop_ub_tmp)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub_tmp, &g_emlrtBCI, sp);
    }

    ii->data[(i + fg->size[0]) + source->size[0]] = i1;
  }

  loop_ub = ii->size[0];
  for (i = 0; i < loop_ub; i++) {
    insulate_correction->data[ii->data[i] - 1] = 1.0;
  }

  st.site = &d_emlrtRSI;
  imfilter(&st, insulate_correction, hl);

  /*  apply filter */
  iters = 0U;
  emxInit_real_T(sp, &velup, 3, &gb_emlrtRTEI, true);
  emxInit_real_T(sp, &b_y, 1, &ob_emlrtRTEI, true);
  emxInit_real_T(sp, &x, 1, &kb_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (iters < maxiters)) {
    /* max iterations */
    iters++;
    i = velup->size[0] * velup->size[1] * velup->size[2];
    velup->size[0] = LP->size[0];
    velup->size[1] = LP->size[1];
    velup->size[2] = LP->size[2];
    emxEnsureCapacity_real_T(sp, velup, i, &gb_emlrtRTEI);
    loop_ub = LP->size[0] * LP->size[1] * LP->size[2];
    for (i = 0; i < loop_ub; i++) {
      velup->data[i] = LP->data[i];
    }

    st.site = &e_emlrtRSI;
    imfilter(&st, velup, hl);

    /* apply averaging filter */
    /* insulate the grey matter so gradient doesn't pass between folds - */
    /* inspired by ndnanfilter */
    st.site = &f_emlrtRSI;
    varargin_1[0] = velup->size[0];
    varargin_2[0] = insulate_correction->size[0];
    varargin_1[1] = velup->size[1];
    varargin_2[1] = insulate_correction->size[1];
    varargin_1[2] = velup->size[2];
    varargin_2[2] = insulate_correction->size[2];
    p = true;
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k < 3)) {
      if (varargin_1[k] != varargin_2[k]) {
        p = false;
        exitg2 = true;
      } else {
        k++;
      }
    }

    overflow = p;
    if (!overflow) {
      emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:dimagree",
        "MATLAB:dimagree", 0);
    }

    loop_ub = velup->size[0] * velup->size[1] * velup->size[2];
    for (i = 0; i < loop_ub; i++) {
      velup->data[i] /= insulate_correction->data[i];
    }

    nx = velup->size[0] * velup->size[1] * velup->size[2];
    i = ii->size[0];
    ii->size[0] = bg->size[0];
    emxEnsureCapacity_int32_T(sp, ii, i, &hb_emlrtRTEI);
    loop_ub = bg->size[0];
    for (i = 0; i < loop_ub; i++) {
      if ((bg->data[i] < 1) || (bg->data[i] > nx)) {
        emlrtDynamicBoundsCheckR2012b(bg->data[i], 1, nx, &h_emlrtBCI, sp);
      }

      ii->data[i] = bg->data[i];
    }

    loop_ub = ii->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      velup->data[ii->data[i] - 1] = 0.0;
    }

    nx = velup->size[0] * velup->size[1] * velup->size[2];
    i = ii->size[0];
    ii->size[0] = source->size[0];
    emxEnsureCapacity_int32_T(sp, ii, i, &ib_emlrtRTEI);
    loop_ub = source->size[0];
    for (i = 0; i < loop_ub; i++) {
      i1 = static_cast<int32_T>(source->data[i]);
      if ((i1 < 1) || (i1 > nx)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nx, &i_emlrtBCI, sp);
      }

      ii->data[i] = i1;
    }

    loop_ub = ii->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      velup->data[ii->data[i] - 1] = 0.0;
    }

    nx = velup->size[0] * velup->size[1] * velup->size[2];
    i = ii->size[0];
    ii->size[0] = sink->size[0];
    emxEnsureCapacity_int32_T(sp, ii, i, &jb_emlrtRTEI);
    loop_ub = sink->size[0];
    for (i = 0; i < loop_ub; i++) {
      i1 = static_cast<int32_T>(sink->data[i]);
      if ((i1 < 1) || (i1 > nx)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nx, &j_emlrtBCI, sp);
      }

      ii->data[i] = i1;
    }

    loop_ub = ii->size[0] - 1;
    for (i = 0; i <= loop_ub; i++) {
      velup->data[ii->data[i] - 1] = 1.0;
    }

    /* stopping condition */
    st.site = &g_emlrtRSI;
    c_indexShapeCheck(&st, *(int32_T (*)[3])LP->size, fg->size[0]);
    st.site = &g_emlrtRSI;
    c_indexShapeCheck(&st, *(int32_T (*)[3])velup->size, fg->size[0]);
    b_LP = LP->size[0] * LP->size[1] * LP->size[2];
    loop_ub = fg->size[0];
    for (i = 0; i < loop_ub; i++) {
      i1 = static_cast<int32_T>(fg->data[i]);
      if ((i1 < 1) || (i1 > b_LP)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_LP, &k_emlrtBCI, sp);
      }
    }

    nx = velup->size[0] * velup->size[1] * velup->size[2];
    loop_ub = fg->size[0];
    for (i = 0; i < loop_ub; i++) {
      i1 = static_cast<int32_T>(fg->data[i]);
      if ((i1 < 1) || (i1 > nx)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, nx, &l_emlrtBCI, sp);
      }
    }

    st.site = &g_emlrtRSI;
    i = x->size[0];
    x->size[0] = fg->size[0];
    emxEnsureCapacity_real_T(&st, x, i, &kb_emlrtRTEI);
    loop_ub = fg->size[0];
    for (i = 0; i < loop_ub; i++) {
      nx = static_cast<int32_T>(fg->data[i]) - 1;
      x->data[i] = LP->data[nx] - velup->data[nx];
    }

    b_st.site = &md_emlrtRSI;
    nx = x->size[0];
    i = b_y->size[0];
    b_y->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&b_st, b_y, i, &lb_emlrtRTEI);
    c_st.site = &nd_emlrtRSI;
    overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
    if (overflow) {
      d_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k < nx; k++) {
      b_y->data[k] = muDoubleScalarAbs(x->data[k]);
    }

    st.site = &g_emlrtRSI;
    b_st.site = &od_emlrtRSI;
    if (b_y->size[0] == 0) {
      y = 0.0;
    } else {
      nx = b_y->size[0];
      y = 0.0;
      c_st.site = &pd_emlrtRSI;
      if (b_y->size[0] > 2147483646) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 0; k < nx; k++) {
        i = k + 1;
        if ((i < 1) || (i > b_y->size[0])) {
          emlrtDynamicBoundsCheckR2012b(i, 1, b_y->size[0], &emlrtBCI, &b_st);
        }

        if (!muDoubleScalarIsNaN(b_y->data[k])) {
          i = k + 1;
          if ((i < 1) || (i > b_y->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i, 1, b_y->size[0], &n_emlrtBCI, &b_st);
          }

          y += b_y->data[i - 1];
        }
      }
    }

    if ((static_cast<int32_T>(iters) < 1) || (static_cast<int32_T>(iters) >
         iter_change->size[1])) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(iters), 1,
        iter_change->size[1], &m_emlrtBCI, sp);
    }

    nx = static_cast<int32_T>(iters) - 1;
    iter_change->data[nx] = y;

    /* compute change from last iteration */
    i = LP->size[0] * LP->size[1] * LP->size[2];
    LP->size[0] = velup->size[0];
    LP->size[1] = velup->size[1];
    LP->size[2] = velup->size[2];
    emxEnsureCapacity_real_T(sp, LP, i, &mb_emlrtRTEI);
    loop_ub = velup->size[0] * velup->size[1] * velup->size[2];
    for (i = 0; i < loop_ub; i++) {
      LP->data[i] = velup->data[i];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }

    if ((static_cast<int32_T>(iters) < 1) || (static_cast<int32_T>(iters) >
         iter_change->size[1])) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(iters), 1,
        iter_change->size[1], &o_emlrtBCI, sp);
    }

    if (iter_change->data[nx] < 0.001) {
      exitg1 = true;
    }
  }

  emxFree_real_T(&x);
  emxFree_real_T(&b_y);
  emxFree_int32_T(&ii);
  emxFree_real_T(&velup);
  emxFree_real_T(&insulate_correction);
  emxFree_int32_T(&bg);
  emxFree_real_T(&hl);
  st.site = &h_emlrtRSI;
  b_st.site = &lc_emlrtRSI;
  c_st.site = &mc_emlrtRSI;
  d_st.site = &nc_emlrtRSI;
  if (LP->size[0] * LP->size[1] * LP->size[2] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &c_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero",
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  e_st.site = &oc_emlrtRSI;
  f_st.site = &pc_emlrtRSI;
  nx = LP->size[0] * LP->size[1] * LP->size[2];
  if (LP->size[0] * LP->size[1] * LP->size[2] <= 2) {
    if (LP->size[0] * LP->size[1] * LP->size[2] == 1) {
      y = LP->data[0];
    } else if ((LP->data[0] < LP->data[1]) || (muDoubleScalarIsNaN(LP->data[0]) &&
                (!muDoubleScalarIsNaN(LP->data[1])))) {
      y = LP->data[1];
    } else {
      y = LP->data[0];
    }
  } else {
    g_st.site = &rc_emlrtRSI;
    if (!muDoubleScalarIsNaN(LP->data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &sc_emlrtRSI;
      overflow = ((2 <= LP->size[0] * LP->size[1] * LP->size[2]) && (LP->size[0]
        * LP->size[1] * LP->size[2] > 2147483646));
      if (overflow) {
        i_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= LP->size[0] * LP->size[1] * LP->size[2])) {
        if (!muDoubleScalarIsNaN(LP->data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      y = LP->data[0];
    } else {
      g_st.site = &qc_emlrtRSI;
      y = LP->data[idx - 1];
      loop_ub_tmp = idx + 1;
      h_st.site = &tc_emlrtRSI;
      overflow = ((idx + 1 <= LP->size[0] * LP->size[1] * LP->size[2]) &&
                  (LP->size[0] * LP->size[1] * LP->size[2] > 2147483646));
      if (overflow) {
        i_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }

      for (k = loop_ub_tmp; k <= nx; k++) {
        if (y < LP->data[k - 1]) {
          y = LP->data[k - 1];
        }
      }
    }
  }

  loop_ub = LP->size[0] * LP->size[1] * LP->size[2];
  for (i = 0; i < loop_ub; i++) {
    LP->data[i] /= y;
  }

  st.site = &i_emlrtRSI;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (laplace_iters.cpp) */
