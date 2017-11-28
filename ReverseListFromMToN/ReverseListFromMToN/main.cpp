//
//  main.cpp
//  ReverseListFromMToN
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
public:ListNode* reverseBetween(ListNode *head,int m ,int n) {
    //计算需要逆置的节点个数
    int change_len = n - m + 1;
    //初始化开始逆置的节点前驱
    ListNode *pre_node = NULL;
    //最终转换后的链表头节点，非特殊情况为head
    ListNode *reslut = head;
  
    //将head向前移动m-1个位置
    while (head&&--m) {
        pre_node = head;  //记录head的前驱
        head = head->next;
    }
    
    //将modify_list_tail指向当前的head,即逆置之后的链表尾部
    ListNode *modify_list_tail = head;
    ListNode *new_head = NULL;
    
    while (head&&change_len) {
        //备份  head->next
        ListNode *next = head->next;
        
        //更新  head->next
        head->next = new_head;
        //
        new_head = head;
        // 为下一次循环指向做准备
        head = next;
        // 每完成一个节点逆置，change_len--
        change_len--;
    }
    
    //连接逆置后的链表尾与逆置段的后一个节点
    modify_list_tail->next = head;
    
    //如果pre_node不空，说明不是从第一个节点开始逆置的 m>1
    if (pre_node) {
        //将逆置链表开始的节点前驱与逆置后的头节点链接
        pre_node->next = new_head;
    }else{
        //如果pre_node为空，说明m==1从第一个节点开始逆置结果即为逆置后的头节点
        reslut = new_head;
    }
    
    return reslut;
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
    
    head = solution.reverseBetween(&a, 2, 4);
    
    while (head) {
        printf("%d \n" ,head->value);
        head = head->next;
    }
    
    return 0;
}

