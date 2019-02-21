#include<bits/stdc++.h>
using namespace std;

/**
 * 1 2 3 4 5 6
 * msort(0,l)  msort(l+1,r)
 * msort(0, r)
 * 
 */ 
class Solution {
    int res = 0;
public:
    int inversePairs(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=n-1;
        int res = mergeC(nums, l, r);
        return res;
    }
    
    int mergeC(vector<int>& nums, int l, int r){
        int res = 0;
        if(l<r){
            int mid=(l+r)/2;
            res += mergeC(nums, l, mid);
            res += mergeC(nums, mid+1, r);
            res += merge_count(nums, l, mid, r);
        }
        return res;
    }
    
    int merge_count(vector<int>& nums, int l, int mid, int r){
        vector<int> res;
        int i=l,j=mid+1;
        int cnt = 0;
        while(i<=mid && j<=r){
            if(nums[i]>nums[j]){
                cnt+=(mid-i+1);
                res.push_back(nums[j++]);
            }
            else{
                res.push_back(nums[i++]);
            }
        }
        while(i<=mid) res.push_back(nums[i++]);
        while(j<=r)   res.push_back(nums[j++]);
        for(int i=l,j=0;i<=r;i++,j++) {nums[i]=res[j];}
        // cout<<", re pair:"<<cnt<<endl;
        return cnt;
    }
    
    void msort(vector<int>& nums, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            msort(nums, l, mid);
            msort(nums, mid+1, r);
            mergeSort(nums, l, mid, r);
        }
    }
    
    void mergeSort(vector<int>& nums, int l, int mid, int r){
        vector<int> res;
        int i=l, j=mid+1;
        while(i<=mid && j<=r){
            if(nums[i]<nums[j]){
                res.push_back(nums[i++]);
            }
            else{
                res.push_back(nums[j++]);
            }
        }
        while(i<=mid) res.push_back(nums[i++]);
        while(j<=r) res.push_back(nums[j++]);
        for(int i=l,j=0;i<=r;i++,j++) {nums[i]=res[j];}
        // cout<<endl;cout<<nums[i];
    }
    
    void quit_sort(vector<int>& nums, int l, int r){
        if(l<r){
            int mid = partition(nums, l, r);
            quit_sort(nums, l, mid-1);
            quit_sort(nums, mid+1, r);
        }
    }
    
    int partition(vector<int>& nums, int l, int r){
        int x = nums[l];
        int i=l, j=r;
        while(i<j){
            while(j>i && nums[j]>x) j--;
            nums[i] = nums[j];
            while(i<j && nums[i]<x) i++;
            nums[j] = nums[i];
        }
        nums[i] = x;
        return i;
    }
    
};