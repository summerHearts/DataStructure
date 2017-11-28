//
//  main.cpp
//  Queue
//
//  Created by Kenvin on 2017/11/28.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <queue>
int main(int argc, const char * argv[]) {
    std::queue<int> Q;
    
    if (Q.empty()) {
        printf("Q is empty !\n");
    }
    
    Q.push(5);
    Q.push(6);
    Q.push(10);
    
    printf("Q.font = %d \n",Q.front());
    Q.pop();
    Q.pop();
    printf("Q.font = %d \n",Q.front());

    Q.push(1);
    printf("Q.back = %d \n",Q.back());
    printf("Q.size = %ld \n",Q.size());
    
    return 0;
}
