

class Solution{
public:
    int maxLength(string S){
        stack<int> stk;
        stk.push(-1);
        int maxLen = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    maxLen = max(maxLen, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }
        return maxLen;
    }
};

