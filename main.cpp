#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

class Maze {
    int m, n;
    int dp[10][10];
    vector<vector<char>> grid;
public:
    Maze() {
        srand((int)time(0));
        m = rand() % 4 + 3;
        n = rand() % 4 + 3;
        system("cls");
        cout << "Find the shortest path from the START position to the END position" << endl;
        cout << "You can move only RIGHT or DOWN" << endl;
        cout << "'.' denotes the path you can travel on and '*' denotes obstacle. You cannot travel through an obstacle" << endl;
        cout << endl;
    }

    void generateMaze() {
        grid.resize(m, vector<char>(n));
        srand((int)time(0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int prob = rand() % 100;
                if (prob <= 80)
                    grid[i][j] = '.';
                else
                    grid[i][j] = '*';
            }
        }
        grid[0][0] = '.';
        grid[m - 1][n - 1] = '.';
    }

    void displayMaze() {
        cout << "START" << endl << "|" << endl << "v" << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j] << " ";
            }
            if (i != m - 1)
                cout << endl;
            else
                cout << " <- END" << endl << endl;
        }
    }

    int pathCalc(int x, int y, int m, int n) {

        if (x == m - 1 && y == n - 1)
            return 1;
        if ((x > m - 1 || y > n - 1) || grid[x][y] == '*')
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];

        return dp[x][y] = pathCalc(x + 1, y, m, n) + pathCalc(x, y + 1, m, n);
    }

    void totalPaths() {
        int c = 0;
        memset(dp, -1, sizeof dp);
        c = pathCalc(0, 0, m, n);
        cout << "Total available paths : " << c << endl;
    }

    void shortestPath() {
        vector<vector<int>> distance(m, vector<int>(n, INF));

        queue<pair<int,int>> q;

        int dx[] = {0, 1};
        int dy[] = {1, 0};

        q.emplace(0,0);
        distance[0][0] = 0;

        while (!q.empty()) {                    //yaha se BFS hai
            int curr_x = (q.front()).first;
            int curr_y = (q.front()).second;
            q.pop();

            for (int i = 0; i < 2; ++i) {
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];

                if ((new_x >= 0 && new_x < m) && (new_y >= 0 && new_y < n) && grid[new_x][new_y] != '*' && distance[new_x][new_y] == INF) {
                    distance[new_x][new_y] = distance[curr_x][curr_y] + 1;
                    q.emplace(new_x, new_y);
                }
            }
        }
        if (distance[m-1][n-1] == INF)
            cout << "No paths available" << endl;
        else
            cout << "\nThe distance covered in the shortest path from START to END is : " << distance[m-1][n-1] << endl;
    }
};

int main() {
    Maze m;
    m.generateMaze();
    m.displayMaze();
    m.totalPaths();
    m.shortestPath();
    return 0;
}