

class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int i = 0, j = 0, starIdx = -1, iIdx = -1, m = wild.size(), n = pattern.size();
        while (j < n) {
            if (i < m && (wild[i] == '?' || wild[i] == pattern[j])) {
                ++i, ++j;
            } else if (i < m && wild[i] == '*') {
                starIdx = i;
                iIdx = j;
                ++i;
            } else if (starIdx >= 0) {
                i = starIdx + 1;
                j = iIdx + 1;
                ++iIdx;
            } else {
                return false;
            }
        }
        while (i < m && wild[i] == '*') {
            ++i;
        }
        return i == m;
    }
};