#include "dealer.h"

#define NUM_PLAYERS 8

int main()
{
    srand(time(NULL));

    Player* player[NUM_PLAYERS];
    Dealer* dealer = new Dealer();
    int number=0;
    int test=0;
    std::string playerChoice;
    std::cout<<"How many players? ";
    std::getline(std::cin, playerChoice);
    number = stoi(playerChoice);
    for(int i=1;i<=number;i++)
    {
        player[i] = new Player();
        player[i]->AddCard(dealer->DealCard());
        player[i]->AddCard(dealer->DealCard());
        std::cout<<"player :"<< i<<std::endl;
        player[i]->PrintHand();
    }

    for(int i=1;i<=number;i++){
        if(player[i]->inGame(false))
        {
            continue;
        }

        std::cout<<"Player: "<<i<<" Hit or Stand? ";
        std::getline(std::cin, playerChoice);

       // std::cout<<"Found: "<<playerChoice<<std::endl;

        do{
            if(playerChoice=="Hit")
            {
                player[i]->AddCard(dealer->DealCard());
                player[i]->PrintHand();
            }


            if(player[i]->GetScore() > 21){
                if(player[i]->CheckForAce()==true)
                {
                    continue;
                }
                std::cout<<"Bust! Player"<< i <<" loses!"<<std::endl;
                player[i]->inGame(false);
                test=test+1;
                break;

            }
            else if(player[i]->GetScore()==21)
            {
                std::cout<<"First try! Player: "<< i << " YoU WIN!"<<std::endl;
                return 0;
            }
            std::cout<<playerChoice<<std::endl;
            std::cout<<"Player: "<<i<<" Hit or Stand? ";
            std::getline(std::cin, playerChoice);
        }
        while(playerChoice == "Hit");

        if(playerChoice=="Stand")
        {
            std::cout<<"Player: "<<i+1<<std::endl;
            player[i+1]->PrintHand();
            test=test+1;
            player[i]->inGame(false);
            continue;

        }

        if(test==number)
        {
            dealer->TakeTurn(player[i]->GetScore());
            for(int i=1;i<=number;i++)
            {
                std::cout<<std::endl<<"Player: "<<i<<" Score: "<<player[i]->GetScore()<<std::endl;
                std::cout<<"Dealer's Score: "<<dealer->GetScore()<<std::endl<<std::endl;
                if(dealer->GetScore() > 21 && player[i]->GetScore()>21){
                    std::cout<<"Dealer and Player: "<< i << " lose"<<std::endl;

                }

                else if(dealer->GetScore() > 21 || (player[i]->GetScore() > dealer->GetScore() && player[i]->GetScore()<=21)){
                    std::cout<<"Player: "<<i<<" wins"<<std::endl;
                }else if(player[i]->GetScore()>21){
                    std::cout<<"Player: "<<i<<" loses"<<std::endl;

                }
                else if(dealer->GetScore()==21)
                {
                    std::cout<<"Dealer Wins"<<std::endl;
                }
            }
        }
    }
    return 0;
}
