#include <iostream>

int64_t dp[21][21][21];

int64_t W(int64_t a, int64_t b, int64_t c);

int main(void)
{
    int64_t a, b, c;
    while (1)
    {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        int64_t ans(W(a, b, c));
        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << std::endl;
    }
    return 0;
}

int64_t W(int64_t a, int64_t b, int64_t c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return W(20, 20, 20);
    if (a < b && b < c)
    {
        if (dp[a][b][c - 1] == 0)
            dp[a][b][c - 1] = W(a, b, c - 1);
        if (dp[a][b - 1][c - 1] == 0)
            dp[a][b - 1][c - 1] =  W(a, b - 1, c - 1);
        if (dp[a][b - 1][c] == 0)
            dp[a][b - 1][c] = W(a, b - 1, c);
        dp[a][b][c] = dp[a][b][c - 1] + dp[a][b - 1][c - 1] - dp[a][b - 1][c];
        return dp[a][b][c];
    }
    if (dp[a - 1][b][c] == 0)
        dp[a - 1][b][c] = W(a - 1, b, c);
    if (dp[a - 1][b - 1][c] == 0)
        dp[a - 1][b - 1][c] = W(a - 1, b - 1, c);
    if (dp[a - 1][b][c - 1] == 0)
        dp[a - 1][b][c - 1] = W(a - 1, b, c - 1);
    if (dp[a - 1][b - 1][c - 1] == 0)
        dp[a - 1][b - 1][c - 1] = W(a - 1, b - 1, c - 1);
    dp[a][b][c] = dp[a - 1][b][c] + dp[a - 1][b - 1][c] + dp[a - 1][b][c - 1] - dp[a - 1][b - 1][c - 1];
    return dp[a][b][c];
}