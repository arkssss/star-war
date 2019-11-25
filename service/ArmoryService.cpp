//
//  ArmoryService.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/25.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _ArmoryService
#define _ArmoryService

#include "Service.cpp"

/*
 customize service
 */

class ArmoryService : public Service{
    
    
    private :
    
    UpgradSystemActivity upgradSystemActivity;
    
    
    
    public :
    
    
    
    void start(SpaceShip &spaceship){
        
        GameLogger::stdOut("you are in armory selector in round : " + std::to_string(RuntimeParameter::GAME_CURRENT_ROUND + 1));
        
        upgradSystemActivity.start(spaceship);
    }
    
    
    
};

#endif
