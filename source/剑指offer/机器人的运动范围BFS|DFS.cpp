#include<bits/stdc++.h>
#define N 100010
using namespace std;

class Solution {
public:
    int movingCount(int k, int rows, int cols)
    {
        int x=0, y=0, cnt=0;
        if(rows==0 || cols==0) return 0;
        vector<vector<char>> visit(rows, vector<char>(cols, 0));
        // dfs(x,y,cnt, threshold, rows, cols, visit);
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        visit[0][0]=1;
        while(!Q.empty()){
            for(int i=0, n=Q.size();i<n;i++){
                auto loc = Q.front();
                Q.pop();
                cnt++;
                int x=loc.first, y=loc.second;
                if(x<rows-1 && valid(k, x+1, y) && !visit[x+1][y]) {
                    Q.push({x+1, y});
                    visit[x+1][y]=1;
                }
                if(y<cols-1 && valid(k, x, y+1) && !visit[x][y+1]) {
                    Q.push({x, y+1});
                    visit[x][y+1]=1;
                }
            }
        }
        return cnt;
    }
    
    void dfs(int x, int y, int& cnt, int k, int rows, int cols, vector<vector<char>> &visit){
        if(x<0 || y<0 || x>=rows || y>=cols) return;
        if(!valid(k, x, y)) return;
        if(visit[x][y]) return;
        cnt++;
        visit[x][y]=1;
        dfs(x+1, y, cnt, k, rows, cols, visit);
        dfs(x, y+1, cnt, k, rows, cols, visit);
        dfs(x-1, y, cnt, k, rows, cols, visit);
        dfs(x, y-1, cnt, k, rows, cols, visit);
    }
    
    bool valid(int k, int x, int y){
        int cnt = 0;
        while(x>0){
            cnt += x%10;
            x/=10;
        }
        while(y>0){
            cnt += y%10;
            y/=10;
        }
        return cnt <= k;
    }
};