//
//  CostcoMember.h
//  Project 5
//
//  Created by Thomas Lien on 2/20/25.
//

#ifndef CostcoMember_h
#define CostcoMember_h

#include <iostream>
#include <string>
using namespace std;

class CostcoMember
{
    
    public:
    
    enum class Kind {BUSINESS, EXECUTIVE, GOLDSTAR};
    CostcoMember(string name, string number, Kind kind);
    string getName();
    string getNumber();
    Kind getKind();
    int getTripCount() const;
    void incrementTripCount();
    void clearTripCount();
    double getPurchaseTotal();
    void incrementPurchaseTotal(double amount);
    void decrementPurchaseTotal(double amount);
    void clearPurchaseTotal();
    double issueReward();
    
    
     // purchase total variable
    
    
    private:
    
    string mName;
    string mNumber;
    Kind mKind;
    int mTripCount;
    double mPurchaseTotal;
     // DO I SET THIS TO 0?
        
    
    
};

#endif /* CostcoMember_h */


