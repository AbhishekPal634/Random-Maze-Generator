#include <bits/stdc++.h>

using namespace std;

class Maze {
    int m = rand() % 4 + 3;
    int n = rand() % 4 + 3;
    int dp[10][10];
public:
    Maze() {
        system("cls");
        cout << "Find the shortest path from the START position to the END position" << endl;
        cout << "You can more only HORIZONTALLY or VERTICALLY" << endl;
        cout << "'.' denotes the path you can travel on and '*' denotes obstacle. You cannot travel through an obstacle"
             << endl << endl;
    }

    vector<vector<char>> generateMaze() {
        vector<vector<char>> grid(m, vector<char>(n));
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
        return grid;
    }

    void displayMaze() {
        vector<vector<char>> grid(m, vector<char>(n));
        grid = generateMaze();
        cout << "START" << endl << "|" << endl << "v" << endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << grid[i][j] << " ";
            }
            if (i != m - 1)cout << endl;
            else cout << " <- END" << endl << endl;
        }
    }

    int pathCalc(int x, int y, int m, int n) {
        vector<vector<char>> grid(m, vector<char>(n));
        grid = generateMaze();

        if (x == m - 1 && y == n - 1) return 1;
        if ((x > m - 1 || y > n - 1) || grid[x][y] == '*') return 0;
        if (dp[x][y] != -1) return dp[x][y];

        return dp[x][y] = pathCalc(x + 1, y, m, n) + pathCalc(x, y + 1, m, n);
    }

    void totalPaths() {
        int c = 0;
        memset(dp, -1, sizeof dp);
        c = pathCalc(0, 0, m, n);
        cout << "Total available paths : " << c << endl;
    }
};

int main() {
    Maze m;
    m.generateMaze();
    m.displayMaze();
    m.totalPaths();
}