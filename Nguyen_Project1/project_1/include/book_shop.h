#ifndef BOOK_SHOP_H
#define BOOK_SHOP_H


class book_shop
{
public: // data members
    char bookname[50];
    char author[30];
    long isbn;
    double price;

    void newbook();
    void currentbook();
    int workers();
    int calc_revenue();
public:// constructor
    book_shop();
    virtual ~book_shop();
    protected:
    private:
};

#endif // BOOK_SHOP_H
