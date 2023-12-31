

class Solution
{
public:
    void db(int t, int p, int k, int n, vector<int>& a, string& res) {
        if (t > n) {
            if (n % p == 0) {
                for (int i = 1; i <= p; ++i) {
                    res += to_string(a[i]);
                }
            }
        } else {
            a[t] = a[t - p];
            db(t + 1, p, k, n, a, res);
            for (int j = a[t - p] + 1; j < k; ++j) {
                a[t] = j;
                db(t + 1, t, k, n, a, res);
            }
        }
    }

    string deBruijn(int k, int n) {
        vector<int> a(k * n);
        string res;
        db(1, 1, k, n, a, res);
        return res;
    }

    string findString(int n, int k) {
        string res = deBruijn(k, n);
        for (int i = 0; i < n - 1; ++i) {
            res += res[i];
        }
        return res;
    }
};
