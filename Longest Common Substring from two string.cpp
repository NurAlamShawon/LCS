#include <stdio.h>
#include <string.h>

int dp[101][101];
int trace[101][101];

int LCS(char x[], char y[], int n, int m) {
    if (n == 0 || m == 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    if (x[n - 1] == y[m - 1]) {
        trace[n][m] = 1;
        return dp[n][m] = 1 + LCS(x, y, n - 1, m - 1);
    } else if (x[n - 1] != y[m - 1]) {
        int L1 = LCS(x, y, n, m - 1);
        int L2 = LCS(x, y, n - 1, m);
        if (L1 >= L2) {
            trace[n][m] = 2;
            return dp[n][m] = L1;
        } else {
            trace[n][m] = 3;
            return dp[n][m] = L2;
        }
    }
}

void traceback(char x[], char y[], int n, int m) {
    if (n == 0 || m == 0) return;
    if (trace[n][m] == 1) {
        traceback(x, y, n - 1, m - 1);
        printf("%c", x[n - 1]);
    } else if (trace[n][m] == 2) {
        traceback(x, y, n, m - 1);
    } else if (trace[n][m] == 3) {
        traceback(x, y, n - 1, m);
    }
}

int main() {
    char x[100], y[100];
    int n, m;
    printf("X: ");
    gets(x);
    printf("Y: ");
    gets(y);
    n = strlen(x);
    m = strlen(y);
    memset(dp, -1, sizeof(dp));
    int len = LCS(x, y, n, m);
    printf("Longest Common Substring length: %d\n", len);
    printf("Longest Common Substring: ");
    traceback(x, y, n, m);
    printf("\n");
    return 0;
}
