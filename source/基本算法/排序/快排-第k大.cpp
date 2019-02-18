#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int l, int r){
    int x = a[l];
    int i=l, j=r;
    while(i<j){
        while(i<j && a[j]>x) j--;
        a[i]=a[j];
        while(i<j && a[i]<x) i++;
        a[j] = a[i];
    }
    a[i] = x;
    return i;
}

int part(vector<int>& a, int l, int r){
    int x = a[l];
    int i=l,j=r;
    while(i<j){
        while(i<j && a[j]<x) j--;
        a[i] = a[j];
        while(i<j && a[i]>x) i++;
        a[j] = a[i];
    }
    a[i] = x;
    return i;
}

void qs(vector<int>& a, int l, int r){
    if(l<r){
        int mid = partition(a, l, r);
        qs(a, l, mid-1);
        qs(a, mid+1, r);
    }
}

int ans;
void find_kl(vector<int>& a, int l, int r, int k){
    if(l<r){
        int mid=part(a, l, r);
        if(mid-l+1 == k) ans = a[mid];
        else if(mid-l+1<k){
            find_kl(a, mid+1, r, k-(mid-l+1));
        }
        else{
            find_kl(a, l, mid-1, k);
        }
    }
}

//**********寻找第k大的数字
void find_kth_largest(){
    vector<int> a;
    for(int i=0;i<10;i++) a.push_back(i);
    find_kl(a, 0, 9, 7);
    cout<<ans<<endl;
}

int main(){
    find_kth_largest();
}