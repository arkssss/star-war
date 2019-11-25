//
//  UpgradSystemActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/25.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _UpgradSystemActivity
#define _UpgradSystemActivity

#include "Activity.cpp"


/*
 
  upgrad all the system
 
 */
class UpgradSystemActivity : public Activity{
    
    
    private :
    std::pair<int, int> upgradCombatAptitRange;
    std::pair<int, int> upgradDefenseAptitRange;
    
    
    public :
    
    
    /* constructor */
    UpgradSystemActivity(){
        
        upgradCombatAptitRange = RuntimeParameter::UPGRAD_SYSTEM_COMBATATITU_RANGE;
        upgradDefenseAptitRange= RuntimeParameter::UPGRAD_SYSTEM_DEFENSE_RANGE;
    }
    
    void start(SpaceShip &spaceship){
        
        /* upgrad CombatAptit */
        upgradCombatAptit();
        
        /* upgrad defense*/
        upgradDefense();
        
    }
    
    void upgradCombatAptit(){
        
        int upgradVal = GameTimer::getRandomByRange(upgradCombatAptitRange);
        
        spaceShipDAO.incCombatAptitude(upgradVal);
        
        GameLogger::stdOut("you have improve your combat aptit for : " + std::to_string(upgradVal) + " in UpgradSystemActivity");
        
    }
    
    void upgradDefense(){
        
        int upgradVal = GameTimer::getRandomByRange(upgradDefenseAptitRange);
        
        spaceShipDAO.incDefenseAptitude(upgradVal);
        
        GameLogger::stdOut("you have improve your defense for : " + std::to_string(upgradVal) + " in UpgradSystemActivity");
        
    }
    
    
};

#endif
