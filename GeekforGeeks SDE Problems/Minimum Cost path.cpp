#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Cell {
    int x, y, distance;
    Cell(int x, int y, int distance) : x(x), y(y), distance(distance) {}
};

struct CompareDistance {
    bool operator()(Cell const& a, Cell const& b) {
        return a.distance > b.distance;
    }
};

class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        priority_queue<Cell, vector<Cell>, CompareDistance> pq;
        pq.push(Cell(0, 0, grid[0][0]));

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            Cell cell = pq.top();
            pq.pop();

            for (vector<int>& dir : dirs) {
                int newX = cell.x + dir[0];
                int newY = cell.y + dir[1];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                    int newDist = cell.distance + grid[newX][newY];
                    if (newDist < dist[newX][newY]) {
                        dist[newX][newY] = newDist;
                        pq.push(Cell(newX, newY, newDist));
                    }
                }
            }
        }

        return dist[n - 1][n - 1];
    }
};