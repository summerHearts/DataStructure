//
//  main.cpp
//  LongestSwingSequence
//
//  Created by Kenvin on 2017/11/30.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
class Solution {
public:
    long wiggleMaxLength(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        long size = nums.size();
        if(size == 0) return 0;
        int up = 1, down = 1;
        for(int i = 1; i < size; ++i){
            if(nums[i] > nums[i-1]){
                up = down + 1;
            } else if (nums[i] < nums[i-1]){
                down = up + 1;
            }
        }
        return std::max(up, down);
    }
};
int main(int argc, const char * argv[]) {
    
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(17);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(13);
    nums.push_back(15);
    nums.push_back(10);
    nums.push_back(5);
    nums.push_back(16);
    nums.push_back(8);
    Solution solve;
    printf("%ld\n", solve.wiggleMaxLength(nums));
    return 0;
}
