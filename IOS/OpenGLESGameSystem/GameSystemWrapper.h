//
//  GameSystemWrapper_h
//  OpenGLGameSystem
//
//  Created by 윤중현 on 2017. 3. 12..
//  Copyright © 2017년 윤중현. All rights reserved.
//

#ifndef GameSystemWrapper_h
#define GameSystemWrapper_h

#import <Foundation/Foundation.h>

@interface GameSystemWrapper : NSObject
- (void) onCreated;
- (void) onChanged:(int) width : (int) height;
- (void) onDraw;
- (void) onTouch:(int) eventsCount : (int **) touchInfo;
- (bool) onBackPressed;
- (void) onDestroy;
@end


#endif /* GameSystemWrapper_h */
