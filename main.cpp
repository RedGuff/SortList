#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

string file = "List.txt";
string fileSorted = "List.txt"; // "List-sorted.txt";
string fileBak = "List.txt_bak";
vector<string> Liste1(0, "");

bool FirstBefore(string world1 = "", string world2 = "") {
    if(world1.size() <= world2.size()) { // Important : le cas "égal" ne doit pas boucler !
        return true;
        }
    else {
        return false;
        }
    }


void readListe1() { // Ok.
    for(int a = 0; a < Liste1.size(); a++) {
        cout << Liste1[a] << endl;
        }
    }

void sortList1() { // Mix Liste1, via une liste temporaire. // Ok.
    bool SortFinished = true;
    string tempString = "";
    do {
        SortFinished = true;
        for(int a = 0; a < Liste1.size() - 1; a++) { // aMax fois, aMax non utilisé. parfait pour les tableaux.
            if(!FirstBefore(Liste1[a], Liste1[a + 1])) {
                SortFinished = false;
swapElementsListe:
                tempString = Liste1[a];
                Liste1[a] = Liste1[a + 1];
                Liste1[a + 1] = tempString;
                }
            }
        }
    while(SortFinished == false);
    }


void initListe(string fileName1 = file) {   // With BAK. // Ok.
    ifstream file(fileName1.c_str(), ios::in);
    ofstream outfile(fileBak.c_str());     // Pas d'append pour le BAK : on remplace !
    if(!file) {
        cerr << "Impossible to read the file: " << fileName1 << endl;
        }
    else if(!outfile) {
        cerr << "Impossible to write the BAK file: " << fileBak << endl;
        }
    else {
        string line;
        while(getline(file, line)) {
            Liste1.push_back(line);
            outfile << line << endl;
            }
        file.close();
        }
    }

void writeListe1(string fileOut = "out.txt") {
    ofstream outfile(fileOut.c_str());     // Pas d'append : on remplace ! On a déjà sauvé avant.
    if(!outfile) {
        cerr << "Impossible to write the file: " << fileOut << endl;
        }
    else {
        string line;
        for(int a = 0; a < Liste1.size(); a++) {
            outfile << Liste1[a] << endl;
            }
        outfile.close();
        }
    }

int main() {
    srand(time(NULL));       // No need for better init.
    initListe();
//    readListe1(); // Tests ok.
    sortList1();
    cout << " " << endl;
 //   readListe1(); // Tests ok.
    writeListe1(fileSorted);
    cout << "Ok." << endl;
    return 0;
    }
