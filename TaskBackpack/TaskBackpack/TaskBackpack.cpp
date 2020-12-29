#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include <iostream>
using namespace std;

int knapSackRec(int W, int wt[],
    int val[], int i,
    int** dp)
{
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W) {

        dp[i][W] = knapSackRec(W, wt,
            val, i - 1,
            dp);
        return dp[i][W];
    }
    else {
        dp[i][W] = max(val[i]
            + knapSackRec(W - wt[i],
                wt, val,
                i - 1, dp),
            knapSackRec(W, wt, val,
                i - 1, dp));

        return dp[i][W];
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    int** dp;
    dp = new int* [n];

    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
    int n = 4;
    int backpack_size = 7;

    int* values = new int[n] { 16, 19, 23, 28 };
    int* weights = new int[n] { 2, 3, 4, 5 };

    std::cout << knapSack(backpack_size, weights, values, n);
    return 0;
}
