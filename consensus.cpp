#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
class score {
public:
    unsigned char a = 0;
    unsigned char t = 0;
    unsigned char g = 0;
    unsigned char c = 0;
    char best() {
        unsigned char best = max({a,t,g,c});
        if (best == a) return 'A';
        if (best == t) return 'T';
        if (best == g) return 'G';
        if (best == c) return 'C';
    }
};
int main() {
    fstream dna_file("consensus.txt");
    string line;
    set<string> seq;
    set<char> base({'A','G','T','C'});
    int seq_len = 0;
    while (!dna_file.eof()) {
        string curr_seq = "";
        getline(dna_file, line);
        if ((line[0] == '>') || line == "") continue;
        curr_seq += line;
        while (base.find(char(dna_file.peek())) != base.end()) {
            getline(dna_file, line);
            curr_seq += line;
        }
        if (seq_len == 0) seq_len = curr_seq.size();
        seq.insert(curr_seq);
    }
    score tmp;
    vector<score> profile(seq_len,tmp);
    for (string s : seq) {
        int index = 0;
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (*it == 'A') profile[index].a += 1;
            if (*it == 'T') profile[index].t += 1;
            if (*it == 'G') profile[index].g += 1;
            if (*it == 'C') profile[index].c += 1;
            ++index;
        }
    }
    for (score b : profile) {
        cout << b.best();
    }
    cout << endl;
    cout << "A:";
    for (int i = 0; i < seq_len; ++i) {
        cout << " " << int(profile[i].a);
    }
    cout << "\nC:";
    for (int i = 0; i < seq_len; ++i) {
        cout << " " << int(profile[i].c);
    }
    cout << "\nG:";
    for (int i = 0; i < seq_len; ++i) {
        cout << " " << int(profile[i].g);
    }
    cout << "\nT:";
    for (int i = 0; i < seq_len; ++i) {
        cout << " " << int(profile[i].t);
    }
    cout << seq_len << endl;
    return 0;
}

