//
//  SpaceshipType.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/21.
//  Copyright © 2019年 ark. All rights reserved.
//

/*
 
 this class for def all the conf for a spaceship during a **init time**
 
 */

#ifndef _SpaceshipType
#define _SpaceshipType

#include "../util/GameManager.cpp"
#include "../util/GameTimer.cpp"
#include "Abilities.cpp"
#include <vector>
#include <string>


class SpaceshipType{
    
    
    public :
    
    //  -------------------------------------- helper filed --------------------------------

    
    /* def the cap of this spaceship*/
    static int FIRST_DEGREE_SPACESHIP;
    static int SECOND_DEGREE_SPACESHIP;
    static int THIRD_DEGREE_SPACESHIP;
    static int FORTH_DEGREE_SPACESHIP;
    static int FIFTH_DEGREE_SPACESHIP;
    
    /* def which civilization the space ship belongs */
    // our civilization
    static int EARTH_SPACESHIP;
    // other civilization
    static int MARS_SPACESHIP;
    static int MERCURY_SPACESHIP;
    static int ORC_SPACESHIP;
    static int NIGHTELF_SPACESHIP;
    
    
    // officer random names & age
    static std::vector<std::string> officerNames;
    static std::vector<int> officerAges;
    // randge for officerAbility [first, second]
    static std::pair<int, int> officerAbilityDegreeRange;

    
    /*
     int combatAptitude;
     int defenseAptitude
     int mineAptitude;
     int travelSpeed;
     int cargoCapacity;
     int prestige;
     
     int travelAvgFuelConsumption;
     int travelAvgFoodConsumption;
     
     int engineeringAptitude;
     */
    static std::pair<int, int> combatAptitudeRange;
    static std::pair<int, int> defenseAptitudeRange;
    static std::pair<int, int> mineAptitudeRange;
    static std::pair<int, int> travelSpeedRange;
    static std::pair<int, int> cargoCapacityRange;
    static std::pair<int, int> prestigeRange;
    static std::pair<int, int> travelAvgFuelConsumptionRange;
    static std::pair<int, int> travelAvgFoodConsumptionRange;
    static std::pair<int, int> engineeringAptitudeRange;
    
    /* the HP base of spaceship, different type of spaceship have diff HP */
    static int spaceshipHPBase;
    
    
    
    
    
    //  -------------------------------------- helper function --------------------------------
    
    /* init evevthing */
    static void _init();
    
    /* get the addition bonus by tppe of spaceship */
    static int getBonusByType(int _spaceshipType){return _spaceshipType;}
    
    /* get the degree of a spaceship */
    static std::string getSpaceshipNameByType(int _spaceshipType);
    
    /* get the civ of a spaceship */
    static std::string getSpaceshipCivByType(int _spaceshipCiv);
    
    /* get the abilites */
    static std::vector<std::string> getInitAbility(int _spaceshipCiv);
    
    /* get a random name for the officers name array*/
    static std::string getRandomOfficerName();
    
    /* get a random type of spaceship*/
    static int getRandomSpaceshipType();
    
    /* get a random spaceship civ include earth */
    static int getRandomSpaceshipCiv();
    
    /* get a random alien spaceship civ (exclude earth)*/
    static int getRandomAlienSpaceshipCiv();
    
    /* get a random age for the officer age array*/
    static int getRandomOfficerAge();
    
    /* get a random ability degree */
    static int getRandomAbilityDegree();
    
    /* get a random ability type */
    static int getRandomAbilityType();
    
    /* get a random combatAptitude */
    static int getRandomCombatAptitudeBySpaceshipType(int _spaceshipType);
    
    /* get a random defenseAptitude */
    static int getRandomDefenseAptitudeBySpaceshipType(int _spaceshipType);
    
    /* get a random mineAptitude */
    static int getRandomMineAptitudeBySpaceshipType(int _spaceshipType);
    
    /* get a random travelSpeed */
    static int getRandomTravelSpeedBySpaceshipType(int _spaceshipType);
    
    /* get a random cargoCapacity */
    static int getRandomCargoCapacityBySpaceshipType(int _spaceshipType);
    
    /* get a random prestige */
    static int getRandomPrestigeBySpaceshipType(int _spaceshipType);
    
    /* get a random travelAvgFuelConsumption*/
    static int getRandomTravelAvgFuelConsumption(int _spaceshipType);
    
    /* get a random travelAvgFoodConsumption */
    static int getRandomTravelAvgFoodConsumption(int _spaceshipType);
    
    /* get a HP of the spaceship by it's type */
    static int getSpaceshipHpBySpaceshipType(int _spaceshipType);
    
    /* get a random engineering Aptitude*/
    static int getRandomEngineeringAptitude(int _spaceshipType);
    
    
};




// different capacity
int SpaceshipType::FIRST_DEGREE_SPACESHIP = 1;
int SpaceshipType::SECOND_DEGREE_SPACESHIP= 2;
int SpaceshipType::THIRD_DEGREE_SPACESHIP = 3;
int SpaceshipType::FORTH_DEGREE_SPACESHIP = 4;
int SpaceshipType::FIFTH_DEGREE_SPACESHIP = 5;


