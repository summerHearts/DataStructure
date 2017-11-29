//
//  main.cpp
//  KLargeNumbersOfHeaps
//
//  Created by Kenvin on 2017/11/29.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

class Solution{
public:
    int findKthLargest(std::vector<int> &nums, int k){
        std::priority_queue<int,std::vector<int>, std::greater<> > Q;
        for (int i = 0; i< nums.size(); i++) {
            //如果堆中元素个数小于K，直接push进入堆。
            if (Q.size()<k) {
                Q.push(nums[i]);
                //如果堆顶比新元素小，弹出堆顶
            }else if (nums[i]>Q.top()){
                Q.pop();
                //push进入新元素
                Q.push(nums[i]);
            }
        }
        return Q.top();
    }
};

int main(int argc, const char * argv[]) {
   
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(4);

    Solution ss;
    printf("%d \n",ss.findKthLargest(nums, 2));
    
    return 0;
}
