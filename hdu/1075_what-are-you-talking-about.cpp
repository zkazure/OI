#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string input;
    cin >> input;

    map<string, string> m;
    string src, dst;
    while (cin >> src && src != "END") {
        cin >> dst;
        m[dst] = src;
    }

    string line;
    while (getline(cin, line) && line != "END") {
        string token;
        for (int i = 0; i < line.length(); i += 1) {
            if (isalpha(line[i])) {
                token += line[i];
            } else {
                if (m.find(token) != m.end())
                    token = m[token];

                cout << token << line[i];
                token = "";
            }
        }
        cout << "\n";
    }

    return 0;
}
