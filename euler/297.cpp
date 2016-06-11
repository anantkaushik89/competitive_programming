#include <iostream>
#include <set>

using namespace std;
typedef long long ll;
const ll maxn = 100000000000000000LL;
set<ll> s;
ll fb[200];
ll dp[200];
int k;

void init() {
    ll a = 0, b = 1;
    s.insert(a); s.insert(b);
    fb[k++] = a; fb[k++] = b;
    while (true) {
        if ((a + b) > maxn) break;
        ll c = a + b; s.insert(c);
        cout << c << endl;
        fb[k++] = c;
        a = b; b = c;
    }
}

int main() {
    init();
    ll start = 2;
    cout << k << endl;
    /*dp[1]= 1, dp[2] = 0;
    for (int i = 3; i <= 84; i++) {
        dp[i] = fb[i - 3] + dp[i - 2] + dp[i - 1];
        cout << start + dp[i] << endl;
        start += dp[i];
    }*/
    return 0;
}
