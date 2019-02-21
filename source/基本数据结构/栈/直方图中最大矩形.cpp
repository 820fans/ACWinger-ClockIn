/**
 * 著名的单调栈问题
 */
#include<bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

int a[N];
int n;

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n && n){
        for(int i=0;i<n;i++) cin>>a[i];
        a[n]=0;
        
        stack<int> Q;
        ll i=0, maxv=0;
        while(i<=n){
            if(Q.empty()|| a[i]>a[Q.top()]) Q.push(i++);
            else{
                int h = Q.top();
                Q.pop();
                
                int len = 0;
                if(Q.empty()) len = i;
                else len = i-1-Q.top();
                ll area = 1ll*len*a[h];
                maxv = max(maxv, area);
            }
        }
        cout<<maxv<<endl;
    }
    return 0;
}