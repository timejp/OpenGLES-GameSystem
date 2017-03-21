//
//  SocketControllerObjC.cpp
//  OpenGLGameSystem
//
//  Created by 윤중현 on 2017. 3. 12..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#include "GameSystemWrapper.h"
#include "GameSystem.h"

@implementation GameSystemWrapper {
    GameSystem *gameSystem;
}

-(id)init {
    self = [super init];
    gameSystem = &GameSystem::getInstance();
    return self;
}

-(void)dealloc {
    gameSystem->destroy();
}

- (void) onCreated {
    gameSystem->onCreated();
}

- (void) onChanged : (int) width : (int) height {
    gameSystem->onChanged(width, height);
}

- (void) onDraw {
    gameSystem->onDraw();
}

- (void) onTouch : (int) eventsCount : (int **) touchInfo {
    gameSystem->onTouch(eventsCount, touchInfo);
}

- (bool) onBackPressed {
    return gameSystem->onBackPressed();
}

- (void) onDestroy {
    gameSystem->onDestroy();
}

@end
