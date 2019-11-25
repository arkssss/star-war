//
//  TradingStationService.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _TradingStationService
#define _TradingStationService

#include "Service.cpp"
/*
 
 The service for encounter a TradingStation
 
 * Trade, Diplomacy,

 
 */
class TradingStationService : public Service{
    
    private :
    
    
    /* Diplomacy */
    DiplomacyActivity diplomacyActivity;
    
    /* Trading */
    TradingActivity tradingActivity;
    
    /* System Recovery */
    SystemsRecoveryActivity systemsRecoveryActivity;
    
    /* Travel eff*/
    TravelEfficiencyActivity travelEfficiencyActivity;
    
    
    
    public :
    
    
    
    void start(SpaceShip &spaceShip){
        
        
        GameLogger::stdOut("You are now leading in a trading station in round : " + std::to_string(RuntimeParameter::GAME_CURRENT_ROUND + 1));
        
        switch (GameTimer::_rand() % 4) {
            case 0:
                /* DiplomacyActivity */
                GameLogger::stdOut("You are doing diplomacy in this trading station");
                diplomacyActivity.start(spaceShip);
                break;
            case 1:
                /* tradingActivity */
                GameLogger::stdOut("You start trading in this trading station");
                tradingActivity.start(spaceShip);
                break;
            case 2:
                GameLogger::stdOut("You are doing Systems Recovery Activity trading station");
                systemsRecoveryActivity.start(spaceShip);
                break;
                
            case 3:
                GameLogger::stdOut("You are doing Systems travel Efficiency Activity trading station");
                travelEfficiencyActivity.start(spaceShip);
                break;
            default:
                GameManager::gameError("Plant Service Activity Type Error !");
                break;
        }
        
        
        
        
        
        
        
    }
    
    
    
    
    
    
};


#endif
