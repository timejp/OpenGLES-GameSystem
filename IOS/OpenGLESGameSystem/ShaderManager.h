//
//  ShaderManager.h
//  OpenGLGameSystem
//
//  Created by 윤중현 on 2017. 3. 12..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef ShaderManager_h
#define ShaderManager_h

#include <unordered_map>
#include <string>
#include "AssetsManager.h"
#include "Logger.h"

class ShaderManager {
private:
    
    std::unordered_map<std::string, std::string> _shaderData;
    
    ShaderManager();
    ~ShaderManager();
    
public:
    
    static ShaderManager &getInstance();
    static void destroy();
    
    std::string get(std::string SHADER);
};

#endif /* ShaderManager_h */