// different civilization
int SpaceshipType::EARTH_SPACESHIP = 1;
int SpaceshipType::MARS_SPACESHIP = 2;
int SpaceshipType::MERCURY_SPACESHIP = 3;
int SpaceshipType::ORC_SPACESHIP = 4;
int SpaceshipType::NIGHTELF_SPACESHIP = 5;

/* Using g++11 compile */
// different the names of officer
std::vector<std::string> SpaceshipType::officerNames = {"Fz", "Ark", "Bill", "Joy", "Iras", "Bob", "FangZhou", "Joly"};
std::vector<int> SpaceshipType::officerAges = {20, 22, 23, 34, 45, 12, 34, 12, 43, 55, 33, 23};
/* [firstInt, secondInt]*/
std::pair<int, int> SpaceshipType::officerAbilityDegreeRange(20, 50);


/*
 int combatAptitude;
 int mineAptitude;
 int travelSpeed;
 int cargoCapacity;
 int prestige;
 */
std::pair<int, int> SpaceshipType::combatAptitudeRange(30, 60);
std::pair<int, int> SpaceshipType::mineAptitudeRange(2, 10);
std::pair<int, int> SpaceshipType::travelSpeedRange(70, 80);
std::pair<int, int> SpaceshipType::cargoCapacityRange(90, 100);
std::pair<int, int> SpaceshipType::prestigeRange(40, 60);
std::pair<int, int> SpaceshipType::travelAvgFuelConsumptionRange(10, 20);
std::pair<int, int> SpaceshipType::travelAvgFoodConsumptionRange(20, 30);
std::pair<int, int> SpaceshipType::engineeringAptitudeRange(10, 20);
std::pair<int, int> SpaceshipType::defenseAptitudeRange(10, 20);


int SpaceshipType::spaceshipHPBase = 100;




/* pass the integer of a spaceship civ, return it's name
    static int EARTH_SPACESHIP;
    static int MARS_SPACESHIP;
    static int MERCURY_SPACESHIP;
    static int ORC_SPACESHIP;
    static int NIGHTELF_SPACESHIP;
 */
std::string SpaceshipType::getSpaceshipCivByType(int _spaceshipType){
    
    switch (_spaceshipType) {
        case 1:
            return "Earth Civilisation";
        case 2:
            return "Mars Civilisation";
        case 3:
            return "Mercury Civilisation";
        case 4:
            return "Orc";
        case 5:
            return "Night Elf";
        default:
            GameManager::gameError("spaceship type error");
    }
    
    return "";
    
}


/* pass the integer of a spaceship type, return it's name */
std::string SpaceshipType::getSpaceshipNameByType(int _spaceshipType){
    
    switch (_spaceshipType) {
        case 1:
            return "First Degree Spaceship";
        case 2:
            return "Second Degree Spaceship";
        case 3:
            return "Third Degree Spaceship";
        case 4:
            return "Forth Degree Spaceship";
        case 5:
            return "Fifth Degree Spaceship";
        default:
            GameManager::gameError("spaceship type error");
    }
    
    return "";
    
}


/* get the ability vector by _spaceshipCiv, for example : our shpaceshi is EARTH, and get all of the ability */
std::vector<std::string> SpaceshipType::getInitAbility(int _spaceshipCiv){
    
    std::vector<std::string> abilities;
    
    if(_spaceshipCiv == EARTH_SPACESHIP){
        
        // our spaceship earth
        abilities.push_back(Abilities::ABILITY_CAPTAIN);
        abilities.push_back(Abilities::ABILITY_PILOT);
        abilities.push_back(Abilities::ABILITY_MINING);
        abilities.push_back(Abilities::ABILITY_WEAPONS);
        abilities.push_back(Abilities::ABILITY_ENGINEERING);
        
    }else if(_spaceshipCiv == MARS_SPACESHIP){
        // mars
        abilities.push_back(Abilities::ABILITY_MINING);
        abilities.push_back(Abilities::ABILITY_WEAPONS);
        abilities.push_back(Abilities::ABILITY_ENGINEERING);
        abilities.push_back(Abilities::ABILITY_CAPTAIN);
        
    }else if(_spaceshipCiv == MERCURY_SPACESHIP){
        // MERCURY
        abilities.push_back(Abilities::ABILITY_WEAPONS);
        abilities.push_back(Abilities::ABILITY_CAPTAIN);
        
    }else if (_spaceshipCiv == ORC_SPACESHIP){
        // orc
        abilities.push_back(Abilities::ABILITY_PILOT);
        abilities.push_back(Abilities::ABILITY_MINING);
        abilities.push_back(Abilities::ABILITY_WEAPONS);
        abilities.push_back(Abilities::ABILITY_ENGINEERING);
        
    }else if (_spaceshipCiv == NIGHTELF_SPACESHIP){
        // Night
        abilities.push_back(Abilities::ABILITY_CAPTAIN);
        abilities.push_back(Abilities::ABILITY_PILOT);
        abilities.push_back(Abilities::ABILITY_MINING);
    
    }else{
        
        GameManager::gameError("spaceship civ error");
        
    }
    
    return abilities;
}

