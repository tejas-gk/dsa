#include<iostream>

int no_of_different_ways_to_move_in_a_grid(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 3;
    std::cout << no_of_different_ways_to_move_in_a_grid(m, n) << std::endl;
    return 0;
}