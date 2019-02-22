#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    double ksm(double base, int expt){
        double ans = 1.0;
        for(;expt;expt>>=1){
            if(expt&1) ans = ans*base;
            base=base*base;
        }
        return ans;
    }
    double Power(double base, int expt) {
        if(base==0) return 0;
        if(expt==0) return 1;
        double res = ksm(base, abs(expt));
        if(expt>0) return res;
        return 1.0/res;
    }
};