#include <iostream>
#include <fstream>
using namespace std;


int randChar () {

    // initialize RNG
    srand(time(nullptr));
    return (rand() % 26) + 91;
    
}


void write (ofstream& theFile, char character) {

    // write to file
    theFile << character;

}


void read (ifstream& readFile) {

    // create string and read from file
    string fileText;

    cout << "The following was written to randomizedtext.txt:\n\n";

    // read file line by line
    while (getline (readFile, fileText)) {
        cout << fileText << endl;
    }

    // close file
    readFile.close();

}


int main () {

    int lineCount;
    int charCount;
    srand(time(nullptr));

    // randomize row and column count
    lineCount = (rand() % 10) + 1;
    charCount = (rand() % 10) + 1;

    char randomletter = randChar();

    ofstream theFile ("randomizedtext.txt");

    for (int i = 0; i <= lineCount; i++) {
        for (int j = 0; j <= charCount; j++) {
            randomletter = randChar();
            write(theFile, randomletter);
        }
        if (i < lineCount) {
            theFile << endl;
        }
    }

    // close file
    theFile.close();

    ifstream readFile("randomizedtext.txt");
    read(readFile);

}