#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(!n) return -1;
        int l=0, r=n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[l]<nums[r]) return nums[l];
            else if(nums[l]>nums[r]){
                // 一定要注意这部分性质只有当nums[l]>nums[r]才有效。
                if(nums[l]<nums[mid]) l=mid;
                else if(nums[mid]<nums[r]) r=mid;
                else l++;
            }
            else l++;
        }
        return nums[l];
    }
};