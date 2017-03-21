//
//  Logger.h
//  OpenGLGameSystem
//
//  Created by 윤중현 on 2017. 3. 12..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef Logger_h
#define Logger_h

#include <stdio.h>

static const bool debug = true;

#ifndef LOG_TAG
#define  LOG_TAG    "GameSystem-lib"
#define  LOGI(...)  if(debug) printf(__VA_ARGS__); if (debug) printf("\n")
#define  LOGE(...)  if(debug) printf(__VA_ARGS__); if (debug) printf("\n")
#endif

#endif /* Logger_h */
