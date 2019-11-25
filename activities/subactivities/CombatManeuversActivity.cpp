//
//  CombatManeuversActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/24.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _CombatManeuversActivity
#define _CombatManeuversActivity

#include "../Activity.cpp"


/*
    for combat Maneuvers logic
 
    : Avoid enemy fire while in combat
    : Must have some crewMember change
    : Enhance the def ability
 
 */
class CombatManeuversActivity : public Activity{
    
    
    private :
    
    std::pair<int, int> reduce_ordcrew_range;
    std::pair<int, int> reduce_officer_range;
    std::pair<int, int> enhance_defense_range;
    
    public :
    
    CombatManeuversActivity(){
        
        
        
        /* init the range */
        reduce_ordcrew_range = RuntimeParameter::COMBAT_MANEUVERRS_REDUCE_ORDCREW_RANGE;
        
        reduce_officer_range = RuntimeParameter::COMBAT_MANEUVERRS_REDUCE_OFFICER_RANGE;
        
        enhance_defense_range = RuntimeParameter::COMBAT_MANEUVERRS_ENHANCE_DEFENSE_RANGE;
        
    }
    
    
    /* come battle Maneuvers with alien , avoid the attack from the alien */
    void start(SpaceShip alien){
        
        /* reduce the crew during this combat */
        reduceCrew(alien);
        
        /* enhance the defense ability */
        enhanceDefense();
    }
    
    /* reduce the crew member */
    void reduceCrew(SpaceShip alien){
        
        int combatApti = alien.getCombatAptitude();
        
        int deadOrdCrew = GameTimer::getRandomByRange(reduce_ordcrew_range) * combatAptiToDeadingParamter(combatApti);
        int deadOfficer = GameTimer::getRandomByRange(reduce_officer_range) * combatAptiToDeadingParamter(combatApti);
        
        /* get myspaceship left crew number  */
        int leftOrdCrewNumbers = spaceShipDAO.getOrdCrewNumber();
        int leftOfficerNumbers = spaceShipDAO.getOfficerNumber();
        
        /* set act dead number */
        deadOrdCrew = deadOrdCrew > leftOrdCrewNumbers ? leftOrdCrewNumbers : deadOrdCrew;
        deadOfficer = deadOfficer > leftOfficerNumbers ? leftOfficerNumbers : deadOfficer;
        
        /* remove ordCrew */
        for(int i=0; i<deadOrdCrew; i++){
            
            CrewMember myDeadOrdCrew = spaceShipDAO.removeOneOrdCrew();
            
            GameLogger::stdOut("oop !! one of your ord crew have dead in this Maneuvers");
            
        }
        
        /* remove officer */
        for(int i=0; i<deadOfficer; i++){
            
            Officer myDeadOfficer = spaceShipDAO.removeOneOfficer();
            
            GameLogger::stdOut("oop !! one of your officer : "+ myDeadOfficer.getName() +" have dead in this Maneuvers who is a : " + Abilities::IntegerToAbility(myDeadOfficer.getAbilityType()));
            
        }
        
    }
    
    /* although have someone dead, but your defense abiliy have been enhance */
    void enhanceDefense(){
        
        
        int defenseEnhance = GameTimer::getRandomByRange(enhance_defense_range);
        
        spaceShipDAO.incDefenseAptitude(defenseEnhance);
        
        GameLogger::stdOut("you have enhance your defense ability for : " + std::to_string(defenseEnhance));
    }
    
    /* the dead number can not */
    /*
        0 ~ 99 -> 1
        100 ~ 199 -> 2
        and so on
     */
    int combatAptiToDeadingParamter(int combatApti){
        
        return combatApti/100 + 1;
        
    }
    
};


#endif
