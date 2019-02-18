#include<bits/stdc++.h>
#define ll long long
#define power(a) (a)*(a)
#define N 500001
using namespace std;

int p[N], ans, l, r;
ll b[N],a[N],m,n,t, ct;

// merge sort
void merge(int l, int mid, int r){
    int i=l, j=mid;
    // cout<<"lmr"<<l<<" "<<mid<<" "<<r<<endl;
    // for(int i=l;i<=r;i++) cout<<a[i]<<" ";
    // cout<<" BTest;"<<endl;
    for(int k=l;k<=r;k++){
        if(j>r || (i<mid && a[i]<a[j])) b[k] = a[i++];
        else b[k] = a[j++];
    }
    // for(int i=l;i<=r;i++) cout<<b[i]<<" ";
    // cout<<" Test;"<<endl;
}

bool check(int l, int mid, int r){
    for(int i=mid;i<=r;i++) a[i]=p[i];
    sort(a+mid, a+r+1);
    merge(l, mid, r);
    ll sum=0;
    for (int i=1; i<=(r-l+1)>>1 && i<=m; i++)
    sum+=power(b[r-i+1]-b[l+i-1]);
    if (sum<=t) {
        for(int i=l; i<=r; i++) 
        a[i]=b[i];
        return true;
    }
    else
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin>>ct;
    while(ct--){
        l=r=0;
        ans=0;
        cin>>n>>m>>t;
        for(int i=1;i<=n;i++) cin>>p[i];
        int len=1;
        l=r=1;
        a[l]=p[l];
        while (r<=n){
            if (!len) {
                len=1;
                ans++;
                l=(++r);
                a[l]=p[l];
            }
            else if (r+len<=n && check(l,r+1,r+len)) {
                // 倍增
                r+=len;
                len<<=1;
                if (r==n)
                break;
            }
            else len>>=1; // 倍减   
        }
        if (r==n) ans++;
        
        cout<<ans<<endl;
    }
    return 0;
}