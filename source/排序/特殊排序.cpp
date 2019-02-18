// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
#include<bits/stdc++.h>
#include<list>
using namespace std;

int b[1001];

bool compare(int a, int b); // predefined function

class Solution {
public:
    vector<int> specialSort(int N) {
        ios::sync_with_stdio(false);
        vector<int> res;
        list<int> ans;
        for(int i=1;i<=N;i++){
            // res.push_back(i);
            auto it = ans.begin();
            while(it!=ans.end() && compare(*it, i)) it++;
            ans.insert(it, i);
        }
        // mergeS(res, 0, N-1);
        // qs(res, 0, N-1);
        auto it = ans.begin();
        while(it!=ans.end()){
            res.push_back(*it);
            it++;
        }
        return res;
    }
    
    void mergeS(vector<int> &nums, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeS(nums, l, mid);
            mergeS(nums, mid+1, r);
            mergeSort(nums, l, mid, r);
        }
    }
    
    void mergeSort(vector<int> &nums, int l, int mid, int r){
        int i=l, j=mid+1;
        for(int k=l;k<=r;k++){
            if(j>r || (i<=mid && compare(nums[i], nums[j]))) b[k] = nums[i++];
            else b[k]=nums[j++];
        }
        for(int k=l;k<=r;k++) nums[k]=b[k];
    }
    
    // 快排比较的次数太多了...
    void qs(vector<int> &nums, int l, int r){
        if(l<r){
            int mid = partition(nums, l, r);
            qs(nums, l, mid-1);
            qs(nums, mid+1, r);
        }
    }
    
    int partition(vector<int> &nums, int l, int r){
        // 每个元素都小于右边与它相邻的元素。
        // qsort compare too many times
        int x = nums[l];
        int i=l, j=r;
        while(i<j){
            while(i<j && !compare(nums[j], x)) j--;
            nums[i]=nums[j];
            while(i<j && compare(nums[i], x)) i++;
            nums[j]=nums[i];
        }
        nums[i] = x;
        return i;
    }
};

int main(){
    return 0;
}