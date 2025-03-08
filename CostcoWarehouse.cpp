//
//  CostcoWarehouse.cpp
//  Project 5
//
//  Created by Thomas Lien on 2/23/25.
//
#include "CostcoMember.h"
#include "CostcoWarehouse.h"

CostcoWarehouse::CostcoWarehouse(string location, int number){
    mLocation = location;
    mNumber = number;
}


string CostcoWarehouse::getLocation()
{
    return mLocation;
}

int CostcoWarehouse::getNumber()
{
    return mNumber;
}

void CostcoWarehouse::shopForStuff(CostcoMember & member, double amount)
{
    member.incrementTripCount();
    member.incrementPurchaseTotal(amount);
}
void CostcoWarehouse::returnStuff(CostcoMember & member, double amount) // does not count as an additional trip
{
    member.decrementPurchaseTotal(amount);
}

double CostcoWarehouse::calculateReward(CostcoMember member)
{
    double rewardStart = 0;
    if (member.getKind() == CostcoMember::Kind::EXECUTIVE)
    {
        rewardStart = member.getPurchaseTotal() * 0.02;
    }
    
    return rewardStart;
}
double CostcoWarehouse::issueReward(CostcoMember & member)
{
    double reward = calculateReward(member);
    if (reward > 0)
    {
        member.clearPurchaseTotal();
    }
    return reward;
}


