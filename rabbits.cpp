#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    //Usage: ./a.out MONTH LITTER_SIZE
    int month = atoi(argv[1]);
    int l_size = atoi(argv[2]); //Litter size
    long long n_1 = 0;  //mature rabbit pairs
    long long n = 1;    //current rabbit pairs
    long long buffer;
    for (int i = 0; i < month; ++i) {
        cout << "\t" << n_1 << "\t" << n << endl;
        buffer = n;
        n += n_1*3;
        n_1 = buffer;
    }
    cout << n_1 << endl;
    return 0;
}
