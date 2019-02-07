#include<bits/stdc++.h>
#define N 1001
#define proj(x, y, d) (x+sqrt(d*d - y*y))
#define mproj(x, y, d) (x-sqrt(d*d - y*y))
using namespace std;

int cmp(const pair<double, double> &a, const pair<double, double> &b){
    // if(a.first == b.first){
    //     return a.second < b.second;
    // }
    return a.first < b.first;
}

// vector<pair<int, int>> a;
vector<pair<double, double>> a; // shit这个区间应该是double

int main(){
    ios::sync_with_stdio(false);
    
    int n, xi, yi;
    double d; // 我靠，不会是这个d吧....
    cin>>n>>d;
    bool lost = false;
    for(int i=0;i<n;i++){
        cin>>xi>>yi;
        if(d-yi < 0) {lost = true;break;}
        double tmp = sqrt(d*d*1.0 - yi*yi);
        // a.push_back({mproj(xi, yi, d), proj(xi, yi, d)});
        a.push_back({(double)xi-tmp, (double)xi+tmp});
        // cout<<a[i].first<<","<<a[i].second<<";\n";
    }
    if(lost){
        cout<<-1<<endl;
        return 0;
    }
    sort(a.begin(), a.end(), cmp);
    
    // vector<double> ans; // position of radars
    double pos = INT_MIN;
    int cnt = 0;
    for(int i=0;i<n;i++){
        double l = a[i].first, r = a[i].second; // FUCK, 这个地方的int一直没改过来....
        
        if(l<=pos){
            pos = min(r*1.0, pos);
        }
        else{
            pos = r;
            cnt++;
        }
        // bool add = true; // new radar needed
        // if(ans.size()>0){
        //     double last_radar_x = ans[ans.size()-1]; // get last radar
        //     // check whether the radar cover current island
        //     if(l<=last_radar_x){
        //         ans[ans.size()-1] = min(r*1.0, last_radar_x);
        //         add = false;
        //     }
        //     // if(last_radar_x > l && last_radar_x > r){ // can cover
        //     //     ans[ans.size()-1] = r*1.0;
        //     //     add = false;
        //     // }
        //     // else if(l <= last_radar_x) add = false; // no add, no adjust
            
        // }
        // if(add){
        //     double new_x = r;
        //     ans.push_back(new_x);
            
        // }
    }
    
    cout<<cnt<<endl;
    return 0;
}