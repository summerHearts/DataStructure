//
//  main.cpp
//  ReverseLinkedList
//
//  Created by Kenvin on 2017/11/27.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode
{
    int value;
    ListNode *next;
    ListNode (int x) : value(x),next(NULL){}
};

class Solution {
    public: ListNode *reverseList(ListNode *head){
        ListNode *new_head = NULL;
        while (head) {
            //备份 head ->next
            ListNode *next = head ->next;
            //修改head ->next 指向new_head节点
            head->next = new_head;
            //移动head 与new_head
            new_head = head;
            head = next;
        }

        return new_head;// 返回新链表的头节点
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    Solution solution;
    ListNode *head = &a;
    while (head) {
        head = head->next;
    }
    
    head = solution.reverseList(&a);
    
    while (head) {
        head = head->next;
    }

    return 0;
}


