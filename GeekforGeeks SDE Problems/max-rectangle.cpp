

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] == 1)
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0, i = 0, n = heights.size();

        while (i < n) {
            if (s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else {
                int tp = s.top();
                s.pop();
                int area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
                maxArea = max(maxArea, area);
            }
        }

        while (!s.empty()) {
            int tp = s.top();
            s.pop();
            int area = heights[tp] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
