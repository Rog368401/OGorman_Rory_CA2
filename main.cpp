#include <iostream>
using namespace std;
#include "Bug.h"
#include <vector>
#include <fstream>
/*https://www.geeksforgeeks.org/copy-file-to-vector-in-cpp-stl/*/
int main() {

    ifstream fin("bugs.txt");
    vector<Bug*> bug_vector;
    Bug *c;
    while (fin >> c){
        bug_vector.push_back(c);
    }
    fin.close();
    for (auto & i : bug_vector) {
        cout << i;
    }

    return 0;

}
