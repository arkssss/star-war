//
//  CombatOffensive.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/24.
//  Copyright © 2019年 ark. All rights reserved.
//



#ifndef _CombatOffensiveActivity
#define _CombatOffensiveActivity


#include "../Activity.cpp"



class CombatOffensiveActivity : public Activity {
    
    
    private :
    
    /* the Hp will must be lost Range */
    std::pair<int, int> MustLostHPRange;
    
    public :
    
    /* constructor */
    CombatOffensiveActivity(){
        
        MustLostHPRange = RuntimeParameter::COMBAT_MUST_LOST_HP_RANGE;

    }
    
    
    /* our spaceship attack */
    void start(SpaceShip &alien){
        
        
        
        /* reduce alien's HP */
        reduceHP(alien);
        
    }
    
    
    /* reduce alien's HP */
    void reduceHP(SpaceShip &alien){
        
        int myCombatAptitu = spaceShipDAO.getCombatAptitude();
        int alienDefense = alien.getDefenseAptitude();
        
        /* avoid aways not lose HP during the combat */
        int _reduceHP = (myCombatAptitu - alienDefense) + GameTimer::getRandomByRange(MustLostHPRange) ;
        int alienLeftHP = alien.getSpaceshipHP();
        
        _reduceHP = _reduceHP > alienLeftHP ? alienLeftHP : _reduceHP;
        
        /* aviod not bigger then 0 */
        _reduceHP = _reduceHP > 0 ? _reduceHP : 0;
        
        alien.setSpaceshipHP(alienLeftHP - _reduceHP);
        GameLogger::stdOut("Alien have been attacked, lost HP : " + std::to_string(_reduceHP));
    }
    
    
    
};

#endif
