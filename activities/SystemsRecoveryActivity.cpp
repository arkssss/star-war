//
//  SystemsRecoveryActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/23.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _SystemsRecoveryActivity
#define _SystemsRecoveryActivity

#include "Activity.cpp"

/*
  for recovery of this spaceship
     1. Need_Ability : ENGINEERING
     2. imporve the HP of this spaceship
 */
class SystemsRecoveryActivity : public Activity{
    
    
    private :
    
    int engineeringAptitude;
    
    std::pair<int, int> systemRecovryHPRange;
    

    
    public :
    /* constructor */
    SystemsRecoveryActivity(){
        
        /* the range of the recovry HP */
        systemRecovryHPRange = RuntimeParameter::SYSTEMRECOVERY_HP_RANGE;
        
        /* needs ability */
        NEED_ABILITES.push_back(Abilities::ABILITY_ENGINEERING);
    }
    
    
    void start(SpaceShip &spaceShip){
        
        
        if(!activityAbilityOK(spaceShip)) {
            GameLogger::stdOut("sorry, you do not have ability to recover this spaceship system");
            return;
        }
        engineeringAptitude = spaceShip.getEngineeringAptitude();
        
        /* Recovery */
        recoverySystem();
        
        /* Supplement */
        supplementOfficer();
        
        return;
    }
    
    /* arcding to the engineeringAptitude to recoevr the system */
    void recoverySystem(){
        
        int recoveryHP = engineeringAptitude * GameTimer::getRandomByRange(systemRecovryHPRange);
        int leftHP = spaceShipDAO.getSpaceShipHP();
        int limitHP = SpaceshipType::getSpaceshipHpBySpaceshipType(spaceShipDAO.getSpaceShipType());
        
        /* HP after recovery must less then the limit */
        recoveryHP = (leftHP + recoveryHP) > limitHP ? (limitHP - leftHP) : recoveryHP;
        
        /* inc */
        spaceShipDAO.incSpaceshipHP(recoveryHP);
        
        GameLogger::stdOut("You have recovery your system for : " + std::to_string(recoveryHP));
    }
    
    
    void supplementOfficer(){
        
        
        int ordCrewNumbers = spaceShipDAO.getOrdCrewNumber();
        
        std::pair<int, int> supplementRange(0, ordCrewNumbers);
        int supplements = GameTimer::getRandomByRange(supplementRange);
        
        for(int i=0; i<supplements; i++){
            
            CrewMember tmpCrew =  spaceShipDAO.removeOneOrdCrew();
            
            Officer tmpOfficer;
            tmpOfficer.setName(SpaceshipType::getRandomOfficerName());
            tmpOfficer.setAge(SpaceshipType::getRandomOfficerAge());
            tmpOfficer.setAbilityType(SpaceshipType::getRandomAbilityType());
            
            spaceShipDAO.addOfficer(tmpOfficer);
            
            GameLogger::stdOut("the crewID : " + std::to_string(tmpCrew.getCrewId())+ " which is your ordinary soilder have becomes officer which major in : " + Abilities::IntegerToAbility(tmpOfficer.getAbilityType()));
        }
        
        
    }
    
    
    
};
#endif
