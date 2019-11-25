//
//  SelectorDispatcher.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//
#ifndef _SelectorDispatcher
#define _SelectorDispatcher

#include "../service/PlanetService.cpp"
#include "../service/SpaceshipService.cpp"
#include "../service/TradingStationService.cpp"
#include "../service/EmptyService.cpp"
#include "../service/ArmoryService.cpp"
/**
 
 The dispather for the spaceship to encounter selector
 
 */
class SelectorDispatcher{

    
    private :
    
    // for the logic when encounter plant
    PlantService plantService;
    
    // for the logic when encounter other spaceship
    SpaceshipService spaceshipService;
    
    // for the logic when encounter TradingStation
    TradingStationService tradingStationService;
    
    // for the logic when encounter the empty selector
    EmptyService emptyService;
    
    // for the logic when encounter the armory station
    ArmoryService armoryService;
    
    // DAO
    SpaceShipDAO spaceShipDAO;
    
    public :
    
    
    // ------------------------- main dispatcher --------------------------------
    
    // our goal is Star and Sea !!!!!!!!!
    void startTravel(SpaceShip &mySpaceShip){
        // check the spaceship's fuel and food
         if(gameFail(mySpaceShip)) {GameManager::gameFail("you lose, game over!");}
        
        GameLogger::stdOut("--------------------------------------------------------------");
        
        // randomly choose next selector
        int randomSeed = (GameTimer::_rand() % 100) + 1;

        if(randomSeed <= 35){
            // Spaceship encounter.
            spaceshipService.start(mySpaceShip);
            
        }else if(randomSeed > 35 && randomSeed <= 60){
            // Planet encounter.
            plantService.start(mySpaceShip);
            
        }else if(randomSeed > 60 && randomSeed <= 75){
            // Trading station.
            tradingStationService.start(mySpaceShip);
            
        }else if(randomSeed > 75 && randomSeed <= 90){
            // Empty sector. This is pretty boring.
            emptyService.start(mySpaceShip);
            
        }else{
            // Some other space thing. This is up to you.
            armoryService.start(mySpaceShip);
        }
        
        spaceShipDAO.consumeResource();
        spaceShipDAO.getReport();
    }
    // ------------------------- main dispatcher --------------------------------

    
    
    
    
    
    // ------------------------- helper function --------------------------------
    bool gameFail(SpaceShip mySpaceShip){
        
        // resource
        // return condition1 || condition2 || ....
        return lackResource(mySpaceShip) || lackHp(mySpaceShip);
    }
    
    
    
    // judge if lack of resource
    bool lackResource(SpaceShip mySpaceShip){
        
        if(mySpaceShip.getResource().getLeftFood() <= 0) return true;
        if(mySpaceShip.getResource().getLeftFuel() <= 0) return true;
        
        return false;
        
    }
    
    bool lackHp(SpaceShip mySpaceShip){
        return mySpaceShip.getSpaceshipHP() <= 0;
    }

    
    
    
    
};



#endif
