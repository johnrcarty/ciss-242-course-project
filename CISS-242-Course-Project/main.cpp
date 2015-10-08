/******************************************************************************
 Week 8 - Course Project
 CD Collection
 CISS 242-B
 
 <description>
 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#include <iomanip>
#include <iostream>
#include "Collection.h"


char cdOutput(vector<Collection> &);
char addCD(vector<Collection> &);
char removeCD(vector<Collection> &);
char updateCD(vector<Collection> &);

int main() {
    
    vector<Collection> CDs;
    
    int choice = 0;
    char cont = 'y';
    
    do{
        cout << "Please select from the following:" << endl;
        cout << "\t 1. Show All CDs" << endl;
        cout << "\t 2. Add a CD" << endl;
        cout << "\t 3. Remove a CD" << endl;
        cout << "\t 4. Update a CD" << endl;
        cout << "\t 5. Exit program" << endl;
        cout << "Option: ";
        cin >> choice;
        
        
        switch (choice) {
            case 1:
                cont = cdOutput(CDs);
                break;
            case 2:
                cont = addCD(CDs);
                break;
            case 3:
                cont = removeCD(CDs);
                break;
            case 4:
                cont = updateCD(CDs);
                break;
                
            default:
                cont = 'n';
                break;
        }
    }while (cont == 'y' || cont == 'Y');
    
    
    return 0;
}

char cdOutput(vector<Collection> &o){
    char cont;
    
    cout << setw(15) << left << "Artist" << setw(15) << "CD Name" << setw(5) << "CD Length" << setw(15) << right << "Song Title" << setw(15) << "Song Length" << endl;
    for (int i = 0; i < o.size(); i++) {
        vector<string> sT = o[i].getSongTitles();
        vector<double> sL = o[i].getSongLength();
        cout << left << setw(15) << o[i].getArtist();
        cout << setw(15) << o[i].getCdName();
        o[i].setCdLength();
        cout << setw(5) << o[i].getCdLength() << right << " min";
        for (int j = 0; j < sT.size(); j++) {
            if (j==0) {
                cout << setw(15) << right << sT[j] << setw(10) << sL[j] << " min" << endl;
            } else{
                cout << setw(54) << right << sT[j] << setw(10) << sL[j] << " min" << endl;
            }
        }
    }
    
    
    cout << "Press 'Y' to return to main menu, any other key to exit: ";
    cin >> cont;
    return cont;
}

char addCD(vector<Collection> &o){
    string a;
    string cN;
    string title;
    char next = 'n';
    double length = 0;
    
    vector<string>sT;
    vector<double>sL;
    char cont;
    
    cout << "Please enter the Artist Name: ";
    cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
    getline(cin, a);
    
    cout << "Please enter the CD Name: ";
    getline(cin, cN);
    do{
        
        cout << "Please enter the Song Name: ";
        getline(cin, title);
        sT.push_back(title);
        cout << "Please enter the Song Length: ";
        cin >> length;
        sL.push_back(length);
        cout << "Add another song? ";
        cin >> next;
        cin.ignore(256,'\n');       //an enter command kept getting stuck in the buffer, this fixed it.
    }while (next == 'y' || next == 'Y');
    
    o.push_back({a, cN, sT, sL});
    
    cout << "Press 'Y' to return to main menu, any other key to exit: ";
    cin >> cont;
    return cont;
}

char removeCD(vector<Collection> &o){
    char cont = 'n';
    char next = 'n';
    int remove = 0;
    
    do{
        cout << "Please select the CD to be removed:" << endl;
        for (int i = 0; i < o.size(); i++) {
            cout << "\t" << (i+1) << ". " << o[i].getArtist() << " - " << o[i].getCdName() << endl;
        }
        cout << "Which number would you like to remove? Press 0 to go back to menu. ";
        cin >> remove;
        if (!remove) {
            cont = 'y';
            return cont;
        }
        o.erase(o.begin()+(remove - 1));
        cout << "Would you like to remove another? (Y/N) ";
        cin >> next;
    } while (next == 'y' || next == 'Y');
    cout << "Would you like to return to menu? (Y/N) ";
    cin >> cont;
    return cont;
}

char updateCD(vector<Collection> &o){
    char cont = 'n';
    char next = 'n';
    int edit = 0;
    
    do{
        cout << "Please select the CD to be removed:" << endl;
        for (int i = 0; i < o.size(); i++) {
            cout << "\t" << (i+1) << ". " << o[i].getArtist() << " - " << o[i].getCdName() << endl;
        }
        cout << "Which number would you like to edit? Press 0 to go back to menu. ";
        cin >> edit;
        if (!edit) {
            cont = 'y';
            return cont;
        }
        edit--;

        cout << "Would you like to edit another? (Y/N) ";
        cin >> next;
    } while (next == 'y' || next == 'Y');
    
    cout << "Press 'Y' to return to main menu, any other key to exit: ";
    cin >> cont;
    return cont;
}