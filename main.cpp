//
//  main.cpp 
//  Project 5 
//
//  Created by Thomas Lien on 2/20/25.
//Simulates information and thoroughly tests if the implementations/declarations for CostcoMember and CostcoWarehouse are functional

#include "CostcoMember.h"
#include "CostcoWarehouse.h"
#include <cassert>
int main() {
    // sample test code working with CostcoMember and CostcoWarehouse
    CostcoMember po("Po", "65873", CostcoMember::Kind::EXECUTIVE);
    CostcoWarehouse warehouse4("Irvine", 400);
    warehouse4.shopForStuff(po, 120);
    warehouse4.returnStuff(po, 120);
    assert( std::to_string( warehouse4.calculateReward( po ) ) == "0.000000" ); //tests if exec member reward is 0
    assert( std::to_string( warehouse4.issueReward( po ) ) == "0.000000" );
    assert( std::to_string( po.getPurchaseTotal( ) ) == "0.000000" ); // test purchase total is already 0
    
    CostcoMember pat("Pat", "0987", CostcoMember::Kind::BUSINESS);
    assert( std::to_string( pat.getPurchaseTotal() ) == "0.000000" );
    CostcoWarehouse warehouse2("San Diego", 500);
    warehouse2.shopForStuff(pat, 120);
    warehouse2.returnStuff(pat, 100);
    assert( std::to_string( pat.getPurchaseTotal( ) ) == "20.000000" ); // test negative purchase total
    assert( std::to_string( warehouse2.calculateReward( pat ) ) == "0.000000" ); //tests if business members reward is 0
    assert( std::to_string( warehouse2.issueReward( pat ) ) == "0.000000" );
    assert( std::to_string( pat.getPurchaseTotal( ) ) == "20.000000" ); // test purchase total after reward calculation for business
    assert(pat.getTripCount() == 1);
    
    CostcoMember kevin("Kevin", "56789", CostcoMember::Kind::GOLDSTAR);
    assert(kevin.getNumber() == "56789");
    assert(kevin.getKind() == CostcoMember::Kind::GOLDSTAR);
    assert(kevin.getTripCount() == 0);
    
    CostcoWarehouse warehouse1("Seaside", 250);
    assert(warehouse1.getLocation() == "Seaside");
    assert(warehouse1.getNumber() == 250);
    assert( std::to_string( warehouse1.calculateReward( kevin ) ) == "0.000000" );
    warehouse1.shopForStuff( kevin, 0 );
    assert( std::to_string( kevin.getPurchaseTotal( ) ) == "0.000000" );
    assert( kevin.getTripCount(  ) == 1 );
    warehouse1.shopForStuff( kevin, 10 );
    assert( std::to_string( kevin.getPurchaseTotal( ) ) == "10.000000" );
    assert( std::to_string( warehouse1.calculateReward( kevin ) ) == "0.000000" ); // test if GOLDSTAR REWARD is 0 no matter what purchase price is
    assert( std::to_string( warehouse1.issueReward( kevin ) ) == "0.000000" );
    assert( std::to_string( kevin.getPurchaseTotal( ) ) == "10.000000" ); // tests if purchase total gets reset if reward = 0
    assert( kevin.getTripCount(  ) == 2 ); // test trip count
    
    
    
    //given test code
    CostcoMember howard( "Howard", "123456", CostcoMember::Kind::EXECUTIVE );
                 CostcoWarehouse warehouse( "Culver City", 210 );

                 assert( howard.getName() == "Howard" );
                 assert( howard.getNumber() == "123456" );
                 assert( howard.getKind() == CostcoMember::Kind::EXECUTIVE );
                 assert( howard.getTripCount() == 0 );
                 
                 // since doubles are inexact, you need to stringify them to assert their value
                 // by doing so, you will always get six digits after the decimal point,
                 // leaving off the rounding error that might be present
                 assert( std::to_string( howard.getPurchaseTotal() ) == "0.000000" );

                 assert( warehouse.getLocation() == "Culver City" );
                 assert( warehouse.getNumber() == 210 );

                 assert( std::to_string( warehouse.calculateReward( howard ) ) == "0.000000" );
                 warehouse.shopForStuff( howard, 100 );
                 assert( std::to_string( howard.getPurchaseTotal( ) ) == "100.000000" );
                 assert( howard.getTripCount(  ) == 1 );
                 warehouse.shopForStuff( howard, 1000 );
                 warehouse.returnStuff( howard, 100 );
                 assert( std::to_string( howard.getPurchaseTotal( ) ) == "1000.000000" );
                 assert( howard.getTripCount(  ) == 2 );
                 assert( std::to_string( warehouse.calculateReward( howard ) ) == "20.000000" ); // tests calculation of reward
                 assert( std::to_string( warehouse.issueReward( howard ) ) == "20.000000" );
                 assert( std::to_string( howard.getPurchaseTotal( ) ) == "0.000000" ); // tests if the purchase total is reset
                 assert( howard.getTripCount(  ) == 2 );
    cout << "All Test Passed!" << endl;
    return 0;
}
//ideas to test
// empty strings? ;
