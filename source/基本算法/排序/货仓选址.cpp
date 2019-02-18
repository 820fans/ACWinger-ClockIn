#include<bits/stdc++.h>
#define N 100001
using namespace std;

int n, a[N];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a, a+n);
    int pos = (a[n/2-1] + a[n/2])/2; //我擦这个下标
    if(n%2) pos = a[(n-1)/2];
    
    int sum=0;
    for(int i=0;i<n;i++) sum+=abs(pos - a[i]);
    cout<<sum<<endl;
    return 0;
}