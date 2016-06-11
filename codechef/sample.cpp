#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstring>
using namespace std;

const int maxn = 100001;
int b[maxn];
int pw[maxn][4];
int rem[maxn];
int nrem;
int arr[201];
int p[maxn];
int prim[1000];
int mp;

void sieve() {
    int lm = sqrt(maxn) + 1;
    for (int i = 2; i <= lm; i++) {
        if (!p[i]) {
            prim[mp++] = i;
            for (int j = i * 2; j < maxn; j += i)
                p[j] = 1;
        }
    }
}

void init() {
    queue<int> q;
    q.push(1);
    b[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int p1 = pw[x][0], p2 = pw[x][1], p3 = pw[x][2], p4 = pw[x][3];
        int n1 = x * 2, n2 = x * 3, n3 = x * 5, n4 = x * 7;
        if (n1 < maxn && !b[n1]) {
            b[n1] = 1, q.push(n1);
            pw[n1][0] = p1 + 1, pw[n1][1] = p2, pw[n1][2] = p3, pw[n1][3] = p4;
        }
        if (n2 < maxn && !b[n2]) {
            b[n2] = 1, q.push(n2);
            pw[n2][0] = p1, pw[n2][1] = p2 + 1, pw[n2][2] = p3, pw[n2][3] = p4;
        }
        if (n3 < maxn && !b[n3]) {
            b[n3] = 1, q.push(n3);
            pw[n3][0] = p1, pw[n3][1] = p2, pw[n3][2] = p3 + 1, pw[n3][3] = p4;
        }
        if (n4 < maxn && !b[n4]) {
            b[n4] = 1, q.push(n4);
            pw[n4][0] = p1, pw[n4][1] = p2, pw[n4][2] = p3, pw[n4][3] = p4 + 1;
        }
    }
    for (int i = 1; i < maxn; i++) 
        if (b[i]) {
            rem[nrem++] = i;
        }

}

int get_lim(int k, int low, int high) {
    while (low < high) {
        if (low + 1 == high) {
            if (rem[high] <= k) return rem[high];
            else return rem[low];
        }
        int mid = (high + low) / 2;
        if (rem[mid] == k) return k;
        else if (rem[mid] > k) 
            high = mid - 1;
        else
            low = mid;
    }
    return rem[low];
}
int arr_idx;
void print_k(int x, int& lim, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = y; j >= 1; j--)
            arr[arr_idx++] = lim + j;
        lim += y;
    }
}

int get_max_lis(int k) {
    int near_k = get_lim(k, 0, nrem - 1);
    int p1 = pw[near_k][0], p2 = pw[near_k][1], p3 = pw[near_k][2], p4 = pw[near_k][3];
    int len = p1 + p2 + p3 + p4;
    if (k > near_k) {
        int t = get_max_lis(k - near_k);
        len = max(t, len);
    }
    return len;
}

void solve_parts(int k, int last, int lis) {
    int near_k = get_lim(k, 0, nrem - 1);
    int p1 = pw[near_k][0], p2 = pw[near_k][1], p3 = pw[near_k][2], p4 = pw[near_k][3];
    int lis_got = p1 + p2 + p3 + p4;
    int pp1 = p1 * 2;
    int pp2 = p2 * 3;
    int pp3 = p3 * 5;
    int pp4 = p4 * 7;
    int len = pp1 + pp2 + pp3 + pp4;
    if (lis_got < lis) len += (lis - lis_got);
    if (k > near_k) {
        solve_parts(k - near_k, last + len, lis);
    }
    print_k(p1, last, 2);
    print_k(p2, last, 3);
    print_k(p3, last, 5);
    print_k(p4, last, 7);
    if (lis_got < lis) {
        int diff = lis - lis_got;
        for (int i = 1; i <= diff; i++) {
            arr[arr_idx++] = last + i;
        }
    }
}

bool bits[101];
void solve_parts_main(int k) {
    int lis = get_max_lis(k);
    memset(arr, 0, sizeof(arr));
    memset(bits, 0, sizeof(bits));
    arr_idx = 0;
    solve_parts(k, 0, lis);
    assert(arr_idx <= 100);
    printf("%d\n", arr_idx);
    for (int i = 0; i < arr_idx; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
        bits[arr[i]] = 1;
    }
    for (int i = 1; i <= arr_idx; i++) {
        assert(bits[i]);
    }
    printf("\n");
}

void solve(int k) {
    if (p[k] == 0) {
        if (k > 100) {
            solve_parts_main(k);
            return;
        }
        printf("%d\n", k);
        for (int i = k; i >= 1; i--) {
            if (i != k) printf(" ");
            printf("%d", i);
        }
        printf("\n");
        return;
    }

    int last = 0, orig = k;
    for (int i = 0; i < mp && prim[i] * prim[i] <= k; i++) {
        if (prim[i] > 100) {
            solve_parts_main(orig);
            return;
        }
        if (k % prim[i] == 0) {
            int sum = 0;
            while (k % prim[i] == 0) {
                k /= prim[i];
                for (int j = 0; j < prim[i]; j++)
                    arr[last + j] = last + prim[i] - j;
                last += prim[i];
            }
        }
    }
    if (k > 1) {
        for (int i = 0; i < k; i++)
            arr[last + i] = last + k - i;
        last += k;
    }

    if (last > 100) {
        solve_parts_main(orig);
        return;
    }

    printf("%d\n", last);
    for (int i = 0; i < last; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    sieve();
    init();
    int t, k;
    for (int i = 1; i < maxn; i++)
        solve(i);
/*    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        solve(k);
    }*/
    return 0;
}
