//
//  main.cpp
//  Priority_queues
//
//  Created by Kenvin on 2017/11/29.
//  Copyright © 2017年 Kenvin. All rights reserved.
//


#include <iostream>
#include <queue>

using namespace std;

struct Node{
    int x, y;
    Node( int a= 0, int b= 0 ):x(a), y(b) {}
};

bool operator<( Node a, Node b ){
    if( a.x== b.x ){
      return a.y> b.y;
    }else{
      return a.x> b.x;
    }
}

int main(int argc, const char * argv[]) {
    priority_queue<Node> q;
    
    for( int i= 0; i< 10; ++i ){
        q.push( Node( rand()%5+20, rand()%6+80 ) );
    }
    
    printf("min heap.top = %d \n",q.top().x);

    while( !q.empty() ){
        cout << q.top().x << ' ' << q.top().y << endl;
        q.pop();
    }
    
    getchar();
    return 0;
}
