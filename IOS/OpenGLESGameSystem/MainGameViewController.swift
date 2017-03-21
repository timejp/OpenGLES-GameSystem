//
//  ViewController.swift
//  OpenGLESGameSystem
//
//  Created by 윤중현 on 2017. 3. 16..
//  Copyright © 2017년 윤중현. All rights reserved.
//

import UIKit
import GLKit

class MainGameViewController: GLKViewController {

    static let MAX_TOUCH_COUNT: Int = 5
    
    var glkView: GLKView!
    var gameSystem: GameSystemWrapper!
    var iscreated: Bool = true
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        glkView = self.view as! GLKView
        glkView.context = EAGLContext(api: .openGLES2)
        
        gameSystem = GameSystemWrapper()
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    override func glkView(_ view: GLKView, drawIn rect: CGRect) {
        if iscreated {
            gameSystem.onCreated()
            let bounds = UIScreen.main.bounds
            let width = bounds.size.width
            let height = bounds.size.height
            gameSystem.onChanged(Int32(width), Int32(height))
            iscreated = false
        }
        gameSystem.onDraw()
    }
    
    override func viewWillTransition(to size: CGSize, with coordinator: UIViewControllerTransitionCoordinator) {
        // UIDevice.current.orientation.isLandscape // 화면 가로 세로 확인
        let bounds = UIScreen.main.bounds
        let width = bounds.size.width
        let height = bounds.size.height
        gameSystem.onChanged(Int32(height), Int32(width))
    }
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        let touchEvent = UnsafeMutablePointer<UnsafeMutablePointer<Int32>?>.allocate(capacity: touches.count)
        
        var i = 0
        for touch in touches {
            let point = touch.location(in: glkView)
            let info = UnsafeMutablePointer<Int32>.allocate(capacity: 4)
            info[0] = Int32(i)
            info[1] = 0
            info[2] = Int32(point.x)
            info[3] = Int32(point.y)
            touchEvent[i] = info
            i += 1
            if MainGameViewController.MAX_TOUCH_COUNT <= i {
                break
            }
        }
        gameSystem.onTouch(Int32(i), touchEvent)
    }
    
    override func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        let touchEvent = UnsafeMutablePointer<UnsafeMutablePointer<Int32>?>.allocate(capacity: touches.count)
        
        var i = 0
        for touch in touches {
            let point = touch.location(in: glkView)
            let info = UnsafeMutablePointer<Int32>.allocate(capacity: 4)
            info[0] = Int32(i)
            info[1] = 2
            info[2] = Int32(point.x)
            info[3] = Int32(point.y)
            touchEvent[i] = info
            i += 1
            if MainGameViewController.MAX_TOUCH_COUNT <= i {
                break
            }
        }
        gameSystem.onTouch(Int32(i), touchEvent)
    }
    
    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        let touchEvent = UnsafeMutablePointer<UnsafeMutablePointer<Int32>?>.allocate(capacity: touches.count)
        
        var i = 0
        for touch in touches {
            let point = touch.location(in: glkView)
            let info = UnsafeMutablePointer<Int32>.allocate(capacity: 4)
            info[0] = Int32(i)
            info[1] = 1
            info[2] = Int32(point.x)
            info[3] = Int32(point.y)
            touchEvent[i] = info
            i += 1
            if MainGameViewController.MAX_TOUCH_COUNT <= i {
                break
            }
        }
        gameSystem.onTouch(Int32(i), touchEvent)
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        print("viewWillDisappear")
        gameSystem.onDestroy()
    }
}

