#include<bits/stdc++.h>
using namespace std;

/**
 * 将算法时间复杂度从O(N^2)简化到O(N):
 * 哈希表
 * 单调队列
 * 双指针
 * 贪心
 * 
 * 这道题用了单调队列的思想。
 */
class Solution{
    unordered_map<char, int> m;
    queue<char> Q;
public:
    //Insert one char from stringstream
    void insert(char ch){
        if(++m[ch]>1){
            while(!Q.empty() && m[Q.front()]>1) Q.pop();
        }
        else Q.push(ch);
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce(){
        if(Q.empty()) return '#';
        else return Q.front();
    }
};