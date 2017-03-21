//
// Created by 윤중현 on 2017. 3. 4..
//

#include "Matrix.h"

GLfloat Matrix::sTemp[] = {0.0f,};

static inline void mx4transform(GLfloat x, GLfloat y, GLfloat z, GLfloat w, const GLfloat* pM, GLfloat* pDest)
{
    pDest[0] = pM[0 + 4 * 0] * x + pM[0 + 4 * 1] * y + pM[0 + 4 * 2] * z + pM[0 + 4 * 3] * w;
    pDest[1] = pM[1 + 4 * 0] * x + pM[1 + 4 * 1] * y + pM[1 + 4 * 2] * z + pM[1 + 4 * 3] * w;
    pDest[2] = pM[2 + 4 * 0] * x + pM[2 + 4 * 1] * y + pM[2 + 4 * 2] * z + pM[2 + 4 * 3] * w;
    pDest[3] = pM[3 + 4 * 0] * x + pM[3 + 4 * 1] * y + pM[3 + 4 * 2] * z + pM[3 + 4 * 3] * w;
    
//    GLfloat pd[4];
//    memcpy(pd + 0, pDest, sizeof(GLfloat) * 4);
}

/**
 * Multiplies two 4x4 matrices together and stores the result in a third 4x4 matrix. In matrix notation: result = lhs x rhs.
 *
 * 두 개의 4x4 행렬을 곱하고 그 결과를 세 번째 4x4 행렬에 저장합니다. 행렬 표기법에서 : result = lhs x rhs.
 */
void Matrix::multiplyMM(GLfloat *result, GLuint resultOffset, const GLfloat *lhs, GLuint lhsOffset, const GLfloat *rhs, GLuint rhsOffset)
{
    for (int i = 0; i < 4; i++) {
        const GLfloat rhs_i0 = rhs[I(i, 0) + rhsOffset];
        GLfloat ri0 = lhs[I(0, 0) + lhsOffset] * rhs_i0;
        GLfloat ri1 = lhs[I(0, 1) + lhsOffset] * rhs_i0;
        GLfloat ri2 = lhs[I(0, 2) + lhsOffset] * rhs_i0;
        GLfloat ri3 = lhs[I(0, 3) + lhsOffset] * rhs_i0;
        for (int j = 1; j < 4; j++) {
            const GLfloat rhs_ij = rhs[I(i, j) + rhsOffset];
            ri0 += lhs[I(j, 0) + lhsOffset] * rhs_ij;
            ri1 += lhs[I(j, 1) + lhsOffset] * rhs_ij;
            ri2 += lhs[I(j, 2) + lhsOffset] * rhs_ij;
            ri3 += lhs[I(j, 3) + lhsOffset] * rhs_ij;
        }
        result[I(i, 0) + resultOffset] = ri0;
        result[I(i, 1) + resultOffset] = ri1;
        result[I(i, 2) + resultOffset] = ri2;
        result[I(i, 3) + resultOffset] = ri3;
    }
}

/**
 * Multiplies a 4 element vector by a 4x4 matrix and stores the result in a 4-element column vector. In matrix notation: result = lhs x rhs
 *
 * 4 요소 벡터에 4x4 행렬을 곱하고 그 결과를 4 요소 열 벡터에 저장합니다. 행렬 표기법에서 : result = lhs x rhs
 */
void Matrix::multiplyMV(GLfloat *resultVec, GLuint resultVecOffset, GLfloat *lhsMat, GLuint lhsMatOffset, GLfloat *rhsVec, GLuint rhsVecOffset)
{
    resultVec += resultVecOffset;
    lhsMat += lhsMatOffset;
    rhsVec += rhsVecOffset;
    
//    GLfloat result[16];
//    memcpy(result + 0, resultVec, sizeof(GLfloat) * 16);
//    
//    GLfloat lhs[16];
//    memcpy(lhs + 0, lhsMat, sizeof(GLfloat) * 16);
//    
//    GLfloat rhs[16];
//    memcpy(rhs + 0, rhsVec, sizeof(GLfloat) * 16);

    mx4transform(rhsVec[0], rhsVec[1], rhsVec[2], rhsVec[3], lhsMat, resultVec);
}

