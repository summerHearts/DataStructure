//
//  main.cpp
//  SingleNumber
//
//  Created by Kenvin on 2017/12/1.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <algorithm>
/*
 给定一组整数，除了一个元素外，每个元素都出现两次。找到那一个。
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        int result=0;
        for(int i=0; i<n; i++){
            //异或运算 :出现两次的元素消除 a^a = 0,只剩下那个出现一次的元素了 0^b = b
            result ^= A[i];
        }
        return result;
    }
};

/*
 *Single Number的本质，就是用一个数记录每个bit出现的次数，如果一个bit出现两次就归0，这种运算采用二进制底下的位操作^是很自然的。
 *Single Number II中，如果能定义三进制底下的某种位操作，也可以达到相同的效果，Single Number II中想要记录每个bit出现的次数，一个数搞不定就加两个数，用ones来记录只出现过一次的bits，用twos来记录只出现过两次的bits，ones&twos实际上就记录了出现过三次的bits，这时候我们来模拟进行出现3次就抵消为0的操作，抹去ones和twos中都为1的bits。
 * 预备知识点：
 *   1: &  如果两个相应的二进制位都为１，则该位的结果值为1；否则为0
 *   2: |  如果两个相应的二进制位只要有一个是1，结果就是1；否则为0。
 *   3: ^  异或： 两个相同的数会变成0，反之是1
 *   4: << 向左移位移 11 << 1 = 22   00001011 << 1   00010110 = 22
 *   5: >> 向右位移  向右移一位，左边自动补1。 11 >> 1 =  5   00001011 >> 1  00000101 = 5
 *   6: ~  x-y = x + ~y + 1   所以~y = - y  -1   比如 ~11 = -11 -1 = -12
 */
class SolutionB{
public:
    int singleNumber(int A[],int n) {
   
        int ones = 0;//记录只出现过1次的bits
        int twos = 0;//记录只出现过2次的bits
        int threes;
        for(int i = 0; i < n; i++){
            int t = A[i];
            twos |= ones&t;//要在更新ones前面更新twos
            ones ^= t;
            threes = ones&twos;//ones和twos中都为1即出现了3次
            ones &= ~threes;//抹去出现了3次的bits
            twos &= ~threes;
            }
        return ones;
    }
};

/*
 * 1: 第一次遍历  t = 2,ones = 0. 那么   0&0010 等于0，这样是因为相应的位上不同。
 *  ones ^=t 表示ones^t   ones= 0, t为0010，那么相应位上只要有一个1，结果就为1.结果为t
 */

int main(int argc, const char * argv[]) {
    Solution solution;
    SolutionB solutionB;

    int A[7] = {2,2,3,3,8,6,6};
    printf("%d \n",solution.singleNumber(A, 7));
    
    
    int B[10] = {2,2,2,3,3,3,8,6,6,6};
    printf("%d \n",solutionB.singleNumber(B, 10));
    
    return 0;
}
