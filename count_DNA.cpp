#include <iostream>
#include <fstream>
#include <array>
using namespace std;

int main(){
    fstream fs;
    fs.open("count_DNA_input.txt");
    char seq [1000];
    fs >> seq;
    array<int,4> count = {0,0,0,0}; //members correspond to A,T,G C
    for (const char& n : seq){
        switch (n){
            case 'A': ++count[0];
                break;
            case 'T': ++count[1];
                break;
            case 'G': ++count[2];
                break;
            case 'C': ++count[3];
        }
    }
    cout << count[0] << ' ' 
        << count[1] << ' ' 
        << count[2] << ' ' 
        << count[3] << endl;
    return 0;
}
