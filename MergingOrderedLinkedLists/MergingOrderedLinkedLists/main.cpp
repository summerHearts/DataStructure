//
//  main.cpp
//  MergingOrderedLinkedLists
//
//  Created by Kenvin on 2017/11/27.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int x): value(x),next(NULL){
        
    }
};


class Solution{
    public :
    ListNode *partition(ListNode *headA,ListNode *headB){
        //设置临时头节点temp_head
        ListNode temp_head(0);
        //使用pre指针指向temp_head
        ListNode *pre = &temp_head;
        while (headA&&headB) {
            //不同时为空，对他们进行比较
            if (headA->value < headB->value) {
                pre->next = headA;
                headA= headA->next;
            }else{
                pre->next = headB;
                headB= headB->next;
            }
            //pre指向新连接的节点
            pre= pre->next;
        }
        
        //如果headA有剩余
        if (headA) {
            //将headA接到pre后
            pre->next = headA;
        }
        
         //如果headB有剩余
        if (headB) {
            //将headB接到pre后
            pre->next = (headB);
        }
        return temp_head.next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode a(5);
    ListNode b(7);
    ListNode c(6);
    ListNode h(8);
    
    ListNode d(1);
    ListNode e(7);
    ListNode f(3);
    ListNode g(6);
    
    a.next = &b;
    b.next = &c;
    c.next = &h;
    h.next = &d;
    
    Solution solution;
    ListNode *headA = &a;
    
    ListNode *result = solution.partition(headA,6);
    
    while (result) {
        printf("%d \n" ,result->value);
        result = result->next;
    }
    
    return 0;
}

