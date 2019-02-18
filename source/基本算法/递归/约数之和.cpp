#include<iostream>
#define M 9901
#define ll long long 
using namespace std;

ll a,b;
ll ksm(ll a, ll b){
    ll ans = 1 % M;
    for(;b;b>>=1){
        if(b&1) ans = ans*a%M;
        a = a*a%M;
    }
    return ans;
}
ll sum(ll a,ll c)
{
    if (c==0) return 1;
    if(c&1)
        return ((1+ksm(a,(c+1)>>1)) * sum(a,(c-1)>>1)) % M;    // 奇数的情况下 
    else 
    return ((1+ksm(a,c>>1)) * sum(a,(c>>1)-1) + ksm(a,c)) % M; // 偶数的情况下 
}

int main(){
    cin>>a>>b;
    ll ans=1;
    for (ll i=2;i<=a;i++) {
        ll s=0;
        while(a%i==0) {
            s++;
            a/=i;
        }
        ans=ans*sum(i,s*b)%M;
    }
    if (a==0) cout<<0<<endl;
    else cout<<ans<<endl;
    return 0;
}
