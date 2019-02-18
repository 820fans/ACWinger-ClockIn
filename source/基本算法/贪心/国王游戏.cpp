/**
 * 高精度还没写，实在不想写了...
 */
#include<bits/stdc++.h>
#define N 1001
#define M 10000
using namespace std;

int comp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first*a.second < b.first*b.second;
}

vector<pair<int, int>> p;
int multi[N], maxv[N], tmp[N];
int n;

void multi_left(int val){
    int carry = 0, v;
    for(int i = 0;i<N;i++){
        v = (multi[i] * val + carry);
        multi[i] = v % M;
        carry = v / M;
        if(carry == 0) break;
    }
}

string getString(int nums[]){
    int i = N-1, cnt = 0;
    while(nums[i]==0) i--;
    string s = "", str;
    while(i>=0) {
        str = to_string(nums[i]);
        if(cnt >0 && str.size()<4) str = string(4-str.size(), '0').append(str);
        s += str;
        cnt++;
    }
}

bool high_max(){
    string maxv_s = getString(maxv);
    string tmp_s = getString(tmp);
    if(maxv_s.size() > tmp_s.size())
    tmp_s = string(maxv_s.size()-tmp_s.size(), '0').append(tmp_s);
    else if(maxv_s.size() < tmp_s.size())
    maxv_s = string(tmp_s.size()-maxv_s.size(), '0').append(maxv_s);
    if(tmp_s > maxv_s) return true;
    return false;
}

void maxv_divid(int val){
    memset(tmp, 0, sizeof(tmp));
    int i = N-1;
    while(multi[i]==0) i--;
    // high bit, multi[i]
    int borrow = 0, mod = 0, v, pos=i;
    while(i>=0){
        v = multi[i] + mod;
        if(v < val) {
            v = v*M + multi[i-1];
            i--;
        }
        tmp[i] = v / val;
        mod = v % val;
    }
    if(high_max()){
        for(int i=0;i<N;i++){
            maxv[i] = tmp[i];
        }
    }
}

int main(){
    cin >> n;
    int a,b;
    for(int i=0;i<=n;i++){
        cin>>a>>b;
        p.push_back({a, b});
    }
    sort(p.begin()+1, p.end(), comp);
    // prefix multi
    // memset(mult, 0, sizeof(mult));
    // mult[0]=1;
    long long multi = 1, maxv=0;
    for(int i=1;i<=n;i++){
        multi = multi * p[i-1].first;
        maxv = max(maxv, multi/p[i].second);
        // mult[i] = mult[i-1] * p[i-1].first;
    }
    cout<<maxv<<endl;
    return 0;
}