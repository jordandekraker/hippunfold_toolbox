/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * indexShapeCheck.cpp
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "indexShapeCheck.h"
#include "laplace_iters.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 43,  /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 51, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 56, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo ld_emlrtRSI = { 33, /* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pathName */
};

static emlrtRTEInfo i_emlrtRTEI = { 121,/* lineNo */
  5,                                   /* colNo */
  "errOrWarnIf",                       /* fName */
  "/export01/local/matlab19b/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"/* pName */
};

/* Function Declarations */
static boolean_T checkSameShape(const int32_T size1[3]);
static boolean_T isExtendedVector(const int32_T sz[3]);

/* Function Definitions */
static boolean_T checkSameShape(const int32_T size1[3])
{
  boolean_T c;
  if (size1[0] == 1) {
    c = true;
  } else {
    c = false;
    if (size1[1] != 1) {
      c = true;
    }
  }

  if (c || (size1[2] != 1)) {
    c = true;
  } else {
    c = false;
  }

  return c;
}

static boolean_T isExtendedVector(const int32_T sz[3])
{
  boolean_T b;
  boolean_T guard1 = false;
  b = false;
  b = ((sz[0] != 1) || b);
  guard1 = false;
  if (sz[1] != 1) {
    if (b) {
      b = false;
    } else {
      b = true;
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 && (sz[2] != 1)) {
    if (b) {
      b = false;
    } else {
      b = true;
    }
  }

  return b;
}

void b_indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[3], const
  int32_T indexSize[3])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (isExtendedVector(matrixSize)) {
    st.site = &jd_emlrtRSI;
    if (checkSameShape(matrixSize)) {
      emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
        "Coder:FE:PotentialMatrixMatrix_MM_Logical1",
        "Coder:FE:PotentialMatrixMatrix_MM_Logical1", 0);
    }
  } else {
    if (isExtendedVector(indexSize)) {
      st.site = &kd_emlrtRSI;
      if (checkSameShape(indexSize)) {
        emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
          "Coder:FE:PotentialMatrixMatrix_MM_Logical2",
          "Coder:FE:PotentialMatrixMatrix_MM_Logical2", 0);
      }
    }
  }
}

void c_indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[3],
  int32_T indexSize)
{
  boolean_T c;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (isExtendedVector(matrixSize) && (indexSize != 1)) {
    if (((matrixSize[0] == 1) != (indexSize == 1)) || (matrixSize[1] != 1) ||
        (matrixSize[2] != 1)) {
      c = true;
    } else {
      c = false;
    }

    st.site = &ld_emlrtRSI;
    if (c) {
      emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
        "Coder:FE:PotentialMatrixMatrix_MV", "Coder:FE:PotentialMatrixMatrix_MV",
        0);
    }
  }
}

void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize, const int32_T
                     indexSize[2])
{
  boolean_T c;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if ((matrixSize != 1) || (indexSize[1] == 1)) {
    c = false;
  } else {
    c = true;
  }

  st.site = &u_emlrtRSI;
  if (c) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
      "Coder:FE:PotentialVectorVector", "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.cpp) */
