#include <iostream>
#include "hashtable.h"

using namespace std;

Hashtable::Hashtable()//sets all collision and operation counters to 0 and is given a hash table size
{
    hashtableSize;
    chaincollisions = 0;
    opencollisions = 0;
    chainsearches = 0;
    opensearches = 0;
}

Hashtable::~Hashtable()
{

}

void Hashtable::mynewarray(int arraysize)//creates an array of pointers based on the input array size
{
    hashtableSize = arraysize;
    chainer = new record *[arraysize];
    opener = new record *[arraysize];
}

int Hashtable::hashSum(string name)//creates an index value for the hash functions based on playerID
{
    int sum = 101;
    unsigned int hashing = 0;

    for(int i = 0; i < name.length(); i++)
    {
        hashing = (hashing * sum) + name[i];
    }
    hashing = hashing % hashtableSize;
    return hashing;
}
/*int Hashtable::hashSum(string name)
{
    int sum = 0;

    for(int i = 0; i < name.length(); i++)
    {
        sum = sum + int(name[i]);
    }
    sum = sum % hashtableSize;
    return sum;
}*/

void Hashtable::createHasherChain(string year, string team, string league, string player, string salar, string first, string last, string byear, string bcountry, string weigh, string heigh, string bat, string thro)
{//creates a hash table using chaining
    //string fullname = first + last;
    int index = hashSum(player);
    record *newchainer = new record(year, team, league, player, salar, first, last, byear, bcountry, weigh, heigh, bat, thro);

    if(chainer[index] == NULL)
    {
        chainer[index] = newchainer;
    }

    else
    {
        record *curr = chainer[index];

        while(curr -> next != NULL && curr -> playerID != player)
        {
            curr = curr -> next;
        }

        if(curr -> playerID == player)
        {
            curr -> yearID.push_back(year);
            curr -> teamID.push_back(team);
            curr -> leagueID.push_back(league);
            curr -> salary.push_back(salar);
        }

        else
        {
            curr = chainer[index];
            chaincollisions ++;

            while(curr -> next != NULL && last > curr -> lastName)
            {
                chaincollisions ++;
                curr = curr -> next;
            }

            if(curr -> previous == NULL)
            {
                newchainer -> next = curr;
                chainer[index] = newchainer;
                curr -> previous = newchainer;
            }

            else if(curr -> next == NULL)
            {
                curr -> next = newchainer;
                newchainer -> previous = curr;
            }

            else
            {
                newchainer -> previous = curr -> previous;
                curr -> previous -> next = newchainer;
                curr -> previous = newchainer;
                newchainer -> next = curr;
            }
        }
    }
}

record *Hashtable::chainSearch(string value)//searches through the created hash table for a specific value or player ID
{
    int index = hashSum(value);

    if(chainer[index] == NULL)
    {
        return NULL;
    }

    else
    {
        chainsearches ++;
        record *curr = chainer[index];

        while(curr -> next != NULL && curr -> playerID != value)
        {
            chainsearches ++;
            curr = curr -> next;
        }
        return curr;
    }
    //return NULL;
}

void Hashtable::chaindisplay(string value)//displays the information from the resulting value of the search function
{
    record *display = chainSearch(value);

    if(display == NULL)
    {
        cout << "Doesn't exist." << endl;
    }

    else
    {
        cout << "Player First Name: " << display -> firstName << endl;
        cout << "Player Last Name: " << display -> lastName << endl;
        cout << "Player's Country: " << display -> birthCountry << endl;
        cout << "Player's Birth Year: " << display -> birthYear << endl;
        cout << "Player's Weight: " << display -> weight << endl;
        cout << "Player's Height: " << display -> height << endl;
        cout << "Player's Bat #: " << display -> bats << endl;
        cout << "Player's Throws: " << display -> throws << endl;
        cout << "Player's Team and Salary: " << endl;

        for(int i = 0; i < display -> teamID.size(); i++)
        {
            cout << display -> yearID[i] << ", " << display -> teamID[i] << ", " << display -> leagueID[i] << ", " << display -> salary[i] << endl;
        }
    }
    cout << "Chain searches: " << chainsearches << endl;
    cout << "Chain collisions: " << chaincollisions << endl;
}

void Hashtable::createHasherOpen(string year, string team, string league, string player, string salar, string first, string last, string byear, string bcountry, string weigh, string heigh, string bat, string thro)
{//creates an open addressing hash table
    //string fullname = first + last;
    record  *newopener = new record(year, team, league, player, salar, first, last, byear, bcountry, weigh, heigh, bat, thro);
    int index = hashSum(player);

    if(opener[index] == NULL)
    {
        opener[index] = newopener;
    }

    else
    {
        opencollisions ++;
        bool adder = 1;

        for(int i = 0; i < hashtableSize; i++)
        {
            if(opener[i] != NULL)
            {
                if(opener[i] -> playerID == player)
                {
                    opener[i] -> yearID.push_back(year);
                    opener[i] -> teamID.push_back(team);
                    opener[i] -> leagueID.push_back(league);
                    opener[i] -> salary.push_back(salar);
                    adder = 0;
                    break;
                }
            }
        }

        if(adder)
        {
            opencollisions ++;
            int temporary = index;

            while(opener[temporary] != NULL)
            {
                opencollisions ++;
                temporary = (temporary + 1) % hashtableSize;

                if(index == temporary)
                {
                    break;
                }
            }
            opener[temporary] = newopener;
        }
    }
}

record *Hashtable::openSearch(string value)// searches through the hash table for a specific value or player ID
{
    opensearches = 0;
    int index = hashSum(value);
    int temporary = index;

    if(opener[index] == NULL)
    {
        return NULL;
    }

    else
    {
        opensearches ++;

        while(opener[temporary] != NULL)
        {
            opensearches ++;

            if(opener[temporary] -> playerID == value)
            {
                return opener[temporary];
            }
            temporary = (temporary + 1) % hashtableSize;

            if(temporary == index)
            {
                return NULL;
            }
        }
    }
}

void Hashtable::opendisplay(string value)//displays the information from the returned value of the search function
{
    record *display = openSearch(value);

    if(display == NULL)
    {
        cout << "Doesn't exist." << endl;
    }

    else
    {
        cout << "Player First Name: " << display -> firstName << endl;
        cout << "Player Last Name: " << display -> lastName << endl;
        cout << "Player's Country: " << display -> birthCountry << endl;
        cout << "Player's Birth Year: " << display -> birthYear << endl;
        cout << "Player's Weight: " << display -> weight << endl;
        cout << "Player's Height: " << display -> height << endl;
        cout << "Player's Bat #: " << display -> bats << endl;
        cout << "Player's Throws: " << display -> throws << endl;
        cout << "Player's Team and Salary: " << endl;

        for(int i = 0; i < display -> teamID.size(); i++)
        {
            cout << display -> yearID[i] << ", " << display -> teamID[i] << ", " << display -> leagueID[i] << ", " << display -> salary[i] << endl;
        }
    }
    cout << "Open searches: " << opensearches << endl;
    cout << "Open collisions: " << opencollisions << endl;
}
