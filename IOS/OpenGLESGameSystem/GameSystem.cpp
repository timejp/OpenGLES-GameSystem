//
//  SocketController.cpp
//  OpenGLGameSystem
//
//  Created by 윤중현 on 2017. 3. 12..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "GameSystem.h"

bool GameSystem::isCreated = false;

float GameSystem::DummyFloat[1] = {0.0f};

vector<Camera *> GameSystem::cameras;
vector<Light *> GameSystem::lights;
vector<Object *> GameSystem::objects;

Camera *GameSystem::maincamera;

GameSystem::GameSystem()
{
    
}

GameSystem::~GameSystem()
{
    
}

void GameSystem::destroy()
{
    GameSystem *gameSystem = &getInstance();
    if (gameSystem != NULL) {
        delete gameSystem;
    }
}

GameSystem& GameSystem::getInstance()
{
    static GameSystem *gameSystem = NULL;
    
    if (gameSystem == NULL) {
        gameSystem = new GameSystem();
    }
    
    return *gameSystem;
}

void GameSystem::onCreated()
{
    LOGI("onCreated");
    GLuint program = createProgram(ShaderManager::getInstance().get("SimpleVertex.vs"),
                                   ShaderManager::getInstance().get("SimpleVertex.fs"));
    
    //shading可否ハンドルの取得
    SharedData::enableShadingHandle = glGetUniformLocation(program, "u_EnableShading");
    
    //光源のハンドルの取得
    SharedData::lightAmbientHandle = glGetUniformLocation(program, "u_LightAmbient");
    SharedData::lightDiffuseHandle = glGetUniformLocation(program, "u_LightDiffuse");
    SharedData::lightSpecularHandle = glGetUniformLocation(program, "u_LightSpecular");
    SharedData::lightPosHandle = glGetUniformLocation(program, "u_LightPos");
    
    //マテリアルのハンドルの取得
    SharedData::materialAmbientHandle = glGetUniformLocation(program, "u_MaterialAmbient");
    SharedData::materialDiffuseHandle = glGetUniformLocation(program, "u_MaterialDiffuse");
    SharedData::materialSpecularHandle = glGetUniformLocation(program, "u_MaterialSpecular");
    SharedData::materialShininessHandle = glGetUniformLocation(program, "u_MaterialShininess");
    //光源を使わない時のマテリアルの色のハンドルの取得
    SharedData::objectColorHandle = glGetUniformLocation(program, "u_ObjectColor");
    
    //行列のハンドルの取得
    SharedData::mMatrixHandle = glGetUniformLocation(program, "u_MMatrix");
    SharedData::pmMatrixHandle = glGetUniformLocation(program, "u_PMMatrix");
    
    //頂点とその法線ベクトルのハンドルの取得
    SharedData::positionHandle = glGetAttribLocation(program, "a_Position");
    SharedData::normalHandle = glGetAttribLocation(program, "a_Normal");
    
    glUseProgram(program);
    glDeleteProgram(program);
    
    //頂点配列の有効化
    glEnableVertexAttribArray(SharedData::positionHandle);
    glEnableVertexAttribArray(SharedData::normalHandle);
    
    //デプスバッファの有効化
    glEnable(GL_DEPTH_TEST);
    
    // カリングの有効化
    glEnable(GL_CULL_FACE); //裏面を表示しないチェックを行う
    
    // 裏面を描画しない
    glFrontFace(GL_CCW); //表面のvertexのindex番号はCCWで登録
    glCullFace(GL_BACK); //裏面は表示しない
//    glCullFace(GL_FRONT); //裏面は表示しない
    
    //光源色の指定 (r, g, b,a)
    glUniform4f(SharedData::lightAmbientHandle, 0.15f, 0.15f, 0.15f, 1.0f); //周辺光
    glUniform4f(SharedData::lightDiffuseHandle, 0.5f, 0.5f, 0.5f, 1.0f); //乱反射光
    glUniform4f(SharedData::lightSpecularHandle, 0.9f, 0.9f, 0.9f, 1.0f); //鏡面反射光
    
    
    // 背景とのブレンド方法を設定します。
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);    // 単純なアルファブレンド
    
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    cameras.push_back(new Camera("MainCamera", 5.0f));
    lights.push_back(new DirectionLight("MainLight", {0.0f, 1.5f, 3.0f, 1.0f}));
    objects.push_back(new Cube("Cube"));
    maincamera = cameras.at(0);
    
    isCreated = true;
}

void GameSystem::onChanged(int _width, int _height)
{
    LOGI("onChanged : width = %d, height = %d", _width, _height);
    SharedData::width = _width;
    SharedData::height = _height;
    glViewport(0, 0, _width, _height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GameSystem::onDraw()
{
    if (!isCreated)
        return;
    //シェーダのattribute属性の変数に値を設定していないと暴走するのでここでセットしておく。この位置でないといけない
    glVertexAttribPointer(SharedData::positionHandle, 3, GL_FLOAT, false, 0, DummyFloat);
    glVertexAttribPointer(SharedData::normalHandle, 3, GL_FLOAT, false, 0, DummyFloat);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    maincamera->draw();
    
    enableShading();   //シェーディング機能を有効にする。（デフォルト）
    
    for (Object *object : objects) {
        object->draw();
    }
}

void GameSystem::onTouch(int eventsCount, int **touchInfo)
{
    for (int i = 0; i < eventsCount; i++) {
        LOGI("onTouch : id = %d, action = %d (%d, %d)", touchInfo[i][0], touchInfo[i][1], touchInfo[i][2], touchInfo[i][3]);
    }
    if(touchInfo[0][1] == 1) {
        int middleX = SharedData::width / 2;
        int middleY = SharedData::height / 2;
        int distanse = 100;
        int x = touchInfo[0][2];
        int y = touchInfo[0][3];
        if(middleX - distanse <= x && x <= middleX + distanse) {
            if (middleY - distanse <= y && y <= middleY + distanse) {
                objects.at(0)->tranform(0.0f, 0.0f, 0.1f);
            }
        } else {
            if (x < middleX) {
                if (y < middleY) {
                    objects.at(0)->tranform(0.0f, 0.1f, 0.0f);
                } else {
                    objects.at(0)->tranform(0.0f, -0.1f, 0.0f);
                }
            } else {
                if (y < middleY) {
                    objects.at(0)->rotate({-0.1f, 0.1f, 0.0f}, 10);
                } else {
                    objects.at(0)->rotate({0.1f, -0.1f, 0.0f}, 10);
                }
            }
        }
    }
    
    for (int i = 0; i < eventsCount; i++) {
        delete []touchInfo[i];
    }
    delete []touchInfo;
}

bool GameSystem::onBackPressed()
{
    LOGI("onBackPressed");
    return true;
}

void GameSystem::onDestroy()
{
    LOGI("onDestroy");
    for (Object *object : objects) {
        object->destroy();
        delete object;
    }
    objects.clear();
    
    for (Light *light : lights) {
        light->destroy();
        delete light;
    }
    lights.clear();
    
    for (Camera *camera : cameras) {
        camera->destroy();
        delete camera;
    }
    cameras.clear();
    
    ShaderManager::destroy();
    
    delete &getInstance();
    
    LOGI("onDestroy");
}

void GameSystem::enableShading()
{
    glUniform1i(SharedData::enableShadingHandle, 1);
}

void GameSystem::disableShading()
{
    glUniform1i(SharedData::enableShadingHandle, 0);
}
