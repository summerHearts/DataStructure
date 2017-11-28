//
//  main.cpp
//  Stack
//
//  Created by Kenvin on 2017/10/10.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <stack>
int main(int argc, const char * argv[]) {

    std::stack<int> S ;
    if (S.empty()) {
        printf("S is empty");
    }
    
    S.push(5);
    S.push(3);
    S.push(10);
    
    printf("S.top = %d \n",S.top());
    S.pop();
    S.pop();
    printf("S.top = %d \n",S.top());
    
    printf("S.size = %ld \n",S.size());
    
    return 0;
}
