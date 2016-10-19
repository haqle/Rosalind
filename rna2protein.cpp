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
    fstream rna_code("rna_codon_table.txt");
    string line;
    regex codon("(([AUGC]{3})\\s([A-Z]))");
    while (!rna_code.eof()) {
        getline(rna_code, line);
        auto line_begin = std::sregex_iterator(line.begin(), line.end(), codon);
        auto line_end = std::sregex_iterator();
        for (std::sregex_iterator i = line_begin; i != line_end; ++i) {
            std::smatch match = *i;
            out.insert(make_pair(match[2].str(), match[3].str()[0]));
        }
    }
    return out;
}
int main() {
    umap protein_table = get_rna_code("rna_codon_table.txt");
    fstream rna_file("rna2protein.txt");
    string rna_seq, codon;
    string protein = "";
    getline(rna_file, rna_seq);
    for (int i = 0; i < rna_seq.size() - 2; i+=3) {
        codon = rna_seq.substr(i,3);
        if (protein_table[codon] == 'Z') {
            break;
        }
        protein += protein_table[codon];
    }
    cout << protein << endl;
    return 0;
}
