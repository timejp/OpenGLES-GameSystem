//
// Created by 윤중현 on 2017. 3. 6..
//

#include "Object.h"

GLfloat Object::convertRoatation(GLfloat angle)
{
    GLfloat resized = angle;
    if (abs(angle) > 360) {
        if (angle < 0) {
            resized = (int) angle % 360 + angle - (int) angle;
        } else {
            resized = (int) angle % 360 + (int) angle - angle;
        }
    }
    return ((angle < 0) ? 360 + resized : resized);
}

Object::Object(string id)
    : _id(id)
{
    Matrix::setIdentityM(matrix, 0);
}

Object::Object(string id, Vector3 scale)
    : _id(id)
{
    Matrix::setIdentityM(matrix, 0);
    set_scale(scale);
}

Object::Object(string id, GLfloat scale[3])
    : _id(id)
{
    Matrix::setIdentityM(matrix, 0);
    set_scale(scale);
}

Object::Object(string id, Vector3 scale, Vector3 position)
    : _id(id)
{
    Matrix::setIdentityM(matrix, 0);
    set_scale(scale);
    set_tranform(position);
}

Object::Object(string id, GLfloat scale[3], GLfloat position[3])
    : _id(id)
{
    Matrix::setIdentityM(matrix, 0);
    set_scale(scale);
    set_tranform(position);
}

Object::Object(string id, Vector3 scale, Vector3 position, Vector3 rotation)
    : _id(id)
{
    Matrix::setIdentityM(matrix, 0);
    set_scale(scale);
    set_tranform(position);
    set_rotate(rotation);
}

Object::Object(string id, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3])
    : _id(id)
{
    Matrix::setIdentityM(matrix, 0);
    set_scale(scale);
    set_tranform(position);
    set_rotate(rotation);
}

Object::~Object()
{
    
}

void Object::destroy()
{
    for(Object *object : _child) {
        object->destroy();
        delete object;
    }
    _child.clear();
}

void Object::setID(string id)
{
    _id = id;
}

string Object::getID()
{
    return _id;
}

/**
 * 위치를 바꾼다. (자식 포함)
 *
 * vector3 : 실제 위치값
 */
void Object::set_tranform(Vector3 new_position)
{
    set_tranform(new_position.x, new_position.y, new_position.z);
}

void Object::set_tranform(GLfloat new_position[3])
{
    set_tranform(new_position[0], new_position[1], new_position[2]);
}

void Object::set_tranform(GLfloat new_positionX, GLfloat new_positionY, GLfloat new_positionZ)
{
    set_tranform_only(new_positionX, new_positionY, new_positionZ);
    
    for(Object *object : _child) {
        object->setParentPosition(_position);
        object->set_tranform(new_positionX, new_positionY, new_positionZ);
    }
}

/**
 * 위치를 바꾼다. (부모만)
 *
 * vector3 : 실제 위치값
 */
void Object::set_tranform_only(Vector3 new_position)
{
    set_tranform_only(new_position.x, new_position.y, new_position.z);
}

void Object::set_tranform_only(GLfloat new_position[3])
{
    set_tranform_only(new_position[0], new_position[1], new_position[2]);
}

void Object::set_tranform_only(GLfloat new_positionX, GLfloat new_positionY, GLfloat new_positionZ)
{
    Matrix::translateM(matrix, 0, new_positionX - _position[0]  + _pare_position[0], new_positionY - _position[1] + _pare_position[1], new_positionZ - _position[2] + _pare_position[2]);
    
    _position[0] = new_positionX + _pare_position[0];
    _position[1] = new_positionY + _pare_position[1];
    _position[2] = new_positionZ + _pare_position[2];
}

/**
 * 현재위치에서 이동시킨다. (자식 포함)
 *
 * vector3 : 앞으로 바뀌어야할 방향과 크기
 */
void Object::tranform(Vector3 new_position)
{
    tranform(new_position.x, new_position.y, new_position.z);
}

void Object::tranform(GLfloat new_position[3])
{
    tranform(new_position[0], new_position[1], new_position[2]);
}

void Object::tranform(GLfloat new_positionX, GLfloat new_positionY, GLfloat new_positionZ)
{
    tranform_only(new_positionX, new_positionY, new_positionZ);
    
    for(Object *object : _child) {
        object->setParentPosition(_position);
        object->tranform(new_positionX, new_positionY, new_positionZ);
    }
}

/**
 * 현재위치에서 이동시킨다. (부모만)
 *
 * vector3 : 앞으로 바뀌어야할 방향과 크기
 */
