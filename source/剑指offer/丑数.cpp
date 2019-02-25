#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int uglyNumber(int n){
        // 3个序列，多路归并
        /**
         *i--> 2 4 6 8 10
         *j--> 3 6 9 12
         *k--> 5 10 15
         */ 
        vector<int> dp(1, 1);
        int i=0, j=0, k=0;
        while(--n){
            int t= min(dp[i]*2, min(dp[j]*3, dp[k]*5));
            dp.push_back(t);
            if(t==dp[i]*2) i++;
            if(t==dp[j]*3) j++;
            if(t==dp[k]*5) k++;
        }
        return dp.back();
    }
};