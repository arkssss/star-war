//
//  CombatService.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//
#ifndef _SpaceshipService
#define _SpaceshipService


#include "Service.cpp"

/*
 
 the servie for spaceship encounter the Spaceship
 
 */
class SpaceshipService : public Service{
    
    
    private :
    
    /* Conflict */
    ConflictActivity conflictActivity;
    
    /* Combat (Battle) */
    CombatActivty combatActivity;
    
    /* Diplomacy */
    DiplomacyActivity diplomacyActivity;
    
    
    
    
    
    public :
    void start(SpaceShip &spaceShip){
        
        
        
        GameLogger::stdOut("You are now leading in a SpaceshipStation in round : " + std::to_string(RuntimeParameter::GAME_CURRENT_ROUND + 1));
        
        switch (GameTimer::_rand() % 3) {
            case 0:
                /* DiplomacyActivity */
                GameLogger::stdOut("You are doing Conflict in this spaceship station");
                conflictActivity.start(spaceShip);
                break;
            case 1:
                /* tradingActivity */
                GameLogger::stdOut("You are encounter a alien in spaceship station");
                combatActivity.start(spaceShip);
                break;
            case 2:
                GameLogger::stdOut("You are doing diplomacy spaceship station");
                diplomacyActivity.start(spaceShip);
                break;
            default:
                GameManager::gameError("Plant Service Activity Type Error !");
                break;
        }
        
        
        
        
        return;
        
        
    }
    
    
    
    
    
    
    
};


#endif