void Object::tranform_only(Vector3 new_position)
{
    tranform_only(new_position.x, new_position.y, new_position.z);
}

void Object::tranform_only(GLfloat new_position[3])
{
    tranform_only(new_position[0], new_position[1], new_position[2]);
}

void Object::tranform_only(GLfloat new_positionX, GLfloat new_positionY, GLfloat new_positionZ)
{
    Matrix::translateM(matrix, 0, new_positionX, new_positionY, new_positionZ);
    
    _position[0] += new_positionX;
    _position[1] += new_positionY;
    _position[2] += new_positionZ;
}

/**
 * 현재 위치를 받아온다.
 */
GLfloat &Object::getPosition()
{
    return *_position;
}

/**
 * 회전 방향을 바꾼다 (자식 포함)
 *
 * vector3 : 실제 방향 값
 */
void Object::set_rotate(Vector3 new_rotation)
{
    set_rotate(new_rotation.x, new_rotation.y, new_rotation.z);
}

void Object::set_rotate(GLfloat new_rotation[3])
{
    set_rotate(new_rotation[0], new_rotation[1], new_rotation[2]);
}

void Object::set_rotate(GLfloat new_rotationX, GLfloat new_rotationY, GLfloat new_rotationZ)
{
    set_rotate_only(new_rotationX, new_rotationY, new_rotationZ);
    
    for(Object *object : _child) {
        object->setParentRotation(_position);
        object->set_rotate(new_rotationX, new_rotationY, new_rotationZ);
    }
}

/**
 * 회전 방향을 바꾼다 (부모만)
 *
 * vector3 : 실제 방향 값
 */
void Object::set_rotate_only(Vector3 new_rotation)
{
    set_rotate_only(new_rotation.x, new_rotation.y, new_rotation.z);
}

void Object::set_rotate_only(GLfloat new_rotation[3])
{
    set_rotate_only(new_rotation[0], new_rotation[1], new_rotation[2]);
}

void Object::set_rotate_only(GLfloat new_rotationX, GLfloat new_rotationY, GLfloat new_rotationZ)
{
    Matrix::setRotateEulerM(matrix, 0, new_rotationX + _pare_rotation[0], new_rotationY + _pare_rotation[1],  new_rotationZ + _pare_rotation[2]);
    
    _rotation[0] = convertRoatation(new_rotationX + _pare_rotation[0]);
    _rotation[1] = convertRoatation(new_rotationY + _pare_rotation[1]);
    _rotation[2] = convertRoatation(new_rotationZ + _pare_rotation[2]);
}

/**
 * 회전을 시킨다. (자식 포함)
 *
 * vector3 : 회전을 시킬 방향
 * angle : 회전시킬 각
 */
void Object::rotate(Vector3 direction, GLfloat angle)
{
    rotate(direction.x, direction.y, direction.z, angle);
}

void Object::rotate(GLfloat direction[3], GLfloat angle)
{
    rotate(direction[0], direction[1], direction[2], angle);
}

void Object::rotate(GLfloat directionX, GLfloat directionY, GLfloat directionZ, GLfloat angle)
{
    rotate_only(directionX, directionY, directionZ, angle);
    
    for(Object *object : _child) {
        object->setParentRotation(_position);
        object->rotate(directionX, directionY, directionZ, angle);
    }
}

void Object::rotate_only(Vector3 direction, GLfloat angle)
{
    rotate_only(direction.x, direction.y, direction.z, angle);
}

void Object::rotate_only(GLfloat direction[3], GLfloat angle)
{
    rotate_only(direction[0], direction[1], direction[2], angle);
}

void Object::rotate_only(GLfloat directionX, GLfloat directionY, GLfloat directionZ, GLfloat angle)
{
    Matrix::rotateM(matrix, 0, angle, directionX, directionY, directionZ);
    
    _rotation[0] = convertRoatation(directionX * angle);
    _rotation[1] = convertRoatation(directionY * angle);
    _rotation[2] = convertRoatation(directionZ * angle);
}

/**
 * 현재 회전 방향을 가져온다.
 */
GLfloat &Object::getRotation()
{
    return *_rotation;
}

/**
 * 크기를 지정한다. (자식 포함)
 *
 * vector3 : Object의 크기
 */
void Object::set_scale(Vector3 new_scale)
{
    set_scale(new_scale.x, new_scale.y, new_scale.z);
}

void Object::set_scale(GLfloat new_scale[3])
{
    set_scale(new_scale[0], new_scale[1], new_scale[2]);
}