/**
 * Transposes a 4 x 4 matrix.
 */
void Matrix::transposeM(GLfloat *mTrans, GLuint mTransOffset, const GLfloat *m, GLuint mOffset)
{
    for (int i = 0; i < 4; i++) {
        int mBase = i * 4 + mOffset;
        mTrans[i + mTransOffset] = m[mBase];
        mTrans[i + 4 + mTransOffset] = m[mBase + 1];
        mTrans[i + 8 + mTransOffset] = m[mBase + 2];
        mTrans[i + 12 + mTransOffset] = m[mBase + 3];
    }
}

/**
 * Inverts a 4 x 4 matrix.
 *
 * 4 x 4 행렬을 반전합니다.
 */
bool Matrix::invertM(GLfloat *mInv, GLuint mInvOffset, const GLfloat *m, GLuint mOffset)
{
    // Invert a 4 x 4 matrix using Cramer's Rule

    // transpose matrix
    const GLfloat src0 = m[mOffset + 0];
    const GLfloat src4 = m[mOffset + 1];
    const GLfloat src8 = m[mOffset + 2];
    const GLfloat src12 = m[mOffset + 3];

    const GLfloat src1 = m[mOffset + 4];
    const GLfloat src5 = m[mOffset + 5];
    const GLfloat src9 = m[mOffset + 6];
    const GLfloat src13 = m[mOffset + 7];

    const GLfloat src2 = m[mOffset + 8];
    const GLfloat src6 = m[mOffset + 9];
    const GLfloat src10 = m[mOffset + 10];
    const GLfloat src14 = m[mOffset + 11];

    const GLfloat src3 = m[mOffset + 12];
    const GLfloat src7 = m[mOffset + 13];
    const GLfloat src11 = m[mOffset + 14];
    const GLfloat src15 = m[mOffset + 15];

    // calculate pairs for first 8 elements (cofactors)
    const GLfloat atmp0 = src10 * src15;
    const GLfloat atmp1 = src11 * src14;
    const GLfloat atmp2 = src9 * src15;
    const GLfloat atmp3 = src11 * src13;
    const GLfloat atmp4 = src9 * src14;
    const GLfloat atmp5 = src10 * src13;
    const GLfloat atmp6 = src8 * src15;
    const GLfloat atmp7 = src11 * src12;
    const GLfloat atmp8 = src8 * src14;
    const GLfloat atmp9 = src10 * src12;
    const GLfloat atmp10 = src8 * src13;
    const GLfloat atmp11 = src9 * src12;

    // calculate first 8 elements (cofactors)
    const GLfloat dst0 = (atmp0 * src5 + atmp3 * src6 + atmp4 * src7)
                         - (atmp1 * src5 + atmp2 * src6 + atmp5 * src7);
    const GLfloat dst1 = (atmp1 * src4 + atmp6 * src6 + atmp9 * src7)
                         - (atmp0 * src4 + atmp7 * src6 + atmp8 * src7);
    const GLfloat dst2 = (atmp2 * src4 + atmp7 * src5 + atmp10 * src7)
                         - (atmp3 * src4 + atmp6 * src5 + atmp11 * src7);
    const GLfloat dst3 = (atmp5 * src4 + atmp8 * src5 + atmp11 * src6)
                         - (atmp4 * src4 + atmp9 * src5 + atmp10 * src6);
    const GLfloat dst4 = (atmp1 * src1 + atmp2 * src2 + atmp5 * src3)
                         - (atmp0 * src1 + atmp3 * src2 + atmp4 * src3);
    const GLfloat dst5 = (atmp0 * src0 + atmp7 * src2 + atmp8 * src3)
                         - (atmp1 * src0 + atmp6 * src2 + atmp9 * src3);
    const GLfloat dst6 = (atmp3 * src0 + atmp6 * src1 + atmp11 * src3)
                         - (atmp2 * src0 + atmp7 * src1 + atmp10 * src3);
    const GLfloat dst7 = (atmp4 * src0 + atmp9 * src1 + atmp10 * src2)
                         - (atmp5 * src0 + atmp8 * src1 + atmp11 * src2);

    // calculate pairs for second 8 elements (cofactors)
    const GLfloat btmp0 = src2 * src7;
    const GLfloat btmp1 = src3 * src6;
    const GLfloat btmp2 = src1 * src7;
    const GLfloat btmp3 = src3 * src5;
    const GLfloat btmp4 = src1 * src6;
    const GLfloat btmp5 = src2 * src5;
    const GLfloat btmp6 = src0 * src7;
    const GLfloat btmp7 = src3 * src4;
    const GLfloat btmp8 = src0 * src6;
    const GLfloat btmp9 = src2 * src4;
    const GLfloat btmp10 = src0 * src5;
    const GLfloat btmp11 = src1 * src4;

    // calculate second 8 elements (cofactors)
    const GLfloat dst8 = (btmp0 * src13 + btmp3 * src14 + btmp4 * src15)
                         - (btmp1 * src13 + btmp2 * src14 + btmp5 * src15);
    const GLfloat dst9 = (btmp1 * src12 + btmp6 * src14 + btmp9 * src15)
                         - (btmp0 * src12 + btmp7 * src14 + btmp8 * src15);
    const GLfloat dst10 = (btmp2 * src12 + btmp7 * src13 + btmp10 * src15)
                          - (btmp3 * src12 + btmp6 * src13 + btmp11 * src15);
    const GLfloat dst11 = (btmp5 * src12 + btmp8 * src13 + btmp11 * src14)
                          - (btmp4 * src12 + btmp9 * src13 + btmp10 * src14);
    const GLfloat dst12 = (btmp2 * src10 + btmp5 * src11 + btmp1 * src9)
                          - (btmp4 * src11 + btmp0 * src9 + btmp3 * src10);
    const GLfloat dst13 = (btmp8 * src11 + btmp0 * src8 + btmp7 * src10)
                          - (btmp6 * src10 + btmp9 * src11 + btmp1 * src8);
    const GLfloat dst14 = (btmp6 * src9 + btmp11 * src11 + btmp3 * src8)
                          - (btmp10 * src11 + btmp2 * src8 + btmp7 * src9);
    const GLfloat dst15 = (btmp10 * src10 + btmp4 * src8 + btmp9 * src9)
                          - (btmp8 * src9 + btmp11 * src10 + btmp5 * src8);

    // calculate determinant
    const GLfloat det =
            src0 * dst0 + src1 * dst1 + src2 * dst2 + src3 * dst3;

    if (det == 0.0f) {
        return false;
    }

    // calculate matrix inverse
    const GLfloat invdet = 1.0f / det;
    mInv[mInvOffset] = dst0 * invdet;
    mInv[1 + mInvOffset] = dst1 * invdet;
    mInv[2 + mInvOffset] = dst2 * invdet;
    mInv[3 + mInvOffset] = dst3 * invdet;

    mInv[4 + mInvOffset] = dst4 * invdet;
    mInv[5 + mInvOffset] = dst5 * invdet;
    mInv[6 + mInvOffset] = dst6 * invdet;
    mInv[7 + mInvOffset] = dst7 * invdet;

    mInv[8 + mInvOffset] = dst8 * invdet;
    mInv[9 + mInvOffset] = dst9 * invdet;
    mInv[10 + mInvOffset] = dst10 * invdet;
    mInv[11 + mInvOffset] = dst11 * invdet;

    mInv[12 + mInvOffset] = dst12 * invdet;
    mInv[13 + mInvOffset] = dst13 * invdet;
    mInv[14 + mInvOffset] = dst14 * invdet;
    mInv[15 + mInvOffset] = dst15 * invdet;

    return true;
}

