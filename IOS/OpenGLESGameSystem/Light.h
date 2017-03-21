//
// Created by 윤중현 on 2017. 3. 8..
//

#ifndef OPENGLGAMESYSTEM_LIGHT_H
#define OPENGLGAMESYSTEM_LIGHT_H


#include "Object.h"

class Light : public Object {
private:
    void setLightPosition(Vector4 position);
    void setLightPosition(GLfloat position[4]);
public:
    static char TYPE_LIGHT;
    static char TYPE_SPOT_LIGHT;
    
    char _type = 0;
    GLfloat lightPosition[4];
    
    Light(string id, Vector4 lightPosition);
    Light(string id, GLfloat lightPosition[4]);
    Light(string id, Vector4 lightPosition, Vector3 scale);
    Light(string id, GLfloat lightPosition[4], GLfloat scale[3]);
    Light(string id, Vector4 lightPosition, Vector3 scale, Vector3 position);
    Light(string id, GLfloat lightPosition[4], GLfloat scale[3], GLfloat position[3]);
    Light(string id, Vector4 lightPosition, Vector3 scale, Vector3 position, Vector3 rotation);
    Light(string id, GLfloat lightPosition[4], GLfloat scale[3], GLfloat position[3], GLfloat rotation[3]);

    virtual void onCreated() = 0;
    virtual void draw() = 0;
    virtual void onTouch(int eventsCount, int **touchInfo) = 0;
    virtual void destroy() = 0;
};


#endif //OPENGLGAMESYSTEM_LIGHT_H
