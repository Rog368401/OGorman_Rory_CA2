#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;


void parseLine(const string& strLine, vector<Bug*>& vect);
void writeLifeHistory(const vector<Bug*>& bug_vector);


int main() {
    vector<Bug*> bug_vector;
    ifstream file("bugs.txt");
    string line;
    while (getline(file, line)) {
        parseLine(line, bug_vector);
    }
    int choice;
    do {
        cout << "Enter 1 to display bugs," << endl;
        cout << "2 to move bugs," << endl;
        cout << "3 to display a single bug," << endl;
        cout << "0 to exit: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (Bug* bug : bug_vector) {
                    bug->display();
                }
                break;
            case 2:
                for (Bug* bug : bug_vector) {
                    bug->move();
                }
                for (Bug* bug : bug_vector) {
                    bug->display();
                }
                break;
            case 3: {
                int id;
                cout << "Enter the ID of the bug you want to display: ";
                cin >> id;
                bool found = false;
                for (Bug* bug : bug_vector) {
                    if (bug->getID() == id) {
                        found = true;
                        bug->display();
                        break;
                    }
                }
                if (!found) {
                    cout << "No bug exists with the ID: " << id << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting..." << endl;
                writeLifeHistory(bug_vector);
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

        // Display bugs after the operation if not exiting
        if (choice != 0) {
            cout << "After the operation:" << endl;
        }
    } while (choice != 0);

    // Clean up
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
void writeLifeHistory(const vector<Bug*>& bug_vector) {
    ofstream outFile("bugs_life_history_date_time.out");
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing life history." << endl;
        return;
    }
    for (const Bug* bug : bug_vector) {
        outFile << "Bug ID: " << bug->getID() << endl;
        outFile << "Path History:" << endl;
        for (const auto& position : bug->getPath()) {
            outFile << "(" << position.first << ", " << position.second << ")" << endl;
        }
        outFile << endl;
    }
    outFile.close();
    cout << "Life history of all bugs has been written to: bugs_life_history_date_time.out" << endl;
}

