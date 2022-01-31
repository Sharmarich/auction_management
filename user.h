#include<iostream>
using namespace std;

class User{
    public:
        string name;
        User(string n){
            name = n;
      
        }
};

class Seller: public User{
   
    private:
        string productName;
        float basePrice;
        float currentBid;
        string currentBidder;
        bool isSold = false;
        float profit = 0;
       
    public:
        // constructer
        Seller(string uName,string pName,float bPrice): User(uName){
            productName = pName;
            basePrice = bPrice;
            currentBid = basePrice;

        }
    
        float profit_percent(){
            return (currentBid - basePrice)/currentBid*100;
            
        }

        float get_bid_amount() {
            return currentBid;
        }

        bool set_bid_info(float bidToSet, string bidderName) {
            currentBid = bidToSet;
            currentBidder = bidderName;
            return true;
        }

        void sell(){
            if (isSold) {
                cout<<"already sold, can not sell it again\n";
            } else {
                cout<<name<<" sold "<<productName<<" to "<<currentBidder<<" for rupees "<<currentBid<<" for "<<profit_percent()<<" % profit\n";
                isSold = true;
            }
        }

        bool get_sell_status(){
            return isSold;


        }   

        
}; 

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
