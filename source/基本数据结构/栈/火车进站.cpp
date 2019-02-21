#include<bits/stdc++.h>
#define N 21
using namespace std;

vector<int> temp;
int n, cnt=0;
vector<int> Q(N);

void dfs(int start, int top){
    if(cnt>=20) return;
    if(start>n && top==0) {
        for(auto i: temp){
            cout<<i;
        }
        cout<<endl;
        cnt++;
        return;
    }
    if(top){
        int val = Q[top];
        temp.push_back(val);
        dfs(start, top-1);
        temp.pop_back();
        Q[top]=val;
    }
    if(start<=n){
        Q[top+1] = start;
        dfs(start+1, top+1);
    }
    
}

int main(){
    cin>>n;
    dfs(1, 0);
    return 0;
}