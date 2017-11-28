//
//  main.cpp
//  QuqueStack
//
//  Created by Kenvin on 2017/10/28.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <queue>

class MyStack{
public:
    MyStack(){
    }
    
    void push(int x){
        std::queue<int> temp_queue;
        //将新元素push进入  临时队列temp_queue
        temp_queue.push(x);
        
        while (!_data.empty()) {
            //将原队列中的元素push进入 临时队列temp_queue
            temp_queue.push(_data.front());
            _data.pop();
        }
        
        while (!temp_queue.empty()) {
            //将 临时队列temp_queue元素push 进入数据队列data_queue
            _data.push(temp_queue.front());
            temp_queue.pop();
        }
    }
    
    //pop弹出栈顶元素
    int pop(){
        int x = _data.front();
        _data.pop();
        return x;
    }
    
    //返回栈顶即直接返回队列头部元素
    int top(){
        return _data.front();
    }
    
    bool empty(){
        return _data.empty();
    }
private:
    std::queue<int> _data;
};

int main(int argc, const char * argv[]) {
   
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    printf("%d \n",s.top());
    s.pop();
    printf("%d \n",s.top());
    s.push(5);
    printf("%d \n",s.top());
    return 0;
}
