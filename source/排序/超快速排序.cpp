/**
## 只允许交 就是换相邻的数字，实际上就是冒泡排序，对大小位置错误的数进行交换。
### 交换的次数就是逆序对的数目

数据毒瘤，居然还出现了`long long`
*/
//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
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