#include <iostream>
#include "customer.h"

Customer::Customer(int count, int a, int b)
{
    id=count;
    arrivaltime=a;
    servicetime=b;
    linetime=0;


}
int Customer::ReturnID()
{
    return id;
}
int Customer::Service()
{

    return servicetime;
}
int Customer::ReturnLinetime()
{
    return linetime;
}
void Customer::incrementLine()
{
    linetime=linetime+1;
}
void Customer::incrementService()
{
    servicetime=servicetime-1;
}
int Customer::Arrival(){
    return arrivaltime;
}
