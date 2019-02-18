#include<bits/stdc++.h>
#include<list>
using namespace std;

int main(){
    vector<list<int>> heaps(14);
    vector<int> ucnt(14, 0); //正面向上的牌的数量
    
    for(int i=1;i<=13;i++){
        list<int> temp;
        char c;
        for(int j=0;j<4;j++){
            cin>>c;
            if(c=='0') temp.push_back(10);
            else if(c=='J') temp.push_back(11);
            else if(c=='Q') temp.push_back(12);
            else if(c=='K') temp.push_back(13);
            else if(c=='A') temp.push_back(1);
            else temp.push_back(c-'0');
        }
        heaps[i] = temp;
    }
    int life = 4;
    while(life > 0){
        // draw from life heap
        int card = heaps[13].front();
        heaps[13].pop_front();
        
        while(card != 13) { // loop operation before 'K' appear
            // put card to the front of heaps[card]
            heaps[card].push_front(card);
            // for(auto i: heaps[card])
            // cout<<i<<" ";
            // cout<<endl;
            // break;
            // number of up in heaps[card]+1
            // draw from back
            card = heaps[card].back();
            heaps[card].pop_back();
            ucnt[card]++;
            // if(ucnt[card]==4) break; // no card to draw
        }
        life--; // die if card = 'K'
    }
    int ans = 0;
    for(int i=1;i<=12;i++){
        if(ucnt[i]==4) ans++;
    }
    cout<<ans<<endl;
    return 0;
}