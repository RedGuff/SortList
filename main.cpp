#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

string file = "List.txt";
string fileSorted = "List.txt"; // "List-sorted.txt";
string fileBak = "List.txt_bak";
vector<string> Liste1(0, "");

int FirstBeforeLong(string world1 = "", string world2 = "") { // Ok.
    if(world1.size() < world2.size()) {
        return 1;
        }
    else if(world1.size() == world2.size()) { // Important : le cas "égal" ne doit pas boucler !
        return 0;
        }
    else {
        return -1;
        }
    }


int FirstBeforeLetterASCII(char a = 'a', char b = 'b') {
    if(int(a) < int(b)) {
        return 1;
        }
    else if(int(a) > int(b)) {
        return -1;
        }
    else {
        return 0; // Important : le cas "égal" ne doit pas boucler !
        }
    }

int FirstBeforeLetter(char a = 'a', char b = 'b'){
return FirstBeforeLetterASCII(a,b);
}

int FirstBeforeWord(string world1 = "", string world2 = "") { // https://fr.wikipedia.org/wiki/Classement_alphab%C3%A9tique#Principes_de_classement
    for(int letter = 0; letter < min(world1.size(), world2.size()); letter++) { // While?
        if(FirstBeforeLetter(world1[letter], world2[letter]) == -1) {
            return -1;
            }
        if(FirstBeforeLetter(world1[letter], world2[letter]) == 1) {
            return 1;
            }
        /*
        if(FirstBeforeLetter(world1[letter], world2[letter]) == 0) {
            break; // Next letter;
            }

        */
        }
    return FirstBeforeLong(world1, world2); // :
    /*
     if(world1.size() == world2.size()) { // Identiques.
         return 0;
         }
     if(world1.size() < world2.size()) { // Si identiques + suite : le plus court avant.
         return 1;
         }
     else {
         return -1;
         }
    */
    }

int FirstBefore(string world1 = "", string world2 = "")  {   // Differents tris possibles.
    // return FirstBeforeLong(world1,  world2);
    return FirstBeforeWord(world1,  world2 );
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
        for(int a = 0; a < Liste1.size() - 1; a++) {
            if(FirstBefore(Liste1[a], Liste1[a + 1]) == -1) {
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

void writeListe1(string fileOut = "out.txt") { // Ok.
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
    initListe();
    readListe1(); // Tests ok.
    sortList1();
    cout << " " << endl;
    readListe1(); // Tests ok.
//    writeListe1(fileSorted);
    cout << "\nOk." << endl;
    return 0;
    }
