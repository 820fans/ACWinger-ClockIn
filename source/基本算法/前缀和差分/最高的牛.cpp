#include<bits/stdc++.h>

#define N 10001
using namespace std;

int a[N], b[N];

int main(){
    int n,p,h,m;
    cin>>n>>p>>h>>m;
    for(int i=0;i<n;i++)
    a[i]=h;
    memset(b, 0, sizeof(b));
    
    int ha, hb;
    set<pair<int, int>> rec;
    for(int i=0;i<m;i++){
        cin>>ha>>hb;
        ha--;hb--;// response to index
        int h1 = min(ha, hb), h2=max(ha, hb);
        if((h2-h1)<=1) continue; //neighbor ox
        
        rec.insert({h1, h2});
    }
    // operate
    for(auto item: rec){
        int h1=item.first, h2=item.second;
        b[h1+1]--;
        b[h2]++;
    }
    
    cout<<a[0]<<endl;
    for(int i=1;i<n;i++){
        a[i] = a[i-1] + b[i];
        cout<<a[i]<<endl;
    }
    return 0;
}