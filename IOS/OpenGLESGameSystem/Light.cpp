//
// Created by 윤중현 on 2017. 3. 8..
//

#include "Light.h"


char Light::TYPE_LIGHT = 0;
char Light::TYPE_SPOT_LIGHT = 1;

Light::Light(string id, Vector4 lightPosition)
    : Object(id)
{
    setLightPosition(lightPosition);
}

Light::Light(string id, GLfloat lightPosition[4])
    : Object(id)
{
    setLightPosition(lightPosition);
}

Light::Light(string id, Vector4 lightPosition, Vector3 scale)
    : Object(id, scale)
{
    setLightPosition(lightPosition);
}

Light::Light(string id, GLfloat lightPosition[4], GLfloat scale[3])
    : Object(id, scale)
{
    setLightPosition(lightPosition);
}

Light::Light(string id, Vector4 lightPosition, Vector3 scale, Vector3 position)
    : Object(id, scale, position)
{
    setLightPosition(lightPosition);
}

Light::Light(string id, GLfloat lightPosition[4], GLfloat scale[3], GLfloat position[3])
    : Object(id, scale, position)
{
    setLightPosition(lightPosition);
}

Light::Light(string id, Vector4 lightPosition, Vector3 scale, Vector3 position, Vector3 rotation)
    : Object(id, scale, position, rotation)
{
    setLightPosition(lightPosition);
}

Light::Light(string id, GLfloat lightPosition[4], GLfloat scale[3], GLfloat position[3], GLfloat rotation[3])
    : Object(id, scale, position, rotation)
{
    setLightPosition(lightPosition);
}

void Light::setLightPosition(Vector4 position)
{
    Light::lightPosition[0] = position.x;
    Light::lightPosition[1] = position.y;
    Light::lightPosition[2] = position.z;
    Light::lightPosition[3] = position.w;
}

void Light::setLightPosition(GLfloat position[4])
{
    Light::lightPosition[0] = position[0];
    Light::lightPosition[1] = position[1];
    Light::lightPosition[2] = position[2];
    Light::lightPosition[3] = position[3];
}
