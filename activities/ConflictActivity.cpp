//
//  ConflictActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/23.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _ConflictActivity
#define _ConflictActivity

#include "Activity.cpp"
#include "subactivities/ConflictProceedActivty.cpp"
#include "subactivities/ConflictEvasionActivity.cpp"
/*
 
    Conflict with the other civ
 
 1. need ability : 
 
 */

class ConflictActivity : public Activity{
    
    
    private :
    
    /* ability for Evasion*/
    std::vector<std::string> conflictEvasionNeedAbilities;
    
    /* ability for Proceed */
    std::vector<std::string> conflictProceedActivities;
    
    /* conflict proceed */
    ConflictProceedActivty conflictProceedActivty;
    
    /* conflict evasion */
    ConflictEvasionActivity conflictEvasionActivity;
    
    public :
    
    /* constructor */
    ConflictActivity(){
        
        /* Evasion */
        conflictEvasionNeedAbilities.push_back(Abilities::ABILITY_PILOT);
        conflictEvasionNeedAbilities.push_back(Abilities::ABILITY_ENGINEERING);
        
        /* Proceed */
        conflictProceedActivities.push_back(Abilities::ABILITY_WEAPONS);
    }
    
    /* start conflict */
    void start(SpaceShip &spaceShip){
        
        /*  */
        int randomSeed = GameTimer::_rand() % 2 ;
        
        switch (randomSeed) {
            case 0:
                GameLogger::stdOut("you are now proceeding a conflict");
                if(activityAbilityOK(spaceShip, conflictProceedActivities)){
                    conflictProceedActivty.start();
                }else{
                    GameLogger::stdOut("you do not have ability to proceed ConflictProceed");
                }
                
                break;
            case 1:
                GameLogger::stdOut("you have evasion success in a conflict");
                if(activityAbilityOK(spaceShip, conflictEvasionNeedAbilities)){
                    conflictEvasionActivity.start();
                }else{
                    GameLogger::stdOut("you do not have ability to proceed ConflictEvasion");
                }
                break;
            default:
                GameLogger::stdOut("Conflict Dealer Error !!!");
                break;
        }
        
        
        return;
    }
    
    
    
};


#endif


