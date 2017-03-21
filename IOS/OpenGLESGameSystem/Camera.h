//
// Created by 윤중현 on 2017. 3. 8..
//

#ifndef OPENGLGAMESYSTEM_CAMERA_H
#define OPENGLGAMESYSTEM_CAMERA_H


#include "Object.h"

class Camera : public Object {
private:
    GLfloat viewLenght = 5.0f;
    
    GLfloat alph = 0.0f,beta = 0.0f;

    static void gluPerspective(GLfloat *pm, GLfloat angle, GLint width, GLint height, GLfloat near, GLfloat far);

public:
    GLfloat projectionMatrix[16] = {0.0f};
    
    Camera(string id, GLfloat viewLenght);
    Camera(string id, GLfloat viewLenght, Vector3 scale);
    Camera(string id, GLfloat viewLenght, GLfloat scale[3]);
    Camera(string id, GLfloat viewLenght, Vector3 scale, Vector3 position);
    Camera(string id, GLfloat viewLenght, GLfloat scale[3], GLfloat position[3]);
    Camera(string id, GLfloat viewLenght, Vector3 scale, Vector3 position, Vector3 rotation);
    Camera(string id, GLfloat viewLenght, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3]);

    void setViewLength(GLfloat viewLength);
    GLfloat getViewLength();

    void onCreated();
    void draw();
    void onTouch(int eventsCount, int **touchInfo);
    void destroy();
};


#endif //OPENGLGAMESYSTEM_CAMERA_H
