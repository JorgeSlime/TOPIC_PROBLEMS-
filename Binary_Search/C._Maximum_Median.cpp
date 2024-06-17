/*
* Author: JorgeSLime     
* Problem: C. Maximum Median
* Contest: Codeforces Round 577 (Div. 2)
* Judge: Codeforces
* URL: https://codeforces.com/contest/1201/problem/C
* Memory Limit: 256
* Time Limit: 2000
* Start: sáb 13 abr 2024 23:27:17
* */
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
static struct FastInput {
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;
    inline char get_char() {
        if (buf_pos >= chars_read) {
            chars_read = fread(buf, 1, BUF_SIZE, in);
            buf_pos = 0;
            buf[0] = (chars_read == 0 ? -1 : buf[0]);
        }
        return cur = buf[buf_pos++];
    }
 
    inline void tie(std::nullptr_t) {}
 
    inline explicit operator bool() {
        return cur != -1;
    }
 
    inline static bool is_blank(char c) {
        return c <= ' ';
    }
 
    inline bool skip_blanks() {
        while (is_blank(cur) && cur != -1) {
            get_char();
        }
        return cur != -1;
    }
 
    inline FastInput& operator>>(char& c) {
        skip_blanks();
        c = cur;
        return *this;
    }
 
    inline FastInput& operator>>(string& s) {
        if (skip_blanks()) {
            s.clear();
            do {
                s += cur;
            } while (!is_blank(get_char()));
        }
        return *this;
    }
 
    template <typename T>
        inline FastInput& read_integer(T& n) {
            // unsafe, doesn't check that characters are actually digits
            n = 0;
            if (skip_blanks()) {
                int sign = +1;
                if (cur == '-') {
                    sign = -1;
                    get_char();
                }
                do {
                    n += n + (n << 3) + cur - '0';
                } while (!is_blank(get_char()));
                n *= sign;
            }
            return *this;
        }
 
    template <typename T>
        inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
            return read_integer(n);
        }
 
#if !defined(_WIN32) || defined(_WIN64)
    inline FastInput& operator>>(__int128& n) {
        return read_integer(n);
    }
#endif
    template <typename T>
        inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
            // not sure if really fast, for compatibility only
            n = 0;
            if (skip_blanks()) {
                string s;
                (*this) >> s;
                sscanf(s.c_str(), "%lf", &n);
            }
            return *this;
        }
} fast_input;
#define cin fast_input

//===================================CODE======================================================


void solve(){
    ll n,k; cin>>n>>k; 
    V<ll> v(n); 
    for(auto &i:v) cin>>i;
    sort(all(v));
    auto f = [&](int x)->bool{
        ll cnt = 0;
        for (auto i =n/2; i<n; ++i) 
      	    if (x >= v[i])  cnt += x - v[i]; 
        return cnt <= k;    
    };
    ll l=0,r=*max_element(all(v))+k+1;
    --l,++r;
    while (r - l > 1) {
        ll m =l+(r-l)/2;
        if (f(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout<<r-1<<LN;
    
}
int main(){turbo_PA;
    ll TT=1; 
    //cin>>TT;
    for(;TT--;) solve();
    return 0;
}
