//
//  DirectionLight.cpp
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 18..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "DirectionLight.h"

DirectionLight::DirectionLight(string id, Vector4 lightPosition)
    : Light(id, lightPosition)
{
    
}

DirectionLight::DirectionLight(string id, GLfloat lightPosition[4])
    : Light(id, lightPosition)
{
    
}

DirectionLight::DirectionLight(string id, Vector4 lightPosition, Vector3 scale)
    : Light(id, lightPosition, scale)
{
    
}

DirectionLight::DirectionLight(string id, GLfloat lightPosition[4], GLfloat scale[3])
    : Light(id, lightPosition,scale)
{
    
}

DirectionLight::DirectionLight(string id, Vector4 lightPosition, Vector3 scale, Vector3 position)
    : Light(id, lightPosition,scale, position)
{
    
}

DirectionLight::DirectionLight(string id, GLfloat lightPosition[4], GLfloat scale[3], GLfloat position[3])
    : Light(id, lightPosition,scale, position)
{
    
}

DirectionLight::DirectionLight(string id, Vector4 lightPosition, Vector3 scale, Vector3 position, Vector3 rotation)
    : Light(id, lightPosition,scale, position, rotation)
{
    
}

DirectionLight::DirectionLight(string id, GLfloat lightPosition[4], GLfloat scale[3], GLfloat position[3], GLfloat rotation[3])
    : Light(id, lightPosition,scale, position, rotation)
{
    
}

void DirectionLight::onCreated()
{
    
}

void DirectionLight::draw()
{
    
}

void DirectionLight::onTouch(int eventsCount, int **touchInfo)
{
    
}

void DirectionLight::destroy()
{
    
}
