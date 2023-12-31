class Solution{
public:
    void wordBreakUtil(int n, vector<string>& dict, string s, int i, vector<string>& res, string ans, vector<bool>& dp)
    {
        for(int j=i; j<s.size(); j++)
        {
            string prefix = s.substr(i, j-i+1);
            if(find(dict.begin(), dict.end(), prefix) != dict.end() && dp[j+1])
            {
                if(j == s.size()-1)
                {
                    res.push_back(ans + prefix);
                    return;
                }
                wordBreakUtil(n, dict, s, j+1, res, ans + prefix + " ", dp);
            }
        }
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        int len = s.size();
        vector<bool> dp(len+1, false);
        dp[len] = true;
        for(int i=len-1; i>=0; i--)
        {
            for(int j=i; j<len; j++)
            {
                if(dp[j+1] && find(dict.begin(), dict.end(), s.substr(i, j-i+1)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        vector<string> res;
        if(dp[0])
            wordBreakUtil(n, dict, s, 0, res, "", dp);
        return res;
    }
};