/**
 * Computes an orthographic projection matrix.
 *
 * 직교 투영 행렬을 계산합니다.
 */
void Matrix::orthoM(GLfloat *m, GLuint mOffset, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
{
    if (left == right) {
//        throw new IllegalArgumentException("left == right");
        LOGE("Matrix::orthoM : left == right");
        return;
    }
    if (bottom == top) {
//        throw new IllegalArgumentException("bottom == top");
        LOGE("Matrix::orthoM : bottom == top");
        return;
    }
    if (near == far) {
//        throw new IllegalArgumentException("near == far");
        LOGE("Matrix::orthoM : near == far");
        return;
    }

    const GLfloat r_width = 1.0f / (right - left);
    const GLfloat r_height = 1.0f / (top - bottom);
    const GLfloat r_depth = 1.0f / (far - near);
    const GLfloat x = 2.0f * (r_width);
    const GLfloat y = 2.0f * (r_height);
    const GLfloat z = -2.0f * (r_depth);
    const GLfloat tx = -(right + left) * r_width;
    const GLfloat ty = -(top + bottom) * r_height;
    const GLfloat tz = -(far + near) * r_depth;
    m[mOffset + 0] = x;
    m[mOffset + 5] = y;
    m[mOffset + 10] = z;
    m[mOffset + 12] = tx;
    m[mOffset + 13] = ty;
    m[mOffset + 14] = tz;
    m[mOffset + 15] = 1.0f;
    m[mOffset + 1] = 0.0f;
    m[mOffset + 2] = 0.0f;
    m[mOffset + 3] = 0.0f;
    m[mOffset + 4] = 0.0f;
    m[mOffset + 6] = 0.0f;
    m[mOffset + 7] = 0.0f;
    m[mOffset + 8] = 0.0f;
    m[mOffset + 9] = 0.0f;
    m[mOffset + 11] = 0.0f;
}

/**
 * Defines a projection matrix in terms of six clip planes.
 *
 * 여섯 개의 클립면으로 프로젝션 매트릭스를 정의합니다.
 */
void Matrix::frustumM(GLfloat *m, GLuint offset, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
{
    if (left == right) {
//        throw new IllegalArgumentException("left == right");
        LOGE("Matrix::frustumM : left == right");
        return;
    }
    if (top == bottom) {
//        throw new IllegalArgumentException("top == bottom");
        LOGE("Matrix::frustumM : top == bottom");
        return;
    }
    if (near == far) {
//        throw new IllegalArgumentException("near == far");
        LOGE("Matrix::frustumM : near == far");
        return;
    }
    if (near <= 0.0f) {
//        throw new IllegalArgumentException("near <= 0.0f");
        LOGE("Matrix::frustumM : near <= 0.0f");
        return;
    }
    if (far <= 0.0f) {
//        throw new IllegalArgumentException("far <= 0.0f");
        LOGE("Matrix::frustumM : far <= 0.0f");
        return;
    }
    const GLfloat r_width  = 1.0f / (right - left);
    const GLfloat r_height = 1.0f / (top - bottom);
    const GLfloat r_depth  = 1.0f / (near - far);
    const GLfloat x = 2.0f * (near * r_width);
    const GLfloat y = 2.0f * (near * r_height);
    const GLfloat A = (right + left) * r_width;
    const GLfloat B = (top + bottom) * r_height;
    const GLfloat C = (far + near) * r_depth;
    const GLfloat D = 2.0f * (far * near * r_depth);
    m[offset + 0] = x;
    m[offset + 5] = y;
    m[offset + 8] = A;
    m[offset +  9] = B;
    m[offset + 10] = C;
    m[offset + 14] = D;
    m[offset + 11] = -1.0f;
    m[offset +  1] = 0.0f;
    m[offset +  2] = 0.0f;
    m[offset +  3] = 0.0f;
    m[offset +  4] = 0.0f;
    m[offset +  6] = 0.0f;
    m[offset +  7] = 0.0f;
    m[offset + 12] = 0.0f;
    m[offset + 13] = 0.0f;
    m[offset + 15] = 0.0f;
}

/**
 * Defines a projection matrix in terms of a field of view angle, an aspect ratio, and z clip planes.
 *
 * 시야각, 가로 세로 비율 및 z 클립면의 관점에서 투영 행렬을 정의합니다.
 */
void Matrix::perspectiveM(GLfloat *m, GLuint offset, GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar)
{
    GLfloat f = 1.0f / (GLfloat) tan(fovy * (M_PI / 360.0));
    GLfloat rangeReciprocal = 1.0f / (zNear - zFar);

    m[offset + 0] = f / aspect;
    m[offset + 1] = 0.0f;
    m[offset + 2] = 0.0f;
    m[offset + 3] = 0.0f;

    m[offset + 4] = 0.0f;
    m[offset + 5] = f;
    m[offset + 6] = 0.0f;
    m[offset + 7] = 0.0f;

    m[offset + 8] = 0.0f;
    m[offset + 9] = 0.0f;
    m[offset + 10] = (zFar + zNear) * rangeReciprocal;
    m[offset + 11] = -1.0f;

    m[offset + 12] = 0.0f;
    m[offset + 13] = 0.0f;
    m[offset + 14] = 2.0f * zFar * zNear * rangeReciprocal;
    m[offset + 15] = 0.0f;
}

/**
 * Computes the length of a vector.
 *
 * 벡터의 길이를 계산합니다.
 */
GLfloat Matrix::length(GLfloat x, GLfloat y, GLfloat z)
{
    return (GLfloat) sqrt(x * x + y * y + z * z);
}

/**
 * Sets matrix m to the identity matrix.
 *
 * 행렬 m을 단위 행렬로 설정합니다.
 */
void Matrix::setIdentityM(GLfloat *sm, GLuint smOffset)
{
    for (int i = 0; i < 16; i++) {
        sm[smOffset + i] = 0;
    }
    for (int i = 0; i < 16; i += 5) {
        sm[smOffset + i] = 1.0f;
    }
}

/**
 * Scales matrix m by x, y, and z, putting the result in sm.
 *
 * x, y, z에 의해 행렬 m을 스케일 해, 결과를 sm에 격납합니다.
 */
void Matrix::scaleM(GLfloat *sm, GLuint smOffset, const GLfloat *m, GLuint mOffset, GLfloat x, GLfloat y, GLfloat z)
{
    for (int i = 0; i < 4; i++) {
        int smi = smOffset + i;
        int mi = mOffset + i;
        sm[smi] = m[mi] * x;
        sm[4 + smi] = m[4 + mi] * y;
        sm[8 + smi] = m[8 + mi] * z;
        sm[12 + smi] = m[12 + mi];
    }
}

/**
 * Scales matrix m in place by sx, sy, and sz.
 *
 * sx, sy 및 sz에 의해 행렬 m의 위치를 조정합니다.
 */
void Matrix::scaleM(GLfloat *m, GLuint mOffset, GLfloat x, GLfloat y, GLfloat z)
{
    for (int i = 0; i < 4; i++) {
        int mi = mOffset + i;
        m[mi] *= x;
        m[4 + mi] *= y;
        m[8 + mi] *= z;
    }
}

/**
 * Translates matrix m by x, y, and z, putting the result in tm.
 *
 * 행렬 m을 x, y 및 z로 변환하여 결과를 tm에 넣습니다.
 */
void Matrix::translateM(GLfloat *tm, GLuint tmOffset, const GLfloat *m, GLuint mOffset, GLfloat x, GLfloat y, GLfloat z)
{
    for (int i = 0; i < 12; i++) {
        tm[tmOffset + i] = m[mOffset + i];
    }
    for (int i = 0; i < 4; i++) {
        int tmi = tmOffset + i;
        int mi = mOffset + i;
        tm[12 + tmi] = m[mi] * x + m[4 + mi] * y + m[8 + mi] * z + m[12 + mi];
    }
}

/**
 * Translates matrix m by x, y, and z in place.
 *
 * 행렬 m을 x, y 및 z로 변환합니다.
 */
void Matrix::translateM(GLfloat *m, GLuint mOffset, GLfloat x, GLfloat y, GLfloat z)
{
    for (int i = 0; i < 4; i++) {
        int mi = mOffset + i;
        m[12 + mi] += m[mi] * x + m[4 + mi] * y + m[8 + mi] * z;
    }
}

/**
 * Rotates matrix m by angle a (in degrees) around the axis (x, y, z).
 *
 * 축 (x, y, z) 주위의 각도 a (각도)로 행렬 m을 회전합니다.
 */
void Matrix::rotateM(GLfloat *rm, GLuint rmOffset, const GLfloat *m, GLuint mOffset, GLfloat a, GLfloat x, GLfloat y, GLfloat z)
{
    //    synchronized(sTemp) {
    Matrix::setRotateM(Matrix::sTemp, 0, a, x, y, z);
    multiplyMM(rm, rmOffset, m, mOffset, Matrix::sTemp, 0);
    //    }
}

/**
 * Rotates matrix m in place by angle a (in degrees) around the axis (x, y, z).
 *
 * 축 (x, y, z)을 중심으로 한 각도 a (각도)로 매트릭스 m을 제자리에서 회전합니다.
 */
void Matrix::rotateM(GLfloat *m, GLuint mOffset, GLfloat a, GLfloat x, GLfloat y, GLfloat z)
{
//    synchronized(sTemp) {
        Matrix::setRotateM(Matrix::sTemp, 0, a, x, y, z);
        Matrix::multiplyMM(Matrix::sTemp, 16, m, mOffset, Matrix::sTemp, 0);
//        System.arraycopy(sTemp, 16, m, mOffset, 16);
        memcpy(m + mOffset, Matrix::sTemp + 16, sizeof(GLfloat) * 16);
//    }
}

/**
 * Creates a matrix for rotation by angle a (in degrees) around the axis (x, y, z).
 *
 * 축 (x, y, z)을 중심으로하는 각도 a (각도)로 회전하는 행렬을 작성합니다.
 */
void Matrix::setRotateM(GLfloat *rm, GLuint rmOffset, GLfloat a, GLfloat x, GLfloat y, GLfloat z)
{
    rm[rmOffset + 3] = 0;
    rm[rmOffset + 7] = 0;
    rm[rmOffset + 11] = 0;
    rm[rmOffset + 12] = 0;
    rm[rmOffset + 13] = 0;
    rm[rmOffset + 14] = 0;
    rm[rmOffset + 15] = 1;
    a *= (GLfloat) (M_PI / 180.0f);
    GLfloat s = (GLfloat) sin(a);
    GLfloat c = (GLfloat) cos(a);
    if (1.0f == x && 0.0f == y && 0.0f == z) {
        rm[rmOffset + 5] = c;
        rm[rmOffset + 10] = c;
        rm[rmOffset + 6] = s;
        rm[rmOffset + 9] = -s;
        rm[rmOffset + 1] = 0;
        rm[rmOffset + 2] = 0;
        rm[rmOffset + 4] = 0;
        rm[rmOffset + 8] = 0;
        rm[rmOffset + 0] = 1;
    } else if (0.0f == x && 1.0f == y && 0.0f == z) {
        rm[rmOffset + 0] = c;
        rm[rmOffset + 10] = c;
        rm[rmOffset + 8] = s;
        rm[rmOffset + 2] = -s;
        rm[rmOffset + 1] = 0;
        rm[rmOffset + 4] = 0;
        rm[rmOffset + 6] = 0;
        rm[rmOffset + 9] = 0;
        rm[rmOffset + 5] = 1;
    } else if (0.0f == x && 0.0f == y && 1.0f == z) {
        rm[rmOffset + 0] = c;
        rm[rmOffset + 5] = c;
        rm[rmOffset + 1] = s;
        rm[rmOffset + 4] = -s;
        rm[rmOffset + 2] = 0;
        rm[rmOffset + 6] = 0;
        rm[rmOffset + 8] = 0;
        rm[rmOffset + 9] = 0;
        rm[rmOffset + 10] = 1;
    } else {
        GLfloat len = length(x, y, z);
        if (1.0f != len) {
            GLfloat recipLen = 1.0f / len;
            x *= recipLen;
            y *= recipLen;
            z *= recipLen;
        }
        GLfloat nc = 1.0f - c;
        GLfloat xy = x * y;
        GLfloat yz = y * z;
        GLfloat zx = z * x;
        GLfloat xs = x * s;
        GLfloat ys = y * s;
        GLfloat zs = z * s;
        rm[rmOffset + 0] = x * x * nc + c;
        rm[rmOffset + 4] = xy * nc - zs;
        rm[rmOffset + 8] = zx * nc + ys;
        rm[rmOffset + 1] = xy * nc + zs;
        rm[rmOffset + 5] = y * y * nc + c;
        rm[rmOffset + 9] = yz * nc - xs;
        rm[rmOffset + 2] = zx * nc - ys;
        rm[rmOffset + 6] = yz * nc + xs;
        rm[rmOffset + 10] = z * z * nc + c;
    }
}

/**
 * Converts Euler angles to a rotation matrix.
 *
 * 오일러 각을 회전 행렬로 변환합니다.
 */
void Matrix::setRotateEulerM(GLfloat *rm, GLuint rmOffset, GLfloat x, GLfloat y, GLfloat z)
{
    x *= (GLfloat) (M_PI / 180.0f);
    y *= (GLfloat) (M_PI / 180.0f);
    z *= (GLfloat) (M_PI / 180.0f);
    GLfloat cx = (GLfloat) cos(x);
    GLfloat sx = (GLfloat) sin(x);
    GLfloat cy = (GLfloat) cos(y);
    GLfloat sy = (GLfloat) sin(y);
    GLfloat cz = (GLfloat) cos(z);
    GLfloat sz = (GLfloat) sin(z);
    GLfloat cxsy = cx * sy;
    GLfloat sxsy = sx * sy;

    rm[rmOffset + 0] = cy * cz;
    rm[rmOffset + 1] = -cy * sz;
    rm[rmOffset + 2] = sy;
    rm[rmOffset + 3] = 0.0f;

    rm[rmOffset + 4] = cxsy * cz + cx * sz;
    rm[rmOffset + 5] = -cxsy * sz + cx * cz;
    rm[rmOffset + 6] = -sx * cy;
    rm[rmOffset + 7] = 0.0f;

    rm[rmOffset + 8] = -sxsy * cz + sx * sz;
    rm[rmOffset + 9] = sxsy * sz + sx * cz;
    rm[rmOffset + 10] = cx * cy;
    rm[rmOffset + 11] = 0.0f;

    rm[rmOffset + 12] = 0.0f;
    rm[rmOffset + 13] = 0.0f;
    rm[rmOffset + 14] = 0.0f;
    rm[rmOffset + 15] = 1.0f;
}

/**
 * Defines a viewing transformation in terms of an eye point, a center of view, and an up vector.
 *
 * 눈 포인트, 시야 중심 및 상향 벡터 관점에서보기 변형을 정의합니다.
 */
void Matrix::setLookAtM(GLfloat *rm, GLuint rmOffset, GLfloat eyeX, GLfloat eyeY, GLfloat eyeZ, GLfloat centerX, GLfloat centerY, GLfloat centerZ, GLfloat upX, GLfloat upY, GLfloat upZ)
{
    // See the OpenGL GLUT documentation for gluLookAt for a description
    // of the algorithm. We implement it in a straightforward way:

    float fx = centerX - eyeX;
    float fy = centerY - eyeY;
    float fz = centerZ - eyeZ;

    // Normalize f
    float rlf = 1.0f / Matrix::length(fx, fy, fz);
    fx *= rlf;
    fy *= rlf;
    fz *= rlf;

    // compute s = f x up (x means "cross product")
    float sx = fy * upZ - fz * upY;
    float sy = fz * upX - fx * upZ;
    float sz = fx * upY - fy * upX;

    // and normalize s
    float rls = 1.0f / Matrix::length(sx, sy, sz);
    sx *= rls;
    sy *= rls;
    sz *= rls;

    // compute u = s x f
    float ux = sy * fz - sz * fy;
    float uy = sz * fx - sx * fz;
    float uz = sx * fy - sy * fx;

    rm[rmOffset + 0] = sx;
    rm[rmOffset + 1] = ux;
    rm[rmOffset + 2] = -fx;
    rm[rmOffset + 3] = 0.0f;

    rm[rmOffset + 4] = sy;
    rm[rmOffset + 5] = uy;
    rm[rmOffset + 6] = -fy;
    rm[rmOffset + 7] = 0.0f;

    rm[rmOffset + 8] = sz;
    rm[rmOffset + 9] = uz;
    rm[rmOffset + 10] = -fz;
    rm[rmOffset + 11] = 0.0f;

    rm[rmOffset + 12] = 0.0f;
    rm[rmOffset + 13] = 0.0f;
    rm[rmOffset + 14] = 0.0f;
    rm[rmOffset + 15] = 1.0f;

    translateM(rm, rmOffset, -eyeX, -eyeY, -eyeZ);
}
