//
//  CombatActivty.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/23.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _CombatActivty
#define _CombatActivty


#include "Activity.cpp"
#include "subactivities/CombatManeuversActivity.cpp"
#include "subactivities/CombatDefensiveActivity.cpp"
#include "subactivities/CombatOffensiveActivity.cpp"
/*
 
    encounter a combat
 
 */
class CombatActivty : public Activity{
    
    
    private :
    
        /* abilities */
        std::vector<std::string> combat_maneuvers_abilities;
        std::vector<std::string> combat_defense_abilities;
        std::vector<std::string> combat_offensive_abilities;
    
        /* alien */
        SpaceShip alien;
    
        /* combat Maneuver */
        CombatManeuversActivity combatManeuversActivity;
    
        /* combat defense */
        CombatDefensiveActivity combatDefensiveActivity;
    
        /* combat offensive */
        CombatOffensiveActivity  CombatOffensiveActivity;
    
        /* combat evasion */
        
    
    
        /* limit round */
        int limitRound;
    
    public :
    
    /* constructor */
    CombatActivty(){
        
        /* maneuvers */
        combat_maneuvers_abilities.push_back(Abilities::ABILITY_PILOT);
        combat_maneuvers_abilities.push_back(Abilities::ABILITY_ENGINEERING);
        
        /* defense */
        combat_defense_abilities.push_back(Abilities::ABILITY_WEAPONS);
        
        /* offensive */
        combat_offensive_abilities.push_back(Abilities::ABILITY_WEAPONS);
        
    }
    
    void initAlien(){
        
        
        SpaceshipFactory spaceshipFactory;
        
        int AlienType = SpaceshipType::getRandomSpaceshipType();
        int AlienCiv = SpaceshipType::getRandomAlienSpaceshipCiv();
        
        /* alien comes !!!*/
        alien = spaceshipFactory.buileSpaceship(AlienType, AlienCiv);
        GameLogger::stdOut("Opps, you encounter the alien !!!");
        GameLogger::stdOut("Opps, you encounter the alien !!! which is : " + SpaceshipType::getSpaceshipCivByType(AlienCiv));
        
    }
    
    
    void start(SpaceShip spaceShip){

        /* alien init */
        initAlien();
        /* judge alien's ability */
        if(!activityAbilityOK(alien, combat_defense_abilities)){
            
            GameLogger::stdOut("You are luckly, alien do not have weapon, you win in this combat");
            return;
        };
        
        
        
        limitRound = 3;
        while(keepFighting()){
            
            int _randSeed = GameTimer::_rand() % 3;
            
            
            
            switch (_randSeed) {
                case 0:
                    
                    GameLogger::stdOut("you are now combat maneuvers with alien");
                    
                    if(activityAbilityOK(spaceShip, combat_maneuvers_abilities)){
                            // start
                        combatManeuversActivity.start(alien);
                    }else{
                        
                        GameLogger::stdOut("sorry, you don't have ability to proceed");
                        
                    }
                    
                    break;
                case 1:
                    
                    GameLogger::stdOut("combat defensive !!!");

                    
                    if(activityAbilityOK(spaceShip, combat_defense_abilities)){
                        // start
                        combatDefensiveActivity.start(alien);
                    }else{
                        
                        GameLogger::stdOut("sorry, you don't have ability to proceed defensive");
                        
                    }
                    
                    break;
                case 2:
                    
                    GameLogger::stdOut("combat offensive !!!");
                    
                    if(activityAbilityOK(spaceShip, combat_offensive_abilities)){
                        
                        CombatOffensiveActivity.start(alien);
                        
                    }else{
                        GameLogger::stdOut("sorry, you don't have ability to proceed offensive");

                    }
                    
                    break;
                default:
                    GameManager::gameError("combat parameter error !");
                    return;
            }
            
            
            
            
            
            
        }
        
        
    }
    
    /* judge the combat if end */
    bool keepFighting(){
        
        /* three round end */
        if(limitRound <= 0) return false;
        
        /* */
        if(alien.getSpaceshipHP() <=0 ) return false;
        
        /* */
        if(spaceShipDAO.getSpaceShipHP() <= 0) return false;
        
        
        limitRound --;
        return true;
    }
    
    
    
    
};

#endif

