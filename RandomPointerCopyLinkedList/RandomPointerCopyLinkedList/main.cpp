//
//  main.cpp
//  RandomPointerCopyLinkedList
//
//  Created by Kenvin on 2017/11/27.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>

struct RandomListNode {
    int value;
    RandomListNode *next ,*random;
    RandomListNode(int x): value(x),next(NULL) ,random(NULL){}
};

class Solution{
public:
    RandomListNode *copyRandomList(RandomListNode *head){
        
        std::map<RandomListNode *, int > node_map;
        std::vector<RandomListNode *> node_vec;
        
        RandomListNode *ptr = head;
        int i = 0;
        while (ptr) {
            node_vec.push_back(new RandomListNode(ptr->value));
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;
        }
        
        node_vec.push_back(0);
        ptr = head;
        i = 0;
        while (ptr) {
            node_vec[i]->next = node_vec[i+1];
            if (ptr->random) {
                int id = node_map[ptr->random];
                node_vec[i]->random = node_vec[id];
            }
            
            ptr = ptr->next;
            i++;
        }
        return node_vec[0];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    std::map<RandomListNode *, int > node_map;
    RandomListNode a(5);RandomListNode b(3);RandomListNode c(6);RandomListNode d(7);RandomListNode e(1);
    
    a.next = &b;b.next = &c;c.next = &d;d.next = &e;
    
    a.random = &c;b.random = &d;c.random = &c;e.random = &d;
    
    Solution solve;
    
    RandomListNode *head = solve.copyRandomList(&a);
    
    while (head) {
           printf("value = %d \n",head->value);
        if (head->random) {
            printf("rand = %d \n ",head->random->value);
        }else{
            printf("rand = NULL \n ");
        }
        head = head->next;
    }

    return 0;
}

