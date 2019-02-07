#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

void hanoi(int n, char a, char b, char c) {
    if(n==1){
        printf("%c -> %c\n", a, c);
    }
    else{
        hanoi(n-1, a, c, b);
        printf("%c -> %c\n", a, c);
        hanoi(n-1, b, a, c);
    }
}

int hanoi_3_count(int n){
    int res = 1;
    for(int i=2;i<=n;i++)
    res = res*2 + 1;
    return res;
}

void hanoi_4_count(){
    vector<int> dp(13, 0);
    // vector<int> f(13, 0x3f);
    vector<int> f(13, INT_MAX);
    // int f[13];
    // memset(f,0x3f,sizeof(f));
    dp[1]=1;
    for(int i=2;i<=12;i++) dp[i]=2*dp[i-1]+1;
    f[0]=0;
    for(int i=1;i<=12;i++) {
        for(int j=0;j<i;j++){
            f[i] = min(f[i], 2*f[j] + dp[i-j]);
        }
    }
    for(int i=1;i<=12;i++) cout<<f[i]<<endl;
}

int main(){
    // hanoi(2, 'a', 'b', 'c');
    hanoi_4_count();
    return 0;
}