#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, char> umap;

umap get_rna_code(string table){
    //Let's agree that 'Z' represents Stop codon
    umap out;
    fstream rna_code;
    string line;
    rna_code.open(table);
    getline(rna_code, line);
    regex codon_rgx("((([AUGC]{3})[[:space:]]([A-Z])[[:space:]]*){4})");
    smatch codon;
    do {
        if (regex_search(line, codon, codon_rgx)) {
            cout << codon[0] << endl;//"<1\t2>" << codon[1] << "\t" << codon[2] << endl;
            for (auto res : codon) cout << res << endl;
        }
        getline(rna_code, line);
    } while (!rna_code.eof());
    return out;
}
int main() {
    get_rna_code("rna_codon_table.txt");
    return 0;
}
