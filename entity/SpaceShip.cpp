//
//  SpaceShip.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _SpaceShip
#define _SpaceShip



#include "Resource.cpp"
#include "Officer.cpp"
#include <vector>
/**
 
 class for a spaceship
 
 */
class SpaceShip{
    
    private :
    // -------------    the followings are the attributes needed to be initizaled    --------------
    // tot number of this crew
    int totCrewNumber;
    
    // current left resource, if it becomes to 0, then game over
    Resource leftResource;
    
    // group for officer
    std::vector<Officer> officers;
    
    // ordinary member
    std::vector<CrewMember> ordMembers;
    
    /* the type of spaceShip*/
    int spaceShipType;
    
    // init the arracker degree
    int combatAptitude;
    
    // init the defense degree
    int defenseAptitude;
    
    // init mining aptitude
    int mineAptitude;
    
    // init Capacity
    int cargoCapacity;
    
    // init prestige
    int prestige;
    
    //  Avg Fuel Consumption for travel one day
    int travelAvgFuelConsumption;
    
    //  Avg Food Consumption for travel one day
    int travelAvgFoodConsumption;
    
    // init speed of this ship
    int travelSpeed;
    
    // HP
    int spaceshipHP;
    
    // the engineering degree for this ship
    int engineeringAptitude;
    
    // -------------    the upon are the attributes needed to be initizaled    --------------
    public :
    
    
    // constructer
    SpaceShip(){
        
    }
    // ------------------------- getter and setter ----------------
    
    
    
    void setResource(Resource _resource){
        leftResource = _resource;
    }
    
    Resource& getResource(){
        
        return leftResource;
        
    }
    
    // init the defense degree
    
    
    int getDefenseAptitude(){
        
        return defenseAptitude;
        
    }
    void setDefenseAptitude(int _defenseAptitude){
        defenseAptitude = _defenseAptitude;
    }
    
    
    //  Avg Fuel Consumption for travel one day
    int getTravelAvgFuelConsumption(){
        return travelAvgFuelConsumption;
    }
    void setTravelAvgFuelConsumption(int _travelAvgFuelConsumption){
        travelAvgFuelConsumption = _travelAvgFuelConsumption;
    }
    
    
    //  Avg Food Consumption for travel one day
    int getTravelAvgFoodConsumption(){
        return travelAvgFoodConsumption;
    }
    void setTravelAvgFoodConsumption(int _travelAvgFoodConsumption){
        travelAvgFoodConsumption = _travelAvgFoodConsumption;
    }
    
    // the engineering degree for this ship
    int getEngineeringAptitude(){
        return engineeringAptitude;
    }
    
    void setEngineeringAptitude(int _engineeringAptitude){
        engineeringAptitude = _engineeringAptitude;
    }
    
    /* the type of spaceShip*/
    void setSpaceShipType(int _spaceShipType){
        spaceShipType = _spaceShipType;
    }
    int getSpaceShipType(){
        return spaceShipType;
    }
    
    
    
    // HP
    int getSpaceshipHP(){
        return spaceshipHP;
    }
    
    void setSpaceshipHP(int _spaceshipHP){
        spaceshipHP = _spaceshipHP;
    }
    
    
    
    //    int combatAptitude;
    int getCombatAptitude(){
        return combatAptitude;
    }
    
    void setCombatAptitude(int _combatAptitude){
        combatAptitude = _combatAptitude;
    }
    

    //    int mineAptitude;
    int getMineAptitude(){
        return mineAptitude;
    }
    void setMineAptitude(int _mineAptitude){
        mineAptitude = _mineAptitude;
    }
    
    
    //   int travelSpeed;
    int getTravelSpeed(){
        return travelSpeed;
    }
    void setTravelSpeed(int _travelSpeed){
        travelSpeed = _travelSpeed;
    }
    

    //  int cargoCapacity;
    int getCargoCapacity(){
        return cargoCapacity;
    }
    void setCargoCapacity(int _cargoCapacity){
        cargoCapacity = _cargoCapacity;
    }
    
    int getPrestige(){
        return prestige;
    }
    
    void setPrestige(int _prestige){
        
        prestige = _prestige;
    
    }
    
    int getTotCrewNumber(){
        
        return totCrewNumber;
        
    }
    
    void setTotCrewNumber(int _totCrewNumber){
        
        totCrewNumber = _totCrewNumber;
        
    }
    
    
    std::vector<Officer> getofficers(){
        
        return officers;
        
    }
    
    std::vector<CrewMember> getOrdCrewMembers(){
        
        return ordMembers;
        
    }
    
    void addOfficer(Officer _officer){
        
        officers.push_back(_officer);
    }
    
    Officer removeOneOfficer(){
        
        Officer deadOfficer = officers[officers.size() - 1];
        officers.pop_back();
        
        return deadOfficer;
    }
    
    CrewMember removeOneOrdCrew(){
        
        CrewMember deadCrewMember = ordMembers[ordMembers.size() - 1];
        ordMembers.pop_back();
        
        return deadCrewMember;
    }
    
    
    void addOrdCrewMember(CrewMember _crewMember){
        ordMembers.push_back(_crewMember);
    }
    
    // ------------------------- getter and setter ----------------

    
    
    
    
    
    //  ---------------------- helper function -----------------
    //  ---------------------- this part have been moved to the DAO -----------------
    
    
    
    
    
    
};

#endif
