#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

std::pair<char, long double> get_pair_from_row(const std::string& s){
    char protein = s[0];
    std::string mass = s.substr(2);
    long double fmass = std::stof(mass);
    return std::pair<char, long double>(protein, fmass);
}

int main() {
    std::fstream fpmass("protein_mass.txt");
    std::map<char, long double> pmass;
    std::string line;
    while (!fpmass.eof()) {
        std::getline(fpmass, line);
        if (line.length() > 0) {
            pmass.insert(get_pair_from_row(line));
        }
    }

    std::fstream fprotein("protein.txt");
    std::stringstream buffer;
    buffer << fprotein.rdbuf();
    std::string protein = buffer.str();
    //std::cout << protein<< std::endl;

    long double mass = 0;
    for (int i = 0; i < protein.length(); ++i) {
        mass += pmass[protein[i]];
    }

    printf("%Lf\n", mass);
    return 0;
}
