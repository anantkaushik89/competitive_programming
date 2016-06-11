#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;
typedef long int lint;

set<lint> s;

lint sq(lint n) {
    lint ss = 0;
    while (n) {
        lint d = n % 10;
        n /= 10;
        ss += (d * d);
    }
    return ss;
}

int main() {
    lint n, ans = 0; bool f = true;
    scanf("%ld", &n);
    while (true) {
        n = sq(n);
        ans++;
        if (n == 1) {break;}
        else if (s.count(n)) {f = false; break;}
        else s.insert(n);
    }
    if (!f) printf("-1\n");
    else printf("%ld\n", ans);
    return 0;
}
