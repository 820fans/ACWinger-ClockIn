#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        int l=1, r=n;
        while(l<r){
            int mid = (l+r)/2;
            int ans = 0;
            for(auto num: nums){
                if(num>=l && num<=mid)
                ans++;
            }
            if(ans>mid-l+1) r=mid;
            else l=mid+1;
        }
        return l;
        
        // int l=0, r=n-1;
        // int mid = quickSort(nums, l, r);
        // qs(nums, l, mid-1);
        // qs(nums, mid+1, r);
        // for(int num:nums)
        // cout<<num<<" ";
        // return 0;
    }
    
    int qs(vector<int> &nums, int l, int r){
        int x = nums[l];
        while(l<r){
            while(l<r && nums[r]>x) r--;
            nums[l] = nums[r];
            while(l<r && nums[l]<x) l++;
            nums[r] = nums[l];
        }
        nums[l] = x;
        return l;
    }
    
    
    void merge(vector<int> &nums, int l, int mid, int r){
        //int b[N];
        // int i=l, j=mid+1, k=l;
        // while(i<=mid && j<=r){
        //     if(j>r || i<=mid && nums[i]<nums[j]) p[k++] = nums[i++];
        //     else p[k++]=nums[j++];
        // }
        // for(int i=l;i<=r;i++) nums[i]=p[i];
        // for(int k=l;k<=r;k++){
        //     if(j>r || i<=mid && nums[i]<nums[j]) p[k]=nums[i++];
        //     else p[k] = nums[j++];
        // }
        // for(int k=l;k<=r;k++) nums[k]=p[k];
    }
    
    int quickSort(vector<int>& nums, int l, int r){
        int x = nums[l];
        while(l<r){
            while(l<r && nums[r]>x) r--;
            nums[l++] = nums[r];
            while(l<r && nums[l]<x) l++;
            nums[r--] = nums[l];
        }
        nums[l] = x;
        return l;
    }
};