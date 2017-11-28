//
//  main.cpp
//  IntersectionPointLinkedList
//
//  Created by Kenvin on 2017/11/27.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <set>


struct ListNode {
    int value;
    ListNode *next;
    ListNode(int x): value(x),next(NULL){}
};


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
    ListNode *detectCycle(ListNode *head){
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = NULL;
        
        while (fast) {
            //让fast和slow各走一步
            slow = slow->next;
            fast = fast->next;
            
            if (!fast) {
                //如果fast遇到链表尾，则返回NULL
                return NULL;
            }
            //fast 再走一步，设置比slow快一步
            fast = fast->next;
            if (fast == slow) {
                //fast与slow相遇，记录相遇位置
                meet = fast;
                break;
            }
        }
        
        if (meet == NULL) {
            // 如果没有遇见，说明无环结构
            return NULL;
        }
        
        while (head&&meet) {
            //当head == meet相遇，说明遇到了环的起始位置
            if (head == meet) {
                return head;
            }
            
            head = head->next;
            meet = meet->next;
        }
        return NULL;
    }
};


class Solution{
    public :
    ListNode *detectCycle(ListNode *head){
        
        //设置查找集合node_set
        std::set<ListNode *>node_set;
        
        while (head) {
            if (node_set.find(head) != node_set.end()) {
                return head;
            }
            node_set.insert(head);
            //遍历链表A
            head = head->next;
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
    h.next = &b;
    
    
    SolutionA solution;
    ListNode *headA = &a;
    
    ListNode *result = solution.detectCycle(headA);
    printf("%d\n",result->value);
    
    return 0;
}
