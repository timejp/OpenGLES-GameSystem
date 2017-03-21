//
//  DirectionLight.h
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 18..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef DirectionLight_h
#define DirectionLight_h

#include "Light.h"

class DirectionLight : public Light {
    
public:
    DirectionLight(string id, Vector4 lightPosition);
    DirectionLight(string id, GLfloat lightPosition[4]);
    DirectionLight(string id, Vector4 lightPosition, Vector3 scale);
    DirectionLight(string id, GLfloat lightPosition[4], GLfloat scale[3]);
    DirectionLight(string id, Vector4 lightPosition, Vector3 scale, Vector3 position);
    DirectionLight(string id, GLfloat lightPosition[4], GLfloat scale[3], GLfloat position[3]);
    DirectionLight(string id, Vector4 lightPosition, Vector3 scale, Vector3 position, Vector3 rotation);
    DirectionLight(string id, GLfloat lightPosition[4], GLfloat scale[3], GLfloat position[3], GLfloat rotation[3]);
    
    void onCreated();
    void draw();
    void onTouch(int eventsCount, int **touchInfo);
    void destroy();
};

#endif /* DirectionLight_h */
