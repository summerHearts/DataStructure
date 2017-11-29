//
//  main.cpp
//  BinaryHeap
//
//  Created by Kenvin on 2017/11/29.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <queue>

int main(int argc, const char * argv[]) {
   
    //默认构造是最大堆
    std::priority_queue<int> big_heap;
    //最小堆的构造方法
    std::priority_queue<int,std::vector<int>,std::greater<int>> small_heap;
    //最大堆的构造方法
    std::priority_queue<int,std::vector<int>,std::less<int>> big_heap2;
    
    if (big_heap.empty()) {
        printf("big_heap is empty! \n");
    }
    
    int test[] = {6,10,1,7,99,4,33};
    for (int i = 0; i< 7; i++) {
        big_heap.push(test[i]);
    }
    
    printf("big heap.top = %d \n",big_heap.top());
    big_heap.push(10000);
    printf("big heap.top = %d \n",big_heap.top());

    for (int i = 0; i<3; i++) {
        big_heap.pop();
    }
    printf("big heap.top = %d \n",big_heap.top());
    printf("big heap.top = %ld \n",big_heap.size());

    
    return 0;
}
