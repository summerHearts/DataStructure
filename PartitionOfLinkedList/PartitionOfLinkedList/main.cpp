//
//  main.cpp
//  PartitionOfLinkedList
//
//  Created by Kenvin on 2017/11/27.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <set>

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int x): value(x),next(NULL){
        
    }
};


class Solution{
    public :
    ListNode *partition(ListNode *head,int x){
        
        //设置两个临时的头节点
        ListNode less_node(0);
        ListNode more_head(0);
        
        //对应指针指向这两个头节点
        ListNode *less_ptr = &less_node;
        ListNode *more_ptr = &more_head;
        
        while (head) {
            //如果节点值小于x,则将该节点插入less_ptr后
            if (head->value < x) {
                less_ptr->next = head;
                //链接完成之后，less_ptr向后移动，指向head
                less_ptr = head;
            }else{
                //否则将该节点插入more_ptr后
                more_ptr->next = head;
                more_ptr = head;
            }
            //遍历链表
            head = head->next;
        }
        //将less链表尾和more链表头部相连。
        less_ptr->next = more_head.next;
        // 将more_ptr即链表尾部节点next置为空
        more_ptr->next = NULL;
        return less_node.next;
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

