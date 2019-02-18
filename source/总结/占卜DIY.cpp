
//这里填你的代码^^
//注意代码要放在两组三个点之间，才可以正确显示代码高亮哦~
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
            int t = card;
            ucnt[t]++;     // increase card
            card = heaps[t].back();
            // heaps[card].pop_back(); // 这里card已经被更新了！！！
            heaps[t].pop_back(); // 弹出的应该是之前的card=t
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