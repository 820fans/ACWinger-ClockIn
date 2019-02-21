#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll merge_count(vector<int>& nums, int l, int mid, int r){
    ll ans = 0;
    int i=l, j=mid+1;
    vector<int> res;
    for(int k=l;k<=r;k++){
        if(j>r || (i<=mid && nums[i]<nums[j])) res.push_back(nums[i++]);
        else{
            ans += (mid-i+1); // count merge cnts
            res.push_back(nums[j++]);
        }
    }
    for(int i=l;i<=r;i++) nums[i]=res[i-l];
    return ans;
}

ll mergeC(vector<int>& nums,int l, int r){
    ll ans = 0;
    if(l<r){
        int mid = (l+r)/2;
        ans += mergeC(nums, l, mid);
        ans += mergeC(nums, mid+1, r);
        ans += merge_count(nums, l, mid, r);
    }
    return ans;
}


int main(){
    int n;
    while(cin>>n){
        if(!n) break;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        cout<< mergeC(a, 0, n-1)<<endl;
    }
    return 0;
}