//
//  SpaceshipFactory.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/21.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _SpaceshipFactory
#define _SpaceshipFactory

#include "../entity/SpaceShip.cpp"
#include "../conf/SpaceshipType.cpp"
#include "../util/GameLogger.cpp"
/*
 
    A factory of spaceship
 
    this class for prodruce a spaceship
 
 */
class SpaceshipFactory{
    
    
    private :
    
    // -----------------------  init paramter set up    --------------
    
    // for init resource
    double const init_base_resource_leftMoney = 100;
    double const init_base_resource_leftFuel = 500;
    double const init_base_resource_leftGoods = 100;
    double const init_base_resource_leftFoods = 500;
    
    // for init crew number officer and ordcrew
    int const init_base_officer_number = 5;
    int const init_base_ordCrew_number = 10;
    
    // for init the combatAptitude
//    int const init_base_combatAptitude = 10;
//
//    // for init the mineAptitude
//    int const init_base_mineAptitude = 10;
//
//    // for init the travelSpeed
//    int const init_base_travelSpeed = 10;
//
//    // for init the init Capacity
//    int const init_base_cargoCapacity = 10;
//
//    // for init the prestige
//    int const init_base_prestige = 10;
    
    
    public :
    
    /* build a spaceship */
    /*
        five type can be choosen in a spaceship to build
     */
    SpaceShip buileSpaceship(int _spaceshipType, int _spaceshipCiv){
        
        int bonus = SpaceshipType::getBonusByType(_spaceshipType);
        
        double init_resource_leftMoney = bonus * init_base_resource_leftMoney;
        double init_resource_leftFuel = bonus * init_base_resource_leftFuel;
        double init_resource_leftGoods = bonus * init_base_resource_leftGoods;
        double init_resource_leftFoods = bonus * init_base_resource_leftFoods;
        
        
        // init resource
        Resource initResource(init_resource_leftFoods, init_resource_leftFuel, init_resource_leftMoney, init_resource_leftGoods);
        
        // build
        SpaceShip spaceShip;
        
        // set resource
        spaceShip.setResource(initResource);
        
        // set type
        spaceShip.setSpaceShipType(_spaceshipType);

        // init officers and ord crew
        int init_officer_number = bonus * init_base_officer_number;
        int init_ordcrew_number = bonus * init_base_ordCrew_number;
        spaceShip.setTotCrewNumber(init_officer_number + init_ordcrew_number);
        
        // init the ability this spaceship have
        // different civ have different ability
        std::vector<std::string> Init_Ability = SpaceshipType::getInitAbility(_spaceshipCiv);
        long init_Ability_length = Init_Ability.size();
        
        /* add officer to this spaceship */
        for(int i=0; i<init_officer_number; i++){
            
            Officer tmpOfficer;
            // set name, age
            // set abilityType
            // set abilityDegree
            tmpOfficer.setCrewId(i);
            tmpOfficer.setName(SpaceshipType::getRandomOfficerName());
            tmpOfficer.setAge(SpaceshipType::getRandomOfficerAge());
            tmpOfficer.setAbilityType(Abilities::abilityToInteger(Init_Ability[i%init_Ability_length]));
            tmpOfficer.setAbilityDegree(SpaceshipType::getRandomAbilityDegree());
            
            // insert into spaceship
            spaceShip.addOfficer(tmpOfficer);
        }
        
        
        /* add ord crew member to this spaceship*/
        for(int i=0; i<init_ordcrew_number; i++){
            
            CrewMember tmpCrewMember;
            tmpCrewMember.setCrewId(i);
            
            // insert
            spaceShip.addOrdCrewMember(tmpCrewMember);
        }
        
        /*
         set :
         int combatAptitude;
         int mineAptitude;
         int travelSpeed;
         int cargoCapacity;
         int prestige;
         
         int travelAvgFuelConsumption;
         int travelAvgFoodConsumption;
         
         int spaceshipHP
         int engineeringAptitude
         */
        int combatAptitude = SpaceshipType::getRandomCombatAptitudeBySpaceshipType(_spaceshipType);
        int mineAptitude = SpaceshipType::getRandomMineAptitudeBySpaceshipType(_spaceshipType);
        int travelSpeed  = SpaceshipType::getRandomTravelSpeedBySpaceshipType(_spaceshipType);
        int cargoCapacity = SpaceshipType::getRandomCargoCapacityBySpaceshipType(_spaceshipType);
        int prestige = SpaceshipType::getRandomPrestigeBySpaceshipType(_spaceshipType);
        int travelAvgFoodCons = SpaceshipType::getRandomTravelAvgFoodConsumption(_spaceshipType);
        int travelAvgFuelCons = SpaceshipType::getRandomTravelAvgFuelConsumption(_spaceshipType);
        int spaceshipHP = SpaceshipType::getSpaceshipHpBySpaceshipType(_spaceshipType);
        int engineeringAptitude = SpaceshipType::getRandomEngineeringAptitude(_spaceshipType);
        int defenseAptitude = SpaceshipType::getRandomDefenseAptitudeBySpaceshipType(_spaceshipType);
        
        spaceShip.setCombatAptitude(combatAptitude);
        spaceShip.setMineAptitude(mineAptitude);
        spaceShip.setTravelSpeed(travelSpeed);
        spaceShip.setCargoCapacity(cargoCapacity);
        spaceShip.setPrestige(prestige);
        spaceShip.setTravelAvgFoodConsumption(travelAvgFoodCons);
        spaceShip.setTravelAvgFuelConsumption(travelAvgFuelCons);
        spaceShip.setSpaceshipHP(spaceshipHP);
        spaceShip.setEngineeringAptitude(engineeringAptitude);
        spaceShip.setDefenseAptitude(defenseAptitude);
        
        return spaceShip;
    }
    
    
    
};

#endif
