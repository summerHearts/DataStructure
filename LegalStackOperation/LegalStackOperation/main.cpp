//
//  main.cpp
//  LegalStackOperation
//
//  Created by Kenvin on 2017/11/28.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

bool check_is_valid_order(std::queue<int> &order){
    //S  为模拟栈
    std::stack<int> S ;
    // 获取队列的长度，将1 到 N 的元素按顺序入栈
    long n = order.size();
    
    for (int i = 0; i<= n; i++) {
        //将元素入栈
        S.push(i);
        //比较每push 一个元素，即检查是否与队列首部元素相同则弹出队列首元素，弹出栈顶元素，直到两元素不同结束。
        while (!S.empty()&&order.front() == S.top()) {
            //弹出队列首元素，弹出栈顶元素
            S.pop();
            order.pop();
        }
    }
    //执行到最后，发现栈不为空，说明是不合法的
    if (!S.empty()) {
        return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
 
    int n ;
    
    int train;
    
    scanf("%d",&n);

    while (n) {
        scanf("%d",&train);
        while (train) {
            std::queue<int> order;
            order.push(train);
            for (int i = 0; i< n; i++) {
                scanf("%d",&train);
                order.push(train);
            }
            
            if (check_is_valid_order(order)) {
                printf("YES \n");
            }else{
                printf("NO\n");
            }
            
            scanf("%d",&train);
        }
        printf("\n");
        scanf("%d",&n);
    }
    
    return 0;
}
