/**
 * ## 暴力枚举时间复杂度O(N^4)
遍历开头、结尾行。开头，结尾列。4层`for`循环。

## 贪心，时间复杂度O(N^3)

枚举开头、结尾行。再枚举每一列。3层`for`循环。
每一层使用`一维maxsum`的贪心策略。

[//]: # (打卡模板，上面预览按钮可以展示预览效果 ^^)
*/
//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
#include<bits/stdc++.h>
#define N 101
using namespace std;

int a[N][N], dp[N][N], n;

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            dp[i][j] = dp[i-1][j] + a[i][j];
        }
    }
    int maxv = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int sum=0;
            for(int k=1;k<=n;k++){
                sum = max(0, sum+dp[j][k]-dp[i-1][k]);
                maxv = max(maxv, sum);
            }
        }
    }
    cout<<maxv<<endl;
    return 0;
}