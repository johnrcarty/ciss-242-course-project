/******************************************************************************
 Week 8 - Course Project
 CD Collection
 CISS 242-B
 
 <description>  Header file for the Collection Class
 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/


#ifndef Collection_h
#define Collection_h

#include <string>
#include <vector>

using namespace std;

class Collection{
    
    private:
        string artist;
        string cdName;
        double cdLength;
        vector<string> songTitle;
        vector<double> songLength;
        
        
    public:
        Collection();
        Collection(string a, string cN, vector<string> sT, vector<double> sL);
        
        void setArtist(string a);
        void setCdName(string cN);
        void setCdLength();
        void setVectors(vector<string> sT, vector<double> sL);
    
        void clearVectors();
        
        string getArtist();
        string getCdName();
        double getCdLength();
        vector<string> getSongTitles();
        vector<double> getSongLength();
};



#endif /* Collection_h */
