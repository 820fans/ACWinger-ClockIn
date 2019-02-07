#include<bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll, ll> calc(int n, ll m){
    if(n==0) return make_pair(0,0);
    
    ll len = 1ll<<(n-1), cnt= 1ll<<(2*n-2);
    pair<ll, ll> pos = calc(n-1, m%cnt);
    ll x=pos.first, y = pos.second;
    
    ll z=m/cnt;
    if(z==0) return make_pair(y, x);
    if(z==1) return make_pair(x, y+len);
    if(z==2) return make_pair(x+len, y+len);
    if(z==3) return make_pair(2*len-y-1, len-x-1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, s, d;
        cin>>n>>s>>d;
        pair<ll, ll> sp = calc(n, s-1);
        pair<ll, ll> dp = calc(n, d-1);
        ll dx=sp.first-dp.first,dy=sp.second-dp.second;
        double ans=(sqrt(dx*dx+dy*dy)*10);
        printf("%0.lf\n",ans);
    }
    return 0;
}