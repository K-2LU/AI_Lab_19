    #include <bits/stdc++.h>
    using namespace std;

    const int STATES = 31;
    const int MAX = (1 << 20);

    map<string, int> mp;
    int xi[4] = {1, -1, 0, 0}; // Corrected array values
    int yi[4] = {0, 0, 1, -1}; // Corrected array values
    int node = 1;

    string str = "";
    string fin = "";

    vector<int> adj[MAX];
    bool vis[MAX];
    bool found = false;
    // vector<int> adj[MAX];

    bool isValid(int x, int y) {
        return (x >= 0 && x < 3 && y >= 0 && y < 3);
    }

    void init(string ini, string fin, int depth) {
        // cout << node << endl;
        if (ini == fin || depth == 0) {
            found = true;
            return; // Base case to terminate recursion
        }
        if(found)
            return;

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

            if (!isValid(nx, ny))
                continue;

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
                adj[par].push_back(node);
                adj[node].push_back(par);
                init(s, fin, depth-1); // Recursive call with reduced depth
            }   else    {
                // cout << "Already present\n";
            }
        }
    }

    void bfs(int node)  {
        // cout << "inside bfs\kn " << node << endl;
        queue<int> q;
        q.push(node);
        vis[node] = true;

        while(!q.empty())   {
            int u = q.front();
            q.pop();

            // cout << u << ' ';

            if(u == mp[fin])    {
                cout << "Found\n";
                break;
            }
            for(int i = 0; i < adj[u].size(); i++)    {
                int v = adj[u][i];
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }   cout << endl;
    }

    int main() {

        // fstream file;
        // file.open("set.txt", ios::in);

        char c;
        cout << "Enter starting state:\n";
        for (int i = 0; i < 9; i++) {
            cin >> c;
            str.push_back(c);
        }

        cout << "Enter final state:\n";
        for (int i = 0; i < 9; i++) {
            cin >> c;
            fin.push_back(c);
        }
        cout << str << ' ' << fin << endl;
        mp.insert({str, 0});
        init(str, fin, 1000); // Specify the depth you want to explore

        cout << mp[str];
        cout << endl;
        cout << mp[fin];
        cout << endl;

        bfs(mp[str]);

        return 0;
    }
