#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int final = 0, ok=0;

void show(int state){
    for(int i=0;i<16;i++){
        cout<<((state>>i)&1);
    }
    cout<<endl;
}

/**
 * 与之前“费解的开关”那道题一样，不能DFS，应该枚举状态！
 */
void dfs(int state, int visit, vector<pii> &path){
    if(ok) return;
    if(state==final){
        cout<<path.size()<<endl;
        for(int i=0;i<path.size();i++)
        cout<<path[i].first<<" "<<path[i].second<<endl;
        ok = 1;
        return;
    }
    for(int i=0;i<16;i++){
        if(ok) return;
        int x = i/4, y = i%4, temp = state, pos;
        if((visit>>i)&1) continue; // cannot press same location twice
        path.push_back({x, y});
        // apply changes to state
        // show(state);
        for(int j=0;j<4;j++) state ^= (1<<(x*4 + j));
        for(int j=0;j<4;j++) {
            pos = (1<<(y + j*4));
            if(pos != (1<<i)) state ^= pos;
        }
        // show(state);
        dfs(state, visit|(1<<i), path);
        path.pop_back();
        state = temp;
    }
}

int main(){
    int state = 0;
    char c;
    for(int i=0;i<16;i++){
        cin>>c;
        if (c=='+') state |= (1<<i);
    }
    for(int k=1;k<(1<<17);k++){
        int temp = state;
        vector<pii> path;
        for(int i=0;i<16;i++){
            if((k>>i)&1){       // not open
                int x = i/4, y = i%4, pos;
                // apply changes to state
                // show(state);
                for(int j=0;j<4;j++) state ^= (1<<(x*4 + j));
                for(int j=0;j<4;j++) {
                    pos = (1<<(y + j*4));
                    if(pos != (1<<i)) state ^= pos;
                }
                path.push_back({x+1, y+1});
            }
        }
        if(state == 0){
            cout<<path.size()<<endl;
            for(auto i: path){
                cout<<i.first<<" "<<i.second<<endl;
            }
            break;
        }
        state = temp;
    }
    
    return 0;
}