#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq; // node with highest priority is at the top

int mov[] = {3, -3, 1, -1};

map<string, bool> vis;
vector<string> path;

bool isValid(int curr)  {
    return curr >= 0 && curr < 9;
}

int huristic(string curr, string goal) {

    vector<pair<int,int>> currRowCol(9), goalRowCol(9);

    for (int x = 0; x <= 8; x++) {
        int row,col;
        for (int i = 0; i < 9; i++) {
            if (curr[i]==x+'0') {
                if (i<=2) row = 0;
                else if (i<=5) row = 1;
                else row = 2;
                col = i%3;
            }
        }
        currRowCol[x] = {row,col};
    }

    for (int x = 0; x <= 8; x++) {
        int row,col;
        for (int i = 0; i < 9; i++) {
            if (goal[i]==x+'0') {
                if (i<=2) row = 0;
                else if (i<=5) row = 1;
                else row = 2;
                col = i%3;
            }
        }
        goalRowCol[x] = {row,col};
    }

    int H = 0;
    for (int i = 0; i <= 8; i++) {
        H += curr[i]!=goal[i];
    }


    return H;
}

int astar(string source, string goal)    {
    pq.push({0, source});
    vis[source] = true;

    while(!pq.empty())  {
        string curr = pq.top().second;
        int cost = pq.top().first;

        // cout << curr << ' ';
        pq.pop();

        if (curr == goal) {
            cout << "Found" << endl;
            return cost+2;
        }

        int pos;

        for(pos = 0; pos < 9; pos++)  {
            if(curr[pos] == '0')
                break;
        }
        int minCost = INT_MAX;
        vector<int> posMove;

        for (int i = 0; i < 4; i++) {
            
            if(!isValid(pos+mov[i]))    continue;

            int currentCost = cost + huristic(curr, goal);

            posMove.push_back(pos+mov[i]);

        }

        for (auto i : posMove) {
            swap(curr[pos],curr[i]);
            if(vis[curr]!=true)  {  
                path.push_back(curr);
                pq.push({cost+1,curr});
                path.pop_back();
                vis[curr] = true;
            }
            swap(curr[pos],curr[i]);
        }
        
    }

    return -1;
}

int main()  {
    string start, fin;
    cin >> start >> fin;

    cout << astar(start, fin) << endl;    
    for(auto i: path)  cout << i << endl;
    // cout << huristic(start,fin) << endl;
}