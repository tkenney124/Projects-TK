#include <iostream>
#include <cstdlib>
#include <ctime>




using namespace std;
int MONTHS;




int STARVE=5;
const int PSHARK=29;
const int PFISH=31;
const int RFISH=75;
const int RSHARK=15;
int fishcount=0;
int sharkcount=0;
const int xsize=20,ysize=20;
int ocean[xsize][ysize];
int nextocean[xsize][ysize];












void generateOcean()
{




   for(int x=0;x<xsize;x++)
   {








       for(int y=0; y<ysize;y++)
       { int r;
           r=rand()%100;
           //  cin>>matrix[i][j]; to get range a-b _ rand()%(b-a) + a
           if(r <  PFISH + PSHARK && r > PSHARK)
           {
               ocean[x][y]=-1;




           }
           else if(r < PSHARK)
               {
               ocean[x][y]=STARVE;




               }
           else
           {
               ocean[x][y]=0;
           }




       }
   }
   return;
}




void printOcean()
{




   fishcount=0;
   sharkcount=0;
   for(int y=0;y<ysize;y++)
   {
       for(int x=0; x<xsize;x++)
       {
           if(ocean[x][y] > 0)
           {
               cout << "S ";
               sharkcount++;








           }
           if(ocean[x][y] ==-1)
           { cout << "f ";
              fishcount++;




           }
           if(ocean[x][y] ==0)
           {
               cout << ". ";
           }
       }
       cout << endl;
   }
   cout << "month " << MONTHS << endl;
   cout << sharkcount << " sharks and " << fishcount << " fishes." << endl;
   return;
}




void CopyOceanToNextOcean()
{
   for(int x=0;x<xsize;x++)
   {
    for(int y=0; y<ysize;y++)
       {
           //  cin>>matrix[i][j]; to get range a-b _ rand()%(b-a) + a
           if(ocean[x][y]==-1)
               nextocean[x][y]=-1;
           else if(ocean[x][y]>0)
               nextocean[x][y]=ocean[x][y];
           else
               nextocean[x][y]=0;
       }
   }
}
void doMovements()
{
   for(int x=0;x<xsize;x++)
   {
    for(int y=0; y<ysize;y++)
       {
           if(ocean[x][y]==-1)
           {
               int dir =rand()%4;
               int repro = rand()%100;
               if(dir==0)
               {
                   if(y !=0 && nextocean[x][y-1]==0) //can it move up
                   {
                       nextocean[x][y-1]=nextocean[x][y];
                       nextocean[x][y]=0;
                       if(repro < RFISH)
                       {
                           nextocean[x][y]=-1;
                           fishcount++;
                       }
                   }

               }
               if(dir==1) // move down
               {
                   if(y != ysize-1 && nextocean[x][y+1]==0)
                   {
                       nextocean[x][y+1]=nextocean[x][y];
                       nextocean[x][y]=0;
                       if(repro < RFISH)
                       {
                           nextocean[x][y]=-1;
                           fishcount++;
                       }
                   }

               }
               if(dir==2) // move left
               {
                   if(x !=0 && nextocean[x-1][y]==0)
                   {
                       nextocean[x-1][y]=nextocean[x][y];
                       nextocean[x][y]=0;
                       if(repro < RFISH)
                       {
                           nextocean[x][y]=-1;
                           fishcount++;
                       }
                   }

               }
               if(dir==3) //move right
               {
                   if(x != xsize-1 && nextocean[x+1][y]==0)
                   {
                       nextocean[x+1][y]=nextocean[x][y];
                       nextocean[x][y]=0;
                       if(repro < RFISH)
                       {
                           nextocean[x][y]=-1;
                           fishcount++;
                       }
                   }

               }
           }
         else if(ocean[x][y]>0)
                   {
                       int dir =rand()%4;
                       int repro = rand()%100;
                       if(dir==0)
                       {
                           if(y !=0 && nextocean[x][y-1]<=0) //can it move up
                           {
                               nextocean[x][y]--;
                               if(nextocean[x][y]==0)
                               {
                                   sharkcount--;
                                   continue;

                               }




                               if(nextocean[x][y-1]==-1)
                               {
                                   nextocean[x][y]=STARVE;
                                   fishcount--;
                                   ocean[x][y-1]=0;
                               }

                               nextocean[x][y-1]=nextocean[x][y];
                               nextocean[x][y]=0;
                               if(repro < RSHARK)
                               {
                                   nextocean[x][y]=nextocean[x][y-1];
                                   sharkcount++;
                               }
                           }

                       }
                       if(dir==1) // move down
                       {




                           if(y != ysize-1 && nextocean[x][y+1]<=0 && ocean[x][y+1]<=0)
                           {
                               nextocean[x][y]--;
                               if(nextocean[x][y]==0)
                               {
                                   sharkcount--;
                                   continue;

                               }




                               if(nextocean[x][y+1]==-1)
                               {
                                   nextocean[x][y]=STARVE;
                                   fishcount--;
                                   ocean[x][y+1]=0;
                               }


                               nextocean[x][y+1]=nextocean[x][y];
                               nextocean[x][y]=0;
                               if(repro < RSHARK)
                               {
                                   nextocean[x][y]=nextocean[x][y+1];
                                   sharkcount++;
                               }
                           }

                       }
                       if(dir==2) // move left
                       {
                           if(x !=0 && nextocean[x-1][y]<=0 && ocean[x-1][y]<=0)
                           {
                               nextocean[x][y]--;
                               if(nextocean[x][y]==0)
                               {
                                   sharkcount--;
                                   continue;
                               }




                               if(nextocean[x-1][y]==-1)
                               {
                                   nextocean[x][y]=STARVE;
                                   fishcount--;
                                   ocean[x-1][y]=0;
                               }

                               nextocean[x-1][y]=nextocean[x][y];
                               nextocean[x][y]=0;
                               if(repro < RSHARK)
                               {
                                   nextocean[x][y]=nextocean[x-1][y];
                                   sharkcount++;
                               }
                           }

                       }
                       if(dir==3) //move right
                       {
                           if(x != xsize-1 && nextocean[x+1][y]<=0 && ocean[x][y+1]<=0)
                           {
                               nextocean[x][y]--;
                               if(nextocean[x][y]==0)
                               {
                                   sharkcount--;
                                   continue;
                               }




                               if(nextocean[x+1][y]==-1)
                               {
                                   nextocean[x][y]=STARVE;
                                   ocean[x+1][y]=0;
                                   fishcount--;
                               }





                               nextocean[x+1][y]=nextocean[x][y];
                               nextocean[x][y]=0;
                               if(repro < RSHARK)
                               {
                                   nextocean[x][y]=nextocean[x+1][y];
                                   sharkcount++;
                               }
                           }

                       }





                   }








               }
           }
       }








void copyNextOceanBackToOcean()
{
   for(int x=0;x<xsize;x++)
   {








       for(int y=0; y<ysize;y++)
       {
           //  cin>>matrix[i][j]; to get range a-b _ rand()%(b-a) + a
           if(nextocean[x][y]==-1)
               ocean[x][y]=-1;
           else if(nextocean[x][y]>0)
               ocean[x][y]=nextocean[x][y];
           else
               ocean[x][y]=0;
       }
   }
}





int main()
{
   srand(time(NULL));
   cout << "how many monthes? ";




   generateOcean();
   printOcean();
   cout << "month 0" << endl;
   for(MONTHS=1;MONTHS<1000;MONTHS++)
   {
       CopyOceanToNextOcean();
       doMovements();
       copyNextOceanBackToOcean();
       printOcean();








   }




}
