#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
const ll INF = 10000000;
const int MAXN = 100010;
ll inp[MAXN];
ll aux1[MAXN], aux2[MAXN];
ll ans;

void reset() {
    memset(inp, 0, sizeof(inp));
    memset(aux1, 0, sizeof(aux1));
    memset(aux2, 0, sizeof(aux2));
    ans = 0;
}

void merge(ll* inp, int low, int mid, int high) {
    int l1 = mid - low + 1;
    for (int i = 0; i < l1; i++)
        aux1[i] = inp[i + low];
    aux1[l1] = INF;
    int l2 = high - mid;
    for (int i = 0; i < l2; i++)
        aux2[i] = inp[mid + 1 + i];
    aux2[l2] = INF;
    int i = 0, j = 0, k = 0, l = high - low + 1;
    ll sum_i = 0; 
    while (k < l) {
        if (aux1[i] < aux2[j]) {
            sum_i += aux1[i];
            inp[low + k] = aux1[i++];
        }
        else {
            ans += sum_i;
            inp[low + k] = aux2[j++];
        }
        k++;
    }
}

void mergesort(ll* inp, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(inp, low, mid);
        mergesort(inp, mid + 1, high);
        merge(inp, low, mid, high);
    }
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        reset();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) 
            scanf("%lld", inp + i);
        mergesort(inp, 0, n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}
