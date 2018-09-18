#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include "hashtable.h"
#include "hashtable.cpp"
//Danny Nguyen final project Rhonda Hoenigman worked with johnson ngo
using namespace std;

void menu()//menu to display to user
{

	cout << "======Main Menu======" << endl;
	cout << "1. Query Hash Table" << endl;
	cout << "2. Quit" << endl;

    /*cout << "Hash table size: " << endl;
    cout << "Collisions using open addressing: " << endl;
    cout << "Collisions using chaining: " << endl;
    cout << "Search operations using open addressing: " << endl;
    cout << "Search operations using chaining: " << endl;*/
}

int main(int argc, char *argv[])
{
    char* filename = argv[1];
    int hashSize = atoi(argv[2]);
    menu();
    Hashtable baseballs;
    baseballs.mynewarray(hashSize);
    //string files = "/home/user/Desktop/playerData";
    ifstream infile;
    infile.open(filename);
    string strline;
    string year, team, league, player, salar, first, last, birthyear, birthcountry, weigh, heigh, bat, thro;
    int index = 0;

    while(getline(infile, strline, '\n'))
    {
        stringstream ss;
        ss << strline;
        getline(ss, strline, ',');
        year = strline;
        getline(ss, strline, ',');
        team = strline;
        getline(ss, strline, ',');
        league = strline;
        getline(ss, strline, ',');
        player = strline;
        getline(ss, strline, ',');
        salar = strline;
        getline(ss, strline, ',');
        first = strline;
        getline(ss, strline, ',');
        last = strline;
        getline(ss, strline, ',');
        birthyear = strline;
        getline(ss, strline, ',');
        birthcountry = strline;
        getline(ss, strline, ',');
        weigh = strline;
        getline(ss, strline, ',');
        heigh = strline;
        getline(ss, strline, ',');
        bat = strline;
        getline(ss, strline, '\n');
        thro = strline;

        baseballs.createHasherChain(year, team, league, player, salar, first, last, birthyear, birthcountry, weigh, heigh, bat, thro);
        baseballs.createHasherOpen(year, team, league, player, salar, first, last, birthyear, birthcountry, weigh, heigh, bat, thro);
    }

    while(int flag = 1)
    {
        int choice;
        cin >> choice;

        if(choice == 1)
        {
            string firstName;
            //string lastName;
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Enter player ID: " << endl;
            getline(cin, firstName);
            //cout << "Enter last name: " << endl;
            //getline(cin, lastName);
            baseballs.chaindisplay(firstName);
            baseballs.opendisplay(firstName);
            menu();
        }

        else if(choice == 2)
        {
            cout << "Goodbye!" << endl;
            return 0;
        }

        else
        {
            cout << "Enter a valid response." << endl;
            menu();
        }
    }
}
