#include<bits/stdc++.h>
#define N 200001

using namespace std;

int n,m;
int a[N],b[N],c[N];
typedef struct Movie{
    int id;
    int like=0, ok=0;
    Movie(int noi, int likei, int oki): id(noi), like(likei), ok(oki) {};
};

int comp(const Movie &a, const Movie &b){
    if(a.like == b.like){
        return a.ok > b.ok;
    }
    return a.like > b.like;
}

int main(){
    ios::sync_with_stdio(false);    // 我擦这句神了，直接让T的代码AC。
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(int i=0;i<m;i++) cin>>b[i];
    for(int i=0;i<m;i++) cin>>c[i];
    
    unordered_map<int, int> man_lang;
    for(int i=0;i<n;i++) man_lang[a[i]]++;
    
    vector<Movie> movies;
    for(int i=0;i<m;i++){
        auto mov = Movie(i+1, man_lang[b[i]], man_lang[c[i]]);
        movies.push_back(mov);
    }
    sort(movies.begin(), movies.end(), comp);
    cout<< movies[0].id << endl;
    return 0;
}