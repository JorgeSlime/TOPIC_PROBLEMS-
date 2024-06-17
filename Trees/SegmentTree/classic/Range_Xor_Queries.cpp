//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q; cin>>n>>q; 
    vector<int> v(n+1); 
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]^=v[i-1]; //lo unico que se hace es hacer un prefix xor LOL
    }
    while(q--){
        int l,r; cin>>l>>r;
        l--; 
        cout<<(v[r]^v[l])<<LN; //consulta en rango hacinedo XOR 
    }
    return 0;
}
