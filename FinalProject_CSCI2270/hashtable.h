#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct record
{
    vector<string> yearID;
    vector<string> teamID;
    vector<string> leagueID;
    string playerID;
    vector<string> salary;
    string firstName;
    string lastName;
    string birthYear;
    string birthCountry;
    string weight;
    string height;
    string bats;
    string throws;
    string fullName = firstName + lastName;
    record *previous;
    record *next;

    record()
    {
    };

    record(string year, string team, string league, string player, string s, string first, string last, string byear, string bcountry, string w, string h, string b, string t)
    {
        yearID.push_back(year);
        teamID.push_back(team);
        leagueID.push_back(league);
        playerID = player;
        salary.push_back(s);
        firstName = first;
        lastName = last;
        birthYear = byear;
        birthCountry = bcountry;
        weight = w;
        height = h;
        bats = b;
        throws = t;
        previous = NULL;
        next = NULL;
    }
};

class Hashtable
{
    public:
        Hashtable();
        ~Hashtable();
        void mynewarray(int arraysize);
        void createHasherChain(string, string, string, string, string, string, string, string, string, string, string, string, string);
        void chaindisplay(string value);
        void createHasherOpen(string, string, string, string, string, string, string, string, string, string, string, string, string);
        void opendisplay(string value);
        void printhashtable();

    private:
        int hashSum(string key);
        int hashtableSize;
        record *chainSearch(string key);
        record *openSearch(string key);
        record **chainer;
        record **opener;
        int chaincollisions;
        int opencollisions;
        int chainsearches;
        int opensearches;
};
#endif // HASHTABLE_H
