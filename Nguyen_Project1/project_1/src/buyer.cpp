#include <iostream>
#include <fstream>
#include "buyer.h"

buyer::buyer()// constructor that initializes each value of each data member.
{
    budget = 0;
    discount = 0;
    tax = 0;
    name = "";
    total = 0;
    receipt[10] = ' ';
    finalcost = 0;
}
buyer::buyer(int b, std::string n)// the method takes in an int and a string which refer to the name and budget and prints them out.
{
    budget = b;
    name = n;
    std::cout << name << ", " << "Your Budget is: $ " << budget << std::endl;
    std::cout << " " << std::endl;

}

int buyer::bookprices()// this method reads every fourth line of the file bookfiles.txt and prints out the price of each book.
{
    std::string numlines;
    int num = 0;
    int prices = 0;
    int pri = 0;
    std::ifstream price;
    price.open("/home/user/Desktop/bookfiles.txt");
    while (!price.eof())
    {
        getline(price, numlines);
        num ++;
        if (num % 4 == 0)
        {
            prices = stoi(numlines);
            std::cout << "Current Price of Book: " << num / 4 << std::endl;
            std::cout << "$ " << prices << std::endl;
            pri = pri + stoi(numlines);
        }
    }
    return pri;
    price.close();
}
float buyer::calc_dis()// this method asks the user if they are a teacher and applys a discount if so. The discount is then applied to the total price.
{
    float discount;
    //float newprice;
    int w = 0;
    std::string y, n;
    y = "y";
    n = "n";
    std::cout << "Are you a Teacher? y/n" << std::endl;

    while (w == 0)
    {
        std::string teacheris;
        std::cin >> teacheris;
        if (teacheris.compare("y") == 0)
        {
            w = 1;
            std::cout << "Teachers get a 35% discount!" << std::endl;
            discount = (bookprices() * 0.35);
            total = bookprices() - discount;
            std::cout << "  " << std::endl;
            std::cout << "Your total will be: " << "$ " << total << std::endl;

        }
        else if (teacheris.compare("n") == 0)
        {
            w = 1;
            std::cout << "Sorry! No discount." << std::endl;
            total = bookprices();
        }

        else
        {
            std::cout << "Please enter a valid answer." << std::endl;
        }
    }
    return total;
}
float buyer::calc_tax()// this method calculates tax for the total price and adds it to the total price. the while loop also only takes in valid values for the input. It also tells you if you have enough money to buy the books or not.
{
    float tax = 0;
    float finalprice = 0;
    tax = total * 0.08;
    finalprice = total + tax;
    finalcost = finalprice;

    std::cout << "Total after taxes: " << "$" << finalprice << std::endl;

    if (finalprice < budget)
    {
        int q = 0;
        std::string y, n;
        y = "y";
        n = "n";

        std::cout << "would you like a receipt? y/n" << std::endl;

        while (q == 0)
        {
            std::string answer;
            std::cin >> answer;

            if (answer.compare("y") == 0)
            {
                q = 1;
                if (finalprice < budget)
                {
                    create_receit();
                    std::cout << "Remaining balance: " << "$" << budget - finalprice << std::endl;
                }
                else if (finalprice > budget)
                {
                    std::cout<< "Sorry! You don't have enough money." << std::endl;
                }
            }
            else if (answer.compare("n") == 0)
            {
                q = 1;
                if (finalprice < budget)
                {
                    std::cout <<"Thanks for your business !" << std::endl;
                    std::cout << "Remaining balance: " << "$" << budget - finalprice << std::endl;
                }
                else if (finalprice > budget)
                {
                    std::cout<< "Sorry! You don't have enough money anyways." << std::endl;
                }
            }
            else
            {
                std::cout <<"Please enter a valid answer." << std::endl;
            }
        }
    }
    else if (finalprice > budget)
    {
        std::cout << "You don't have enough money anyways." << std::endl;
    }
}

void buyer::create_receit()// this method creates a new text file that prints out a receipt that tells the user that all sales are final and the amount they paid.
{
    std::ofstream receit;
    receit.open("/home/user/Desktop/newreceit.txt");
    for (int i = 0; i < 10; i++)
    {
        receipt[10] = '*';
        receit << receipt[10] << "\n";
        receit << "All sales are final." << "\n";
        receit << "$" << finalcost << "\n";

    }

    receit.close();
}
buyer::~buyer()
{
    //dtor
}
