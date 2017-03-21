//
// Created by 윤중현 on 2017. 3. 8..
//

#ifndef OPENGLGAMESYSTEM_CUBE_H
#define OPENGLGAMESYSTEM_CUBE_H


#include "Object.h"
#include "GameSystem.h"

class Cube : public Object {
    private:
    static float Cubevertexs[];
    static float Cubenormals[];
    static unsigned int Cubeindexs[];
public:
    Cube(string id);
    Cube(string id, Vector3 scale);
    Cube(string id, GLfloat scale[3]);
    Cube(string id, Vector3 scale, Vector3 position);
    Cube(string id, GLfloat scale[3], GLfloat position[3]);
    Cube(string id, Vector3 scale, Vector3 position, Vector3 rotation);
    Cube(string id, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3]);

    void onCreated();
    void draw();
    void onTouch(int eventsCount, int **touchInfo);
    void destroy();
};


#endif //OPENGLGAMESYSTEM_CUBE_H
