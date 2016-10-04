#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    const int size = 1000;
    ifstream fs;
    fs.open("complement_DNA_input.txt");
    fs.seekg(0, fs.end);    //Set pointer to the end of the input stream
    int length = fs.tellg();//Get position of pointer ie stream length
    --length;               //Length is one char longer than we need because of null terminator
    fs.seekg(0, fs.beg);    //Restore pointer pos back to the beginning so we can read from it to seq_in
    cout << length << endl;
    char seq_in [size] = "";
    char seq_out [size] = "";
    //fs.read(seq_in, length);
    fs >> seq_in;
    map<char, char> dna_pair;
    dna_pair['A'] = 'T';
    dna_pair['T'] = 'A';
    dna_pair['G'] = 'C';
    dna_pair['C'] = 'G';
    for (int i = 0; i < length; ++i) {
        seq_out[length-i-1] = dna_pair[seq_in[i]];
    }
    cout << seq_out << endl;
    return 0;
}
