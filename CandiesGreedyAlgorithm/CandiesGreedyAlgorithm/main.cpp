//
//  main.cpp
//  CandiesGreedyAlgorithm
//
//  Created by Kenvin on 2017/11/30.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <vector>
#include <algorithm>

class Solution{
public:
    int findContentChildren(std::vector<int> &g,std::vector<int> &s){
        //对需求因子数组g与糖果大小数组s进行从小到大的排序
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int child = 0;
        int cookie = 0;
        //按照从小到大的顺序使用各糖果尝试是否可满足某个孩子，每个糖果只尝试1次；
        //若尝试成功，则换下一个孩子尝试；直到发现没更多的孩子或者没更多的糖果，循环结束
        while (child<g.size()&&cookie< s.size()) {
            if (g[child] <= s[cookie]) {
                child++;
            }
            cookie++;
        }
        return child;
    }
};

int main(int argc, const char * argv[]) {
   
    Solution solution;
    std::vector<int> g;
    std::vector<int> s;
    
    g.push_back(5);
    g.push_back(10);
    g.push_back(2);
    g.push_back(9);
    g.push_back(15);
    g.push_back(9);
    s.push_back(6);
    s.push_back(1);
    s.push_back(20);
    s.push_back(3);
    s.push_back(8);

    printf("%d \n",solution.findContentChildren(g, s));
    
    return 0;
}
