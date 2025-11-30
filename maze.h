#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Maze {
private:
    char grid[20][20];
    bool visited[20][20];
    bool solvable;
    int startR, startC;

    bool dfs(int r, int c) {
        if (r < 0 || r >= 20 || c < 0 || c >= 20)
            return false;
        if (grid[r][c] == '#')
            return false;
        if (visited[r][c])
            return false;

        if (grid[r][c] == 'E')
            return true;

        visited[r][c] = true;

        return dfs(r - 1, c) ||
               dfs(r + 1, c) ||
               dfs(r, c - 1) ||
               dfs(r, c + 1);
    }

public:
    // Constructor reads ONE maze from the file stream
    Maze(istream &in) {
        string line;
        startR = startC = -1;

        // Read 20 lines
        for (int r = 0; r < 20; r++) {
            getline(in, line);
            for (int c = 0; c < 20; c++) {
                grid[r][c] = line[c];
                if (grid[r][c] == 'S') {
                    startR = r;
                    startC = c;
                }
            }
        }

        // Reset visited array
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                visited[i][j] = false;

        // Run DFS
        solvable = dfs(startR, startC);

        // Skip blank line if present
        if (in.peek() == '\n')
            in.get();
    }

    string toString() const {
        return string("Maze: ") + (solvable ? "YES" : "NO");
    }
};

#endif