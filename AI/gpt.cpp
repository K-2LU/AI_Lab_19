#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Define correct move directions
const int xi[4] = {0, 0, -1, 1};
const int yi[4] = {-1, 1, 0, 0};

const int MAX_DEPTH = 1000;

map<string, int> mp;
int node = 1;

bool isValid(int x, int y) {
    return (x >= 0 && x < 3 && y >= 0 && y < 3);
}

bool init(string ini, string fin, int depth) {
    if (ini == fin) {
        return true;
    }
    if (depth == 0) {
        return false;
    }

    int x, y;
    char temp[3][3];
    string t = "";
    int par = mp[ini];

    for (int c = 0, i = 0, j = 0; c < 9; c++, j++) {
        if (j == 3) {
            j = 0, i++;
        }
        temp[i][j] = ini[c];
        t.push_back(ini[c]);
        if (ini[c] == '0') {
            x = i, y = j;
        }
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + xi[i];
        int ny = y + yi[i];

        if (!isValid(nx, ny)) {
            continue;
        }

        char temp2[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp2[i][j] = temp[i][j];
            }
        }
        swap(temp2[x][y], temp2[nx][ny]);

        string s = "";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                s.push_back(temp2[i][j]);

        if (mp.find(s) == mp.end()) {
            mp.insert({s, node++});
            if (init(s, fin, depth - 1)) {
                return true; // Solution found
            }
        }
    }

    return false; // No solution found at this depth
}

void bfs(string start, string finish) {
    queue<string> q;
    map<string, bool> vis;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        string u = q.front();
        q.pop();

        if (u == finish) {
            cout << "Found\n";
            return;
        }

        int x, y;
        char temp[3][3];

        for (int c = 0, i = 0, j = 0; c < 9; c++, j++) {
            if (j == 3) {
                j = 0, i++;
            }
            temp[i][j] = u[c];
            if (u[c] == '0') {
                x = i, y = j;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + xi[i];
            int ny = y + yi[i];

            if (!isValid(nx, ny)) {
                continue;
            }

            char temp2[3][3];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    temp2[i][j] = temp[i][j];
                }
            }
            swap(temp2[x][y], temp2[nx][ny]);

            string s = "";
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    s.push_back(temp2[i][j]);
                }
            }

            if (!vis[s]) {
                vis[s] = true;
                q.push(s);
            }
        }
    }
    cout << "Not found\n";
}

int main() {
    string str = "123456780";
    string fin = "123456708";

    if (init(str, fin, MAX_DEPTH)) {
        bfs(str, fin);
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
