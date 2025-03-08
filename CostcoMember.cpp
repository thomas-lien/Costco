//
//  CostcoMember.cpp
//  Project 5
//
//  Created by Thomas Lien on 2/21/25.
//

#include "CostcoMember.h"
using namespace std;
CostcoMember::CostcoMember (string name, string number, Kind kind) {
    mName = name;
    mNumber = number;
    mKind = kind;
    mTripCount = 0;
    mPurchaseTotal = 0;
   // mTripCount = TripCount;
}

//returns information regarding CostcoMember
string CostcoMember::getName() 
{
    return mName;
}
string CostcoMember::getNumber()
{
    return mNumber;
}

CostcoMember::Kind CostcoMember::getKind()
{
    return mKind;
}

int CostcoMember::getTripCount() const
{
    return mTripCount; // possisble edge case: what to do if trip count is set to a negative number
}

//methods that update information stored about the Costco member
void CostcoMember::incrementTripCount()
{
    mTripCount += 1; // increment by 1 -- need to check if this is a variable amount
}

void CostcoMember::clearTripCount()
{
    mTripCount = 0; // set equal to zero
}

double CostcoMember::getPurchaseTotal() // getter 
{
    return mPurchaseTotal;
}

//edge case to be aware of: what if the numbers are negative? ***


void CostcoMember::incrementPurchaseTotal(double amount)
{
    mPurchaseTotal += amount;
}
void CostcoMember::decrementPurchaseTotal(double amount)
{
    mPurchaseTotal -= amount;
}
void CostcoMember::clearPurchaseTotal()
{
    mPurchaseTotal = 0; // clear by setting purchase total to zero
}

