//
//  GameSystem_h
//  OpenGLGameSystem
//
//  Created by 윤중현 on 2017. 3. 12..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef GameSystem_h
#define GameSystem_h

#include <OpenGLES/ES2/gl.h>
#include "ShaderManager.h"
#include "ShaderUtil.h"
#include "Camera.h"
#include "DirectionLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Cube.h"
#include "Object.h"
#include "logger.h"

class GameSystem {
private:
    
    static bool isCreated;

    static float DummyFloat[1];
    
    GameSystem();
    ~GameSystem();
    
public:
    static vector<Camera *> cameras;
    static vector<Light *> lights;
    static vector<Object *> objects;
    
    static Camera *maincamera;
    
    static GameSystem &getInstance();
        
    void onCreated();
    void onChanged(int _width, int _height);
    void onDraw();
    void onTouch(int eventsCount, int **touchInfo);
    bool onBackPressed();
    void onDestroy();
    
    static void destroy();
    
    static void enableShading();
    static void disableShading();
};


#endif /* GameSystem_h */
