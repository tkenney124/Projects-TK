#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <queue>
#include <ctime>


class Customer
{
public:
    Customer(int i, int a, int b);
    int ReturnID();
    int Service();
    int ReturnLinetime();
    void incrementLine();
    void incrementService();
    int Arrival();
private:
    int arrivaltime;
    int servicetime;
    int id;
    int linetime;


};


#endif // CUSTOMER_H
