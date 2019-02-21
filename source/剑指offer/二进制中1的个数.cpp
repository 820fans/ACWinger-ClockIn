#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        int sum=0;
        for(int k=31;k>=0;k--){
            sum+= n>>k&1;
        }
        return sum;
    }

    int ksm(int a, int b, int p){
        int ans = 1%p;
        for(;b;b>>=1){
            if(b&1) ans=1ll*ans*a%p;
            a=1ll*a*a%p;
        }
        return ans;
    }
};