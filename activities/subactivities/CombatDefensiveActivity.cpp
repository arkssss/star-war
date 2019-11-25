//
//  CombatDefensiveActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/24.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _CombatDefensiveActivity
#define _CombatDefensiveActivity

#include "../Activity.cpp"

class CombatDefensiveActivity : public Activity{
    
    private :
    
    std::pair<int, int> MustLostHPRange;
    
    
    public :
    
    
    /* constructor */
    CombatDefensiveActivity(){
        
        MustLostHPRange = RuntimeParameter::COMBAT_MUST_LOST_HP_RANGE;
        
    }
    
    
    /* start defense when facing the alien's attack */
    void start(SpaceShip alien){
        
        
        /* reduceHP */
        reduceHP(alien);
        
        
        /* reduce crew */
        
        
    }
    
    /* reduce our HP*/
    void reduceHP(SpaceShip alien){
        
        /* combat ability */
        int alienCombatApti = alien.getCombatAptitude();
        int ourDenfense = spaceShipDAO.getSpaceDefense();
        int ourLeftHP = spaceShipDAO.getSpaceShipHP();
        
        /* avoid HP not change */
        int _reduceHP = (alienCombatApti - ourDenfense) + GameTimer::getRandomByRange(MustLostHPRange);
        
        
        /* combat apti must larger then denfense apti */
        _reduceHP = _reduceHP > ourLeftHP ? ourLeftHP : _reduceHP;
        _reduceHP = _reduceHP > 0 ? _reduceHP : 0;
        
        spaceShipDAO.decSpaceshipHP(_reduceHP);
        GameLogger::stdOut("you have lost HP : " + std::to_string(_reduceHP));
    }
    
    
    
    
};



#endif
