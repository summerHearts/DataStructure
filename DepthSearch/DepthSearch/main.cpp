//
//  main.cpp
//  DepthSearch
//
//  Created by Kenvin on 2017/12/1.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <stdio.h>

#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int> > pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int> > result;
        std::vector<int> path;
        int path_value = 0;
        preorder(root, path_value, sum, path, result);
        return result;
    }
private:
    void preorder(TreeNode *node, int &path_value, int sum,
                  std::vector<int> &path,
                  std::vector<std::vector<int> > &result){
        if (!node){
            return;
        }
        //遍历一个节点即更新一次路径值
        path_value += node->val;
        path.push_back(node->val);
        // 满足条件时需要将路径栈保存
        if (!node->left && !node->right && path_value == sum){
            result.push_back(path);
        }
        preorder(node->left, path_value, sum, path, result);
        preorder(node->right, path_value, sum, path, result);
        path_value -= node->val;
        // 遍历完成后，将该节点从路径栈中弹出
        path.pop_back();
    }
};

int main(){
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;
    Solution solve;
    std::vector<std::vector<int> > result = solve.pathSum(&a, 22);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

