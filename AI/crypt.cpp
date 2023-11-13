#include <bits/stdc++.h>
using namespace std;

int main()  {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int n = s1.length();
    int m = s2.length();
    int o = s3.length();

    map<char, int> mp;

    int a1 = 1, a2 = 1, a3 = 1;
    a1 = pow(10, n); 
    a2 = pow(10, m);
    a3 = pow(10, o);

    cout << a1 << ' ' << a2 << ' ' << a3 << endl;
    for (int a = 0; a < 10000; a++) {
        int r1 = rand() % a1;
        int r2 = rand() % a2;
        int r3 = r1 + r2;

        string t1 = to_string(r1);
        string t2 = to_string(r2);
        string t3 = to_string(r3);

        if(t3.size() != o)
            continue;

        for(int i = 0; i < n; i++)  {
            mp[s1[i]] = t1[i] - '0';
        }
        for(int i = 0; i < m; i++)  {
            if(mp.find(s2[i]) == mp.end())  {
                mp[s2[i]] = t2[i] - '0';
            }
        }
        for (int i = 0; i < o; i++) {
            if(i > t3.size())
                break;
            if (mp.find(s3[i]) == mp.end()) {
                mp[s3[i]] = t3[i] - '0';
            }
        }
        break;
    }
    
    for (int i = 0; i < n; i++) {
        cout << mp[s1[i]];
    }   cout << endl;
    
    for (int i = 0; i < m; i++) {
        cout << mp[s2[i]];
    }   cout << endl;

    for (int i = 0; i < o; i++) {
        cout << mp[s3[i]];
    }   cout << endl;
    return 0;
}