#include <stdio.h>
#include <stdbool.h>
#define N 10

void print_solution(int board[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_safe(int board[N][N], int row, int col, int n) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solve_n_queens_util(int board[N][N], int col, int n) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (is_safe(board, i, col, n)) {
            board[i][col] = 1;

            if (solve_n_queens_util(board, col + 1, n))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

bool solve_n_queens(int n) {
    int board[N][N] = { {0} };

    if (!solve_n_queens_util(board, 0, n)) {
        printf("Solution does not exist\n");
        return false;
    }

    printf("Solution found:\n");
    print_solution(board, n);
    return true;
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Invalid input\n");
        return 1;
    }

    solve_n_queens(n);

    return 0;
}
