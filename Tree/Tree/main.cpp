//
//  main.cpp
//  Tree
//
//  Created by Kenvin on 2017/09/12.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): value(x),left(NULL),right(NULL) {}
};

void preorder_Print(TreeNode *node,int layer){
    //正在遍历的节点
    if (!node) {
        return;
    }
    //根据层数，打印相应数量的-
    for (int i = 0; i< layer; i++) {
        printf("----------");
    }
    
    printf("[%d]\n",node->value);

    //遍历左子树和右子树，层数+1
    preorder_Print(node->left, layer+1);
    preorder_Print(node->right, layer+1);
}

int main(int argc, const char * argv[]) {
    
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    
    a.left = &b;
    a.right = &c;
    
    b.left = &d;
    b.right = &e;
    c.right = &f;
    
    preorder_Print(&a,0);

    return 0;
}
