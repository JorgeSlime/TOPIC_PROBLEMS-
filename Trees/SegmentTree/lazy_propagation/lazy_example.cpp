//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;

struct Nodo{
    long long suma;
    bool lazy;
    long long p;
    Nodo(){}
    Nodo(int z){
        suma=z;
        lazy=0;
        p=0;
    }
    void merge(Nodo a,Nodo b){
        suma=a.suma+b.suma;
        lazy=0;
        p=0;
    }
};
const int NMAX=1<<4;
int a[NMAX];
Nodo T[NMAX];
void init(int N,int L,int R){
    if(L==R){
        T[N]=Nodo(a[L]);
        return; 
    }
    int A=N<<1;
    int M=(L+R)>>1;
    init(A,L,M);
    init(A|1,M+1,R);
    T[N].merge(T[A],T[A|1]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin>>n; 
    for(int i=0;i<n;i++){
        cin>>a[i]; 
    }
    init(1,0,n-1);
    
    return 0;
}
