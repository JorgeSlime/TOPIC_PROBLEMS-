/*
* Author: JorgeSLime     
* Problem: D. Xenia and Bit Operations
* Contest: Codeforces Round 197 (Div. 2)
* Judge: Codeforces
* URL: https://codeforces.com/problemset/problem/339/D
* Memory Limit: 256
* Time Limit: 2000
* Start: jue 04 abr 2024 17:12:43    //estuve 3 horas aprendiendo pipipi :'V
* */
//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define V vector
using namespace std;
const int N=(1<<16)+7;   
struct STree{
    int T[4*N];
    void modify(int n,int ok){
        int x=n<<1;
        ok ? T[n]=(T[x] ^ T[x|1]) : T[n]=(T[x] | T[x|1]);  //condicional repecto al estado y x|1 = !(x&1) ? +1 : nada;
    }
    void init(const V<int> &a,int n,int L,int R,int ok){
        if(L==R){
            T[n]=a[L];
            return;
        }
        int M=(L+R)>>1;
        int x=n<<1;
        init(a,x,L,M,1-ok);  //cambio de estado en cada llada 1-ok
        init(a,x|1,M+1,R,1-ok);
        modify(n,ok);
    }
    void update(int n,int L,int R,int I,int val,int ok){
        if(L==R){
            T[n]=val;
            return;
        }
        int M=(L+R)>>1;
        int x=n<<1;
        if(I<=M) update(x,L,M,I,val,1-ok);
        else update(x|1,M+1,R,I,val,1-ok);
        modify(n,ok);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q; cin>>n>>q; 
    int tam=1<<n; //2^n
    V<int> v(tam); 
    for(auto &i:v) cin>>i;
    STree ST;
    ST.init(v,1,0,tam-1,(n+1)%2);
    
    for(;q--;){
        int i,x; cin>>i>>x; 
        i--;
        ST.update(1,0,tam-1,i,x,(n+1)%2);
        cout<<ST.T[1]<<'\n';
    }
    return 0;
}
