// BISMILLAH

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ifstream MyReadFile("set.txt");

    map<int,string> data;
    
    string dt;
    int id=0;
    while (getline (MyReadFile, dt)) {
        data[id++] = dt;
    }

    while (true) {
        string Q; getline(cin,Q);

        // What's your name?
        // How old are you?
        // Where do you live?

        stringstream ss(Q);

        string s; id = -1;
        while (ss>>s) {
            // cout << s << endl;
            if (s=="name?") { id = 0; break; }
            else if (s=="old") { id = 1; break; }
            else if (s=="live?") { id = 2; break; }
        }

        if (id==-1) cout << "undefined" << endl;
        else cout << data[id] << endl;
    }


    return 0;
}