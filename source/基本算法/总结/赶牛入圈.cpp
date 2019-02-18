/**
 * #### 这道题很难
相当于“激光炸弹”的增强版。加上了 **离散化** 和 **二分** 的操作。
感谢 [春晖のlqz](https://www.acwing.com/activity/content/code/content/23071/)  的题解。

1. 将坐标离散化到1-500范围内
2. 计算1-500范围内的三叶草数量前缀数组
3. 二分边长大小R。
3. 使用`lower_bound(k)`函数找到离散化后，k对应的下标。
4. 如果当前R范围内三叶草数量足够，说明R略大，需要缩减右边界。


注意！这道题和 **激光炸弹** 不一样，这道题里边长上的三叶草会被算入当前区域。所以边长为R的正方形对应的前缀和是
`a[i+R][j+R] - a[i-1][j+R] - a[i+R][j-1] + a[i-1][j-1]`
注意这里的`a[i-1][j-1]`，而**激光炸弹**题目里的式子是`a[i+R][j+R]-a[i][j+R]-a[i+R][j]+a[i][j]`对应的实际上是`R-1`边长的正方形（激光炸弹不能炸到边界）

*/
//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
#include<bits/stdc++.h>
#define N 501
#define pii pair<int, int>
using namespace std;

int a[N][N]; // global variable will be initialized to 0
int x[N], y[N], nx, ny;
int c, n;
vector<pii> leaf(N); // must here

int findx(int k){
    int tmp=lower_bound(x+1, x+nx+1, k) - x;
    return tmp;
}

int findy(int k){
    int tmp=lower_bound(y+1, y+ny+1, k) - y;
    return tmp;
}

bool check(int k){
    for(int i=1;i<=nx;i++){
        for(int j=1;j<=ny;j++){
            int ix = findx(x[i]+k+1)-1, jy = findy(y[j]+k+1)-1;
            if(a[ix][jy]-a[i-1][jy]-a[ix][j-1]+a[i-1][j-1]>=c) return 1;
        }
    }
    return 0;
}

int main(){
    cin>>c>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        leaf[i] = {x[i], y[i]};
        // a[x][y]++; // maybe more than one three leaf
        // farm[{x, y}]++;
    }
    sort(x+1, x+n+1);
    sort(y+1, y+n+1);
    nx = unique(x+1, x+n+1) - (x+1);
    ny = unique(y+1, y+n+1) - (y+1);
    for(int i=1;i<=n;i++){
        a[findx(leaf[i].first)][findy(leaf[i].second)]++;
    }
    // prefix sum
    for(int i=1;i<=nx;i++){
        for(int j=1;j<=ny;j++){
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
        }
    }
    int l=0, r=10000, res;
    while(l<=r){
        int mid = (l+r)>>1;
        // cout<<"mid:"<<mid<<endl;
        if(check(mid)){
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    cout<<res+1<<endl;
    return 0;
}