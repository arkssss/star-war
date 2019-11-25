//
//  BootStrap.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/21.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _Bootstrap
#define _Bootstrap

/*
    this class do all the init work
 */
#include "../dispatcher/SelectorDispatcher.cpp"
class Bootstrap{
    
    
public:
    
    static void start(int RoundTimes);
    
};

/* get starts */
void Bootstrap::start(int RoundTimes){
    
    
    // randomly choose the type of spaceship
    // we are from EARTH !!!
    // Go conquer this universe !!!
    int ourSpaceshipCiv = SpaceshipType::EARTH_SPACESHIP;
    int ourSpaceshipType = SpaceshipType::getRandomSpaceshipType();

    
    // build my spaceship
    SpaceshipFactory spaceshipFactory;
    SpaceShip mySpaceship = spaceshipFactory.buileSpaceship(ourSpaceshipType, ourSpaceshipCiv);

    
    // def my spaceshipDAO
    SpaceShipDAO::setSpaceShip(&mySpaceship);
    
    
    // def my dispatcher
    SelectorDispatcher selectorDispatcher;

    
    
    // load N
    // int RoundTimes = 100;
    /* main loop */
    for(int i=0; i<RoundTimes; i++){
        
        /* record game round */
        RuntimeParameter::GAME_CURRENT_ROUND = i;
        
        /* go !*/
        selectorDispatcher.startTravel(mySpaceship);
    }
    
    
}




#endif
