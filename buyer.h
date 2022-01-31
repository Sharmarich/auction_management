#include<iostream>
#include "user.h"
#include "seller.h"
using namespace std;


class Buyer: public User{
    public:
        string cart; 
        Buyer(string n): User(n){

        }
        void bid(Seller &seller, float bidAmount){
            if (seller.get_sell_status()) {
                cout<<"can not bid, item already sold\n";
            } else {
                if(bidAmount > seller.get_bid_amount()){
                    seller.set_bid_info(bidAmount,name);
                }
            }
        }
};
