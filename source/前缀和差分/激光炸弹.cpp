#include<iostream>
#include<cstring>
#define N 5001
using namespace std;

// int a[N][N]; // 直接申请两个数组超内存
int s[N][N];
int ni,r;

int main(){
    cin>>ni>>r;
    // memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    int xi,yi,vi,maxn;
    for(int i=0;i<ni;i++){
        cin>>xi>>yi>>vi;
        s[xi][yi] = vi;
        maxn=max(maxn, max(xi, yi));
    }
    int n=maxn+1;//数组大小=最大下标+1
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int v1 = (i>0 && j>0)?s[i-1][j-1]:0;
            int v2 = (i>0)?s[i-1][j]:0;
            int v3 = (j>0)?s[i][j-1]:0;
            // s[i-1][j]
            // s[i][j-1]
            // a[i][j]
            s[i][j] = v2+v3-v1+s[i][j];
        }
    }
    if(r>n){
        cout<<s[n-1][n-1]<<endl;
        return 0;
    }
    int maxv=0;
    for(int i=r-1;i<n;i++){
        for(int j=r-1;j<n;j++){
            int ri=i-r, rj=j-r;
            int v1 = (ri>=0&&rj>=0)?s[ri][rj]:0;
            int v2 = (ri>=0)?s[ri][j]:0;
            int v3 = (rj>=0)?s[i][rj]:0;
            maxv=max(maxv, s[i][j]-v2-v3+v1);
        }
    }
    cout<<maxv<<endl;
    return 0;
}