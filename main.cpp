#include<iostream>
#include "user.h"
using namespace std;

int main(){
    //User user1();
    Seller user2("karan","laptop",50000);
    Buyer user3("pappu");
    Buyer user4("Champu");


    user3.bid(user2,51000);
    user2.sell();    // karan sold phone to pappu for 15000 for x% profit
    user4.bid(user2,55000); // if sold then can not bid
    user2.sell();





    return 0;
}