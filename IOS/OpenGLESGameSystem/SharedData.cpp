//
//  SharedData.cpp
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 16..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "SharedData.h"

//システム
GLint   SharedData::enableShadingHandle = 0; //shadingを行うflagのハンドル
GLint   SharedData::objectColorHandle = 0;   //shadingを行わない時に使う単色ハンドル

//光源のハンドル
GLint   SharedData::lightAmbientHandle = 0; //光源の環境光色ハンドル
GLint   SharedData::lightDiffuseHandle = 0; //光源の拡散光色ハンドル
GLint   SharedData::lightSpecularHandle = 0;
//光源の鏡面光色ハンドル
GLint   SharedData::lightPosHandle = 0;     //光源の位置ハンドル


//マテリアルのハンドル
GLint   SharedData::materialAmbientHandle = 0;  //マテリアルの環境光色ハンドル
GLint   SharedData::materialDiffuseHandle = 0;  //マテリアルの拡散光色ハンドル
GLint   SharedData::materialSpecularHandle = 0; //マテリアルの鏡面光色ハンドル
GLint   SharedData::materialShininessHandle = 0;//マテリアルの鏡面指数ハンドル

//行列のハンドル
GLint   SharedData::mMatrixHandle = 0;     //モデルビュー行列ハンドル（カメラビュー行列×モデル変換行列）
GLint   SharedData::pmMatrixHandle = 0;     //(射影行列×モデルビュー行列)ハンドル

//頂点のハンドル
GLint   SharedData::positionHandle = 0;
//位置ハンドル
GLint   SharedData::normalHandle = 0;  //法線ハンドル

int SharedData::width = 0;
int SharedData::height = 0;
