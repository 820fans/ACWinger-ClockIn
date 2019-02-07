/**
 * 计算a*b % p 的值
 * 其中a,b,p都是int
 */
#include<iostream>

using namespace std;

int quick_pow(int a, int b, int p){
    int ans = 1%p;
    for(;b;b>>=1){
        if(b&1) ans = 1ll*ans*a % p;
        a = 1ll*a%p;
    }
    return ans;
}

int main(){
    int res = quick_pow(23, 47, 100001);
    cout<<res<<endl;
    return 0;
}