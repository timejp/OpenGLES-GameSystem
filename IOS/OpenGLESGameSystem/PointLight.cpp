//
//  PointLight.cpp
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 18..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "PointLight.h"

PointLight::PointLight(string id, Vector4 lightPosition, GLfloat power)
    : Light(id, lightPosition), power(power)
{
    
}

PointLight::PointLight(string id, GLfloat lightPosition[4], GLfloat power)
    : Light(id, lightPosition), power(power)
{
    
}

PointLight::PointLight(string id, Vector4 lightPosition, GLfloat power, Vector3 scale)
    : Light(id, lightPosition, scale), power(power)
{
    
}

PointLight::PointLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat scale[3])
    : Light(id, lightPosition,scale), power(power)
{
    
}

PointLight::PointLight(string id, Vector4 lightPosition, GLfloat power, Vector3 scale, Vector3 position)
    : Light(id, lightPosition,scale, position), power(power)
{
    
}

PointLight::PointLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat scale[3], GLfloat position[3])
    : Light(id, lightPosition,scale, position), power(power)
{
    
}

PointLight::PointLight(string id, Vector4 lightPosition, GLfloat power, Vector3 scale, Vector3 position, Vector3 rotation)
    : Light(id, lightPosition,scale, position, rotation), power(power)
{
    
}

PointLight::PointLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3])
    : Light(id, lightPosition,scale, position, rotation), power(power)
{
    
}

GLfloat PointLight::getPower()
{
    return power;
}

void PointLight::setPower(GLfloat new_power)
{
    power = new_power;
}

void PointLight::onCreated()
{
    
}

void PointLight::draw()
{
    
}

void PointLight::onTouch(int eventsCount, int **touchInfo)
{
    
}

void PointLight::destroy()
{
    
}
