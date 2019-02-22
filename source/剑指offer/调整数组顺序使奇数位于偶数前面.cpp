#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 显然这个方法会改变nums数组里原始数据的顺序
    void reOrderArray(vector<int> &nums) {
        int n = nums.size();
        int l=0, r=n-1;
        while(l<r){
            while(nums[l] % 2 == 1) l++;
            while(nums[r] % 2 == 0) r--;
            if(l<r) swap(nums[l], nums[r]);
        }
    }

    void reorder(vector<int> &nums){
        int n = nums.size();
        mergeS(nums, 0, n-1);
    }

    void mergeS(vector<int> &nums, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeS(nums, l, mid);
            mergeS(nums, mid+1, r);
            mergeSort(nums, l, mid, r);
        }
    }
    // 这个归并排序保证原始数据顺序不改变
    void mergeSort(vector<int> &nums, int l, int mid, int r){
        int i=l, j=mid+1;
        vector<int> temp;
        for(int k=l;k<=r;k++){
            if(j>r || i<=mid && (nums[i]%2==1)) temp.push_back(nums[i++]);
            else if(nums[j]%2==1) temp.push_back(nums[j++]);
            else if(i<=mid) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        for(int i=0;i<temp.size();i++) nums[i+l]=temp[i];
    }
};