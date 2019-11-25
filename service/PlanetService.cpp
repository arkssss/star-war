//
//  PlanetService.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _PlantService
#define _PlantService

#include "Service.cpp"


/*
    the servie for spaceship encounter the plant
    * Trade, Conflict, Mining, Diplomacy
 
 */
class PlantService : public Service{
    
    private :
    
    /* Diplomacy */
    DiplomacyActivity diplomacyActivity;
    
    /* Trading */
    TradingActivity tradingActivity;
    
    /* Mining */
    MiningActivity miningActivity;
    
    /* conflict */
    ConflictActivity conflictActivity;
    
    /* System Recovery */
    SystemsRecoveryActivity systemsRecoveryActivity;
    
    /* Travel eff*/
    TravelEfficiencyActivity travelEfficiencyActivity;
    
    
    public :
    
    void start(SpaceShip &spaceShip){
        
        GameLogger::stdOut("You are now leading in a plant in round : " + std::to_string(RuntimeParameter::GAME_CURRENT_ROUND + 1));
        
        switch (GameTimer::_rand() % 6) {
            case 0:
                /* DiplomacyActivity */
                GameLogger::stdOut("You are doing Diplomacy in this plant");
                diplomacyActivity.start(spaceShip);
                break;
            case 1:
                /* tradingActivity */
                GameLogger::stdOut("You are doing trading in this plant");
                tradingActivity.start(spaceShip);
                break;
            case 2:
                GameLogger::stdOut("You are doing mining in this plant");
                miningActivity.start(spaceShip);
                break;
            case 3:
                GameLogger::stdOut("You are encountering conflict in this plant");
                conflictActivity.start(spaceShip);
                break;
            case 4:
                GameLogger::stdOut("You are doing System recovery in this plant");
                systemsRecoveryActivity.start(spaceShip);
                break;
            case 5:
                GameLogger::stdOut("You are doing Travel efficiency in this plant");
                travelEfficiencyActivity.start(spaceShip);
                break;
            default:
                GameManager::gameError("Plant Service Activity Type Error !");
                break;
        }
        
    }
    
    
    
    
    
};

#endif
