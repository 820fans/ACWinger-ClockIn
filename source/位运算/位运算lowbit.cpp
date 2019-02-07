#include<iostream>
using namespace std;

const int MAX = 1<<20;
int get(){
    
    int H[MAX + 1], n;
    for(int i=0;i<=20;i++) H[1<<i]=i;
    while(cin>>n){
        while(n>0){
            cout<<H[n&-n]<<" ";
            n-=n&-n;
        }
        cout<<endl;
    }
}

int main(){
    get();
    return 0;
}