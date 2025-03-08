//
//  CostcoWarehouse.cpp
//  Project 5
//
//  Created by Thomas Lien on 2/23/25.
//
#include "CostcoMember.h"
#include "CostcoWarehouse.h"

CostcoWarehouse::CostcoWarehouse(string location, int number){ //constructor
    mLocation = location;
    mNumber = number;
}

//return information about warehouse
string CostcoWarehouse::getLocation()
{
    return mLocation;
}

int CostcoWarehouse::getNumber()
{
    return mNumber;
}

//methods for updating customer-specific information/data
void CostcoWarehouse::shopForStuff(CostcoMember & member, double amount) //simulates Costco Customer making a purchase
{
    member.incrementTripCount();
    member.incrementPurchaseTotal(amount);
}
void CostcoWarehouse::returnStuff(CostcoMember & member, double amount) // Note: does not count as an additional trip ---- simulates Costco Customer returning their purchases
{
    member.decrementPurchaseTotal(amount);
}

double CostcoWarehouse::calculateReward(CostcoMember member) //calculates reward awarded to member; ONLY AVAILABLE FOR EXECUTIVES, not business or goldstar 
{
    double rewardStart = 0;
    if (member.getKind() == CostcoMember::Kind::EXECUTIVE)
    {
        rewardStart = member.getPurchaseTotal() * 0.02;
    }
    
    return rewardStart;
}
double CostcoWarehouse::issueReward(CostcoMember & member) //implements reward & reset purchase total if customer is given a positive reward
{
    double reward = calculateReward(member);
    if (reward > 0)
    {
        member.clearPurchaseTotal();
    }
    return reward;
}


