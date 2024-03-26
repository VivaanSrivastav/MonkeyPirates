#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<string> > lines;
    while(true){
        string a;
        getline(cin, a);
        if(a == "break") break;
        vector<string> cur;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == '"') cur.push_back('\\' + string(1, a[i]));
            else if(a[i] == '\\') cur.push_back('\\' + string(1, a[i]));
            else cur.push_back(string(1, a[i]));
        }
        lines.push_back(cur);
    }
    for(int i = 0; i < lines.size(); i++) {
        cout << "   cout << \"";
        for(int j = 0; j < lines[i].size(); j++) cout << lines[i][j];
        cout << "\"" << " << endl;";
        cout << endl;
    }
}