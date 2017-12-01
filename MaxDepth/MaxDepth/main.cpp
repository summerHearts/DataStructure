//
//  main.cpp
//  MaxDepth
//
//  Created by Kenvin on 2017/09/12.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

#pragma mark -  首先定义节点
typedef struct BTree{
    int    value;
    struct BTree *lchild;
    struct BTree *rchild;
}BTree;

#pragma mark -  前序递归建立二叉树
BTree *CreateBTree(BTree *node,int *num,int& index){
    if(num[index] == 0){
        return NULL;
    }else{
        node = new BTree;
        node -> value = num[index];
        node -> lchild = CreateBTree(node->lchild,num,++index);
        node -> rchild = CreateBTree(node->rchild,num,++index);
    }
    return node;
}

#pragma mark -  递归－－前序遍历
void preOrder(BTree * root){
    if(root == NULL)
        return;
    //先输出树的根节点的值
    cout << root -> value << "         ";
    preOrder(root -> lchild);       //递归　左子树
    preOrder(root -> rchild);       //递归　右子树
}

#pragma mark -  非递归－－前序遍历（规则是先是根结点，再前序遍历左子树，再前序遍历右子树）
void preOrder_dxm(BTree * root){
    stack<BTree*> S;
    BTree *p = root;
    while(p != NULL || !S.empty()){
        while(p != NULL){
            cout << p -> value << "       ";
            S.push(p);
            p = p -> lchild;
        }
        if(!S.empty()){
            S.pop();
            if(S.empty())
                return ;
            p = S.top();
            S.pop();
            p = p -> rchild;
        }
    }
}

#pragma mark -  递归－－中序遍历 （规则是先中序遍历左子树，再是根结点，再是中序遍历右子树）
void inOrder(BTree * root){
    if(root == NULL)
        return;
    inOrder(root -> lchild);
    cout << root -> value << "         ";
    inOrder(root -> rchild);
}

#pragma mark -  非递归－－中序遍历
void inOrder_dxm(BTree * root){
    stack<BTree*> S;
    BTree *p = root;
    while(p != NULL || !S.empty()){
        while(p != NULL){
            //cout << p -> value << " ";
            S.push(p);
            p = p -> lchild;
        }
        if(!S.empty()){
            p = S.top();
            cout << p -> value << "      ";
            S.pop();
            if(S.empty())
                return ;
            //S.pop();
            p = S.top();
            cout << p -> value << "       ";
            S.pop();
            p = p -> rchild;
        }
    }
}

#pragma mark -  递归－－后序遍历 (规则是先后序遍历左子树，再是后序遍历右子树，再是根结点）

void postOrder(BTree * root){
    if(root == NULL)
        return;
    postOrder(root -> lchild);
    postOrder(root -> rchild);
    cout << root -> value << "       ";
}

#pragma mark -  非递归－－后序遍历
void postOrder_dxm(BTree * root){
    stack<BTree*> S;
    BTree *cur;
    BTree *pre = NULL;
    S.push(root);
    while(!S.empty()){
        cur = S.top();
        if((cur -> lchild == NULL && cur -> rchild == NULL) ||
           (pre != NULL && (pre == cur -> lchild || pre == cur ->rchild))){
            cout << cur -> value << "        ";
            S.pop();
            pre = cur;
        }else{
            if(cur -> rchild != NULL)
                S.push(cur -> rchild);
            if(cur -> lchild != NULL)
                S.push(cur -> lchild);
        }
    }
}

#pragma mark - 求二叉树的深度
int getdepth(BTree *root){
    if(root == NULL)
        return 0;
    int lchild_depth = getdepth(root -> lchild);
    int rchild_depth = getdepth(root -> rchild);
    return max(lchild_depth,rchild_depth) + 1;
}

#pragma mark - 求二叉树叶子节点的个数
int getleaves(BTree *root){
    if(root == NULL)
        return 0;
    if(root -> lchild == NULL && root -> rchild == NULL)
        return 1;
    return 1 + getleaves(root -> lchild) + getleaves(root -> rchild);
}


#pragma mark - 树状打印二叉树
void print(BTree *root,int h){
    if(root != NULL){
        print(root -> rchild,h+1);
        for(int i=0; i<h; i++)
            cout << "        ";
        cout << root -> value;
        print(root -> lchild,h+1);
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    int nums[] = {1,2,4,8,0,0,9,0,0,5,10,0,0,11,0,0,3,6,12,0,0,13,0,0,7,14,0,0,15,0,0};
    
    BTree *root = NULL;
    int index = 0;
    root = CreateBTree(root,nums,index);
    
    cout << "前序非递归遍历: " << endl;
    preOrder_dxm(root);
    cout << endl;
    
    cout << "中序递归遍历: " << endl;
    inOrder_dxm(root);
    cout << endl;
    
    cout << "后续非递归遍历: " << endl;
    postOrder_dxm(root);
    cout << endl << endl;;
    
    cout << "此二叉树的形状为: " << endl;
    print(root,1);

    return 0;
}
