#include<bits/stdc++.h>
#define N 1000001
#define ll long long
using namespace std;

int a[N], n;
long long sum = 0;

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    if(sum%n != 0){ // impossible case
        cout<<-1<<endl;
        return 0;
    }
    int num = sum/n; // number of candies of each child
    // get minus num
    for(int i=0;i<n;i++) a[i] -= num;
    // get prefix sum
    for(int i=1;i<n;i++) a[i] += a[i-1];
    
    // 果不其然这个方案TLE了
    // int minv = INT_MAX;
    // for(int k=0;k<n;k++){
    //     int res = 0;
    //     for(int i=0;i<n;i++){
    //         res += abs(a[i]-a[k]);
    //     }
    //     minv = min(minv, res);
    // }
    sort(a, a+n);
    int mpos = n/2;
    ll minv=0;
    for(int i=0;i<n;i++){
        minv += abs(1ll*a[i] - 1ll*a[mpos]);
    }
    cout<<minv<<endl;
    return 0;
}