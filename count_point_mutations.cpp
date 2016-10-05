#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream fs;
    fs.open("count_point_mutations_input.txt");
    string s;
    string t;
    getline(fs, s);
    getline(fs, t);
    int dist = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != t[i]) ++dist;
    }
    cout << dist << endl;
    return 0;
}
