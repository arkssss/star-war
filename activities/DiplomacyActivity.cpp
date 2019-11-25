//
//  DiplomacyActivity.cpp
//  
//
//  Created by 方舟Ark on 2019/11/20.
//
#ifndef _DiplomacyActivity
#define _DiplomacyActivity


#include "Activity.cpp"
/*
 
 define the effect of happening diplomacy

 
 need ability:
 
    1. captain
 
 effect of this activity :
 
    1. improve the prestige which is helpful for avoiding the conflict
 
 
 */
class DiplomacyActivity : public Activity{
    
    
    private :
    
    /* the inc range for Prestige to increase */
    std::pair<int, int> PrestigeIncRange;
    

    
    public :
    
    // constructor
    DiplomacyActivity(){
        
        // PrestigeIncRange
        PrestigeIncRange = RuntimeParameter::DiPLOMACY_PRESTIGE_RANGE;
        
        // need captain to precess diplomacy
        NEED_ABILITES.push_back(Abilities::ABILITY_CAPTAIN);
        
    }
    
    
    /* main func */
    void start(SpaceShip &spaceShip){
        
        
        
        if(!diplomacyOK(spaceShip)) {
            
            // diplomacy error
            // for example : the captain dead
            GameLogger::stdOut("Diplomacy Fail!!!");
            return;
        }
        
        // inc thr prestige
        spaceShipDAO.incPrestige(getPrestigeIncNumber());
        GameLogger::stdOut("Diplomacy success, your Prestige becomce : " + std::to_string(spaceShip.getPrestige()));
        return;
    }
    
    
    
    
    // -------------------------------- helper function -------------------
    
    /*
        check if this ship can exc diplomacy
     */
    bool diplomacyOK(SpaceShip spaceShip){
        
    
        // condition1 || condition2 || ...
        return activityAbilityOK(spaceShip);
    }
    
    /* get a random inc for the Prestige*/
    int getPrestigeIncNumber(){
        
        
        int randomSeed = GameTimer::_rand() % (PrestigeIncRange.second - PrestigeIncRange.first);
        
        return PrestigeIncRange.first + randomSeed;
        
    }
    
    
    
    
};

#endif
