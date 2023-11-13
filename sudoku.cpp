#include <bits/stdc++.h>
using namespace std;

int index = 0;
map<int, vector<vector<int>>> solutions;

void showGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        if(i%3==0 && i != 0)    cout << "- - - - - - - - - - - \n";
        for (int j = 0; j < 9; j++) {
            if(j%3==0 && j != 0)  cout << "| ";
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

pair<int, int> findEmptySpace(int grid[9][9]) {
    pair<int, int> space = {-1, -1}; 

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] == 0) {
                space.first = i;
                space.second = j;
                return space;
            }

    return space;
}

bool isValid(int grid[9][9], int n, pair<int, int> pos) {
    int row = pos.first;
    int col = pos.second;

    for (int i = 0; i < 9; i++)
        if (grid[row][i] == n || grid[i][col] == n)
            return false;

    int x = row - (row % 3);
    int y = col - (col % 3);

    for (int i = x; i < x + 3; i++)
        for (int j = y; j < y + 3; j++)
            if (grid[i][j] == n)
                return false;

    return true;
}

bool sudokuSolver(int grid[9][9]) {
    pair<int, int> location = findEmptySpace(grid);

    if (location.first == -1) { 
        cout << "Solved:\n";
        showGrid(grid);
        return true;
    }

    int row = location.first;
    int col = location.second;

    for (int i = 1; i <= 9; i++) {
        if (isValid(grid, i, location)) {
            grid[row][col] = i;

            if (sudokuSolver(grid)) {

                vector<vector<int>> temp(9);
                for (size_t a = 0; a < 9; a++)
                {
                    for (size_t b = 0; b < 9; b++)
                    {
                        temp[a].push_back(grid[a][b]);
                    }
                    
                }
                solutions[index++] = temp;
                return true; 
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r+", stdin);
    int grid[9][9];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> grid[i][j];

    showGrid(grid);
    sudokuSolver(grid);

    return 0;
}
