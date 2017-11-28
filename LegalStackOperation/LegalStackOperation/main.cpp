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
    std::stack<int> S ;
    long n = order.size();
    for (int i = 0; i<= n; i++) {
        S.push(i);
        while (!S.empty()&&order.front() == S.top()) {
            S.pop();
            order.pop();
        }
    }
    
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
