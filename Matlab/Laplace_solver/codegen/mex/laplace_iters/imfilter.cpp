/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.cpp
 *
 * Code generation for function 'imfilter'
 *
 */

/* Include files */
#include "imfilter.h"
#include "all.h"
#include "combineVectorElements.h"
#include "diag.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "laplace_iters.h"
#include "laplace_iters_data.h"
#include "laplace_iters_emxutil.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include "mwmathutil.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "svd.h"

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 55,  /* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 59,  /* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 64,  /* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 66,  /* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 67, /* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 68, /* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 84, /* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 88, /* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 106,/* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 110,/* lineNo */
  "imfilter",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 600,/* lineNo */
  "isSeparable",                       /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 603,/* lineNo */
  "isSeparable",                       /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 606,/* lineNo */
  "isSeparable",                       /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 607,/* lineNo */
  "isSeparable",                       /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 608,/* lineNo */
  "isSeparable",                       /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo uc_emlrtRSI = { 15, /* lineNo */
  "sum",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 769,/* lineNo */
  "padImage",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 20, /* lineNo */
  "padarray",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo xc_emlrtRSI = { 64, /* lineNo */
  "padarray",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo yc_emlrtRSI = { 80, /* lineNo */
  "padarray",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo ad_emlrtRSI = { 76, /* lineNo */
  "validateattributes",                /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/lang/validateattributes.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 736,/* lineNo */
  "getPaddingIndices",                 /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 843,/* lineNo */
  "filterPartOrWhole",                 /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 917,/* lineNo */
  "imfiltercore",                      /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 945,/* lineNo */
  "imfiltercoreAlgo",                  /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 957,/* lineNo */
  "imfiltercoreAlgo",                  /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 823,/* lineNo */
  "filterPartOrWhole",                 /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pathName */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  846,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "ReplicatePad",                      /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  846,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "ReplicatePad",                      /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  846,                                 /* lineNo */
  9,                                   /* colNo */
  "ReplicatePad",                      /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnan",                    /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnan.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 14,/* lineNo */
  37,                                  /* colNo */
  "validatenonnegative",               /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+valattr/validatenonnegative.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 13,/* lineNo */
  37,                                  /* colNo */
  "validateinteger",                   /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+valattr/validateinteger.m"/* pName */
};

static emlrtDCInfo m_emlrtDCI = { 836, /* lineNo */
  32,                                  /* colNo */
  "ReplicatePad",                      /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 827, /* lineNo */
  33,                                  /* colNo */
  "ReplicatePad",                      /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 827, /* lineNo */
  33,                                  /* colNo */
  "ReplicatePad",                      /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  36,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  93,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 83,  /* lineNo */
  56,                                  /* colNo */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 83,  /* lineNo */
  56,                                  /* colNo */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  820,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "filterPartOrWhole",                 /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  823,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "filterPartOrWhole",                 /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  820,                                 /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "filterPartOrWhole",                 /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo hc_emlrtRTEI = { 736,/* lineNo */
  12,                                  /* colNo */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 836,/* lineNo */
  5,                                   /* colNo */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 28,/* lineNo */
  9,                                   /* colNo */
  "colon",                             /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/ops/colon.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 845,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 769,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = { 80,/* lineNo */
  5,                                   /* colNo */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 839,/* lineNo */
  9,                                   /* colNo */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = { 845,/* lineNo */
  30,                                  /* colNo */
  "padarray",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 17,/* lineNo */
  13,                                  /* colNo */
  "isinf",                             /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/isinf.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 820,/* lineNo */
  27,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 66,/* lineNo */
  18,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = { 110,/* lineNo */
  17,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 823,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = { 606,/* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = { 814,/* lineNo */
  8,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = { 67,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 68,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = { 917,/* lineNo */
  11,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = { 608,/* lineNo */
  16,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 84,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 820,/* lineNo */
  21,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = { 88,/* lineNo */
  13,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = { 917,/* lineNo */
  28,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo id_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = { 603,/* lineNo */
  8,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = { 820,/* lineNo */
  9,                                   /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

static emlrtRTEInfo md_emlrtRTEI = { 823,/* lineNo */
  23,                                  /* colNo */
  "imfilter",                          /* fName */
  "/export01/local/matlab19b/toolbox/images/images/eml/imfilter.m"/* pName */
};

/* Function Declarations */
static int32_T eml_ndims_varsized(const int32_T sz[3]);
static void padImage(const emlrtStack *sp, const emxArray_real_T *a_tmp, const
                     real_T pad[3], emxArray_real_T *a);

/* Function Definitions */
static int32_T eml_ndims_varsized(const int32_T sz[3])
{
  int32_T n;
  n = 3;
  if (sz[2] == 1) {
    n = 2;
  }

  return n;
}

static void padImage(const emlrtStack *sp, const emxArray_real_T *a_tmp, const
                     real_T pad[3], emxArray_real_T *a)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  real_T varargin_1[3];
  uint32_T varargin_1_tmp_tmp_tmp;
  real_T varargin_1_tmp;
  uint32_T b_varargin_1_tmp_tmp_tmp;
  real_T b_varargin_1_tmp;
  uint32_T c_varargin_1_tmp_tmp_tmp;
  real_T c_varargin_1_tmp;
  real_T x_data[3];
  int32_T idx;
  int32_T i;
  real_T d;
  emxArray_int32_T *idxA;
  emxArray_int8_T *onesVector;
  int32_T i1;
  emxArray_real_T *y;
  emxArray_uint32_T *idxDir;
  uint32_T u;
  int32_T iv[1];
  int32_T i2;
  int32_T b_i;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &vc_emlrtRSI;
  b_st.site = &wc_emlrtRSI;
  c_st.site = &ad_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!muDoubleScalarIsNaN(pad[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonNaN",
      "MATLAB:padarray:expectedNonNaN", 3, 4, 24, "input number 2, PADSIZE,");
  }

  c_st.site = &ad_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!(pad[k] < 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &p_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedNonnegative",
      "MATLAB:padarray:expectedNonnegative", 3, 4, 24,
      "input number 2, PADSIZE,");
  }

  c_st.site = &ad_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if ((!muDoubleScalarIsInf(pad[k])) && (!muDoubleScalarIsNaN(pad[k])) &&
        (muDoubleScalarFloor(pad[k]) == pad[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
      "Coder:toolbox:ValidateattributesexpectedInteger",
      "MATLAB:padarray:expectedInteger", 3, 4, 24, "input number 2, PADSIZE,");
  }

  if ((a_tmp->size[0] == 0) || (a_tmp->size[1] == 0) || (a_tmp->size[2] == 0)) {
    varargin_1[0] = static_cast<real_T>(a_tmp->size[0]) + 2.0 * pad[0];
    varargin_1[1] = static_cast<real_T>(a_tmp->size[1]) + 2.0 * pad[1];
    varargin_1[2] = static_cast<real_T>(a_tmp->size[2]) + 2.0 * pad[2];
    b_st.site = &xc_emlrtRSI;
    repmat(&b_st, varargin_1, a);
  } else {
    b_st.site = &yc_emlrtRSI;
    c_st.site = &cd_emlrtRSI;
    varargin_1_tmp_tmp_tmp = static_cast<uint32_T>(a_tmp->size[0]);
    varargin_1_tmp = 2.0 * pad[0] + static_cast<real_T>(varargin_1_tmp_tmp_tmp);
    varargin_1[0] = varargin_1_tmp;
    b_varargin_1_tmp_tmp_tmp = static_cast<uint32_T>(a_tmp->size[1]);
    b_varargin_1_tmp = 2.0 * pad[1] + static_cast<real_T>
      (b_varargin_1_tmp_tmp_tmp);
    varargin_1[1] = b_varargin_1_tmp;
    c_varargin_1_tmp_tmp_tmp = static_cast<uint32_T>(a_tmp->size[2]);
    c_varargin_1_tmp = 2.0 * pad[2] + static_cast<real_T>
      (c_varargin_1_tmp_tmp_tmp);
    varargin_1[2] = c_varargin_1_tmp;
    x_data[0] = varargin_1_tmp;
    x_data[1] = b_varargin_1_tmp;
    x_data[2] = c_varargin_1_tmp;
    if (!muDoubleScalarIsNaN(varargin_1_tmp)) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx != 0) {
      varargin_1_tmp = varargin_1[idx - 1];
      i = idx + 1;
      for (k = i; k < 4; k++) {
        d = varargin_1[k - 1];
        if (varargin_1_tmp < d) {
          varargin_1_tmp = d;
        }
      }
    }

    if (!(varargin_1_tmp >= 0.0)) {
      emlrtNonNegativeCheckR2012b(varargin_1_tmp, &o_emlrtDCI, &c_st);
    }

    if (varargin_1_tmp != static_cast<int32_T>(muDoubleScalarFloor
         (varargin_1_tmp))) {
      emlrtIntegerCheckR2012b(varargin_1_tmp, &n_emlrtDCI, &c_st);
    }

    emxInit_int32_T(&c_st, &idxA, 2, &mc_emlrtRTEI, true);
    emxInit_int8_T(&c_st, &onesVector, 2, &ic_emlrtRTEI, true);
    i = idxA->size[0] * idxA->size[1];
    i1 = static_cast<int32_T>(varargin_1_tmp);
    idxA->size[0] = i1;
    idxA->size[1] = 3;
    emxEnsureCapacity_int32_T(&c_st, idxA, i, &hc_emlrtRTEI);
    i = onesVector->size[0] * onesVector->size[1];
    onesVector->size[0] = 1;
    emxEnsureCapacity_int8_T(&c_st, onesVector, i, &ic_emlrtRTEI);
    if (!(pad[0] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(pad[0], &m_emlrtDCI, &c_st);
    }

    idx = static_cast<int32_T>(pad[0]);
    i = onesVector->size[0] * onesVector->size[1];
    onesVector->size[1] = idx;
    emxEnsureCapacity_int8_T(&c_st, onesVector, i, &ic_emlrtRTEI);
    for (i = 0; i < idx; i++) {
      onesVector->data[i] = 1;
    }

    emxInit_real_T(&c_st, &y, 2, &oc_emlrtRTEI, true);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    idx = static_cast<int32_T>((static_cast<real_T>(varargin_1_tmp_tmp_tmp) -
      1.0));
    y->size[1] = idx + 1;
    emxEnsureCapacity_real_T(&c_st, y, i, &jc_emlrtRTEI);
    for (i = 0; i <= idx; i++) {
      y->data[i] = static_cast<real_T>(i) + 1.0;
    }

    emxInit_uint32_T(&c_st, &idxDir, 2, &nc_emlrtRTEI, true);
    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = (onesVector->size[1] + y->size[1]) + onesVector->size[1];
    emxEnsureCapacity_uint32_T(&c_st, idxDir, i, &kc_emlrtRTEI);
    idx = onesVector->size[1];
    for (i = 0; i < idx; i++) {
      idxDir->data[i] = static_cast<uint32_T>(onesVector->data[i]);
    }

    idx = y->size[1];
    for (i = 0; i < idx; i++) {
      d = muDoubleScalarRound(y->data[i]);
      if (d < 4.294967296E+9) {
        if (d >= 0.0) {
          u = static_cast<uint32_T>(d);
        } else {
          u = 0U;
        }
      } else if (d >= 4.294967296E+9) {
        u = MAX_uint32_T;
      } else {
        u = 0U;
      }

      idxDir->data[i + onesVector->size[1]] = u;
    }

    idx = onesVector->size[1];
    for (i = 0; i < idx; i++) {
      idxDir->data[(i + onesVector->size[1]) + y->size[1]] =
        varargin_1_tmp_tmp_tmp * onesVector->data[i];
    }

    if (1 > i1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &p_emlrtBCI, &c_st);
    }

    if ((idxDir->size[1] < 1) || (idxDir->size[1] > i1)) {
      emlrtDynamicBoundsCheckR2012b(idxDir->size[1], 1, i1, &q_emlrtBCI, &c_st);
    }

    iv[0] = idxDir->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 1, &idxDir->size[0], 2, &b_emlrtECI,
      &c_st);
    idx = idxDir->size[1];
    for (i = 0; i < idx; i++) {
      idxA->data[i] = static_cast<int32_T>(idxDir->data[i]);
    }

    i = onesVector->size[0] * onesVector->size[1];
    onesVector->size[0] = 1;
    emxEnsureCapacity_int8_T(&c_st, onesVector, i, &ic_emlrtRTEI);
    if (!(pad[1] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(pad[1], &m_emlrtDCI, &c_st);
    }

    idx = static_cast<int32_T>(pad[1]);
    i = onesVector->size[0] * onesVector->size[1];
    onesVector->size[1] = idx;
    emxEnsureCapacity_int8_T(&c_st, onesVector, i, &ic_emlrtRTEI);
    for (i = 0; i < idx; i++) {
      onesVector->data[i] = 1;
    }

    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    idx = static_cast<int32_T>((static_cast<real_T>(b_varargin_1_tmp_tmp_tmp) -
      1.0));
    y->size[1] = idx + 1;
    emxEnsureCapacity_real_T(&c_st, y, i, &jc_emlrtRTEI);
    for (i = 0; i <= idx; i++) {
      y->data[i] = static_cast<real_T>(i) + 1.0;
    }

    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = (onesVector->size[1] + y->size[1]) + onesVector->size[1];
    emxEnsureCapacity_uint32_T(&c_st, idxDir, i, &kc_emlrtRTEI);
    idx = onesVector->size[1];
    for (i = 0; i < idx; i++) {
      idxDir->data[i] = static_cast<uint32_T>(onesVector->data[i]);
    }

    idx = y->size[1];
    for (i = 0; i < idx; i++) {
      d = muDoubleScalarRound(y->data[i]);
      if (d < 4.294967296E+9) {
        if (d >= 0.0) {
          u = static_cast<uint32_T>(d);
        } else {
          u = 0U;
        }
      } else if (d >= 4.294967296E+9) {
        u = MAX_uint32_T;
      } else {
        u = 0U;
      }

      idxDir->data[i + onesVector->size[1]] = u;
    }

    idx = onesVector->size[1];
    for (i = 0; i < idx; i++) {
      idxDir->data[(i + onesVector->size[1]) + y->size[1]] =
        b_varargin_1_tmp_tmp_tmp * onesVector->data[i];
    }

    if (1 > idxA->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, idxA->size[0], &p_emlrtBCI, &c_st);
    }

    if ((idxDir->size[1] < 1) || (idxDir->size[1] > idxA->size[0])) {
      emlrtDynamicBoundsCheckR2012b(idxDir->size[1], 1, idxA->size[0],
        &q_emlrtBCI, &c_st);
    }

    iv[0] = idxDir->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 1, &idxDir->size[0], 2, &b_emlrtECI,
      &c_st);
    idx = idxDir->size[1];
    for (i = 0; i < idx; i++) {
      idxA->data[i + idxA->size[0]] = static_cast<int32_T>(idxDir->data[i]);
    }

    i = onesVector->size[0] * onesVector->size[1];
    onesVector->size[0] = 1;
    emxEnsureCapacity_int8_T(&c_st, onesVector, i, &ic_emlrtRTEI);
    if (!(pad[2] >= 0.0)) {
      emlrtNonNegativeCheckR2012b(pad[2], &m_emlrtDCI, &c_st);
    }

    idx = static_cast<int32_T>(pad[2]);
    i = onesVector->size[0] * onesVector->size[1];
    onesVector->size[1] = idx;
    emxEnsureCapacity_int8_T(&c_st, onesVector, i, &ic_emlrtRTEI);
    for (i = 0; i < idx; i++) {
      onesVector->data[i] = 1;
    }

    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    idx = static_cast<int32_T>((static_cast<real_T>(c_varargin_1_tmp_tmp_tmp) -
      1.0));
    y->size[1] = idx + 1;
    emxEnsureCapacity_real_T(&c_st, y, i, &jc_emlrtRTEI);
    for (i = 0; i <= idx; i++) {
      y->data[i] = static_cast<real_T>(i) + 1.0;
    }

    i = idxDir->size[0] * idxDir->size[1];
    idxDir->size[0] = 1;
    idxDir->size[1] = (onesVector->size[1] + y->size[1]) + onesVector->size[1];
    emxEnsureCapacity_uint32_T(&c_st, idxDir, i, &kc_emlrtRTEI);
    idx = onesVector->size[1];
    for (i = 0; i < idx; i++) {
      idxDir->data[i] = static_cast<uint32_T>(onesVector->data[i]);
    }

    idx = y->size[1];
    for (i = 0; i < idx; i++) {
      d = muDoubleScalarRound(y->data[i]);
      if (d < 4.294967296E+9) {
        if (d >= 0.0) {
          u = static_cast<uint32_T>(d);
        } else {
          u = 0U;
        }
      } else if (d >= 4.294967296E+9) {
        u = MAX_uint32_T;
      } else {
        u = 0U;
      }

      idxDir->data[i + onesVector->size[1]] = u;
    }

    idx = onesVector->size[1];
    for (i = 0; i < idx; i++) {
      idxDir->data[(i + onesVector->size[1]) + y->size[1]] =
        c_varargin_1_tmp_tmp_tmp * onesVector->data[i];
    }

    emxFree_real_T(&y);
    emxFree_int8_T(&onesVector);
    if (1 > idxA->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, idxA->size[0], &p_emlrtBCI, &c_st);
    }

    if ((idxDir->size[1] < 1) || (idxDir->size[1] > idxA->size[0])) {
      emlrtDynamicBoundsCheckR2012b(idxDir->size[1], 1, idxA->size[0],
        &q_emlrtBCI, &c_st);
    }

    iv[0] = idxDir->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 1, &idxDir->size[0], 2, &b_emlrtECI,
      &c_st);
    idx = idxDir->size[1];
    for (i = 0; i < idx; i++) {
      idxA->data[i + idxA->size[0] * 2] = static_cast<int32_T>(idxDir->data[i]);
    }

    emxFree_uint32_T(&idxDir);
    d = static_cast<real_T>(a_tmp->size[0]) + 2.0 * pad[0];
    if (!(d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d, &q_emlrtDCI, &st);
    }

    if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
      emlrtIntegerCheckR2012b(d, &p_emlrtDCI, &st);
    }

    b_varargin_1_tmp = static_cast<real_T>(a_tmp->size[1]) + 2.0 * pad[1];
    if (!(b_varargin_1_tmp >= 0.0)) {
      emlrtNonNegativeCheckR2012b(b_varargin_1_tmp, &q_emlrtDCI, &st);
    }

    if (b_varargin_1_tmp != static_cast<int32_T>(muDoubleScalarFloor
         (b_varargin_1_tmp))) {
      emlrtIntegerCheckR2012b(b_varargin_1_tmp, &p_emlrtDCI, &st);
    }

    c_varargin_1_tmp = static_cast<real_T>(a_tmp->size[2]) + 2.0 * pad[2];
    if (!(c_varargin_1_tmp >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c_varargin_1_tmp, &q_emlrtDCI, &st);
    }

    if (c_varargin_1_tmp != static_cast<int32_T>(muDoubleScalarFloor
         (c_varargin_1_tmp))) {
      emlrtIntegerCheckR2012b(c_varargin_1_tmp, &p_emlrtDCI, &st);
    }

    i = a->size[0] * a->size[1] * a->size[2];
    a->size[0] = static_cast<int32_T>(d);
    a->size[1] = static_cast<int32_T>(b_varargin_1_tmp);
    i1 = static_cast<int32_T>(c_varargin_1_tmp);
    a->size[2] = i1;
    emxEnsureCapacity_real_T(&st, a, i, &lc_emlrtRTEI);
    for (k = 0; k < i1; k++) {
      i = a->size[1];
      for (idx = 0; idx < i; idx++) {
        i2 = a->size[0];
        for (b_i = 0; b_i < i2; b_i++) {
          i3 = b_i + 1;
          if ((i3 < 1) || (i3 > idxA->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, idxA->size[0], &r_emlrtBCI, &st);
          }

          i3 = idxA->data[i3 - 1];
          if ((i3 < 1) || (i3 > a_tmp->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, a_tmp->size[0], &r_emlrtBCI,
              &st);
          }

          i4 = idx + 1;
          if ((i4 < 1) || (i4 > idxA->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, idxA->size[0], &r_emlrtBCI, &st);
          }

          i4 = idxA->data[(i4 + idxA->size[0]) - 1];
          if ((i4 < 1) || (i4 > a_tmp->size[1])) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, a_tmp->size[1], &r_emlrtBCI,
              &st);
          }

          i5 = k + 1;
          if ((i5 < 1) || (i5 > idxA->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, idxA->size[0], &r_emlrtBCI, &st);
          }

          i5 = idxA->data[(i5 + idxA->size[0] * 2) - 1];
          if ((i5 < 1) || (i5 > a_tmp->size[2])) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, a_tmp->size[2], &r_emlrtBCI,
              &st);
          }

          i6 = b_i + 1;
          if ((i6 < 1) || (i6 > a->size[0])) {
            emlrtDynamicBoundsCheckR2012b(i6, 1, a->size[0], &s_emlrtBCI, &st);
          }

          i7 = idx + 1;
          if ((i7 < 1) || (i7 > a->size[1])) {
            emlrtDynamicBoundsCheckR2012b(i7, 1, a->size[1], &s_emlrtBCI, &st);
          }

          i8 = k + 1;
          if ((i8 < 1) || (i8 > a->size[2])) {
            emlrtDynamicBoundsCheckR2012b(i8, 1, a->size[2], &s_emlrtBCI, &st);
          }

          a->data[((i6 + a->size[0] * (i7 - 1)) + a->size[0] * a->size[1] * (i8
                    - 1)) - 1] = a_tmp->data[((i3 + a_tmp->size[0] * (i4 - 1)) +
            a_tmp->size[0] * a_tmp->size[1] * (i5 - 1)) - 1];
        }
      }
    }

    emxFree_int32_T(&idxA);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void imfilter(const emlrtStack *sp, emxArray_real_T *varargin_1, const
              emxArray_real_T *varargin_2)
{
  real_T outSizeT[3];
  real_T startT[3];
  real_T filter_center[3];
  emxArray_real_T *unusedU0;
  emxArray_real_T *s;
  int32_T loop_ub;
  emxArray_real_T *unusedU1;
  int32_T i;
  emxArray_real_T *b_s;
  emxArray_boolean_T *x;
  emxArray_boolean_T *r;
  int32_T nz;
  emxArray_real_T *c_s;
  boolean_T overflow;
  boolean_T b_varargin_2[3];
  int32_T n;
  emxArray_real_T *a;
  emxArray_real_T *nonzero_h;
  emxArray_int32_T *r1;
  int32_T k;
  int32_T idx;
  emxArray_boolean_T *connb;
  emxArray_real_T *hcol;
  real_T tol;
  boolean_T tooBig;
  emxArray_real_T *hrow;
  real_T start[3];
  real_T padSizeT[3];
  boolean_T exitg1;
  real_T d;
  emxArray_boolean_T *b_connb;
  real_T connDimsT[2];
  emxArray_int32_T *r2;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
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
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  outSizeT[0] = varargin_1->size[0];
  startT[0] = static_cast<real_T>(varargin_2->size[0]) - muDoubleScalarFloor((
    static_cast<real_T>(varargin_2->size[0]) + 1.0) / 2.0);
  outSizeT[1] = varargin_1->size[1];
  startT[1] = static_cast<real_T>(varargin_2->size[1]) - muDoubleScalarFloor((
    static_cast<real_T>(varargin_2->size[1]) + 1.0) / 2.0);
  outSizeT[2] = varargin_1->size[2];
  startT[2] = static_cast<real_T>(varargin_2->size[2]) - muDoubleScalarFloor((
    static_cast<real_T>(varargin_2->size[2]) + 1.0) / 2.0);
  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0) &&
      (varargin_1->size[2] != 0)) {
    if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0) ||
        (varargin_2->size[2] == 0)) {
      filter_center[1] = varargin_1->size[1];
      filter_center[2] = varargin_1->size[2];
      loop_ub = varargin_1->size[0];
      i = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
      varargin_1->size[0] = loop_ub;
      emxEnsureCapacity_real_T(sp, varargin_1, i, &rc_emlrtRTEI);
      nz = static_cast<int32_T>(filter_center[1]);
      i = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
      varargin_1->size[1] = static_cast<int32_T>(filter_center[1]);
      emxEnsureCapacity_real_T(sp, varargin_1, i, &rc_emlrtRTEI);
      n = static_cast<int32_T>(filter_center[2]);
      i = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
      varargin_1->size[2] = static_cast<int32_T>(filter_center[2]);
      emxEnsureCapacity_real_T(sp, varargin_1, i, &rc_emlrtRTEI);
      for (i = 0; i < n; i++) {
        for (k = 0; k < nz; k++) {
          for (idx = 0; idx < loop_ub; idx++) {
            varargin_1->data[(idx + varargin_1->size[0] * k) + varargin_1->size
              [0] * varargin_1->size[1] * i] = 0.0;
          }
        }
      }
    } else {
      st.site = &v_emlrtRSI;
      emxInit_real_T(&st, &unusedU0, 2, &jd_emlrtRTEI, true);
      emxInit_real_T(&st, &s, 2, &xc_emlrtRTEI, true);
      emxInit_real_T(&st, &unusedU1, 2, &jd_emlrtRTEI, true);
      emxInit_real_T(&st, &b_s, 1, &kd_emlrtRTEI, true);
      emxInit_boolean_T(&st, &x, 1, &dd_emlrtRTEI, true);
      emxInit_boolean_T(&st, &r, 1, &ab_emlrtRTEI, true);
      emxInit_real_T(&st, &c_s, 2, &xc_emlrtRTEI, true);
      if ((varargin_2->size[0] * varargin_2->size[1] * varargin_2->size[2] >= 49)
          && (eml_ndims_varsized(*(int32_T (*)[3])varargin_2->size) == 2)) {
        b_varargin_2[0] = (varargin_2->size[0] != 1);
        b_varargin_2[1] = (varargin_2->size[1] != 1);
        b_varargin_2[2] = (varargin_2->size[2] != 1);
        if (all(b_varargin_2)) {
          i = x->size[0];
          x->size[0] = varargin_2->size[0] * varargin_2->size[1] *
            varargin_2->size[2];
          emxEnsureCapacity_boolean_T(&st, x, i, &sc_emlrtRTEI);
          loop_ub = varargin_2->size[0] * varargin_2->size[1] * varargin_2->
            size[2];
          for (i = 0; i < loop_ub; i++) {
            x->data[i] = muDoubleScalarIsInf(varargin_2->data[i]);
          }

          i = r->size[0];
          r->size[0] = varargin_2->size[0] * varargin_2->size[1] *
            varargin_2->size[2];
          emxEnsureCapacity_boolean_T(&st, r, i, &ab_emlrtRTEI);
          loop_ub = varargin_2->size[0] * varargin_2->size[1] * varargin_2->
            size[2];
          for (i = 0; i < loop_ub; i++) {
            r->data[i] = muDoubleScalarIsNaN(varargin_2->data[i]);
          }

          loop_ub = x->size[0];
          for (i = 0; i < loop_ub; i++) {
            x->data[i] = ((!x->data[i]) && (!r->data[i]));
          }

          b_st.site = &gb_emlrtRSI;
          if (b_all(&b_st, x)) {
            b_st.site = &hb_emlrtRSI;
            svd(&b_st, varargin_2, unusedU0, s, unusedU1);
            loop_ub = s->size[0] - 1;
            nz = s->size[1] - 1;
            i = c_s->size[0] * c_s->size[1];
            c_s->size[0] = s->size[0];
            c_s->size[1] = s->size[1];
            emxEnsureCapacity_real_T(&st, c_s, i, &xc_emlrtRTEI);
            for (i = 0; i <= nz; i++) {
              for (k = 0; k <= loop_ub; k++) {
                c_s->data[k + c_s->size[0] * i] = s->data[k + s->size[0] * i];
              }
            }

            i = s->size[0] * s->size[1];
            s->size[0] = c_s->size[0];
            s->size[1] = c_s->size[1];
            emxEnsureCapacity_real_T(&st, s, i, &xc_emlrtRTEI);
            loop_ub = c_s->size[1];
            for (i = 0; i < loop_ub; i++) {
              nz = c_s->size[0];
              for (k = 0; k < nz; k++) {
                s->data[k + s->size[0] * i] = c_s->data[k + c_s->size[0] * i];
              }
            }

            b_st.site = &ib_emlrtRSI;
            diag(&b_st, s, b_s);
            nz = varargin_2->size[0];
            if (varargin_2->size[1] > varargin_2->size[0]) {
              nz = varargin_2->size[1];
            }

            if (varargin_2->size[2] > nz) {
              nz = varargin_2->size[2];
            }

            b_st.site = &jb_emlrtRSI;
            c_st.site = &lc_emlrtRSI;
            d_st.site = &mc_emlrtRSI;
            e_st.site = &nc_emlrtRSI;
            if (b_s->size[0] < 1) {
              emlrtErrorWithMessageIdR2018a(&e_st, &c_emlrtRTEI,
                "Coder:toolbox:eml_min_or_max_varDimZero",
                "Coder:toolbox:eml_min_or_max_varDimZero", 0);
            }

            f_st.site = &oc_emlrtRSI;
            g_st.site = &pc_emlrtRSI;
            n = b_s->size[0];
            if (b_s->size[0] <= 2) {
              if (b_s->size[0] == 1) {
                tol = b_s->data[0];
              } else if ((b_s->data[0] < b_s->data[1]) || (muDoubleScalarIsNaN
                          (b_s->data[0]) && (!muDoubleScalarIsNaN(b_s->data[1]))))
              {
                tol = b_s->data[1];
              } else {
                tol = b_s->data[0];
              }
            } else {
              h_st.site = &rc_emlrtRSI;
              if (!muDoubleScalarIsNaN(b_s->data[0])) {
                idx = 1;
              } else {
                idx = 0;
                i_st.site = &sc_emlrtRSI;
                if (b_s->size[0] > 2147483646) {
                  j_st.site = &p_emlrtRSI;
                  check_forloop_overflow_error(&j_st);
                }

                k = 2;
                exitg1 = false;
                while ((!exitg1) && (k <= b_s->size[0])) {
                  if (!muDoubleScalarIsNaN(b_s->data[k - 1])) {
                    idx = k;
                    exitg1 = true;
                  } else {
                    k++;
                  }
                }
              }

              if (idx == 0) {
                tol = b_s->data[0];
              } else {
                h_st.site = &qc_emlrtRSI;
                tol = b_s->data[idx - 1];
                loop_ub = idx + 1;
                i_st.site = &tc_emlrtRSI;
                overflow = ((idx + 1 <= b_s->size[0]) && (b_s->size[0] >
                  2147483646));
                if (overflow) {
                  j_st.site = &p_emlrtRSI;
                  check_forloop_overflow_error(&j_st);
                }

                for (k = loop_ub; k <= n; k++) {
                  d = b_s->data[k - 1];
                  if (tol < d) {
                    tol = d;
                  }
                }
              }
            }

            tol = static_cast<real_T>(nz) * tol * 2.2204460492503131E-16;
            b_st.site = &kb_emlrtRSI;
            i = x->size[0];
            x->size[0] = b_s->size[0];
            emxEnsureCapacity_boolean_T(&b_st, x, i, &dd_emlrtRTEI);
            loop_ub = b_s->size[0];
            for (i = 0; i < loop_ub; i++) {
              x->data[i] = (b_s->data[i] > tol);
            }

            c_st.site = &uc_emlrtRSI;
            d_st.site = &m_emlrtRSI;
            nz = combineVectorElements(&d_st, x);
            overflow = (nz == 1);
          } else {
            overflow = false;
          }
        } else {
          overflow = false;
        }
      } else {
        overflow = false;
      }

      emxFree_boolean_T(&r);
      emxInit_real_T(sp, &a, 3, &id_emlrtRTEI, true);
      emxInit_real_T(sp, &nonzero_h, 1, &ld_emlrtRTEI, true);
      emxInit_int32_T(sp, &r1, 1, &md_emlrtRTEI, true);
      if (overflow) {
        st.site = &w_emlrtRSI;
        padImage(&st, varargin_1, startT, a);
        st.site = &x_emlrtRSI;
        svd(&st, varargin_2, unusedU0, s, unusedU1);
        loop_ub = s->size[0] - 1;
        nz = s->size[1] - 1;
        i = c_s->size[0] * c_s->size[1];
        c_s->size[0] = s->size[0];
        c_s->size[1] = s->size[1];
        emxEnsureCapacity_real_T(sp, c_s, i, &uc_emlrtRTEI);
        for (i = 0; i <= nz; i++) {
          for (k = 0; k <= loop_ub; k++) {
            c_s->data[k + c_s->size[0] * i] = s->data[k + s->size[0] * i];
          }
        }

        i = s->size[0] * s->size[1];
        s->size[0] = c_s->size[0];
        s->size[1] = c_s->size[1];
        emxEnsureCapacity_real_T(sp, s, i, &uc_emlrtRTEI);
        loop_ub = c_s->size[1];
        for (i = 0; i < loop_ub; i++) {
          nz = c_s->size[0];
          for (k = 0; k < nz; k++) {
            s->data[k + s->size[0] * i] = c_s->data[k + c_s->size[0] * i];
          }
        }

        st.site = &y_emlrtRSI;
        diag(&st, s, b_s);
        if (1 > unusedU0->size[1]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, unusedU0->size[1], &v_emlrtBCI, sp);
        }

        if (1 > b_s->size[0]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, b_s->size[0], &w_emlrtBCI, sp);
        }

        emxInit_real_T(sp, &hcol, 1, &ad_emlrtRTEI, true);
        tol = b_s->data[0];
        st.site = &ab_emlrtRSI;
        b_sqrt(&st, &tol);
        loop_ub = unusedU0->size[0];
        i = hcol->size[0];
        hcol->size[0] = unusedU0->size[0];
        emxEnsureCapacity_real_T(sp, hcol, i, &ad_emlrtRTEI);
        for (i = 0; i < loop_ub; i++) {
          hcol->data[i] = unusedU0->data[i] * tol;
        }

        if (1 > unusedU1->size[1]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, unusedU1->size[1], &x_emlrtBCI, sp);
        }

        if (1 > b_s->size[0]) {
          emlrtDynamicBoundsCheckR2012b(1, 1, b_s->size[0], &y_emlrtBCI, sp);
        }

        emxInit_real_T(sp, &hrow, 2, &bd_emlrtRTEI, true);
        tol = b_s->data[0];
        st.site = &bb_emlrtRSI;
        b_sqrt(&st, &tol);
        loop_ub = unusedU1->size[0];
        i = hrow->size[0] * hrow->size[1];
        hrow->size[0] = 1;
        hrow->size[1] = unusedU1->size[0];
        emxEnsureCapacity_real_T(sp, hrow, i, &bd_emlrtRTEI);
        for (i = 0; i < loop_ub; i++) {
          hrow->data[i] = unusedU1->data[i] * tol;
        }

        filter_center[0] = a->size[0];
        start[0] = 0.0;
        filter_center[1] = static_cast<int32_T>(outSizeT[1]);
        start[1] = static_cast<int32_T>(startT[1]);
        filter_center[2] = static_cast<int32_T>(outSizeT[2]);
        k = static_cast<int32_T>(startT[2]);
        start[2] = k;
        st.site = &cb_emlrtRSI;
        i = x->size[0];
        x->size[0] = hrow->size[1];
        emxEnsureCapacity_boolean_T(&st, x, i, &tc_emlrtRTEI);
        loop_ub = hrow->size[1];
        for (i = 0; i < loop_ub; i++) {
          x->data[i] = (hrow->data[i] != 0.0);
        }

        n = x->size[0];
        for (idx = 0; idx < n; idx++) {
          if (x->data[idx]) {
            i = idx + 1;
            if ((i < 1) || (i > hrow->size[1])) {
              emlrtDynamicBoundsCheckR2012b(i, 1, hrow->size[1], &ab_emlrtBCI,
                &st);
            }
          }
        }

        i = x->size[0];
        x->size[0] = hrow->size[1];
        emxEnsureCapacity_boolean_T(&st, x, i, &tc_emlrtRTEI);
        loop_ub = hrow->size[1];
        for (i = 0; i < loop_ub; i++) {
          x->data[i] = (hrow->data[i] != 0.0);
        }

        n = x->size[0] - 1;
        nz = 0;
        for (idx = 0; idx <= n; idx++) {
          if (x->data[idx]) {
            nz++;
          }
        }

        i = r1->size[0];
        r1->size[0] = nz;
        emxEnsureCapacity_int32_T(&st, r1, i, &ed_emlrtRTEI);
        nz = 0;
        for (idx = 0; idx <= n; idx++) {
          if (x->data[idx]) {
            r1->data[nz] = idx + 1;
            nz++;
          }
        }

        b_st.site = &ed_emlrtRSI;
        i = nonzero_h->size[0];
        nonzero_h->size[0] = r1->size[0];
        emxEnsureCapacity_real_T(&b_st, nonzero_h, i, &fd_emlrtRTEI);
        loop_ub = r1->size[0];
        for (i = 0; i < loop_ub; i++) {
          nonzero_h->data[i] = hrow->data[r1->data[i] - 1];
        }

        emxInit_boolean_T(&b_st, &b_connb, 2, &yc_emlrtRTEI, true);
        i = b_connb->size[0] * b_connb->size[1];
        b_connb->size[0] = 1;
        b_connb->size[1] = hrow->size[1];
        emxEnsureCapacity_boolean_T(&b_st, b_connb, i, &yc_emlrtRTEI);
        loop_ub = hrow->size[0] * hrow->size[1];
        for (i = 0; i < loop_ub; i++) {
          b_connb->data[i] = (hrow->data[i] != 0.0);
        }

        overflow = false;
        if (static_cast<real_T>(r1->size[0]) / static_cast<real_T>(hrow->size[1])
            > 0.05) {
          overflow = true;
        }

        tooBig = true;
        i = eml_ndims_varsized(*(int32_T (*)[3])a->size);
        for (idx = 0; idx < i; idx++) {
          if ((!tooBig) || (!(filter_center[idx] > 65500.0))) {
            tooBig = false;
          }
        }

        if (overflow && (!tooBig)) {
          overflow = true;
        } else {
          overflow = false;
        }

        c_st.site = &fd_emlrtRSI;
        i = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
        varargin_1->size[0] = a->size[0];
        varargin_1->size[1] = static_cast<int32_T>(outSizeT[1]);
        varargin_1->size[2] = static_cast<int32_T>(outSizeT[2]);
        emxEnsureCapacity_real_T(&c_st, varargin_1, i, &cd_emlrtRTEI);
        if (overflow) {
          d_st.site = &gd_emlrtRSI;
          padSizeT[0] = a->size[0];
          padSizeT[1] = a->size[1];
          padSizeT[2] = a->size[2];
          connDimsT[0] = hrow->size[0];
          connDimsT[1] = hrow->size[1];
          ippfilter_real64(&a->data[0], &varargin_1->data[0], filter_center,
                           static_cast<real_T>(eml_ndims_varsized(*(int32_T (*)
            [3])a->size)), padSizeT, &hrow->data[0], connDimsT, true);
        } else {
          d_st.site = &hd_emlrtRSI;
          padSizeT[0] = a->size[0];
          padSizeT[1] = a->size[1];
          padSizeT[2] = a->size[2];
          connDimsT[0] = b_connb->size[0];
          connDimsT[1] = b_connb->size[1];
          imfilter_real64(&a->data[0], &varargin_1->data[0], 3.0, filter_center,
                          static_cast<real_T>(eml_ndims_varsized(*(int32_T (*)[3])
            a->size)), padSizeT, &nonzero_h->data[0], static_cast<real_T>
                          (r1->size[0]), &b_connb->data[0], 2.0, connDimsT,
                          start, 3.0, true, true);
        }

        emxFree_boolean_T(&b_connb);
        emxFree_real_T(&hrow);
        start[0] = static_cast<int32_T>(startT[0]);
        start[1] = 0.0;
        start[2] = k;
        st.site = &db_emlrtRSI;
        i = x->size[0];
        x->size[0] = hcol->size[0];
        emxEnsureCapacity_boolean_T(&st, x, i, &tc_emlrtRTEI);
        loop_ub = hcol->size[0];
        for (i = 0; i < loop_ub; i++) {
          x->data[i] = (hcol->data[i] != 0.0);
        }

        n = x->size[0];
        for (idx = 0; idx < n; idx++) {
          if (x->data[idx]) {
            i = idx + 1;
            if ((i < 1) || (i > hcol->size[0])) {
              emlrtDynamicBoundsCheckR2012b(i, 1, hcol->size[0], &ab_emlrtBCI,
                &st);
            }
          }
        }

        i = x->size[0];
        x->size[0] = hcol->size[0];
        emxEnsureCapacity_boolean_T(&st, x, i, &tc_emlrtRTEI);
        loop_ub = hcol->size[0];
        for (i = 0; i < loop_ub; i++) {
          x->data[i] = (hcol->data[i] != 0.0);
        }

        n = x->size[0] - 1;
        nz = 0;
        for (idx = 0; idx <= n; idx++) {
          if (x->data[idx]) {
            nz++;
          }
        }

        emxInit_int32_T(&st, &r2, 1, &tc_emlrtRTEI, true);
        i = r2->size[0];
        r2->size[0] = nz;
        emxEnsureCapacity_int32_T(&st, r2, i, &gd_emlrtRTEI);
        nz = 0;
        for (idx = 0; idx <= n; idx++) {
          if (x->data[idx]) {
            r2->data[nz] = idx + 1;
            nz++;
          }
        }

        b_st.site = &ed_emlrtRSI;
        i = nonzero_h->size[0];
        nonzero_h->size[0] = r2->size[0];
        emxEnsureCapacity_real_T(&b_st, nonzero_h, i, &fd_emlrtRTEI);
        loop_ub = r2->size[0];
        for (i = 0; i < loop_ub; i++) {
          nonzero_h->data[i] = hcol->data[r2->data[i] - 1];
        }

        i = x->size[0];
        x->size[0] = hcol->size[0];
        emxEnsureCapacity_boolean_T(&b_st, x, i, &yc_emlrtRTEI);
        loop_ub = hcol->size[0];
        for (i = 0; i < loop_ub; i++) {
          x->data[i] = (hcol->data[i] != 0.0);
        }

        overflow = false;
        if (static_cast<real_T>(r2->size[0]) / static_cast<real_T>(hcol->size[0])
            > 0.05) {
          overflow = true;
        }

        tooBig = true;
        i = eml_ndims_varsized(*(int32_T (*)[3])varargin_1->size);
        for (idx = 0; idx < i; idx++) {
          if ((!tooBig) || (!(outSizeT[idx] > 65500.0))) {
            tooBig = false;
          }
        }

        if (overflow && (!tooBig)) {
          overflow = true;
        } else {
          overflow = false;
        }

        c_st.site = &fd_emlrtRSI;
        i = a->size[0] * a->size[1] * a->size[2];
        a->size[0] = varargin_1->size[0];
        a->size[1] = varargin_1->size[1];
        a->size[2] = varargin_1->size[2];
        emxEnsureCapacity_real_T(&c_st, a, i, &hd_emlrtRTEI);
        loop_ub = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
        for (i = 0; i < loop_ub; i++) {
          a->data[i] = varargin_1->data[i];
        }

        i = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
        varargin_1->size[0] = static_cast<int32_T>(outSizeT[0]);
        varargin_1->size[1] = static_cast<int32_T>(outSizeT[1]);
        varargin_1->size[2] = static_cast<int32_T>(outSizeT[2]);
        emxEnsureCapacity_real_T(&c_st, varargin_1, i, &cd_emlrtRTEI);
        if (overflow) {
          d_st.site = &gd_emlrtRSI;
          padSizeT[0] = a->size[0];
          padSizeT[1] = a->size[1];
          padSizeT[2] = a->size[2];
          connDimsT[0] = hcol->size[0];
          connDimsT[1] = 1.0;
          ippfilter_real64(&a->data[0], &varargin_1->data[0], outSizeT,
                           static_cast<real_T>(eml_ndims_varsized(*(int32_T (*)
            [3])a->size)), padSizeT, &hcol->data[0], connDimsT, true);
        } else {
          d_st.site = &hd_emlrtRSI;
          padSizeT[0] = a->size[0];
          padSizeT[1] = a->size[1];
          padSizeT[2] = a->size[2];
          connDimsT[0] = x->size[0];
          connDimsT[1] = 1.0;
          imfilter_real64(&a->data[0], &varargin_1->data[0], 3.0, outSizeT,
                          static_cast<real_T>(eml_ndims_varsized(*(int32_T (*)[3])
            a->size)), padSizeT, &nonzero_h->data[0], static_cast<real_T>
                          (r2->size[0]), &x->data[0], 2.0, connDimsT, start, 3.0,
                          true, true);
        }

        emxFree_int32_T(&r2);
        emxFree_real_T(&hcol);
      } else {
        st.site = &eb_emlrtRSI;
        padImage(&st, varargin_1, startT, a);
        st.site = &fb_emlrtRSI;
        if (((varargin_2->size[0] == 1) || (varargin_2->size[1] == 1)) &&
            (varargin_2->size[2] == 1) && ((varargin_2->size[0] == 1) ||
             (varargin_2->size[1] == 1))) {
          i = x->size[0];
          x->size[0] = varargin_2->size[0] * varargin_2->size[1];
          emxEnsureCapacity_boolean_T(&st, x, i, &tc_emlrtRTEI);
          loop_ub = varargin_2->size[0] * varargin_2->size[1];
          for (i = 0; i < loop_ub; i++) {
            x->data[i] = (varargin_2->data[i] != 0.0);
          }

          n = x->size[0] - 1;
          nz = 0;
          for (idx = 0; idx <= n; idx++) {
            if (x->data[idx]) {
              nz++;
            }
          }

          i = nonzero_h->size[0];
          nonzero_h->size[0] = nz;
          emxEnsureCapacity_real_T(&st, nonzero_h, i, &vc_emlrtRTEI);
          nz = 0;
          for (idx = 0; idx <= n; idx++) {
            if (x->data[idx]) {
              i = varargin_2->size[0] * varargin_2->size[1];
              k = idx + 1;
              if ((k < 1) || (k > i)) {
                emlrtDynamicBoundsCheckR2012b(k, 1, i, &t_emlrtBCI, &st);
              }

              nonzero_h->data[nz] = varargin_2->data[k - 1];
              nz++;
            }
          }
        } else {
          b_st.site = &id_emlrtRSI;
          b_indexShapeCheck(&b_st, *(int32_T (*)[3])varargin_2->size, *(int32_T
            (*)[3])varargin_2->size);
          n = varargin_2->size[0] * (varargin_2->size[1] * varargin_2->size[2])
            - 1;
          nz = 0;
          for (idx = 0; idx <= n; idx++) {
            if (varargin_2->data[idx] != 0.0) {
              nz++;
            }
          }

          i = r1->size[0];
          r1->size[0] = nz;
          emxEnsureCapacity_int32_T(&st, r1, i, &vc_emlrtRTEI);
          nz = 0;
          for (idx = 0; idx <= n; idx++) {
            if (varargin_2->data[idx] != 0.0) {
              r1->data[nz] = idx + 1;
              nz++;
            }
          }

          nz = varargin_2->size[0] * varargin_2->size[1] * varargin_2->size[2];
          i = nonzero_h->size[0];
          nonzero_h->size[0] = r1->size[0];
          emxEnsureCapacity_real_T(&st, nonzero_h, i, &wc_emlrtRTEI);
          loop_ub = r1->size[0];
          for (i = 0; i < loop_ub; i++) {
            if ((r1->data[i] < 1) || (r1->data[i] > nz)) {
              emlrtDynamicBoundsCheckR2012b(r1->data[i], 1, nz, &u_emlrtBCI, &st);
            }

            nonzero_h->data[i] = varargin_2->data[r1->data[i] - 1];
          }
        }

        emxInit_boolean_T(&st, &connb, 3, &yc_emlrtRTEI, true);
        b_st.site = &ed_emlrtRSI;
        i = connb->size[0] * connb->size[1] * connb->size[2];
        connb->size[0] = varargin_2->size[0];
        connb->size[1] = varargin_2->size[1];
        connb->size[2] = varargin_2->size[2];
        emxEnsureCapacity_boolean_T(&b_st, connb, i, &yc_emlrtRTEI);
        loop_ub = varargin_2->size[0] * varargin_2->size[1] * varargin_2->size[2];
        for (i = 0; i < loop_ub; i++) {
          connb->data[i] = (varargin_2->data[i] != 0.0);
        }

        overflow = false;
        if (static_cast<real_T>(nonzero_h->size[0]) / static_cast<real_T>
            ((varargin_2->size[0] * varargin_2->size[1] * varargin_2->size[2])) >
            0.05) {
          overflow = true;
        }

        tooBig = true;
        i = eml_ndims_varsized(*(int32_T (*)[3])a->size);
        for (idx = 0; idx < i; idx++) {
          if ((!tooBig) || (!(outSizeT[idx] > 65500.0))) {
            tooBig = false;
          }
        }

        if (overflow && (eml_ndims_varsized(*(int32_T (*)[3])varargin_2->size) ==
                         2) && (!tooBig)) {
          overflow = true;
        } else {
          overflow = false;
        }

        c_st.site = &fd_emlrtRSI;
        i = varargin_1->size[0] * varargin_1->size[1] * varargin_1->size[2];
        varargin_1->size[0] = static_cast<int32_T>(outSizeT[0]);
        varargin_1->size[1] = static_cast<int32_T>(outSizeT[1]);
        varargin_1->size[2] = static_cast<int32_T>(outSizeT[2]);
        emxEnsureCapacity_real_T(&c_st, varargin_1, i, &cd_emlrtRTEI);
        if (overflow) {
          d_st.site = &gd_emlrtRSI;
          padSizeT[0] = a->size[0];
          filter_center[0] = varargin_2->size[0];
          padSizeT[1] = a->size[1];
          filter_center[1] = varargin_2->size[1];
          padSizeT[2] = a->size[2];
          filter_center[2] = varargin_2->size[2];
          ippfilter_real64(&a->data[0], &varargin_1->data[0], outSizeT,
                           static_cast<real_T>(eml_ndims_varsized(*(int32_T (*)
            [3])a->size)), padSizeT, &varargin_2->data[0], filter_center, true);
        } else {
          d_st.site = &hd_emlrtRSI;
          padSizeT[0] = a->size[0];
          filter_center[0] = connb->size[0];
          padSizeT[1] = a->size[1];
          filter_center[1] = connb->size[1];
          padSizeT[2] = a->size[2];
          filter_center[2] = connb->size[2];
          imfilter_real64(&a->data[0], &varargin_1->data[0], 3.0, outSizeT,
                          static_cast<real_T>(eml_ndims_varsized(*(int32_T (*)[3])
            a->size)), padSizeT, &nonzero_h->data[0], static_cast<real_T>
                          (nonzero_h->size[0]), &connb->data[0],
                          static_cast<real_T>(eml_ndims_varsized(*(int32_T (*)[3])
            connb->size)), filter_center, startT, 3.0, true, true);
        }

        emxFree_boolean_T(&connb);
      }

      emxFree_real_T(&c_s);
      emxFree_boolean_T(&x);
      emxFree_int32_T(&r1);
      emxFree_real_T(&nonzero_h);
      emxFree_real_T(&b_s);
      emxFree_real_T(&unusedU1);
      emxFree_real_T(&s);
      emxFree_real_T(&unusedU0);
      emxFree_real_T(&a);
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (imfilter.cpp) */
