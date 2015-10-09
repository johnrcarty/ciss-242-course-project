/******************************************************************************
 Week 8 - Course Project
 CD Collection
 CISS 242-B
 
 <description>  This program will have the user input CDs from their collection
                then allow them to ouput the list, remove a CD, or edit a CD.
 
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
    
    //Initialize the a vector of the Collection Class
    vector<Collection> CDs;
    
    int choice = 0;
    char cont = 'y';
    
    do{
        //switch for the menu
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
                //Option 1 - Output all CDs
                cont = cdOutput(CDs);
                break;
            case 2:
                //Option 2 - Add a CD
                cont = addCD(CDs);
                break;
            case 3:
                //Option 3 -  Remove a CD
                cont = removeCD(CDs);
                break;
            case 4:
                //Option 4 - Update a CD
                cont = updateCD(CDs);
                break;
                
            default:
                cont = 'n';
                break;
        }
    }while (cont == 'y' || cont == 'Y');
    
    
    return 0;
}

//Output the CDs in table format
char cdOutput(vector<Collection> &o){
    char cont;
    
    //Table Header
    cout << setw(15) << left << "Artist" << setw(15) << "CD Name" << setw(5) << "CD Length" << setw(15) << right << "Song Title" << setw(15) << "Song Length" << endl;
    for (int i = 0; i < o.size(); i++) {
        
        //populate local vector for song titles and lengths
        vector<string> sT = o[i].getSongTitles();
        vector<double> sL = o[i].getSongLength();
        
        //output data for each cd
        cout << left << setw(15) << o[i].getArtist();
        cout << setw(15) << o[i].getCdName();
        o[i].setCdLength();
        cout << setw(5) << o[i].getCdLength() << right << " min";
        
        //for loop to output songs and their length - lines after the first one only have song title/length
        for (int j = 0; j < sT.size(); j++) {
            if (j==0) {
                cout << setw(15) << right << sT[j] << setw(10) << sL[j] << " min" << endl;
            } else{
                cout << setw(54) << right << sT[j] << setw(10) << sL[j] << " min" << endl;
            }
        }
    }
    
    //Ask for user input to return to main menu, or exit program
    cout << "Press 'Y' to return to main menu, any other key to exit: ";
    cin >> cont;
    return cont;
}


//Add a CD to the CDs vector
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
        do{
            cout << "Please enter the Song Length: ";
            cin >> length;
            if (length < 0) {
                cout << "Please enter a number greater than 0!" << endl;
            }
        }while (length < 0);
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


//Remove a CD from the vector
char removeCD(vector<Collection> &o){
    char cont = 'n';
    char next = 'n';
    int remove = 0;
    
    do{
        //Ask the user which CD they want to remove and validate
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
            } else if (remove > o.size()){
                cout << "Please enter a valid number!" << endl;
            }
        } while (remove > o.size());
        o.erase(o.begin()+(remove - 1));
        cout << "Would you like to remove another? (Y/N) ";
        cin >> next;
    } while (next == 'y' || next == 'Y');
    cout << "Would you like to return to menu? (Y/N) ";
    cin >> cont;
    return cont;
}

//Edit all fields for a selected element in the CD vector
char updateCD(vector<Collection> &o){
    string a;
    string cN;
    string title;
    
    vector<string>sT;
    vector<double>sL;
    
    char cont = 'n';
    char next = 'n';
    int edit = 0;
    double length = 0;
    
    do{
        //Get user input on which CD to edit and validate
        do{
            cout << "Please select the CD to be edited:" << endl;
            for (int i = 0; i < o.size(); i++) {
                cout << "\t" << (i+1) << ". " << o[i].getArtist() << " - " << o[i].getCdName() << endl;
            }
            cout << "Which number would you like to edit? Press 0 to go back to menu. ";
            cin >> edit;
            if (!edit) {
                cont = 'y';
                return cont;
            }else if (edit > o.size()){
                cout << "Please enter a valid number!" << endl;
            }
        }while(edit > o.size());
        
        edit--;
        cout << "Please enter the Artist Name: ";
        cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
        getline(cin, a);
        o[edit].setArtist(a);
        cout << "Please enter the CD Name: ";
        getline(cin, cN);
        o[edit].setCdName(cN);
        o[edit].clearVectors();
        do{
            cout << "Please enter the Song Name: ";
            getline(cin, title);
            sT.push_back(title);
            do{
                cout << "Please enter the Song Length: ";
                cin >> length;
                if (length < 0) {
                    cout << "Please enter a number greater than 0!" << endl;
                }
            }while (length < 0);
            sL.push_back(length);
            cout << "Add another song? ";
            cin >> next;
            cin.ignore(256,'\n');       //an enter command kept getting stuck in the buffer, this fixed it.
        }while (next == 'y' || next == 'Y');
        
        o[edit].setVectors(sT, sL);
        
        cout << "Would you like to edit another? (Y/N) ";
        cin >> next;
    } while (next == 'y' || next == 'Y');
    
    cout << "Press 'Y' to return to main menu, any other key to exit: ";
    cin >> cont;
    return cont;
}