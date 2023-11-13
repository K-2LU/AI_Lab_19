#include <bits/stdc++.h>
using namespace std;

int main()  {

    fstream file;
    file.open("set.txt", ios::in);

    vector <string> dataset;
    string myline;
    while(getline(file, myline))   {
        dataset.push_back(myline);
    }
    file.close();

    map <string, int> mymap;
    mymap["name"] = 0;
    mymap["university"] = 1;
    mymap["semester"] = 2;
    mymap["registration"] = 3;

    string ans;

    string question, ig;
    cout << "Ask me a question: ";
        
    while(getline(cin, question))    {
        

        // question = tolower(question);

        if(question.find("university") != string::npos )  ans = dataset[mymap["university"]];
        else if(question.find("name") != string::npos )  ans = dataset[mymap["name"]];
        else if(question.find("semester") != string::npos )  ans = dataset[mymap["semester"]];
        else if(question.find("registration") != string::npos )  ans = dataset[mymap["registration"]];
        else ans = "The answer does not exist in my dataset";

        cout << ans << endl;
        // break;
    }

    return 0;
}