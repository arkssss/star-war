//
//  Abilities.h
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/20.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _Abilities
#define _Abilities

#include <string>
#include "../util/GameManager.cpp"

class Abilities{
    
public:
    
    // Negotiation which includes diplomacy and trading.
    // index 1
    static std::string ABILITY_CAPTAIN;
    
    // Influence travel efficiency, combat maneuvers, conflict evasion.
    // index 2
    static std::string ABILITY_PILOT;
    
    // Influence travel efficiency, combat maneuvers, conflict evasion, defensive performance, systems recovery.
    // index 3
    static std::string ABILITY_ENGINEERING;
    
    
    // Mining ability.
    // index 4
    static std::string ABILITY_MINING ;
    
    
    // Offensive performance, defensive performance.
    // index 5
    static std::string ABILITY_WEAPONS;
    
    
    /*
     convert the name of ability to the integer type
     */
    static int abilityToInteger(std::string abilityName);

    
    /*
     
     convert the integer type to the name of ability
     
     */
    
    static std::string IntegerToAbility(int type);
    
};
//  ------------------------ defination --------------------------
std::string Abilities::ABILITY_CAPTAIN = "Captain";
std::string Abilities::ABILITY_PILOT = "Pilot";
std::string Abilities::ABILITY_ENGINEERING = "Engineering";
std::string Abilities::ABILITY_MINING = "Mining";
std::string Abilities::ABILITY_WEAPONS = "Weapons";

/*
 convert the name of ability to the integer type
 */
int Abilities::abilityToInteger(std::string abilityName){

    if(abilityName == "Captain") return 1;
    if(abilityName == "Pilot") return 2;
    if(abilityName == "Engineering") return 3;
    if(abilityName == "Mining") return 4;
    if(abilityName == "Weapons") return 5;

    GameManager::gameError("Unexcepted ability name");
    return -1;
}


/*
 
 convert the integer type to the name of ability
 
 */

std::string Abilities::IntegerToAbility(int type){

    
    if(type == 1) return "Captain";
    if(type == 2) return "Pilot";
    if(type == 3) return "Engineering";
    if(type == 4) return "Mining";
    if(type == 5) return "Weapons";

    GameManager::gameError("Unexcepted ability type");
    return "";
}




#endif /* Abilities_h */
