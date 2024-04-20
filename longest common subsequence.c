#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void printLCS(int c[MAX_LENGTH][MAX_LENGTH], char X[MAX_LENGTH], int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (c[i][j] == c[i - 1][j - 1] + 1) {
        printLCS(c, X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    } else if (c[i][j] == c[i - 1][j])
        printLCS(c, X, i - 1, j);
    else
        printLCS(c, X, i, j - 1);
}

void lcs(char X[MAX_LENGTH], char Y[MAX_LENGTH]) {
    int m = strlen(X);
    int n = strlen(Y);
    int c[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (j = 0; j <= n; j++)
        c[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    }
    printf("The longest common subsequence is: ");
    printLCS(c, X, m, n);
    printf("\n");

}

int main() {
    char X[MAX_LENGTH];
    char Y[MAX_LENGTH];

    printf("Enter the first string: ");
    fgets(X, sizeof(X), stdin);
    X[strcspn(X, "\n")] = '\0';

    printf("Enter the second string: ");
    fgets(Y, sizeof(Y), stdin);
    Y[strcspn(Y, "\n")] = '\0';

    printf("First string: %s\n", X);
    printf("Second string: %s\n", Y);
    lcs(X, Y);

    return 0;
}