void Object::set_scale(GLfloat new_scaleX, GLfloat new_scaleY, GLfloat new_scaleZ)
{
    set_scale_only(new_scaleX, new_scaleY, new_scaleZ);
    
    for(Object *object : _child) {
        object->setParentScale(_position);
        object->set_scale(new_scaleX, new_scaleY, new_scaleZ);
    }
}

/**
 * 크기를 지정한다. (부모만)
 *
 * vector3 : Object의 크기
 */
void Object::set_scale_only(Vector3 new_scale)
{
    set_scale_only(new_scale.x, new_scale.y, new_scale.z);
}

void Object::set_scale_only(GLfloat new_scale[3])
{
    set_scale_only(new_scale[0], new_scale[1], new_scale[2]);
}

void Object::set_scale_only(GLfloat new_scaleX, GLfloat new_scaleY, GLfloat new_scaleZ)
{
    Matrix::scaleM(matrix, 0, _scale[0] - new_scaleX + _pare_scale[0], _scale[1] - new_scaleY + _pare_scale[1], _scale[2] - new_scaleZ + _pare_scale[2]);
    
    _scale[0] = new_scaleX + _pare_scale[0];
    _scale[1] = new_scaleY + _pare_scale[1];
    _scale[2] = new_scaleZ + _pare_scale[2];
}

/**
 * 크기를 증/감 시킨다. (자식 포함)
 *
 * vector3 : 크기를 키울 방향과 정도도
 */
void Object::scale(Vector3 new_scale)
{
    scale(new_scale.x, new_scale.y, new_scale.z);
}

void Object::scale(GLfloat new_scale[3])
{
    scale(new_scale[0], new_scale[1], new_scale[2]);
}

void Object::scale(GLfloat new_scaleX, GLfloat new_scaleY, GLfloat new_scaleZ)
{
    scale_only(new_scaleX, new_scaleY, new_scaleZ);
    
    for(Object *object : _child) {
        object->setParentScale(_position);
        object->scale(new_scaleX, new_scaleY, new_scaleZ);
    }
}

/**
 * 크기를 증/감 시킨다. (부모만)
 *
 * vector3 : 크기를 키울 방향과 정도도
 */
void Object::scale_only(Vector3 new_scale)
{
    set_scale_only(new_scale.x, new_scale.y, new_scale.z);
}

void Object::scale_only(GLfloat new_scale[3])
{
    set_scale_only(new_scale[0], new_scale[1], new_scale[2]);
}

void Object::scale_only(GLfloat new_scaleX, GLfloat new_scaleY, GLfloat new_scaleZ)
{
    Matrix::scaleM(matrix, 0, new_scaleX, new_scaleY, new_scaleZ);
    
    _scale[0] += new_scaleX;
    _scale[1] += new_scaleY;
    _scale[2] += new_scaleZ;
}

/**
 * 크기를 받아온다.
 */
GLfloat &Object::getScale()
{
    return *_scale;
}

/**
 * 자식 객체를 추가한다.
 * 겹치는 id가 있으면 false를 반환
 */
void Object::addChild(Object *object)
{
    _child.push_back(object);
}

/**
 * id에 해당하는 자식 객체들을 모두 _child에서 가져온다.
 */
Object &Object::getChild(string id)
{
    Object *result = NULL;
    for (Object *object : _child) {
        if (object->getID().compare(id) == 0) {
            result = object;
            break;
        }
    }
    return *result;
}

Object &Object::getChild(int position)
{
    return *(_child.at(position));
}

bool Object::isContainChild(string id)
{
    for (Object *object : _child) {
        if (object->getID().compare(id) == 0) {
            return true;
        }
    }
    return false;
}

long Object::getChildCount()
{
    return _child.size();
}

void Object::removeChild(int position)
{
    delete _child.at(position);
    _child.erase(_child.begin() + position);
}

void Object::removeChild(string id)
{
    for (Object *object : _child) {
        static int position = 0;
        position += 1;
        if (object->getID().compare(id) == 0) {
            delete object;
            _child.erase(_child.begin() + position);
        }
    }
}

void Object::setParentPosition(GLfloat new_position[3])
{
    _pare_position[0] = new_position[0];
    _pare_position[1] = new_position[1];
    _pare_position[2] = new_position[2];
}

void Object::setParentRotation(GLfloat new_rotation[3])
{
    _pare_rotation[0] = new_rotation[0];
    _pare_rotation[1] = new_rotation[1];
    _pare_rotation[2] = new_rotation[2];
}

void Object::setParentScale(GLfloat new_scale[3])
{
    _pare_scale[0] = new_scale[0];
    _pare_scale[1] = new_scale[1];
    _pare_scale[2] = new_scale[2];
}
