

#include <vector>
#include <queue>

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i], word2 = dict[i+1];
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; i++) {
            for (int j : adj[i]) {
                indegree[j]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        string result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result += ('a' + u);
            for (int v : adj[u]) {
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return result;
    }
};








