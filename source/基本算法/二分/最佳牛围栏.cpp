/**
## 前缀数组
感谢[秦淮岸～灯火阑珊](https://www.acwing.com/solution/acwing/content/833) 的题解

这题的`l`和`r`在最终输出会有细微的精度区别。
因为我们需要的是`计算围起区域内每块地包含的牛的数量的平均值可能的最大值是多少。`，所以取较大的r。

这道题价值巨大，综合了多个思想：
1. max sum，即数组中最大子数组的大小
2. 求一个子段，它的和最大（前缀数组）。
3. 问题转化：是否存在一个长度不小于`f`的子段，子段和非负
*/
#include<iostream>
#define N 100001
#define S 1000
using namespace std;

double a[N], b[N], sum[N];
int n, f;

int main(){
    cin>>n>>f;
    for(int i=0;i<n;i++) cin>>a[i];
    
    double eps = 1e-5;
    double l=-1e6, r=1e6;
    while(r-l > eps){
        double mid=(l+r)/2;
        for(int i=0;i<n;i++) b[i] = a[i]-mid;
        for(int i=0;i<n;i++){
            if(i==0) sum[i]=b[i];
            else sum[i] = sum[i-1]+b[i];
        }
        double ans = 0;
        double minv = 0;
        for(int i=f-1;i<n;i++){
            minv = min(minv, sum[i-f]);
            ans = max(ans, sum[i] - minv);
        }
        if(ans>0) l=mid;
        else r=mid;
    }
    cout<<(int)(r*1000)<<endl;
    return 0;
}