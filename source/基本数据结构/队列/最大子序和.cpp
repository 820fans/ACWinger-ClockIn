/**
 * ## 经典单调队列题，和`滑动窗口`类似，必做！

### 细节处理上和`滑动窗口`略有区别。

注释掉的部分是用于求最大子序列和`不考虑长度限制`的代码。
[//]: # (打卡模板，上面预览按钮可以展示预览效果 ^^)
*/
//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
#include<bits/stdc++.h>
#define ll long long
#define N 300001
using namespace std;

int a[N],n,m;

int main(){
    ios::sync_with_stdio(false);
    memset(a, 0, sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i], a[i] = a[i]+a[i-1]; // prefix sum
    ll maxv=0;
    deque<int> Q;
    for(int i=1;i<=n;i++){
        while(!Q.empty() && Q.front()<i-m) Q.pop_front();
        maxv=max(maxv, 0ll+a[i]-a[Q.front()]);
        while(!Q.empty() && a[Q.back()] >= a[i]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    // for(int i=0;i<n;i++){
    //     sum = a[i] + max(0, sum);
    //     maxv = max(maxv, sum);
    // }
    cout<<maxv<<endl;
    return 0;
}