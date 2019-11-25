//
//  MiningActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/20.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _MiningActivity
#define _MiningActivity

#include "Activity.cpp"


/*
 
    The activity with mining resourcr
 
 1. Need Ability : Mining
 2. effect : increase crewMember (ordCrew), increase food, increase fuel, Goods
 */

class MiningActivity : public Activity{
    
    
    
    
    private :
    
    std::pair<int, int> incCrewNumberRange;
    std::pair<int, int> incFoodRange;
    std::pair<int, int> incFuelRange;
    std::pair<int, int> incGoodsRange;
    int mineAptitude;
    
    public :
    
    // constructor
    MiningActivity(){
        
        // init
        incCrewNumberRange = RuntimeParameter::MINING_CREW_RANGE;
        incFoodRange = RuntimeParameter::MINING_FOODS_RANGE;
        incFuelRange = RuntimeParameter::MINING_FUEL_RANGE;
        incGoodsRange = RuntimeParameter::MINING_GOODS_RANGE;
        
        // needs mining ability
        NEED_ABILITES.push_back(Abilities::ABILITY_MINING);
    }
    
    
    void start(SpaceShip &spaceShip){
        
        if(!activityAbilityOK(spaceShip)) {
            GameLogger::stdOut("Sorry, you do not have ability to mine");
            return;
        }
        
        /* set up the mineAptitude of this spaceShip*/
        mineAptitude = spaceShip.getMineAptitude();
        
        /* recruitCrew */
        recruitCrew();
        
        /* make food */
        makeFood();
        
        /* mine fuel*/
        mineFuel();
        
        /* make goods */
        makeGoods();
        
    }
    
    /* inc the crew number according to the mineAptitude */
    void recruitCrew(){
        
        /* inc number */
        int incRecruitNumber = GameTimer::getRandomByRange(incCrewNumberRange) * mineAptitude;
        
        /* inc */
        CrewMember lastCrewMember = spaceShipDAO.getLastOrdCrew();
        int lastID = lastCrewMember.getCrewId();
        int newID = lastID;
        /* recruit tot number randomSeed ordCrew */
        while(incRecruitNumber > 0){
            CrewMember newRecruitCre;
            
            /* recruit */
            newRecruitCre.setCrewId(++newID);
            spaceShipDAO.addOrdCrew(newRecruitCre);

            incRecruitNumber--;
        }
        
        GameLogger::stdOut("Congratulations !! you have new recruit :" + std::to_string(newID-lastID) + " crewman");
    }
    
    /* make Food*/
    void makeFood(){
        
        int incFood = GameTimer::getRandomByRange(incGoodsRange) * mineAptitude;
        
        /* make food */
        spaceShipDAO.incResourceFood(incFood);
        
        GameLogger::stdOut("Congratulations !! you have made :" + std::to_string(incFood) + " food");
    }
    
    /* mine fuel */
    void mineFuel(){
        
        int incFuel = GameTimer::getRandomByRange(incFuelRange) * mineAptitude;
        
        /* mine fuel */
        spaceShipDAO.incResourceFuel(incFuel);
        
        GameLogger::stdOut("Congratulations !! you have mine :" + std::to_string(incFuel) + " fuel");
    }
    
   /* make Goods */
   void makeGoods(){
       
       int incGoods = GameTimer::getRandomByRange(incGoodsRange) * mineAptitude;
       
       /* mine fuel */
       spaceShipDAO.incResourceGoods(incGoods);
       
       GameLogger::stdOut("Congratulations !! you have made :" + std::to_string(incGoods) + " Goods");
   }
    
    
    
    
    
};





#endif


