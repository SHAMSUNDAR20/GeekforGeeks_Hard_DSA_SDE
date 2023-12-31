class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        vector<int> dp(n);
        
        for(int i=0; i<n; i++)
            isPalin[i][i] = true;
        
        for(int len=2; len<=n; len++)
        {
            for(int i=0; i<n-len+1; i++)
            {
                int j = i+len-1;
                if(len == 2)
                    isPalin[i][j] = (str[i] == str[j]);
                else
                    isPalin[i][j] = (str[i] == str[j] && isPalin[i+1][j-1]);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            if(isPalin[0][i])
                dp[i] = 0;
            else
            {
                dp[i] = INT_MAX;
                for(int j=0; j<i; j++)
                {
                    if(isPalin[j+1][i] && 1+dp[j]<dp[i])
                        dp[i] = 1+dp[j];
                }
            }
        }
        return dp[n-1];
    }
};


