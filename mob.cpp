#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define int ll int

int x[]={0,0,1,-1};
int y[]={1,-1,0,0};

vector<vector<int>> goal = {{1, 2, 3},{4, 5, 6},{7, 8, 0}};
map<vector<vector<int>>,vector<vector<int>>> par;

bool is_safe(int a,int b)   {
    if(a>=0 and b>=0 and a<=2 and b<=2) return true;
    return false;
}

bool is_goal(vector<vector<int>> init){
    return init==goal;
}

int heuristic(vector<vector<int>> s){
    int cnt=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(s[i][j]!=goal[i][j]) cnt++;

    return cnt;
}

void print_state(vector<vector<int>> s) {
    for(int i=0;i<3;i++)    {
        for(int j=0;j<3;j++)
            cout << s[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

pair<int,int> find_empty(vector<vector<int>> s) {
    for(int i=0;i<3;i++)    {
        for(int j=0;j<3;j++)
           if(s[i][j]==0) return {i,j};
    }
    return {-1, -1};
}

vector<vector<int>> Swap(vector<vector<int>> cur,int a,int b,int c,int d)   {
    swap(cur[a][b],cur[c][d]);
    return cur;
}

void solve(int cs)  {
    vector<vector<int>> init = {{1, 2, 3},{5, 6, 0},{7, 8, 4}};

    map<vector<vector<int>> ,bool> vis;
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, greater<pair<int, vector<vector<int>>>>> pq;
    
    pq.push({heuristic(init),init});
    int deep=0;

    while(!pq.empty())  {
        vector<vector<int>> cur = pq.top().second;
        int cost=pq.top().first;
        pq.pop();
        // print_state(cur);
        vis[cur]=true;

        if(cur==goal)
        {
            print_state(cur);
            break;
        }

        deep++;

        pair<int,int> e = find_empty(cur);

        for(int i=0;i<4;i++)    {
            int p=e.first+x[i];
            int q=e.second+y[i];

            if(is_safe(p,q))    {
                vector<vector<int>> new_state = Swap(cur,e.first,e.second,p,q);
            
                if(!vis[new_state]){
                    par[new_state]=cur;
                    pq.push({deep+heuristic(new_state), new_state});
                }
            }
        }
    }

    cout << "path: " << endl;
    
    vector<vector<vector<int>>> ans;
    vector<vector<int>> x=goal;
    
    ans.push_back(x);
    while(par[x]!=init) {   
        x=par[x];
        ans.push_back(x);
    }   ans.push_back(init);

    reverse(ans.begin(),ans.end());
    
    cout << ans.size() << endl << endl;
    
    for(int i=0;i<ans.size();i++)
        print_state(ans[i]);
}

int32_t main()  {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    int cs=1;
    
    while (t--)
        solve(cs++);

   return 0;
}