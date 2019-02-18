#include<bits/stdc++.h>
#define N 10010
#define ll long long 
using namespace std;
ll n, x[N], y[N], mid1, mid2;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i]>>y[i];
    sort(x, x+n);
    sort(y, y+n);
    for(int i=0;i<n;i++) x[i]-=i; // 
    sort(x, x+n);
    
    mid1 = x[n/2];
    mid2 = y[n/2];
    
    ll res = 0;
    for(int i=0;i<n;i++){
        res += abs(x[i]-mid1);
        res += abs(y[i]-mid2);
    }
    cout<<res<<endl;
    return 0;
}