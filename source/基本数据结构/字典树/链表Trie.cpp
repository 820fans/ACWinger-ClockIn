#include<bits/stdc++.h>
#define N 1000010
using namespace std;

typedef struct Node{
    int tail=0; //字符串结尾
    vector<Node*> next;
    vector<int> cnt;
    Node(){
        next.assign(26, NULL);
        cnt.assign(26, 0);
    }
};

Node *root = new Node();
int n,m;

void insert(string s){
    Node* p=root;
    for(int i=0;i<s.size();i++){
        int ch = s[i]-'a';
        if(!p->next[ch]) p->next[ch]=new Node();
        p->cnt[ch]++;
        p = p->next[ch];
    }
    p->tail++;
}

int search(string s){
    Node *p = root;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        int ch = s[i]-'a';
        ans += p->tail;
        if(!p->next[ch]) return ans;
        p = p->next[ch];
    }
    ans += p->tail;
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