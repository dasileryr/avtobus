#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

bool isValid(const string& s) {
    if (s.size() != 6) return false;

    const set<char> L = { 'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'Y' }; //РАЗРЕШЕННЫЕ СИМВОЛЫ

    if (L.find(s[0]) == L.end()) return false;

    for (int i = 1; i <= 3; ++i) {
        if (!isdigit(s[i])) return false;
    }

    if (L.find(s[4]) == L.end()) return false;
    if (L.find(s[5]) == L.end()) return false;

    return true;
}

int main() {
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");

    int n;
    fin >> n;
    string line;
    getline(fin, line);

    for (int i = 0; i < n; ++i) {
        getline(fin, line);
        if (isValid(line))
            fout << "Yes\n";
        else
            fout << "No\n";
    }

    return 0;
}
//COPIRIGHT GLEBASIKCPP, ORANGESVITSHOT & OMAR