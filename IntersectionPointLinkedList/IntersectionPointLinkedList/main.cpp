//
//  main.cpp
//  IntersectionPointLinkedList
//
//  Created by Kenvin on 2017/11/27.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <set>

void findSameElement () {
    std::set<int> test_set;
    const int A_LENGTH = 7;
    const int B_LENGTH = 8;
    
    int a[A_LENGTH] = {5,1,4,8,10,1,3};
    int b[B_LENGTH] = {2,7,6,3,1,6,0,1};
    
    for (int i = 0; i< A_LENGTH; i++) {
        test_set.insert(a[i]);
    }
    for (int i = 0; i< B_LENGTH; i++) {
        if (test_set.find(b[i]) != test_set.end()) {
            printf("b[%d] = %d in ArrayA.\n" ,i ,b[i]);
        }
    }
};

struct ListNode {
    int value;
    ListNode *next;
    ListNode(int x): value(x),next(NULL){
        
    }
};


class Solution{
    public :
    ListNode *getIntersectionNode(ListNode *headA ,ListNode *headB){
        
        //设置查找集合node_set
        std::set<ListNode *>node_set;
        while (headA) {
            node_set.insert(headA);
            //遍历链表A
            headA = headA->next;
        }
        
        while (headB) {
            //在set中查找是否存在
            if (node_set.find(headB) != node_set.end()) {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};

/*
 *1:如果两个链表没有交点，则返回NULL
 *2:在求交点的过程中，不可以破坏链表的结构或者修改链表的数据域
 *3:可以确保传入的链表A与链表B没有任何环。
 *4:实现算法尽可能使时间复杂度为O(n)，空间复杂度O(1)
 */


int get_list_length(ListNode *head){
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

ListNode *forward_long_list(int long_len,int short_len,ListNode *head){
    int delta = long_len - short_len;
    while (head&&delta) {
        head = head->next;
        delta--;
    }
    return head;
}

class SolutionA{
    public :
    ListNode *getIntersectionNode(ListNode *headA ,ListNode *headB){
        int list_A_length = get_list_length(headA);
        int list_B_length = get_list_length(headB);
        
        if (list_A_length>list_B_length) {
            headA = forward_long_list(list_A_length, list_B_length, headA);
        }else{
            headB = forward_long_list(list_B_length, list_A_length, headB);
        }
        
        while (headA&&headB) {
            if (headA==headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
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
    
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &c;
    c.next = &h;

    SolutionA solution;
    ListNode *headA = &a;
    ListNode *headB = &d;
    
    ListNode *result = solution.getIntersectionNode(headA, headB);
    printf("%d\n",result->value);
    
    return 0;
}
