//
// Created by 윤중현 on 2017. 3. 8..
//

#include "Cube.h"
#include <math.h>

float Cube::Cubevertexs[] = {
//    1.0f,1.0f,1.0f,//P0　第0面
//    1.0f,1.0f,-1.0f,//P1
//    -1.0f,1.0f,1.0f,//P2
//    -1.0f,1.0f,-1.0f,//P3
//    -1.0f,1.0f,1.0f,//P4　 第1面
//    -1.0f,1.0f,-1.0f,//P5
//    -1.0f,-1.0f,1.0f,//P6
//    -1.0f,-1.0f,-1.0f,//P7
//    -1.0f,-1.0f,1.0f,//P8　第2面
//    -1.0f,-1.0f,-1.0f,//P9
//    1.0f,-1.0f,1.0f,//P10
//    1.0f,-1.0f,-1.0f,//P11
//    1.0f,-1.0f,1.0f,//P12　第3面
//    1.0f,-1.0f,-1.0f,//P13
//    1.0f,1.0f,1.0f,//P14
//    1.0f,1.0f,-1.0f,//P15
//    -1.0f,-1.0f,1.0f,//P16　第4面
//    1.0f,-1.0f,1.0f,//P17
//    -1.0f,1.0f,1.0f,//P18
//    1.0f,1.0f,1.0f,//P19
//    1.0f,-1.0f,-1.0f,//P20　第5面
//    -1.0f,-1.0f,-1.0f,//P21
//    1.0f,1.0f,-1.0f,//P22
//    -1.0f,1.0f,-1.0f//P23
    
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, -1.0f,
    
    -1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, 1.0f,
    
    1.0f, -1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, -1.0f, 1.0f,
    -1.0f, -1.0f, -1.0f,
    
    1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, -1.0f
};

float Cube::Cubenormals[] = {
//    0.0f,1.0f,0.0f,
//    0.0f,1.0f,0.0f,
//    0.0f,1.0f,0.0f,
//    0.0f,1.0f,0.0f,
//    -1.0f,0.0f,0.0f,
//    -1.0f,0.0f,0.0f,
//    -1.0f,0.0f,0.0f,
//    -1.0f,0.0f,0.0f,
//    0.0f,-1.0f,0.0f,
//    0.0f,-1.0f,0.0f,
//    0.0f,-1.0f,0.0f,
//    0.0f,-1.0f,0.0f,
//    1.0f,0.0f,0.0f,
//    1.0f,0.0f,0.0f,
//    1.0f,0.0f,0.0f,
//    1.0f,0.0f,0.0f,
//    0.0f,0.0f,1.0f,
//    0.0f,0.0f,1.0f,
//    0.0f,0.0f,1.0f,
//    0.0f,0.0f,1.0f,
//    0.0f,0.0f,-1.0f,
//    0.0f,0.0f,-1.0f,
//    0.0f,0.0f,-1.0f,
//    0.0f,0.0f,-1.0f
    
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
    
    -1.0f, 0.0f, 0.0f,
    
    0.0f, 0.0f, -1.0f,
    0.0f, 0.0f, -1.0f,
    
    1.0f, 0.0f, 0.0f,
    1.0f, 0.0f, 0.0f,
    
    0.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f,
    
    -1.0f, 0.0f, 0.0f,
    
    0.0f, -1.0f, 0.0f,
    0.0f, -1.0f, 0.0f,
};

unsigned int Cube::Cubeindexs[] = {
    0, 1, 2, 3,
    4, 5, 6, 7,
    8, 9, 10, 11,
    12, 13, 14, 15,
    16, 17, 18, 19,
    20, 21, 22, 23
};

Cube::Cube(string id)
    : Object(id)
{
    onCreated();
}

Cube::Cube(string id, Vector3 scale)
    : Object(id, scale)
{
    onCreated();
}

Cube::Cube(string id, GLfloat scale[3])
    : Object(id, scale)
{
    onCreated();
}

Cube::Cube(string id, Vector3 scale, Vector3 position)
    : Object(id, scale, position)
{
    onCreated();
}

Cube::Cube(string id, GLfloat scale[3], GLfloat position[3])
    : Object(id, scale, position)
{
    onCreated();
}

Cube::Cube(string id, Vector3 scale, Vector3 position, Vector3 rotation)
    : Object(id, scale, position, rotation)
{
    onCreated();
}

Cube::Cube(string id, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3])
    : Object(id, scale, position, rotation)
{
    onCreated();
}

void Cube::onCreated()
{
    
}

void Cube::draw()
{
    GLfloat mvMatrix[16];
    GLfloat pmMatrix[16];
    GLfloat CVLightPos[4];
    
    GLfloat cMatrix[16];
    memcpy(cMatrix, GameSystem::maincamera->matrix, sizeof(GLfloat) * 16);
    
    GLfloat pMatrix[16];
    memcpy(pMatrix, GameSystem::maincamera->projectionMatrix, sizeof(GLfloat) * 16);
    
    GLfloat LightPos[4];
    
    
    Matrix::multiplyMM(mvMatrix, 0, cMatrix, 0, matrix, 0);       //mvMatrix = cMatrix * mm
    Matrix::multiplyMM(pmMatrix, 0, pMatrix, 0, mvMatrix, 0); //pmMatrix = pMatrix * mvMatrix
    //モデルビュー行列をシェーダに指定
    glUniformMatrix4fv(SharedData::mMatrixHandle, 1, false, mvMatrix);
    
    //プロジェクション行列（射影行列）×モデルビュー行列をシェーダに指定
    glUniformMatrix4fv(SharedData::pmMatrixHandle, 1, false, pmMatrix);

    //シェーダはカメラビュー座標系の光源位置を使う
    //ワールド座標系のLightPosを，カメラビュー座標系に変換してシェーダに送る
    memcpy(LightPos, GameSystem::lights.at(0)->lightPosition, sizeof(GLfloat) * 4);
    Matrix::multiplyMV(CVLightPos, 0, cMatrix, 0, LightPos, 0);
    glUniform4f(SharedData::lightPosHandle, CVLightPos[0], CVLightPos[1], CVLightPos[2], 1.0f);
    
    
    //頂点点列
    glVertexAttribPointer(SharedData::positionHandle, 3, GL_FLOAT, false, 0, Cubevertexs);
    
    //頂点での法線ベクトル
    glVertexAttribPointer(SharedData::normalHandle, 3, GL_FLOAT, false, 0, Cubenormals);
    
    //周辺光反射
    glUniform4f(SharedData::materialAmbientHandle, 1.0f, 0.2f, 0.2f, 1.0f);
    
    //拡散反射
    glUniform4f(SharedData::materialDiffuseHandle, 1.0f, 0.2f, 0.2f, 1.0f);
    
    //鏡面反射
    glUniform4f(SharedData::materialSpecularHandle, 1.0f, 1.0f, 1.0f, 1.0f);
    glUniform1f(SharedData::materialShininessHandle, 10.0f);
    
    //shadingを使わない時に使う単色の設定 (r, g, b,a)
    glUniform4f(SharedData::objectColorHandle, 1.0f, 0.2f, 0.2f, 1.0f);

    //描画をシェーダに指示
    //    indexBuffer.position(0);
    glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_INT, Cubeindexs);
}

void Cube::onTouch(int eventsCount, int **touchInfo)
{

}

void Cube::destroy()
{

}
