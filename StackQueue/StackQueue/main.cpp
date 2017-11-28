//
//  main.cpp
//  StackQueue
//
//  Created by Kenvin on 2017/11/28.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <stack>

//将队列使用栈的方式实现
class MyQueue{
public:
    MyQueue(){}
    
    // 将元素x压入队列中
    void push(int x){
        std::stack<int> temp_stack;
        while (!_data.empty()) {
            //将栈中的数据push到临时栈中
            temp_stack.push(_data.top());
            _data.pop();
        }
        temp_stack.push(x);
        while (!temp_stack.empty()) {
            //将临时栈中的元素push到数据栈中
            _data.push(temp_stack.top());
            temp_stack.pop();
        }
    }
    
    //弹出(移除)队列头部元素,即弹出栈头部元素
    int pop(){
        int x = _data.top();
        _data.pop();
        return x ;
    }
    
    //返回队列头部元素(即为front)，返回栈顶元素top
    int peek(){
        return _data.top();
    }
    
    //判断队列是否是空
    bool empty(){
        return _data.empty();
    }
private:
    std::stack<int> _data;
};

int main(int argc, const char * argv[]) {
  
    MyQueue  q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    printf("%d\n",q.peek());
    q.pop();
    printf("%d\n",q.peek());

    return 0;
}
