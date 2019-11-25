//
//  SpaceShipDAO.hpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/20.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef SpaceShipDAO_cpp
#define SpaceShipDAO_cpp

#include "../entity/SpaceShip.cpp"
#include "../util/GameLogger.cpp"
#include "../conf/RumtimeParameter.cpp"
#include "../util/GameTimer.cpp"

/*
 
 this class aim to grand a spaceship (our spaceship), and do some data opreation

 hold a static pointer of spaceship for operating the same spaceship during the runtime
 
 */

class SpaceShipDAO{

    public :
    
    static SpaceShip *mySpaceShip;

    
    static void setSpaceShip(SpaceShip *_myShpaceShip){
        
        mySpaceShip = _myShpaceShip;

        return;
    }
    
    
    
    // ------------------ for data operatation spaceship of mySpaceShip --------------------
    
    
    
    //  ----------------------------------- change data operation -----------------------------
    // increase the prestige of mySpaceShip
    void incPrestige(int _inc){
        
        // std::cout << "In DAO" <<mySpaceShip->getPrestige() << std::endl;
        
        mySpaceShip->setPrestige(mySpaceShip->getPrestige()+_inc);
        
        // std::cout << "In DAO" << mySpaceShip->getPrestige() << std::endl;

        return;
    }
    
    
    //  ----------------------- for Resource ------------
    // increase the left money to += _inc
    void incResourceMoney(double _inc){
        
        mySpaceShip->getResource().setleftMoney(mySpaceShip->getResource().getLeftMoney() + _inc);
        
    }
    
    void decResourceMoney(double _Moneydec){
        
        mySpaceShip->getResource().setleftMoney(mySpaceShip->getResource().getLeftMoney() - _Moneydec);
        
    }
    
    void incResourceGoods(double _inc){
        
        mySpaceShip->getResource().setLeftGoods(mySpaceShip->getResource().getTradableGoods() + _inc);
        
    }
    
    /* dec the left Goods to -= dec */
    void decResourceGoods(double _dec){
        
        mySpaceShip->getResource().setLeftGoods(mySpaceShip->getResource().getTradableGoods() - _dec);
        
    }
    
    
    void incResourceFood(double _foodInc){
        
        mySpaceShip->getResource().setLeftFood(mySpaceShip->getResource().getLeftFood() + _foodInc);
        
    }
    
    void decResourceFood(double _foodDes){
        
        mySpaceShip->getResource().setLeftFood(mySpaceShip->getResource().getLeftFood() - _foodDes);
        
    }
    
    void incResourceFuel(double _fuelInc){
        
        mySpaceShip->getResource().setLeftFuel(mySpaceShip->getResource().getLeftFuel() + _fuelInc);
        
    }
    
    void decResourceFuel(double _fuelDes){
        
        mySpaceShip->getResource().setLeftFuel(mySpaceShip->getResource().getLeftFuel() - _fuelDes);

    }
    
    
    //  ----------------------- for TotCrewMember ------------
    
    void incTotCrewMember(int _inc){
        
        mySpaceShip->setTotCrewNumber(mySpaceShip->getTotCrewNumber() + _inc);
        
    }
    
    void decTotCrewMember(int _dec){
        
        mySpaceShip->setTotCrewNumber(mySpaceShip->getTotCrewNumber() - _dec);

    }
    
    //  ----------------------- for  combatAptitude ------------
    void incCombatAptitude(int _inc){
        
        mySpaceShip->setCombatAptitude(mySpaceShip->getCombatAptitude() + _inc);
        
    }

    
    void DecCombatAptitude(int _dec){
        
        mySpaceShip->setCombatAptitude(mySpaceShip->getCombatAptitude() - _dec);
        
    }
    
    //  ----------------------- for defenseAptitude
    
    void incDefenseAptitude(int _inc){
        
        mySpaceShip->setDefenseAptitude(mySpaceShip->getDefenseAptitude() + _inc);
        
    }
    
    void decDefenseAptitude(int _dec){
        
        mySpaceShip->setDefenseAptitude(mySpaceShip->getDefenseAptitude() - _dec);
        
    }
    
    
    
    //  ----------------------- for travel speed ------------
    
    void incTravelSpped(int _inc){
        
        mySpaceShip->setTravelSpeed(mySpaceShip->getTravelSpeed() + _inc);
        
    }
    
    
    //  ----------------------- for Food Avg Cons  ------------

    void decTravelFoodAvgCons(int _dec){
        
        
        int curentFoodCons = mySpaceShip->getTravelAvgFoodConsumption() - _dec;
        
        /* must larger then 0 */
        curentFoodCons = curentFoodCons > 0 ? curentFoodCons : 0;
        
        mySpaceShip->setTravelAvgFoodConsumption(curentFoodCons);
    }
    
    
    
    //  ----------------------- for Fuel Avg Cons  ------------

    void decTravelFuelAvgCons(int _dec){
        
        int currentFuelCons = mySpaceShip->getTravelAvgFuelConsumption() - _dec;
        
        /* must larger then 0 */
        currentFuelCons = currentFuelCons > 0 ? currentFuelCons : 0;
        
        mySpaceShip->setTravelAvgFuelConsumption(currentFuelCons);
    }
    
    
    // ------------------------- for HP -------------------
    
