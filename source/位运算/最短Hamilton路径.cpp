//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;

int n;
int f[1<<20][20];
int mat[20][20];
int hamilton(){
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                for(int k=0;k<n;k++){
                    if((i^1<<j) >> k&1){
                        f[i][j] = min(f[i][j], f[i^1<<j][k] + mat[k][j]);
                    }
                }
            }
        }
    }
    return f[(1<<n)-1][n-1];
}

int main(){
    ios::sync_with_stdio(false);//加快cin的读入速度，但是scanf将会不能用。
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // scanf("%d", &mat[i][j]);
            cin>>mat[i][j];
        }
    }
    int res = hamilton();
    cout<<res;
    return 0;
}
