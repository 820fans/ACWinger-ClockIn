#include<bits/stdc++.h>
#define N 1000010
using namespace std;

int trie[N][26], tail[N], tot=0;
int n,m;

void insert(string s){
    int p=0;
    for(int i=0;i<s.size();i++){
        int ch = s[i]-'a';
        if(trie[p][ch]==0) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    tail[p]++;
}

int search(string s){
    int p=0, ans=0;
    for(int i=0;i<s.size();i++){
        p=trie[p][s[i]-'a'];
        if(p==0) return ans;
        ans+=tail[p];
    }
    return ans;
}

int main(){
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        insert(s);
    }
    for(int i=0;i<m;i++){
        cin>>s;
        int res = search(s);
        cout<<res<<endl;
    }
    return 0;
}