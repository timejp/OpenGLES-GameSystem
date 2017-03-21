//
//  SharedData.h
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 16..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef SharedData_h
#define SharedData_h

#include <OpenGLES/ES2/gl.h>

class SharedData {
public:
    static int width, height;
    
    //システム
    static GLint enableShadingHandle; //shadingを行うflagのハンドル
    static GLint objectColorHandle;   //shadingを行わない時に使う単色ハンドル
    
    //光源のハンドル
    static GLint lightAmbientHandle; //光源の環境光色ハンドル
    static GLint lightDiffuseHandle; //光源の拡散光色ハンドル
    static GLint lightSpecularHandle;
    //光源の鏡面光色ハンドル
    static GLint lightPosHandle;     //光源の位置ハンドル
    
    
    //マテリアルのハンドル
    static GLint materialAmbientHandle;  //マテリアルの環境光色ハンドル
    static GLint materialDiffuseHandle;  //マテリアルの拡散光色ハンドル
    static GLint materialSpecularHandle; //マテリアルの鏡面光色ハンドル
    static GLint materialShininessHandle;//マテリアルの鏡面指数ハンドル
    
    //行列のハンドル
    static GLint mMatrixHandle;     //モデルビュー行列ハンドル（カメラビュー行列×モデル変換行列）
    static GLint pmMatrixHandle;     //(射影行列×モデルビュー行列)ハンドル
    
    //頂点のハンドル
    static GLint positionHandle;
    //位置ハンドル
    static GLint normalHandle;  //法線ハンドル

};

#endif /* SharedData_h */
