#include<bits/stdc++.h>
#define N 200001
#define ll long long
using namespace std;

ll t, n, l, r, mid;
struct Node{
    ll s,e,d;
}a[N];

int judge(ll x){
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(a[i].s <= x){
            ans += (min(a[i].e, x) - a[i].s)/a[i].d + 1; // +1 because start=1
        }
    }
    return ans;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].s>>a[i].e>>a[i].d;
        }
        l = 0, r = (1ll<<31) - 1;
        while(l<r){
            ll mid = (l+r)/2;
            if(judge(mid)&1){
                r = mid;
            }
            else l = mid+1;
        }
        // judge calculate prefix sum
        int ans = judge(r) - judge(r-1);
        if(ans){
            cout<<l<<" "<<ans<<endl;
        }
        else cout<<"There's no weakness."<<endl;
        
    }
    return 0;
}