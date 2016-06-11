#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>
using namespace std;
const int maxk = 100010;
int inp[400];
int np;
bool b[maxk];
const int maxl = 110;
int arr[maxl];
int mn = 0, nn;

void sieve() {
    int lim = sqrt(maxk) + 1;
    for (int i = 2; i <= lim; i++) {
        if (b[i] == 0) {
            inp[np++] = i;
            for (int j = i * 2; j < maxk; j += i)
                b[j] = 1;
        }
    }
}

void solve(int k) {
    if (b[k] == 0) {
        printf("%d\n", k);
        for (int i = k; i >= 1; i--) {
            if (i != k) printf(" ");
            printf("%d", i);
        }
        printf("\n");
        return;
    }

    int last = 0;
    for (int i = 0; i < np && inp[i] * inp[i] <= k; i++) {
        if (k % inp[i] == 0) {
            int sum = 0;
            while (k % inp[i] == 0) {
                k /= inp[i];
                for (int j = 0; j < inp[i]; j++)
                    arr[last + j] = last + inp[i] - j;
                last += inp[i];
            }
        }
    }

    if (k > 1) {
        for (int i = 0; i < k; i++)
            arr[last + i] = last + k - i;
        last += k;
    }
    assert(last <= 100);
    printf("%d\n", last);
    for (int i = 0; i < last; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    sieve();
    int t, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        solve(k);
    }
    return 0;
}
