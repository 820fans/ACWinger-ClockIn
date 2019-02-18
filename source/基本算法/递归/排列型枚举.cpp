#include<iostream>
#include<vector>

using namespace std;

int n;
void dfs(vector<int>& visit, int cnt, vector<int>& temp){
    if(temp.size()==n) {
        for(auto num: temp){
            cout<<num<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(visit[i]>0) continue;
        visit[i]=1;
        temp.push_back(i);
        dfs(visit, cnt+1, temp);
        visit[i]=0;
        temp.pop_back();
    }
}

vector<int> path;
void ddfs(int x, int state){
    if(x==n){
        for(auto i: path) cout<<i<<" ";
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!(state>>i&1)) {
            path.push_back(i);
            ddfs(x+1, state|1<<i);
            path.pop_back();
        }

    }
}

int main(){
    cin>>n;
    vector<int> visit(n, 0);
    vector<int> temp;
    // dfs(visit, 1, temp);
    ddfs(1, 0);
    return 0;
}