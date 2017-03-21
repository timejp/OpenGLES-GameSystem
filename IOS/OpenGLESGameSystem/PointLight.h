//
//  PointLight.h
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 18..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef PointLight_h
#define PointLight_h

#include "Light.h"

class PointLight : public Light {
private:
    GLfloat power = 1.0f;
    
public:
    PointLight(string id, Vector4 lightPosition, GLfloat power);
    PointLight(string id, GLfloat lightPosition[4], GLfloat power);
    PointLight(string id, Vector4 lightPosition, GLfloat power, Vector3 scale);
    PointLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat scale[3]);
    PointLight(string id, Vector4 lightPosition, GLfloat power, Vector3 scale, Vector3 position);
    PointLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat scale[3], GLfloat position[3]);
    PointLight(string id, Vector4 lightPosition, GLfloat power, Vector3 scale, Vector3 position, Vector3 rotation);
    PointLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3]);
    
    void setPower(GLfloat new_power);
    GLfloat getPower();
    
    void onCreated();
    void draw();
    void onTouch(int eventsCount, int **touchInfo);
    void destroy();
};


#endif /* PointLight_h */
