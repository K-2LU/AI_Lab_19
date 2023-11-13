#include <bits/stdc++.h>
using namespace std;


vector<int> generateBoard(int n)   {
    vector<int> rows(n+1);
    for (int i = 0; i <= n; i++)
        rows[i] = i;

    random_shuffle(rows.begin(), rows.end());
    return rows;
    
}

int huristic(vector<int> curr)  {
    int attack = 0;
}