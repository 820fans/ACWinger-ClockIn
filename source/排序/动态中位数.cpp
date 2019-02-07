#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    //**********************************
    int p, no, m, ai;
    cin>>p;
    while(p--){
        priority_queue<int> maxQ;                            // 大根堆
        priority_queue<int, vector<int>, greater<int>> minQ; // 小根堆
        
        cin>>no>>m;
        cout<<no<<" "<<(int)(m+1)/2<<endl;
        int cnt = 0;
        for(int i=0;i<m;i++){
            cin>>ai;
            if(maxQ.size()==0) maxQ.push(ai);
            else{
                if(maxQ.size()<=minQ.size()){
                    if(ai<minQ.top()) maxQ.push(ai);
                    else{
                        maxQ.push(minQ.top());
                        minQ.pop();
                        minQ.push(ai);
                    }
                }
                else{
                    if(ai>maxQ.top()) minQ.push(ai);
                    else{
                        minQ.push(maxQ.top());
                        maxQ.pop();
                        maxQ.push(ai);
                    }
                }
            }
            
            if(i%2==0){
                cout<<maxQ.top()<<" ";
                cnt++;
            }
            if(cnt==10){
                cout<<endl;
                cnt=0;
            }
        }
        cout<<endl;
    }
    return 0;
}