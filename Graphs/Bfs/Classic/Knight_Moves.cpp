/*
* Author: JorgeSLime     
* Problem: Knight Moves
* Contest: Graph
* Judge: beecrowd
* URL: https://judge.beecrowd.com/en/problems/view/1100
* Memory Limit: 1024
* Time Limit: 1000
* Start: lun 08 abr 2024 21:10:25
* */

//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;
const int N=8;
int vis[N][N];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a,b; 
    memset(vis,1,sizeof(vis));
     for (int i = 0; i < 8; ++i) {
            for (int j = i; j < 8; ++j)
                vis[i][j] = vis[j][i] = false;
            vis[i][i] = false;
        }
    for (int i = 0; i < 8; ++i,cout<<LN) 
            for (int j = i; j < 8; ++j) 
                cout<<vis[i][j]<<" ";
    //while(cin>>a>>b){
    //    
    //}
    return 0;
}
