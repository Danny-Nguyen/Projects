#include <iostream>
#include <book_shop.h>
#include <buyer.h>

using namespace std;
book_shop mybook;

buyer mycustomer(500, "Danny");


int main()
{
    int w = 0;
    string ad, se;
    ad = "add";
    se = "browse";
    cout << "Welcome to the Book Store! Would you like to (sell) a book or" << endl;
    cout << "(browse) our current collection?" << endl;
    cout << "  " << endl;
    mybook.workers();

    while (w == 0)
    {
        string answer;
        cin >> answer;
        if (answer.compare("sell") == 0)
        {
            w = 1;
            mybook.newbook();
            mybook.calc_revenue();
        }
        else if (answer.compare("browse") == 0)
        {
            w = 1;
            mybook.currentbook();
            cout << "Would you like to buy these books?" << endl;
            mycustomer.bookprices();
            int x = 0;
            string y, n;
            y = "y";
            n = "n";
            cout << "y/n" << endl;

            while (x == 0)
            {
                string answer;
                cin >> answer;

                if(answer.compare("y") == 0)
                {
                    x = 1;
                    mycustomer.calc_dis();
                    mycustomer.calc_tax();
                }
                else if (answer.compare("n") == 0)
                {
                    x = 1;
                    cout << "Have a nice day!" << endl;
                }
                else
                {
                    cout << "Please enter a valid answer." << endl;
                }
            }

        }
        else
        {
            cout << "Please enter a valid answer." << endl;
        }
    }
    return 0;
}
