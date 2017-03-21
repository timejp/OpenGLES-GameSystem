//
//  SpotLight.h
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 18..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef SpotLight_h
#define SpotLight_h

#include "Light.h"

class SpotLight : public Light {
private:
    GLfloat power = 1.0f;
    GLfloat area = 1.0f;
    
public:
    SpotLight(string id, Vector4 lightPosition, GLfloat power, GLfloat area);
    SpotLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat area);
    SpotLight(string id, Vector4 lightPosition, GLfloat power, GLfloat area, Vector3 scale);
    SpotLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat area, GLfloat scale[3]);
    SpotLight(string id, Vector4 lightPosition, GLfloat power, GLfloat area, Vector3 scale, Vector3 position);
    SpotLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat area, GLfloat scale[3], GLfloat position[3]);
    SpotLight(string id, Vector4 lightPosition, GLfloat power, GLfloat area, Vector3 scale, Vector3 position, Vector3 rotation);
    SpotLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat area, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3]);
    
    void setPower(GLfloat new_power);
    GLfloat getPower();
    
    void setArea(GLfloat new_area);
    GLfloat getArea();
    
    void onCreated();
    void draw();
    void onTouch(int eventsCount, int **touchInfo);
    void destroy();
};

#endif /* SpotLight_h */
