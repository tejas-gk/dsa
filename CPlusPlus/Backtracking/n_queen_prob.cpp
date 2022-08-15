#include<iostream>

bool is_safe(int m[][10], int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (m[row][i] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (m[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (m[i][j] == 1) {
            return false;
        }
    }
    return true;
}
int solveProblem(int m[][10], int row, int col, int n) {
    if (row == n) {
        return 1;
    }
    if (col == n) {
        return solveProblem(m, row + 1, 0, n);
    }
    if (m[row][col] == 1) {
        return solveProblem(m, row, col + 1, n);
    }
    int count = 0;
    m[row][col] = 1;
    if (is_safe(m, row, col, n)) {
        count += solveProblem(m, row, col + 1, n);
    }
    m[row][col] = 0;
    if (is_safe(m, row, col, n)) {
        count += solveProblem(m, row, col + 1, n);
    }
    return count;
}
int main() {
    int m[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int n = 10;
    std::cout << solveProblem(m, 0, 0, n) << std::endl;
    return 0;
}