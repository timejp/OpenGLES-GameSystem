//
//  ShaderManager.cpp
//  OpenGLGameSystem
//
//  Created by 윤중현 on 2017. 3. 12..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "ShaderManager.h"

ShaderManager::ShaderManager()
{
    
}

ShaderManager::~ShaderManager()
{
    _shaderData.clear();
}

ShaderManager &ShaderManager::getInstance()
{
    static ShaderManager *shaderManger = NULL;
    if (shaderManger == NULL) {
        shaderManger = new ShaderManager();
    }
    return *shaderManger;
}

void ShaderManager::destroy()
{
    AssetsManager::destroy();
    
    ShaderManager *shaderManager = &getInstance();
    
    if (shaderManager != NULL) {
        delete shaderManager;
    }
}

std::string ShaderManager::get(std::string SHADER)
{
    std::unordered_map<std::string, std::string>::const_iterator findIterator = _shaderData.find(SHADER);
    
    if (findIterator == _shaderData.end()) {
        _shaderData.insert(std::make_pair(SHADER, AssetsManager::getInstance().readFile(SHADER)));
        LOGI("%s is saved", SHADER.c_str());
        findIterator = _shaderData.find(SHADER);
    }
    
    return findIterator->second;
}