    void incSpaceshipHP(int _inc){
        
        mySpaceShip->setSpaceshipHP(mySpaceShip->getSpaceshipHP() + _inc);
        
    }
    
    void decSpaceshipHP(int _dec){
        
        mySpaceShip->setSpaceshipHP(mySpaceShip->getSpaceshipHP() - _dec);

        
    }
    

    
    
    //  ----------------------- for OrdcrewMembers ------------

    /* For recruit */
    void addOrdCrew(CrewMember crewMember){
        
        mySpaceShip->addOrdCrewMember(crewMember);
        
        /* crew number plus 1 */
        incTotCrewMember(1);
    }
    
    /* add officer */
    void addOfficer(Officer officer){
        mySpaceShip->addOfficer(officer);
        incTotCrewMember(1);
    }
    
    
    /* remove one ordCrew */
    CrewMember removeOneOrdCrew(){
        
        decTotCrewMember(1);

        return mySpaceShip->removeOneOrdCrew();
    }
    
    /* remove one officer */
    Officer removeOneOfficer(){
        
        decTotCrewMember(1);

        return mySpaceShip->removeOneOfficer();
        
    }
    
    
    
    /* get the last ordcrew in spaceship*/
    CrewMember getLastOrdCrew(){
        
        std::vector<CrewMember> tmpCrewMember = mySpaceShip->getOrdCrewMembers();
        long length = tmpCrewMember.size();
        
        return tmpCrewMember[length - 1];
    }
    
    
    /* random consume resource*/
    void consumeResource(){
        
        
        /* food */
        int reduceFood = GameTimer::getRandomByRange(RuntimeParameter::RESOURCE_CONSUME_RANGE);
        decResourceFood(reduceFood);
        
        /* fuel */
        int reduceFuel = GameTimer::getRandomByRange(RuntimeParameter::RESOURCE_CONSUME_RANGE);
        decResourceFuel(reduceFuel);
        
        GameLogger::stdOut("In this round travel you have lost food : " + std::to_string(reduceFood));
        GameLogger::stdOut("In this round travel you have lost fuel : " + std::to_string(reduceFuel));

    }
    
    
    
    
    
    //  ----------------------------------- query data operation -----------------------------
    bool existOfficer(std::string abilityName){
        
        int abilityType = Abilities::abilityToInteger(abilityName);
        
        std::vector<Officer> myOfficers = mySpaceShip->getofficers();
        std::vector<Officer>::iterator it = myOfficers.begin();
        
        // reseraval
        while(it != myOfficers.end()){
            
            if(it->getAbilityType() == abilityType){
                return true;
            }
            it++;
        }
        
        return false;
        
        
    }
    
    int getSpaceShipHP(){
        
        return mySpaceShip->getSpaceshipHP();
        
    }
    
    int getSpaceShipType(){
        
        return mySpaceShip->getSpaceShipType();
        
    }
    
    int getSpaceDefense(){
        
        return mySpaceShip->getDefenseAptitude();
        
    }
    
    
    
    
    double getLeftMoney(){
        
        return mySpaceShip->getResource().getLeftMoney();
    }
    
    double getLeftGoods(){
        
        return mySpaceShip->getResource().getTradableGoods();
        
    }
    
    double getLeftFuel(){
        return mySpaceShip->getResource().getLeftFuel();
    }
    
    double getLeftFood(){
        return mySpaceShip->getResource().getLeftFood();
    }
    
    int getCombatAptitude(){
        
        return mySpaceShip->getCombatAptitude();
        
    }
    
    int getPrestige(){
        return mySpaceShip->getPrestige();
    }
    
    
    int getOrdCrewNumber(){
        
        return (int)mySpaceShip->getOrdCrewMembers().size();
        
    }
    
    int getOfficerNumber(){
        
        return (int)mySpaceShip->getofficers().size();
        
    }


    /* print repory */
    void getReport(){
        
        GameLogger::stdOut("");
        GameLogger::stdOut("********** report **********");
        GameLogger::stdOut("Left HP : " + std::to_string(getSpaceShipHP()));
        GameLogger::stdOut("left Food : " + std::to_string(getLeftFood()));
        GameLogger::stdOut("Left Fuel : " + std::to_string(getLeftFuel()));
        GameLogger::stdOut("current Prestige: " + std::to_string(getPrestige()));
        GameLogger::stdOut("current Combat Aptitude: " + std::to_string(getCombatAptitude()));
        GameLogger::stdOut("current Defense: " + std::to_string(getSpaceDefense()));
        GameLogger::stdOut("current Crew numbers: " + std::to_string(getOrdCrewNumber()));
        GameLogger::stdOut("current officers numbers: " + std::to_string(getOfficerNumber()));
        GameLogger::stdOut("********** report **********");
        GameLogger::stdOut("");
    }

};
SpaceShip* SpaceShipDAO::mySpaceShip = NULL;


#endif /* SpaceShipDAO_hpp */
