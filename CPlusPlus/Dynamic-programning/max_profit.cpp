#include<iostream>

int max_profit(int* prices, int n) {
    int max_profit = 0;
    int min_price = prices[0];
    for (int i = 1; i < n; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        else {
            max_profit = std::max(max_profit, prices[i] - min_price);
        }
    }
    return max_profit;
}
int main() {
    int prices[] = { 7, 1, 5, 3, 6, 4 };
    int n = sizeof(prices) / sizeof(prices[0]);
    std::cout << max_profit(prices, n) << std::endl;
    return 0;
}