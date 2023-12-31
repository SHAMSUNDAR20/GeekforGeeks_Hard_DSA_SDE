
class Solution{
  public:
    int minDifference(int arr[], int n)  { 
        int sum = accumulate(arr, arr+n, 0);
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        int diff = INT_MAX;
        for (int j = sum/2; j >= 0; j--) {
            if (dp[n][j] == true) {
                diff = sum - 2*j;
                break;
            }
        }
        return diff;
    } 
};