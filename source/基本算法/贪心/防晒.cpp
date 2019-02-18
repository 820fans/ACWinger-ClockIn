#include<bits/stdc++.h>
#define N 2501
using namespace std;

int comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first>b.first;
}

int main(){
    vector<pair<int, int>> cows, spfs;
    int c,l, maxf, minf;
    cin>>c>>l;
    for(int i=0;i<c;i++){
        cin>>minf>>maxf;
        cows.push_back(make_pair(minf, maxf));
    }
    int spf, cov;
    for(int i=0;i<l;i++){
        // cin>>spf[i]>>cover[i];
        cin>>spf>>cov;
        spfs.push_back({spf, cov});
    }
    sort(cows.begin(), cows.end(), comp);
    sort(spfs.begin(), spfs.end(), comp);
    
    int ans = 0;
    for(int i=0;i<c;i++){
        int low = cows[i].first, high = cows[i].second;
        for(int j=0;j<l;j++){
            spf = spfs[j].first, cov = spfs[j].second;
            if(cov>0 && spf>=low && spf<=high){
                spfs[j].second--;
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}