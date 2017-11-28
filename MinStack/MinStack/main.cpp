//
//  main.cpp
//  MinStack
//
//  Created by Kenvin on 2017/11/28.
//  Copyright © 2017年 Kenvin. All rights reserved.
//

#include <iostream>
#include <stack>

class MinStack{
public:
    MinStack(){}
    
    void push(int x){
        //将数据压入数据栈
        _data.push(x);
        if (_min.empty()) {
            _min.push(x);
        }else{
            //如果新数据大于最小值栈的栈顶，则此时状态的最小值状态为x = _min.top()
            if (x> _min.top()) {
                x = _min.top();
            }
            //将x push进入最小值栈
            _min.push(x);
        }
    }
    //数据栈和最小值栈同时弹出
    void pop(){
        
        _data.pop();
        _min.pop();
    }
    // 返回数据栈栈顶
    int top(){
        return  _data.top();
    }
    
    // 返回最小值栈栈顶
    int getMin(){
        return _min.top();
    }
    
private:
    //数据栈
    std::stack<int> _data;
    //最小值栈
    std::stack<int> _min;
};


int main(int argc, const char * argv[]) {

    return 0;
}
