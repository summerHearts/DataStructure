//
//  main.cpp
//  GreedyAlgorithm
//
//  Created by Kenvin on 2017/11/29.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    const int RMN[] = {100,50,20,10,5,2,1};
    const int NUM = 7;
    
    int x = 688;
    int count = 0;
    
    for (int i = 0; i< NUM; i++) {
        //得出使用最大面额多少张
        int use = x /RMN[i];
        //记录当前使用了多少张
        count = count + use;
        //得出剩余的需要凑齐的面额
        x = x - use*RMN[i];
        printf("需要面额为：%d的%d张RMB\n",RMN[i],use);
        printf("剩余需要支付RMB %d.\n",x);
    }
    printf("总共需要 %d张RMB\n",count);
    return 0;
}
