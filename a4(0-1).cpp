//-------------------------------------------------------------
//0-1 KnapSack Problem (DP)
//-------------------------------------------------------------


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, W;
    cout << "Enter number of items and capacity: ";
    cin >> n >> W;

    vector<int> wt(n), val(n);
    cout << "Enter <weight value> for each item:\n";
    for (int i = 0; i < n; ++i) cin >> wt[i] >> val[i];

    // dp[c] = best value with capacity c
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; ++i)
        for (int c = W; c >= wt[i]; --c)
            dp[c] = max(dp[c], val[i] + dp[c - wt[i]]);

    cout << "Maximum Value: " << dp[W] << "\n";
    return 0;
}
