/*
* Author: JorgeSLime     
* Problem: B. You Are Given a Decimal String...
* Contest: Educational Codeforces Round 70 (Rated for Div. 2)
* Judge: Codeforces
* URL: https://codeforces.com/contest/1202/problem/B
* Memory Limit: 256
* Time Limit: 2000
* Start: vie 12 abr 2024 20:20:54
* */
//THINK ONCE, CODE TWICE
#include "bits/stdc++.h"
#define LN '\n'
using namespace std;
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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
