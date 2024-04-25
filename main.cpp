#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;


void parseLine(const string& strLine, vector<Bug*>& vect);

int main() {

    vector<Bug*> bug_vector;


    ifstream file("bugs.txt");
    string line;
    while (getline(file, line)) {
        parseLine(line,bug_vector);
    }


    for (Bug* bug : bug_vector) {
        bug->display();
    }
    /*for (Bug* bug : bug_vector) {
        bug->move();
    }

    for (Bug* bug : bug_vector) {
        bug->display();
    }*/


    for (Bug* bug : bug_vector) {
        delete bug;
    }
    bug_vector.clear();

    return 0;
}

void parseLine(const string& strLine, vector<Bug*>& vect) {
    stringstream strStream(strLine);

    const char DELIMITER = ';';

    string bug_type;
    getline(strStream, bug_type, DELIMITER);

    string strTemp;

    try {
        if (bug_type == "C") {
            getline(strStream, strTemp, DELIMITER);
            int id = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER);
            int x = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER);
            int y = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER);
            int dir = stoi(strTemp);
            Direction direction;
            switch (dir) {
                case 1: direction = Direction::North;
                    break;
                case 2: direction = Direction::East;
                    break;
                case 3: direction = Direction::South;
                    break;
                case 4: direction = Direction::West;
            }

            getline(strStream, strTemp, DELIMITER);
            int size = stoi(strTemp);
            // Create Crawler object and push it into bug_vector
            vect.push_back(new Crawler(id, x, y, direction, size, true));
        } else if (bug_type == "H") {
            getline(strStream, strTemp, DELIMITER);
            int id = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER);
            int x = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER);
            int y = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER);
            int dir = stoi(strTemp);
            Direction direction;
            switch (dir) {
                case 1: direction = Direction::North;
                    break;
                case 2: direction = Direction::East;
                    break;
                case 3: direction = Direction::South;
                    break;
                case 4: direction = Direction::West;
            }

            getline(strStream, strTemp, DELIMITER);
            int size = stoi(strTemp);

            getline(strStream, strTemp, DELIMITER);
            int hop_distance = stoi(strTemp);

            // Create Hopper object and push it into bug_vector
            vect.push_back(new Hopper(id, x, y, direction, size, true, hop_distance));
        }
    } catch (std::invalid_argument const& e) {
        // Handle invalid argument exception
        cout << "Invalid argument: " << e.what() << endl;
    }
}

