//
//  CostcoWarehouse.h
//  Project 5
//
//  Created by Thomas Lien on 2/23/25.
//

#ifndef CostcoWarehouse_h
#define CostcoWarehouse_h
#include "CostcoMember.h"

class CostcoWarehouse
{
    
    public:
    CostcoWarehouse(string location, int number);
    string getLocation();
    int getNumber();
    void shopForStuff(CostcoMember &member, double amount);
    void returnStuff(CostcoMember &member, double amount);
    double calculateReward(CostcoMember member);
    double issueReward(CostcoMember &member);
    
    private:
    string mLocation;
    int mNumber;
    
};

#endif /* CostcoWarehouse_h */
