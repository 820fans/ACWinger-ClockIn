/**
## 这道贪心的难点有好几个
1. 贪心的性质证明
2. 要求给出每头牛对应的畜栏，因为排序会让编号乱掉，所以要开结构体
3. O(N^2)的方法过不了最大的数据，因为寻找最优的畜栏这个操作，可以通过优先队列，使取畜栏这个操作的复杂度从O(N)降低到O(logN)

c++优先队列，结构体比较的写法（重载运算符）
```
struct Fence{
    int id, r;
    Fence(int idx, int ri): id(idx), r(ri){}
    bool operator <(Fence a) const  {  return r < a.r; }
    bool operator >(Fence a) const  {  return r > a.r; }
};
```
*/
//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
#include<bits/stdc++.h>
#define N 50001
using namespace std;

struct Cow{
    int id;
    int l, r;
    Cow(int idx, int li, int ri): id(idx), l(li), r(ri) {}
};

struct Fence{
    int id, r;
    Fence(int idx, int ri): id(idx), r(ri){}
    bool operator <(Fence a) const  {  return r < a.r; }
    bool operator >(Fence a) const  {  return r > a.r; }
};

int cmp(const Cow &a, const Cow &b){
    if(a.l == b.l){
        return a.r < b.r;
    }
    return a.l < b.l;
}

int comp(const Fence &a, const Fence &b){
    return a.r > b.r;
}

// int comp(const pair<int, int> &a, const pair<int, int> &b){
//     if(a.first == b.first){
//         return a.second < b.second;
//     }
//     return a.first < b.first;
// }


int hold[N], ans[N];
// vector<pair<int, int>> a; // pair不能记录编号和牛的对应关系，所以要换成结构体
vector<Cow> a;

int main(){
    ios::sync_with_stdio(false); 
    int n, ai, bi;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ai>>bi;
        // a.push_back({ai, bi});
        a.push_back(Cow(i, ai, bi));
    }
    // sort(a.begin(), a.end(), comp);
    sort(a.begin(), a.end(), cmp);
    // memset(hold, 0x3f, sizeof(hold));
    int hold_size = 0;
    priority_queue<Fence, vector<Fence>, greater<Fence> > holder;
    
    for(int i=0;i<n;i++){
        int l=a[i].l, r=a[i].r;
        // find a place to place
        bool find=false;
        if(hold_size > 0){
            auto htop = holder.top();
            if(l > htop.r){
                holder.pop();
                holder.push(Fence(htop.id, r));
                ans[a[i].id] = htop.id + 1;
                find = true;
            }
        }
        if(!find){
            ans[a[i].id] = hold_size + 1;
            holder.push(Fence(hold_size++, r));
        }
        // for(int j=0;j<hold_size;j++){
        //     if(l > hold[j]){
        //         hold[j] = r;// place here, update hodler
        //         ans[a[i].id] = j + 1; // answer
        //         find = true;// already find
        //         break;
        //     }
        // }
        // if(!find){
        //     // not find yet
        //     ans[a[i].id] = hold_size + 1; // add a new fence
        //     hold[hold_size++]=r;
        // }
    }
    
    cout<<hold_size<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
