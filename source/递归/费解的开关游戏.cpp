/**
 * 这个题实在是太费解了。我看题解都看了好久好久
 * 就是以前玩过的一种游戏。
 * 
 */
#include <bits/stdc++.h> 
#define N 7
using namespace std; 

int a[N][N],b[N][N],n,answer;

int init()
{
    getchar();
    for (int i=1;i<=5;i++) {
        for (int j=1;j<=5;j++) {
            char ch=getchar();
            a[i][j]=ch-'0';
        }
        getchar();
    }
}

int handle(int x,int y)
{
    b[x][y]^=1;
    b[x-1][y]^=1;
    b[x][y+1]^=1;
    b[x][y-1]^=1;
    b[x+1][y]^=1;
}

bool judge(void)
{
    for (int i=1;i<=5;i++) 
        for (int j=1;j<=5;j++) 
        if(!b[i][j]) return false;
    return true;
}

int work(void)
{
    answer=1e7;
    // 枚举第一行的点击方法
    for (int i=1;i<=(1<<5);i++) {
        //需要存储一下当前的a
        int ans=0;
        memcpy(b,a,sizeof(a));
        // 处理第一行点击
        for (int j=1;j<=5;j++) {
            if (i>>(j-1) & 1) {
                handle(1,j);
                ans++;
            }
        }
        
        // 处理剩下四列
        // 切记是1~4，而不是2~5，因为我们是控制j+1行，而不是控制第i行
        for (int j=1;j<=4;j++) {
            for (int k=1;k<=5;k++) 
            // 第j行出现了0
            if (!b[j][k]) {
                ans++;
                //留给j+1行去处理
                handle(j+1,k);
            }
        }
            
        if (judge())
            answer=min(ans,answer);
    }
    return answer;
}

int main()
{
    cin>>n;
    while(n--) {
        init();
        if (work()<=6) cout<<answer;
        else cout<<"-1";
        puts("");
    }
    return 0;
}