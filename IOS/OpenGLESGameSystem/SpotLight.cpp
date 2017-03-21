//
//  SpotLight.cpp
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 18..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "SpotLight.h"

SpotLight::SpotLight(string id, Vector4 lightPosition, GLfloat power, GLfloat area)
    : Light(id, lightPosition), power(power), area(area)
{
    
}

SpotLight::SpotLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat area)
    : Light(id, lightPosition), power(power), area(area)
{
    
}

SpotLight::SpotLight(string id, Vector4 lightPosition, GLfloat power, GLfloat area, Vector3 scale)
    : Light(id, lightPosition, scale), power(power), area(area)
{
    
}

SpotLight::SpotLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat area, GLfloat scale[3])
    : Light(id, lightPosition,scale), power(power), area(area)
{
    
}

SpotLight::SpotLight(string id, Vector4 lightPosition, GLfloat power, GLfloat area, Vector3 scale, Vector3 position)
    : Light(id, lightPosition,scale, position), power(power), area(area)
{
    
}

SpotLight::SpotLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat area, GLfloat scale[3], GLfloat position[3])
    : Light(id, lightPosition,scale, position), power(power), area(area)
{
    
}

SpotLight::SpotLight(string id, Vector4 lightPosition, GLfloat power, GLfloat area, Vector3 scale, Vector3 position, Vector3 rotation)
    : Light(id, lightPosition,scale, position, rotation), power(power), area(area)
{
    
}

SpotLight::SpotLight(string id, GLfloat lightPosition[4], GLfloat power, GLfloat area, GLfloat scale[3], GLfloat position[3], GLfloat rotation[3])
    : Light(id, lightPosition,scale, position, rotation), power(power), area(area)
{
    
}

GLfloat SpotLight::getPower()
{
    return power;
}

void SpotLight::setPower(GLfloat new_power)
{
    power = new_power;
}

GLfloat SpotLight::getArea()
{
    return area;
}

void SpotLight::setArea(GLfloat new_area)
{
    area = new_area;
}

void SpotLight::onCreated()
{
    
}

void SpotLight::draw()
{
    
}

void SpotLight::onTouch(int eventsCount, int **touchInfo)
{
    
}

void SpotLight::destroy()
{
    
}
