#include "customer.h"
#include <iostream>
#include <queue>
#include <ctime>

#include <deque>

#define NUM_LANES 7 // easy to change how many lines there are

//int id=0;


//std::queue<Customer*> line1;
//std::queue<Customer*> line2;
//std::queue<Customer*> line3;





int main(int argc, char *argv[])
{
    int arrivaltime1=2;
    int servicetime1=6;
    srand(time(0));
    std::deque<Customer*> line1c[NUM_LANES];
    unsigned int ogsize=line1c[0].size(); // this line of code is used to help place the customers in the shortest line



    int clocktime=0; // counts the amount of times the loop goes through
    int index=0; //used to figure out which line was actually used when the smallest size was determined

    int a=rand()%arrivaltime1+1;
    int b=rand()%servicetime1+1;
    int MaxWait=0; // you know what it is
    int MaxSize=0;







    int count=0; // determines the customer id
    int timebetweencustomers=0; // prevents a customer from being made everytime the loop goes through
    Customer* temp;
    while(clocktime<=720)
    {
        timebetweencustomers=timebetweencustomers+1;

        clocktime=clocktime+1;

     /*  for(int i=0;i<NUM_LANES;i++)
       {
          std::cout<< line1c[i].size()<<std::endl;
       }*/


    for(int i=0;i<NUM_LANES;i++){
        if(line1c[i].size()>0)
        {
            Customer* Front=line1c[i].front();

           Front->incrementService(); // should be decrement but this subtracts from each lines front most person service time each time
           if(Front->Service()==0) // when they are at the front of the line and the service time is zero, pop them from the line
           {
               line1c[i].pop_front();

               std::cout<<"line "<< i << " just got popped"<<std::endl;
               std::cout <<"customer: "<<  Front->ReturnID() << " has waited in line" << i << " for  "<<clocktime - Front->Arrival()<< " minutes" <<std::endl;
               if(clocktime-Front->Arrival()>MaxWait)
                   MaxWait=clocktime-Front->Arrival();
           }

        }





        if(line1c[i].size()>1)
        {

            for(unsigned int j=1;j<line1c[i].size();j++)
            {

                Customer* d=line1c[i].at(j); // goes to the reference point of everyone after the first person in line and adds to their linetime
                d->incrementLine(); // as of my most recent code this appears to not do anything useful as i dont record linetime in this manner anymore
            }
        }
    }




        if(a==timebetweencustomers) // if the random number generated equals the diffferences in time of arrival of each customer

        {

            count=count+1; // iterates the customer
            temp=new Customer(count,clocktime,b); // creates the customer
            a=rand()%arrivaltime1+1; // arrival time
            b=servicetime1; // service time
            timebetweencustomers=0; // resets the variable





     for(int i=0;i<NUM_LANES;i++)
     {
         
         if(line1c[i].size()<ogsize) // does the comparison of each line to find the shortest line
         {
             ogsize=line1c[i].size(); // sets the new smallest size as the variable to compare
              index=i; // sets the index to the shortest line so it knows where to put the customer
         }
         if(line1c[i].size()>MaxSize) // finds the max size
         {
             MaxSize=line1c[i].size();
         }

     }
     line1c[index].push_back(temp);
     std::cout<< "line "<<index<<" customer: "<<temp->ReturnID()<<" has arrived" <<std::endl;
     std::cout<< "clocktime is: "<<clocktime<<std::endl;
     ogsize=line1c[index].size(); // sets the size to the new size of the line that just had a customer added to it







}





}
    std::cout<<"Max wait time was: "<<MaxWait<<" minutes!"<<std::endl;
    std::cout<<"Max size was: "<<MaxSize<<" customers!"<<std::endl;

    return 0;

}
// 1. with a service and arrival time of between 1-4 minutes the max across all lines was around 300 for a 720 minute day
// 2.the maximum wait was 4 minutes and the longest line was 1 customer in length
// 3.2-5 min arrival time, the findings were exactly the same
// 4.1 is the minimum amount of lanes to keep under 5 minutes with a 1-4 min arrival and serivce time and 2 lanes is the minimum
// for under ten minutes
