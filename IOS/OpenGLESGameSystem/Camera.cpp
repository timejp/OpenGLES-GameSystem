//
// Created by 윤중현 on 2017. 3. 8..
//

#include "Camera.h"

Camera::Camera(string id, GLfloat viewLenght)
    : Object(id), viewLenght(viewLenght)
{
    onCreated();
}

Camera::Camera(string id, GLfloat viewLenght, Vector3 scale)
    : Object(id, scale)
{
    onCreated();
}

Camera::Camera(string id, GLfloat viewLenght, GLfloat scale[3])
    : Object(id, scale), viewLenght(viewLenght)
{
    onCreated();
}

Camera::Camera(string id, GLfloat viewLenght, Vector3 scale, Vector3 position)
    : Object(id, scale, position)
{
    onCreated();
}

Camera::Camera(string id, GLfloat viewLenght, GLfloat scale[3], GLfloat position[3])
    : Object(id, scale, position), viewLenght(viewLenght)
{
    onCreated();
}

Camera::Camera(string id, GLfloat viewLenght, Vector3 scale, Vector3 position, Vector3 rotation)
    : Object(id, scale, position, rotation)
{
    onCreated();
}

Camera::Camera(string id, GLfloat viewLenght, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3])
    : Object(id, scale, position, rotation), viewLenght(viewLenght)
{
    onCreated();
}

void Camera::setViewLength(GLfloat viewLength)
{
    Camera::viewLenght = viewLength;
}

GLfloat Camera::getViewLength()
{
    return viewLenght;
}

void Camera::onCreated()
{
    
}

void Camera::draw()
{
    gluPerspective(projectionMatrix,
                   45.0f,  //Y方向の画角
                   SharedData::width,
                   SharedData::height,
                   //aspect, //アスペクト比
                   1.0f,   //ニアクリップ　　　z=-1から
                   100.0f);//ファークリップ　　Z=-100までの範囲を表示することになる

    //カメラビュー変換（視野変換）-----------------------------------
    //カメラ視点が原点になるような変換
    Matrix::setLookAtM(matrix, 0,
                      (float) (viewLenght * sin(beta) * cos(alph)),  //カメラの視点 x
                      (float) (viewLenght * sin(alph)),                    //カメラの視点 y
                      (float) (viewLenght * cos(beta) * cos(alph)),  //カメラの視点 z
                      0.0f, 0.0f, 0.0f, //カメラの視線方向の代表点
                      0.0f, 1.0f, 0.0f);//カメラの上方向
    //カメラビュー変換はこれで終わり。
}

void Camera::onTouch(int eventsCount, int **touchInfo)
{

}

void Camera::destroy()
{

}

void Camera::gluPerspective(GLfloat *pm, GLfloat angle, GLint width, GLint height, GLfloat near, GLfloat far)
{
    GLfloat aspect = (height > width) ? height / width : width / height;
    float top, bottom, left, right;
    if (aspect < 1.0f) {
        top = near * (float) tan(angle * (M_PI / 360.0));
        bottom = -top;
        left = bottom * aspect;
        right = -left;
    } else {
        right = 1.1f * near * (float) tan(angle * (M_PI / 360.0));
        left = -right;
        bottom = left / aspect;
        top = -bottom;
    }
    Matrix::frustumM(pm, 0, left, right, bottom, top, near, far);
}
