/**
 * 从 1~n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。
 * 
*/
#include<iostream>
#include<vector>
#define N 26
using namespace std;

int n,m;
vector<int> visit;
void dfs(int x){
    if(visit.size()>m || visit.size()+(n-x+1)<m) return;
    if(x>n){
        for(auto i: visit) cout<<i<<" ";
        cout<<endl;
        return;
    }
    visit.push_back(x);
    dfs(x+1);
    visit.pop_back();
    dfs(x+1);
}

void ddfs(int x, int sum, int state){
    if(sum+n-x+1<m) return;
    if(sum==m){
        for(int i=1;i<=n;i++){
            if(state>>i & 1) cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    if(x>n) return;
    
    ddfs(x+1, sum+1, state|1<<x);
    ddfs(x+1, sum, state);
}

int main(){
    cin>>n>>m;
    dfs(1);
    return 0;
}