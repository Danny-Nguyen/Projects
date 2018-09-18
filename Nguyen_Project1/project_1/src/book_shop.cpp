#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <string>
#include "book_shop.h"

book_shop::book_shop()// constructor
{
    bookname[50] = ' ';
    author[30] = ' ';
    isbn = 0;
    price = 0;
}

void book_shop::newbook()// this method takes inputs for each data member and stores it to a file named bookfiles.txt use underscores instead of spaces.
{

    std::cout << "Enter a New Book." << std::endl;
    std::ofstream nbook;
    nbook.open ("/home/user/Desktop/bookfiles.txt", std::fstream::app);

    std::cout << "Bookname: " << std::endl;
    std::cin >> bookname;
    nbook << bookname << "\n";
    std::cout << "Author: " << std::endl;
    std::cin >> author;
    nbook << author << "\n";
    std::cout << "ISBN: " << std::endl;
    std::cin >> isbn;
    nbook << isbn << "\n";
    std::cout << "Price: " << std::endl;
    std::cin >> price;
    nbook << price << "\n";
    std::cout << "Thank you for your business!" << std::endl;

    nbook.close();
}

void book_shop::currentbook()// this method reads from the file bookfiles.txt and adds a header in front of each line from the file.
{
    std::cout << std::setw(20) << "Current Book Store Inventory" << std::endl;
    std::string line;
    std::ifstream bookinv;
    bookinv.open("/home/user/Desktop/bookfiles.txt");
    while (!bookinv.eof())
    {
        std::string inv[4];
        for (int i = 0; i < 4 ; i++)
        {
            bookinv >> inv[i];
            if (inv[i] != "")
            {

            if (i % 4 == 0)
            {
                std::cout <<"Book Name  : " << inv[i] << std::endl;
            }
            else if (i % 3 == 0)
            {
                std::cout <<"Book Price : " << inv[i] << std::endl;
                std::cout << " " << std::endl;
            }
            else if (i % 2 == 0)
            {
                std::cout <<"Book ISBN  : " << inv[i] << std::endl;
            }
            else
            {
                std::cout <<"Book Author: " << inv[i] << std::endl;
            }
            }
        }
    }
    bookinv.close();
}
int book_shop::workers()// this method randomized a number between 1 - 10 and selects a number
{
    srand(time(NULL));
    int random = std::rand() % 10 + 1;
    std::cout << "There are " << random << " workers to help you today." << std::endl;
}

int book_shop::calc_revenue() // this method takes the values from every 4th line of the file bookfiles.txt and sums them together.
{
    std::string rev;
    int counter = 0;
    int index = 0;
    std::ifstream calcr;
    calcr.open("/home/user/Desktop/bookfiles.txt");
    while (!calcr.eof())
    {
        getline(calcr, rev);
        index ++;

        if (index % 4 == 0)
        {
            counter = counter + stoi(rev);
        }

    }
    std::cout << "Total possible store revenue is: $" << counter << std::endl;
}

book_shop::~book_shop()
{
    //dtor
}
