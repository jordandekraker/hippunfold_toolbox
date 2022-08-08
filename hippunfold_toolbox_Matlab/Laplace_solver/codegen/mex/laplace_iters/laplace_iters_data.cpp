/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * laplace_iters_data.cpp
 *
 * Code generation for function 'laplace_iters_data'
 *
 */

/* Include files */
#include "laplace_iters_data.h"
#include "laplace_iters.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "laplace_iters",                     /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 4209757260U, 1383518620U, 1328961664U, 2918865455U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo m_emlrtRSI = { 96,         /* lineNo */
  "sumprod",                           /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

emlrtRSInfo n_emlrtRSI = { 124,        /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo o_emlrtRSI = { 184,        /* lineNo */
  "colMajorFlatIter",                  /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

emlrtRSInfo p_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo cc_emlrtRSI = { 9,         /* lineNo */
  "int",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/int.m"/* pathName */
};

emlrtRSInfo dc_emlrtRSI = { 8,         /* lineNo */
  "majority",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/majority.m"/* pathName */
};

emlrtRSInfo ec_emlrtRSI = { 31,        /* lineNo */
  "infocheck",                         /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/infocheck.m"/* pathName */
};

emlrtRSInfo hc_emlrtRSI = { 174,       /* lineNo */
  "ceval_xgesvd",                      /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

emlrtRSInfo ic_emlrtRSI = { 117,       /* lineNo */
  "ceval_xgesvd",                      /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

emlrtRSInfo jc_emlrtRSI = { 110,       /* lineNo */
  "ceval_xgesvd",                      /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

emlrtRSInfo kc_emlrtRSI = { 59,        /* lineNo */
  "ceval_xgesvd",                      /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/+lapack/xgesvd.m"/* pathName */
};

emlrtRSInfo lc_emlrtRSI = { 14,        /* lineNo */
  "max",                               /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

emlrtRSInfo mc_emlrtRSI = { 20,        /* lineNo */
  "minOrMax",                          /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo nc_emlrtRSI = { 45,        /* lineNo */
  "unaryOrBinaryDispatch",             /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

emlrtRSInfo oc_emlrtRSI = { 145,       /* lineNo */
  "unaryMinOrMax",                     /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo pc_emlrtRSI = { 1019,      /* lineNo */
  "maxRealVectorOmitNaN",              /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo qc_emlrtRSI = { 932,       /* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo rc_emlrtRSI = { 924,       /* lineNo */
  "minOrMaxRealVector",                /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo sc_emlrtRSI = { 975,       /* lineNo */
  "findFirst",                         /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo tc_emlrtRSI = { 992,       /* lineNo */
  "minOrMaxRealVectorKernel",          /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pathName */
};

emlrtRSInfo dd_emlrtRSI = { 827,       /* lineNo */
  "ReplicatePad",                      /* fcnName */
  "/export01/local/matlab19b/toolbox/images/images/eml/padarray.m"/* pathName */
};

emlrtRTEInfo b_emlrtRTEI = { 26,       /* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

emlrtRTEInfo c_emlrtRTEI = { 95,       /* lineNo */
  27,                                  /* colNo */
  "unaryMinOrMax",                     /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/unaryMinOrMax.m"/* pName */
};

emlrtRTEInfo d_emlrtRTEI = { 30,       /* lineNo */
  27,                                  /* colNo */
  "nan_sum_or_mean",                   /* fName */
  "/export01/local/matlab19b/toolbox/stats/eml/private/nan_sum_or_mean.m"/* pName */
};

emlrtRTEInfo e_emlrtRTEI = { 43,       /* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pName */
};

emlrtRTEInfo j_emlrtRTEI = { 47,       /* lineNo */
  19,                                  /* colNo */
  "allOrAny",                          /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/allOrAny.m"/* pName */
};

emlrtRTEInfo ab_emlrtRTEI = { 17,      /* lineNo */
  13,                                  /* colNo */
  "isnan",                             /* fName */
  "/export01/local/matlab19b/toolbox/eml/lib/matlab/elmat/isnan.m"/* pName */
};

/* End of code generation (laplace_iters_data.cpp) */
