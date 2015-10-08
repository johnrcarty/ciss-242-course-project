//
//  Collection.cpp
//  CISS-242-Course-Project
//
//  Created by John Carty on 10/5/15.
//  Copyright © 2015 John Carty. All rights reserved.
//

#include "Collection.h"

Collection::Collection(){
    artist = "";
    cdName = "";
    cdLength = 0;
    songTitle = {};
    songLength = {};
    
}


Collection::Collection(string a, string cN, vector<string> sT, vector<double> sL){
    artist = a;
    cdName = cN;
    cdLength = 0;
    songTitle = sT;
    songLength = sL;
}

void Collection::setArtist(string a){
    artist = a;
    
}
void Collection::setCdName(string cN){
    cdName = cN;
}
void Collection::setCdLength(){
    cdLength = 0;
    for (int i = 0; i < songLength.size(); i++) {
        cdLength += songLength[i];
    }
}
void Collection::clearVectors(){
    songTitle.erase(songTitle.begin(),songTitle.end());
}
void Collection::setVectors(vector<string> sT, vector<double> sL){
    songTitle = sT;
    songLength = sL;
    
}

string Collection::getArtist(){
    
    return artist;
}
string Collection::getCdName(){
    
    return cdName;
}
double Collection::getCdLength(){
    
    return cdLength;
}
vector<string> Collection::getSongTitles(){
    
    return songTitle;
}
vector<double> Collection::getSongLength(){
    
    return songLength;
}