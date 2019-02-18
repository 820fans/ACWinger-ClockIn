/**
 * 从 1~n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案。
 * 
 * 重点在“任意多个”
 */ 
#include<iostream>
#include<vector>
#include<set>
#define N 16
using namespace std;

int n;
int H[37];

/**
 * 重点在于这个双DFS，可以避免for循环的使用。
 */
void ddfs(int x, int visit){
    if(x>n){
        for(int j=1;j<=n;j++){
            if(visit>>j & 1) 
            // if(visit&(1<<j)) 
            cout<<j<<" ";
        }
        cout<<endl;
        return;
    }
    ddfs(x+1,  visit);
    ddfs(x+1,visit| 1<<x); // 这样可以避免重置visit
    // visit|=(1<<x);
    // ddfs(x+1, visit);
    // visit^=(1<<x);
}

/**
 * 不需要判重
 */
void dfs(int visit, int i, set<int>& res){
    if(i>n) {
        int temp=0;
        for(int j=1;j<=n;j++){
            if(visit&(1<<j)) temp|=(1<<j);
        }
        // exist check
        if(res.find(temp)==res.end()){
            res.insert(temp);
            while(temp>0){
                cout<< H[(temp&-temp) % 37] <<" ";
                temp -= (temp&-temp);
            }
            cout<<endl;
        }
        return;
    }
    dfs(visit, i+1, res);
    visit|=(1<<i);
    dfs(visit, i+1, res);
    visit^=(1<<i);
    // }
}

/**
 * 这种方式存在重复，需要判重。而实际上，这个过程并不一定需要
 */
void normal_update(vector<int>& visit, int cnt){
    if(cnt>n) return;
    for(int i=cnt;i<=n;i++){
        if(visit[i]>0) continue;
        visit[i]=1;
        bool flag=false;
        for(int j=1;j<=n;j++){
            if(visit[j]>0) cout<<j<<" ";
            flag=true;
        }
        if(flag) cout<<endl;
        
        normal_update(visit, cnt+1);
        visit[i]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);//加快cin的读入速度，但是scanf将会不能用。
    
    int visit=0;
    set<int> res;
    for(int i=0;i<36;i++) H[(1ll<<i) % 37]=i;
    cin>>n;
    ddfs(1, visit);
    return 0;
}