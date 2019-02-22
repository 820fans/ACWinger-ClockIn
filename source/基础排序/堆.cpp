#include<bits/stdc++.h>
#define N 100010
using namespace std;

int a[N];
void push_down(int u, int size){
    int t=u, l=t*2, r=t*2+1;
    if(l<=size && a[l]>a[t]) t = l;
    if(r<=size && a[r]>a[t]) t = r;
    if(t != u){
        swap(a[t], a[u]);
        push_down(t, size);
    }
} 

void push_up(int u){
    while(u/2 && a[u/2] < a[u]){
        swap(a[u], a[u/2]);
        u/=2;
    }
}

void insert(int size, int x){
    a[size++] = x;
    push_up(size);
}

int get(){
    return a[1];
}

void push_down(int u, int size){
    int t=u, l=u*2, r=u*2+1;
    if(l<=size && a[l]>a[t]) t=l;
    if(r<=size && a[r]>a[t]) t=r;
    if(t!=u){
        swap(a[t], a[u]);
        push_down(t, size);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int size = n;

    for(int i=1;i<=n;i++) push_up(i);
    for(int i=1;i<=n;i++){
        swap(a[1], a[size--]);
        push_down(1, size);
    }
    for(int i=1;i<=n;i++) cout<<a[i];
    cout<<endl;
    return 0;
}