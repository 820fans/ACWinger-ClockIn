#include<bits/stdc++.h>
#define N 100001
using namespace std;

int trie[N*32+5][2], tot=1, a[N];

void insert(int val){
    int p=1;
    for(int i=30;i>=0;i--){
        int ch = val>>i & 1;
        if(trie[p][ch]==0) trie[p][ch]=++tot;
        p = trie[p][ch];
    }
}

int search(int val){
    int p = 1, ans = 0;
    for(int i=30;i>=0;i--){
        int ch = val>>i & 1;
        if(trie[p][ch ^ 1]){
            p = trie[p][ch^1];
            ans |= 1<<i;
        }
        else p = trie[p][ch];
    }
    return ans;
}

int main(){
    int n, res=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
        res=max(res, search(a[i]));
    }
    cout<<res<<endl;
    return 0;
}