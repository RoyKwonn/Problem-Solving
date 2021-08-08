#include <bits/stdc++.h>
using namespace std;

bool check(const string &a) {
    int r = 0;
    for (char ch : a) {
        if (ch == '(') ++r;
        else --r;
        if (r < 0) return false;
    }
    return r == 0;
}
string solution(string p) {
    if (p == "") return "";
    if (check(p)) return p;

    int i, t = 0;
    for (i = 0; i < p.size(); ++i) {
        if (p[i] == '(') ++t;
        else --t;
        if (t == 0) break;
    }

    string u = p.substr(0, i + 1);
    string v = p.substr(i + 1);

    if (check(u)) return u + solution(v);

    for (char &ch : u) ch = ch == '(' ? ')' : '(';
    return string("(") + solution(v) + ")" + u.substr(1, u.size() - 2);
}