#include<iostream>
#define N 100001
#define ll long long
using namespace std;

int a[N],b[N];


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0) b[i]=a[i];
        else b[i]=a[i]-a[i-1];
    }
    if(n<=1){
        cout<<0<<endl<<1<<endl;
        return 0;
    }
    ll p=0, q=0;
    for(int i=1;i<n;i++){
        if(b[i]>0) p+=b[i];
        else if(b[i]<0){
            q+=abs(b[i]);
        }
    }
    ll op_num = max(p, q);
    ll res_num = abs(p-q)+1ll;
    cout<<op_num<<endl;
    cout<<res_num<<endl;
    // more than one item
    return 0;
}