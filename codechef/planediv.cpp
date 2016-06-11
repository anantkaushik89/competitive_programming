#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cassert>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
 
struct compPair{
    bool operator()(const pii& p1, const pii& p2) const {
        if (p1.first != p2.first) return p1.first < p2.first;
        else return p1.second < p2.second;
    }
};
 
map<pii, int, compPair> ics, ocs;
map<pii, set<double>, compPair> m;
map<pii, set<double>, compPair>::const_iterator mitr, me;
map<pii, int, compPair>::const_iterator mmitr, mme;
 
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void check1(int& a, int& b, int& c) {
    if (a < 0) {
        a *= -1; b *= -1; c *= -1;
    }
}
 
void check2(int& a, int& b) {
    if (a < 0) {
        a *= -1; b *= -1;
    }
}
 
int main() {
    int t, n, a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        m.clear();
        ics.clear();
        ocs.clear();
        int is = 0, os =0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            if (a && b) {
                check1(a, b, c);
                int d = abs(a), e = abs(b);
                int g = gcd(max(d, e), min(d, e));
                pii p = make_pair(a / g, b / g);
                if (m.find(p) == m.end()) m[p] = set<double>();
                double t = (c * 1.0) / g;
                //printf("%d %d %lf\n", p.first, p.second, t);
                m[p].insert(t);
            }
            else if (b && c) {
                check2(b, c);
                int d = abs(b), e = abs(c);
                int g = gcd(max(d, e), min(d, e));
                pii p = make_pair(b / g, c / g);
                if (ics.find(p) == ics.end()) ics[p] = 0;
                ics[p]++;
                //printf("%d %d %d\n", p.first, p.second, ics[p]);
            }
            else if (a && c) {
                check2(a, c);
                int d = abs(a), e = abs(c);
                int g = gcd(max(d, e), min(d, e));
                pii p = make_pair(a / g, c / g);
                if (ocs.find(p) == ocs.end()) ocs[p] = 0;
                ocs[p]++;
                //printf("%d %d %d\n", p.first, p.second, ocs[p]);
            }
            else if (a) os = 1;
            else if (b) is = 1;
            else assert(0);
        }
        int ans = 0, ans1 = 0, ans2 = 0;
        me = m.end();
        for (mitr = m.begin(); mitr != me; mitr++) ans = max(ans, (int)(mitr->second.size()));
        //mme = ics.end();
        //for (mmitr = ics.begin(); mmitr != mme; mmitr++) ans1 = max(ans1, mmitr->second);
        //mme = ocs.end();
        //for (mmitr = ocs.begin(); mmitr != mme; mmitr++) ans2 = max(ans2, mmitr->second);
        ans1 = (int)ics.size() + is;
        ans2 = (int)ocs.size() + os;
        ans = max(ans, max(ans1, ans2));
        printf("%d\n", ans);
        
    }
    return 0;
}
