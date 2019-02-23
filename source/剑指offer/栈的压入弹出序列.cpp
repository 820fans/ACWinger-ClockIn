#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 思路更加顺畅，思路更加清晰的版本
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> Q;
        int m=pushV.size(), n=popV.size();
        if(m!=n || !n) return false;
        int pos=0;
        for(int i=0;i<n;i++){
            Q.push(pushV[i]);
            while(!Q.empty() && Q.top()==popV[pos]){
                Q.pop();
                pos++;
            }
        }
        return Q.empty();
    }

    // 自己写的有点搓
    bool isPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> Q;
        int m=pushV.size(), n=popV.size();
        if(m!=n || !n) return false;
        int pos1=0, pos2=0;
        while(pos2<n){
            if(Q.empty()) {
                if(pos1<n) Q.push(pushV[pos1++]);
                else return false;
            }
            else{
                if(pos2<n && Q.top()==popV[pos2]) Q.pop(), pos2++;
                else if(pos1<n) Q.push(pushV[pos1++]);
                else return false;
            }
        }
        return true;
    }
};