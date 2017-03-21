//
// Created by 윤중현 on 2017. 3. 6..
//

#ifndef PENGUINET_OBJECT_H
#define PENGUINET_OBJECT_H

#include <vector>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "Matrix.h"
#include "SharedData.h"
#include "Vector.h"


using namespace std;
class Object {
private:
    
    string _id;
    GLfloat _position[3] = {0.0f, 0.0f, 0.0f};
    GLfloat _rotation[3] = {0.0f, 0.0f, 0.0f};
    GLfloat _scale[3] = {1.0f, 1.0f, 1.0f};
    
    vector<Object *> _child;
    
    string _pare_id;
    GLfloat _pare_position[3] = {0.0f, 0.0f, 0.0f};
    GLfloat _pare_rotation[3] = {0.0f, 0.0f, 0.0f};
    GLfloat _pare_scale[3] = {0.0f, 0.0f, 0.0f};
    
    static GLfloat convertRoatation(GLfloat angle);

public:
    GLfloat matrix[16] = {0.0f};

    Object(string id);
    Object(string id, Vector3 scale);
    Object(string id, GLfloat scale[3]);
    Object(string id, Vector3 scale, Vector3 position);
    Object(string id, GLfloat scale[3], GLfloat position[3]);
    Object(string id, Vector3 scale, Vector3 position, Vector3 rotation);
    Object(string id, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3]);
    
    ~Object();

    string getID();
    void setID(string id);
    
    void set_tranform(Vector3 new_position);
    void set_tranform_only(Vector3 new_position);
    void set_tranform(GLfloat new_position[3]);
    void set_tranform_only(GLfloat new_position[3]);
    void set_tranform(GLfloat new_positionX, GLfloat new_positionY, GLfloat new_positionZ);
    void set_tranform_only(GLfloat new_positionX, GLfloat new_positionY, GLfloat new_positionZ);
    
    void set_rotate(Vector3 new_rotation);
    void set_rotate_only(Vector3 new_rotation);
    void set_rotate(GLfloat new_rotation[3]);
    void set_rotate_only(GLfloat new_rotation[3]);
    void set_rotate(GLfloat new_rotationX, GLfloat new_rotationY, GLfloat new_rotationZ);
    void set_rotate_only(GLfloat new_rotationX, GLfloat new_rotationY, GLfloat new_rotationZ);
    
    void set_scale(Vector3 new_scale);
    void set_scale_only(Vector3 new_scale);
    void set_scale(GLfloat new_scale[3]);
    void set_scale_only(GLfloat new_scale[3]);
    void set_scale(GLfloat new_scaleX, GLfloat new_scaleY, GLfloat new_scaleZ);
    void set_scale_only(GLfloat new_scaleX, GLfloat new_scaleY, GLfloat new_scaleZ);
    
    void tranform(Vector3 new_position);
    void tranform_only(Vector3 new_position);
    void tranform(GLfloat new_position[3]);
    void tranform_only(GLfloat new_position[3]);
    void tranform(GLfloat new_positionX, GLfloat new_positionY, GLfloat new_positionZ);
    void tranform_only(GLfloat new_positionX, GLfloat new_positionY, GLfloat new_positionZ);
    
    void rotate(Vector3 direction, GLfloat angle);
    void rotate_only(Vector3 direction, GLfloat angle);
    void rotate(GLfloat direction[3], GLfloat angle);
    void rotate_only(GLfloat direction[3], GLfloat angle);
    void rotate(GLfloat directionX, GLfloat directionY, GLfloat directionZ, GLfloat angle);
    void rotate_only(GLfloat directionX, GLfloat directionY, GLfloat directionZ, GLfloat angle);
    
    void scale(Vector3 new_scale);
    void scale_only(Vector3 new_scale);
    void scale(GLfloat new_scale[3]);
    void scale_only(GLfloat new_scale[3]);
    void scale(GLfloat new_scaleX, GLfloat new_scaleY, GLfloat new_scaleZ);
    void scale_only(GLfloat new_scaleX, GLfloat new_scaleY, GLfloat new_scaleZ);
    
    GLfloat &getMatrix();
    GLfloat &getPosition();
    GLfloat &getRotation();
    GLfloat &getScale();

    void setParentPosition(GLfloat new_position[3]);
    void setParentRotation(GLfloat new_rotation[3]);
    void setParentScale(GLfloat new_scale[3]);

    void addChild(Object *object);
    Object &getChild(string id);
    Object &getChild(int position);
    bool isContainChild(string id);
    void removeChild(string id);
    void removeChild(int position);
    long getChildCount();

    virtual void onCreated() = 0;
    virtual void draw() = 0;
    virtual void onTouch(int eventsCount, int **touchInfo) = 0;
    virtual void destroy();
};



#endif //PENGUINET_OBJECT_H
