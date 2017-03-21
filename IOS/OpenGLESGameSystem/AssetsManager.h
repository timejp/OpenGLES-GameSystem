//
//  AssetsManager.h
//  OpenGLGameSystem
//
//  Created by 윤중현 on 2017. 3. 12..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef AssetsManager_h
#define AssetsManager_h

#include <Foundation/Foundation.h>
#include <stdlib.h>
#include <string>
#include "Logger.h"

class AssetsManager {
private:
    AssetsManager();
    ~AssetsManager();
    
public:
    static AssetsManager &getInstance();
    
    static void destroy();
    
    std::string readFile(std::string filename);
};

#endif /* AssetsManager_h */
