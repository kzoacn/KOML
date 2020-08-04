#include<iostream>
#include<fstream>
#include "koml.hpp"


using namespace std;


int main(){


    fstream fin("test.koml");

    string s,all;
    while(getline(fin,s)){
        all+=s+'\n';
    }

    KOML koml;
    koml.parse(all);

    cout<<koml.serialize();
    cout<<koml.getint("prime")<<endl;
    cout<<koml.getstr("author")<<endl;
    cout<<koml.getstr("tip")<<endl;
    return 0;
}