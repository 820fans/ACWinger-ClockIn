
#include<bits/stdc++.h>
#define offset(n) (int)pow(3, n-2)
#define N 1000
using namespace std;

char res[N][N];
// , vector<vector<char>> &res
void dfs(int x, int y, int n){
    if(n==1){
        res[x][y] = 'X';
        return;
    }
    dfs(x, y, n-1);
    dfs(x, y + offset(n) * 2, n-1);
    dfs(x + offset(n), y + offset(n), n-1);
    dfs(x + offset(n) * 2, y, n-1);
    dfs(x + offset(n) * 2, y + offset(n) * 2, n-1);
    
}

int main(){
    int n;
    while(cin>>n){
        if(n==-1) break;
        memset(res, 0, sizeof(res));
        dfs(1, 1, n);
        
        int len = (int) pow(3, n-1);
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                if(res[i][j] != 'X') cout<<" ";
                else cout<<"X";
            }
            cout<<endl;
        }
        cout<<"-"<<endl;
    }
    return 0;
}