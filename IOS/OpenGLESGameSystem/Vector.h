//
//  Vector.h
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 18..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

#include <OpenGLES/ES2/gl.h>

typedef struct {
    GLfloat x;
    GLfloat y;
}Vector2;

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
}Vector3;

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
    GLfloat w;
}Vector4;

#endif /* Vector_h */
