#include <fstream>
#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main() {
    fstream dna_file("find_motif.txt");
    string seq;
    string motif;
    getline(dna_file, seq);
    getline(dna_file, motif);
    int motif_length = motif.size();
    for (int i = 0; i < seq.size() - motif_length; ++i) {
        string curr_seq = seq.substr(i, motif_length);
        if (curr_seq == motif) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    return 0;
}
