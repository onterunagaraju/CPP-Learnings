// DIP

#include<iostream>

using namespace std;

class IBankCard {
public:
    virtual void DoTranction(int amount) = 0;
};

class DebitCard : public IBankCard {
public:
    void DoTranction(int amount) {
        cout << "Transactionion through Debitcard" << endl;
    }
};

class CreditCard : public IBankCard {
public:
    void DoTranction(int amount) {
        cout << "Transaction through CreditCard" << endl;
    }
};

class CardForTransaction {
    // If it is tightly coupled if we want to do transaction with credit card or debit card then we  need to 
        // write lot of code and we not able to change obj dynamically

        // transaction through debit card;
public:
    /*DebitCard* debitcard;
    CardForTransaction(DebitCard* _debitcard){
        debitcard = _debitcard;
    }
    void doPurchaseWithCard(int amount){
        debitcard->DoTranction(amount);
    }*/


    // if suppose debitcard not accepted,if we want to transaction with credit card then you need to change lot of code;
    /*CreditCard* creditcard;
    CardForTransaction(CreditCard* _creditcard){
        creditcard = _creditcard;
    }
    void doPurchaseWithCard(int amount){
        creditcard->DoTranction(amount);
    }*/


    IBankCard* card;
    CardForTransaction(IBankCard* _card) {
        card = _card;
    }
    void doPurchaseWithCard(int amount) {
        card->DoTranction(amount);
    }


};

int main() {
    CardForTransaction* card = new CardForTransaction(new DebitCard());
    card->doPurchaseWithCard(1000);

    /*CardForTransaction* card = new CardForTransaction(new CreditCard());
    card->doPurchaseWithCard(1000);*/
    return 0;
}