//  https://cses.fi/problemset/task/1640

//THINK ONCE, CODE TWICE
#include <bits/stdc++.h>
using namespace std;

#define sz(x)     ((int)x.size())
#define all(x)    begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
#define pb              push_back
#define eb           emplace_back
#define V                  vector
#define LN                   '\n'
#define turbo_PA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;

void solve(){
    int n,x; cin>>n>>x; 
    V<array<int,2>> v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i][0];
        v[i][1]=i+1;
    }
    sort(all(v));
    array<int,2> ans({-1,-1});
    int l=0,r=n-1;
    bool ok=0;
    for(;l<r;){
        if(v[r][0]+v[l][0]>x) r--;
        if(r==l) continue;
        if(v[r][0]+v[l][0]<=x){
            if(v[r][0]+v[l][0]==x){
                ans={l,r};
                ok=1;
                break;
            }
            l++;
        }
    }
    if(!ok){
        cout<<"IMPOSSIBLE"<<LN;
        return;
    }
    cout<<v[ans[1]][1]<<" "<<v[ans[0]][1]<<LN;
}
int main(){turbo_PA;
    ll TT=1; 
    //cin>>TT;
    for(;TT--;) solve();
    return 0;
}

