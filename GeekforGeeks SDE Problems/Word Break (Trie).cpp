class Solution{
public:
    int wordBreak(string A, vector<string> &B) {
        int size = A.size();
        if (size == 0) return 1;

        unordered_set<string> dict(B.begin(), B.end());
        vector<bool> dp(size+1, false);
        vector<int> matchedIndex;
        matchedIndex.push_back(-1);

        for (int i=0; i<size; i++) {
            int msize = matchedIndex.size();
            int f = 0;
            for (int j=msize-1; j>=0; j--) {
                string s = A.substr(matchedIndex[j]+1, i-matchedIndex[j]);
                if (dict.find(s) != dict.end()) {
                    f = 1;
                    break;
                }
            }
            if (f == 1) {
                dp[i] = 1;
                matchedIndex.push_back(i);
            }
        }
        return dp[size-1];
    }
};






