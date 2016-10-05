#include <iostream>
#include <string>
/* k = AA; m = Aa; n = aa; Let s = k + m + n
 * First parent has 
 *  k/s chance to be AA
 *      100% of dominant phenotype in offspring
 *  m/s chance to be Aa
 *      k/(s-1) chance that 2nd parent is AA > 100% chance for dom phenotype
 *      (m-1)/(s-1) chance that 2nd parent is Aa > 75% chance for dom
 *      n/(s-1) chance that 2nd parent is aa > 50% chance for dom
 *  n/s chance to be homozygous recessive
 *      k/(s-1) chance that 2nd parent is AA > 100% chance
 *      m/(s-1) chance that 2nd parent is Aa > 50% chance
 * Total chance for dominant phenotype is then
 * (1/s)*{k+[1/(s-1)]*[m*k+k*n+n*m+.75*m*(m-1)]}
 */
using namespace std;

int main(int argc, char* argv[]) {
    double k = stod(argv[1]);
    double m = stod(argv[2]);
    double n = stod(argv[3]);
    double s = k + m + n;
    double S = m*k + k*n + n*m;
    double result = (1/s)*(k+(1/(s-1))*(S+0.75*m*(m-1)));
    cout << result << endl;
}
