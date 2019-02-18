#include<bits/stdc++.h>
#define N 50005
#define ll long long

using namespace std;

int comp(const pair<ll, ll> &a, const pair<ll, ll> &b){
    return a.first+a.second < b.first+b.second;
}

pair<ll, ll> a[N];
ll n;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    ll wi, si;
    for(int i=0;i<n;i++){
        cin>>wi>>si;
        a[i] = {wi, si};
    }
    if(n==1){
        cout<<-a[0].second<<endl;
        return 0;
    }
    sort(a, a+n, comp);
    ll sum=0, risk=-1e8;
    for(int i=0;i<n;i++){
        risk = max(risk, sum-a[i].second);
        sum += a[i].first;
    }
    cout<<risk<<endl;
    return 0;
}