/* get a random name for the officers name array*/
std::string SpaceshipType::getRandomOfficerName(){
    
    long length = officerNames.size();
    int randomSeed = GameTimer::_rand() % length;
    
    return officerNames[randomSeed];
}


/* get a random spaceship type */
int SpaceshipType::getRandomSpaceshipType(){
    
    return (GameTimer::_rand() % 5) + 1;
    
}

/* get a random spaceship civ */
int SpaceshipType::getRandomSpaceshipCiv(){
    
    return (GameTimer::_rand() % 5) + 1;
    
}
/* get a random alien civ */
int SpaceshipType::getRandomAlienSpaceshipCiv(){
    
    /* alien civ is 2, 3*/
    return (GameTimer::_rand() % 2) + 2;
}



/* get a random age for the officer age array*/
int SpaceshipType::getRandomOfficerAge(){
    long length = officerAges.size();
    int randomSeed = GameTimer::_rand() % length;
    
    return officerAges[randomSeed];
}


/* get a random ability degree */
int SpaceshipType::getRandomAbilityDegree(){
    
    int randomSeed = GameTimer::_rand() % (officerAbilityDegreeRange.second - officerAbilityDegreeRange.first);
    
    return officerAbilityDegreeRange.first + randomSeed;
}

/* get a random ability type */
int SpaceshipType::getRandomAbilityType(){
    
    return GameTimer::_rand() % 5 + 1;
    
}

/* get a random defenseAptitude */
int SpaceshipType::getRandomDefenseAptitudeBySpaceshipType(int _spaceshipType){
    
    return _spaceshipType * GameTimer::getRandomByRange(defenseAptitudeRange);
    
}

/* get a random combatAptitude by the type of spaceship*/
int SpaceshipType::getRandomCombatAptitudeBySpaceshipType(int _spaceshipType){
    
    int randomSeed = GameTimer::_rand() % (combatAptitudeRange.second - combatAptitudeRange.first);
    randomSeed *= getBonusByType(_spaceshipType);
    
    return combatAptitudeRange.first * getBonusByType(_spaceshipType) + randomSeed;
}

/* get a random mineAptitude */
int SpaceshipType::getRandomMineAptitudeBySpaceshipType(int _spaceshipType){
    int randomSeed = GameTimer::_rand() % (mineAptitudeRange.second - mineAptitudeRange.first);
    randomSeed *= getBonusByType(_spaceshipType);
    
    return mineAptitudeRange.first * getBonusByType(_spaceshipType) + randomSeed;
}

/* get a random travelSpeed */
int SpaceshipType::getRandomTravelSpeedBySpaceshipType(int _spaceshipType){
    
    int randomSeed = GameTimer::_rand() % (travelSpeedRange.second - travelSpeedRange.first);
    randomSeed *= getBonusByType(_spaceshipType);
    
    return travelSpeedRange.first * getBonusByType(_spaceshipType) + randomSeed;
    
}

/* get a random cargoCapacity */
int SpaceshipType::getRandomCargoCapacityBySpaceshipType(int _spaceshipType){
    int randomSeed = GameTimer::_rand() % (cargoCapacityRange.second - cargoCapacityRange.first);
    randomSeed *= getBonusByType(_spaceshipType);
    
    return cargoCapacityRange.first * getBonusByType(_spaceshipType) + randomSeed;
}

/* get a random prestige */
int SpaceshipType::getRandomPrestigeBySpaceshipType(int _spaceshipType){
    
    int randomSeed = GameTimer::_rand() % (prestigeRange.second - prestigeRange.first);
    randomSeed *= getBonusByType(_spaceshipType);
    
    return prestigeRange.first * getBonusByType(_spaceshipType) + randomSeed;
}

/* get a random travelAvgFuelConsumption*/
int SpaceshipType::getRandomTravelAvgFuelConsumption(int _spaceshipType){
    
    return _spaceshipType * GameTimer::getRandomByRange(travelAvgFuelConsumptionRange);
    
}

/* get a random travelAvgFoodConsumption */
int SpaceshipType::getRandomTravelAvgFoodConsumption(int _spaceshipType){
    
    return _spaceshipType * GameTimer::getRandomByRange(travelAvgFoodConsumptionRange);
    
    
}

/* a init HP of a spaceship by it's type */
int SpaceshipType::getSpaceshipHpBySpaceshipType(int _spaceshipType){
    
    return _spaceshipType * spaceshipHPBase;
    
}

/* Engineering Aptitude*/
int SpaceshipType::getRandomEngineeringAptitude(int _spaceshipType){
    
    return _spaceshipType * GameTimer::getRandomByRange(engineeringAptitudeRange);
}






#endif

