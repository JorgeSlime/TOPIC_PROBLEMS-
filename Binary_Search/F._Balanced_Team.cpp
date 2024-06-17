/*
* Author: JorgeSLime     
* Problem: F. Balanced Team
* Contest: Binary Search
* Judge: Codeforces
* URL: https://codeforces.com/group/isP4JMZTix/contest/379072/problem/F
* Memory Limit: 256
* Time Limit: 2000
* Start: dom 14 abr 2024 22:26:24
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
    int n; cin>>n; 
    V<int> v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(all(v));
    int ans=INT32_MIN,j=0,c=0;
    for(int i=0;i<n;i++){
        (v[i]-v[j]<=5)  ? c++: j++;
        ans=max(ans,c);
    }
    cout<<ans<<LN;
}
int main(){turbo_PA;
    ll TT=1; 
    //cin>>TT;
    for(;TT--;) solve();
    return 0;
}
