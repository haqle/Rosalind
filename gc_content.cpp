#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class seq {
public:
    string name;
    string sequence;
    double gc_ratio;
    seq(string fa_name,string fa_seq) : name(fa_name.substr(1)), sequence(fa_seq)
    {
        int total = 0;
        int gc = 0;
        for (char n : sequence){
            ++total;
            if ((n == 'G') or (n == 'C')) {
                ++gc;
            }
        }
        gc_ratio = double(gc) / double(total) * 100;
    }
};
int main() {
    fstream fasta;
    fasta.open("gc_content_input.txt");
    string line, tmp_name, tmp_seq;
    double highest_ratio = 0.0;
    string highest_seq = "";
    while (true) {
        getline(fasta, line);
        if (fasta.eof()){
            break;
        }
        if (line[0] == '>') {
            tmp_name = line;
            tmp_seq = "";
            while (true) {
                getline(fasta,line);
                tmp_seq += line;
                if ((fasta.peek() == '>') or fasta.eof()) break;
            }
            seq my_seq(tmp_name, tmp_seq);
            if (highest_ratio < my_seq.gc_ratio) {
                highest_ratio = my_seq.gc_ratio;
                highest_seq = my_seq.name;
            }
        }
    }
    cout << highest_seq << endl;
    cout << highest_ratio << endl;
    return 0;
}
