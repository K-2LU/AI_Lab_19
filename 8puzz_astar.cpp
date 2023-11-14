#include <bits/stdc++.h>
using namespace std;


int mov[] = {3, -3, 1, -1};

map<string, bool> vis;
vector<string> path;

bool isValid(int pos)   {
    return pos >= 0 && pos <= 8;
}

int heuristic(string current, string goal)  {
    int H = 0;
    for(int i = 0; i < 9; i++)
        H += current[i] != goal[i];
    
    return H;
}

int astar(string start, string goal)    {
    int step = 0;
    priority_queue <pair<int, pair<int, string>>, 
        vector<pair<int, pair<int, string>>>, 
        greater<pair<int, pair<int, string>>>> pq;
    // int ans = 0;
    pq.push({heuristic(start, goal), {1, start}});

    while(!pq.empty())  {
        // ans++;
        string current = pq.top().second.second;
        int cost = pq.top().first;
        int ans = pq.top().second.first;
        pq.pop();

        if(current == goal) {
            cout << "Found" << endl;
            return ans;
        }

        int pos;
        for(pos = 0; pos < 9; pos++)
            if(current[pos] == '0')
                break;

        vector<int> posMove;
        for(int i = 0; i < 4; i++)  {
            if(!isValid(pos+mov[i]))   continue;

            posMove.push_back(pos+mov[i]);
        }

        for(auto i: posMove)    {
            string temp = current;
            swap(current[i], current[pos]);

            if(vis[current] != true)    {
                int currentCost = ans + 1 + heuristic(current, goal);
                vis[current] = true;
                pq.push({currentCost, {ans+1, current}});
            }

            current = temp;
        }   
    }
    return - 1;
}

int main()  {
    string start, fin;
    cin >> start >> fin;

    cout << astar(start, fin) << endl;
}