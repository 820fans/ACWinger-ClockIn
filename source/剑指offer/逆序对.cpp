#include<bits/stdc++.h>
using namespace std;


const int N = 100010;
int p[N];
class Sortor{
public:
    int inversePair(vector<int> nums){
        int n = nums.size();
        int res = mergeC(nums, 0, n-1);
        return res;
    }

    int mergeC(vector<int> &nums, int l, int r){
        int ans = 0;
        if(l<r){
            int mid = (l+r)/2;
            ans += mergeC(nums, l, mid);
            ans += mergeC(nums, mid+1, r);
            ans += mergeCount(nums, l, mid, r);
        }
        return ans;
    }
    int mergeCount(vector<int> &nums, int l, int mid, int r){
        int ans = 0;
        int i=l, j=mid+1;
        for(int k=l;k<=r;k++){
            if(j>r || i<=mid && nums[i]<nums[j]){
                p[k]=nums[i++];
            }
            else{
                p[k]=nums[j++];
                ans+=(mid-i+1);
            }
        }
        return ans;
    }

    void qsp(vector<int> &nums, int l, int r){
        if(l<r){
            int mid = qs(nums, l, r);
            qs(nums, l, mid-1);
            qs(nums, mid+1, r);
        }
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
    
};