#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream fs;
    fs.open("dna2rna_input.txt");
    const int size = 1000;
    char seq_in [size];
    char seq_out [size] = ""; //Allow space for null-terminated char
    fs >> seq_in;
    for (int i = 0; i < size; ++i) {
        switch (seq_in[i]){
            case 'T': seq_out[i] = 'U';
                break;
            default: seq_out[i] = seq_in[i];
                break;
        }
    }

    cout << seq_out << endl;
    return 0;
}
