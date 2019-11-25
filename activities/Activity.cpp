//
//  Activity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/20.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _Activity
#define _Activity


#include "../entity/SpaceShip.cpp"
#include "../conf/Abilities.cpp"
#include "../util/GameLogger.cpp"
#include "../dao/SpaceShipDAO.cpp"
#include "../conf/ExchangeRate.cpp"
#include "../factory/SpaceshipFactory.cpp"
#include "../util/GameTimer.cpp"
#include "../conf/RumtimeParameter.cpp"


/*
    the basic class of activity
 */

class Activity{
    
    public :
    
    // Require the type of ability to do this activity
    std::vector<std::string> NEED_ABILITES;
    
    // DAO
    SpaceShipDAO spaceShipDAO;
    
    
    // check the spaceShip if have the abiliy def in NEED_ABILITY
    bool activityAbilityOK(SpaceShip spaceShip){
        
        
        std::vector<std::string>::iterator it = NEED_ABILITES.begin();
        
        while(it!=NEED_ABILITES.end()){
            
            // exist one of the NEED_ABILITES is OK
            if(spaceShipDAO.existOfficer(*it)) return true;
            
            it++;
        }
        
        return false;
     
    }
    
    
    /* overload */
    bool activityAbilityOK(SpaceShip spaceShip, std::vector<std::string> abilities){
        
        
        std::vector<std::string>::iterator it = abilities.begin();
        
        while(it!=abilities.end()){
            
            // exist one of the NEED_ABILITES is OK
            if(spaceShipDAO.existOfficer(*it)) return true;
            
            it++;
        }
        
        return false;
        
        
        
    }
    
};

#endif
