//
//  Collection.hpp
//  CISS-242-Course-Project
//
//  Created by John Carty on 10/5/15.
//  Copyright © 2015 John Carty. All rights reserved.
//

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
        void setSongTitles(vector<string> sT);
        void setSongLength(vector<double> sL);
        
        string getArtist();
        string getCdName();
        double getCdLength();
        vector<string> getSongTitles();
        vector<double> getSongLength();
};



#endif /* Collection_h */
