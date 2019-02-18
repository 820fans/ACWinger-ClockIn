#include<bits/stdc++.h>
using namespace std;


class MinStack {
    stack<int> Q1, Q2;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        Q1.push(x);
        if(Q2.empty()) Q2.push(x);
        else Q2.push(min(Q2.top(), x));
    }
    
    void pop() {
        Q1.pop();
        Q2.pop();
    }
    
    int top() {
        return Q1.top();
    }
    
    int getMin() {
        return Q2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */