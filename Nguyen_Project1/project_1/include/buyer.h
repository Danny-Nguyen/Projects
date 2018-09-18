#ifndef BUYER_H
#define BUYER_H


class buyer
{
public:// my data members for the buyer class.
    int budget;
    int discount;
    int tax;
    std::string name;
    double total;
    char receipt[10];
    double finalcost;

    float calc_dis();
    float calc_tax();
    int bookprices();
    void create_receit();

public:// constructors for the class.
    buyer();
    buyer(int, std::string);
    virtual ~buyer();
protected:
private:
};

#endif // BUYER_H
