//
//  ViewController.swift
//  SumManger
//
//  Created by Kenvin on 2017/11/30.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

import UIKit
import Foundation
class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let sum = Sum.init();
        sum.wj_add { (mag) in
            print( mag.add()(20).result)
        }
    }
}


class SumManager:NSObject{
    var result:Int = 0
    func add()->((_ a:Int)->SumManager){
        return {a in
            self.result = self.result + a ;
            return self;
        }
    }
}


class Sum:NSObject{
    func wj_add(_ block:(_ mag:SumManager)->()){
        let mag:SumManager = SumManager.init()
        block(mag)
    }
}
