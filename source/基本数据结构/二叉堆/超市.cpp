#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define N 10001
using namespace std;

int n;
vector<pii> a;
priority_queue<int, vector<int>, greater<int> > heap;

int comp(const pii &a, const pii &b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        int p, d;
        a.clear();
        for(int i=0;i<n;i++){
            cin>>p>>d;
            a.push_back({p, d});
        }
        sort(a.begin(), a.end(), comp);
        for(int i=0;i<n;i++){
            if(a[i].second > heap.size()) heap.push(a[i].first);
            else if(a[i].second == heap.size() && heap.top()<a[i].first){
                heap.pop();
                heap.push(a[i].first);
            }
        }
        ll profit = 0;
        while(!heap.empty()){
            profit += heap.top();
            heap.pop();
        }
        cout<<profit<<endl;
        // 忘记了可以先卖价值高的，后过期的产品。所以这个贪心策略错了。
        // int day = 0, cnt=0;
        // ll profit = 0; 
        // while(cnt<n){
        //     if(a[cnt].second > day){
        //         profit+=a[cnt].first;
        //         day = max(day+1, a[cnt].second);
        //         cnt++;
        //     }
        //     else{
        //         cnt++;
        //     }
        // }
        // cout<<profit<<endl;
    }
    return 0;
}