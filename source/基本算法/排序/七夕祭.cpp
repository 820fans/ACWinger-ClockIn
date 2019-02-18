/**
## 这道题确实好难好难。

参考:  https://blog.csdn.net/xiaonanxinyi/article/details/84590766
1. 前置题目应当是，交换卡片使n个人手上的卡片相等。问是否存在解?
2. 很显然，所有卡片数量必须是n的倍数，否则不能让每个人卡片一样。
2. 假设每个人要k张卡，第一个人的操作数是a[0]-k，第二个人的操作数是a[0]+a[1]-2*k
3. ∑k*i-s[i] 其中s是前缀数组。
4. 回到这道题，这道题的行和列是互不影响的。也就是交换相邻两列里面的数，不影响每行里面感兴趣摊点数。
5. 这道题第一个和最后一个摊点是连接的，所以是个环。可以证明，环上肯定有2个人是不用互相交换的。因为在无环的情况下，最后一个人不需要和第一个人交换，也能达到目的。
6. 问题转化为，从哪里选择这个断开点的问题。∑|s[i]-s[k]|，最佳分开的点位于中位数的位置(排序过后的s[(n+1)/2)。


[//]: # (打卡模板，上面预览按钮可以展示预览效果 ^^)

//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
*/

#include<bits/stdc++.h>
using namespace std;

const long long MAXN = 100000 + 10;
long long d[MAXN], c[MAXN],sum[MAXN];
long long n, m, k;
 
long long solve(long long a[MAXN], long long n) {
	long long k=a[0]/n; // target num
	for (long long i = 1; i <=n; i++) {
		a[i] = a[i] - k;     // pad to zero
		sum[i] = sum[i - 1] + a[i];//prefix sum
	}
 
	sort(sum+1,sum+1+n);
	long long ans=0;
	// median is the answer
	for (long long i = 1; i <= n; i++)ans += abs(sum[i]-sum[(n+1)/2]);
	return ans;
}
 
int main() {
	cin >> n >> m >> k;
	long long a, b;// a row, b col
	for (long long i = 1; i <= k; i++) {
		cin >> a >> b;
		d[a]++; c[b]++;
	}
	//d[0] stores number of perline
	for (long long i = 1; i <= n; i++)d[0] += d[i];
	for (long long i = 1; i <= m; i++)c[0] += c[i];
 
	if (d[0] % n == 0 && c[0] % m == 0)
		printf("both %lld\n", solve(d, n) + solve(c, m));
	else if (d[0] % n == 0)
		printf("row %lld\n", solve(d, n));
	else if (c[0] % m == 0)
		printf("column %lld\n", solve(c, m));
	else
		printf("impossible\n");
	return 0;
}