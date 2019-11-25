//
//  TravelEfficiency.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/23.
//  Copyright © 2019年 ark. All rights reserved.
//
#ifndef _TravelEfficiencyActivity
#define _TravelEfficiencyActivity

#include "Activity.cpp"

/*
    this class is for upgrad the travel efficiency my spaceship
 */
class TravelEfficiencyActivity : public Activity{
    
    
    private :
    std::pair<int, int> travelSpeedUpgradRange;
    std::pair<int, int> travelFuelUpgradRange;
    std::pair<int, int> travelFoodUpgradRange;
    
    
    
    public :
    
    /* constructor */
    TravelEfficiencyActivity(){
        
        
        // range def
        travelSpeedUpgradRange = RuntimeParameter::TRAVELEFF_SPEED_UPGREADING_RANGE;
        travelFuelUpgradRange = RuntimeParameter::TRAVELEFF_FUEL_UPGREADING_RANGE;
        travelFoodUpgradRange = RuntimeParameter::TRAVELEFF_FOOD_UPGREADING_RANGE;
    
        
        // needs ability
        NEED_ABILITES.push_back(Abilities::ABILITY_PILOT);
        NEED_ABILITES.push_back(Abilities::ABILITY_ENGINEERING);
    }
    
    /* start upgrad */
    void start(SpaceShip &spaceShip){
        
        if(!activityAbilityOK(spaceShip)){
            GameLogger::stdOut("You do not have ability to upgrad your travel efficiency !");
            return;
        }
        
        
        /* upgrad travel speed */
        accelerationSpaceship();
        
        /* reduce the cons food */
        reduceFoodAvgCons();
        
        /* redcue the cons fuel */
        reduceFuelAvgCons();
        
        GameLogger::stdOut("You have Travel Efficiency successfully !!");
    }
    
    /* acceleration Spaceship */
    void accelerationSpaceship(){
        
        int acceSpeed = GameTimer::getRandomByRange(travelSpeedUpgradRange);
        
        spaceShipDAO.incTravelSpped(acceSpeed);
        
        GameLogger::stdOut("your travel speed have been upgrad for : " + std::to_string(acceSpeed) + " lightYear/Year");
    }
    
    
    /* reduce the food Avg cons*/
    void reduceFoodAvgCons(){
        
        int reduceAvgFoodCon = GameTimer::getRandomByRange(travelFoodUpgradRange);
        
        spaceShipDAO.decTravelFoodAvgCons(reduceAvgFoodCon);
        
        GameLogger::stdOut("your avg food consume have been reduce for : " + std::to_string(reduceAvgFoodCon) );
    }
    
    
    /* reduce the fuel avg cons */
    void reduceFuelAvgCons(){
        
        int reduceAvgFuelCon = GameTimer::getRandomByRange(travelFuelUpgradRange);
        
        spaceShipDAO.decTravelFuelAvgCons(reduceAvgFuelCon);
        
        GameLogger::stdOut("your avg food consume have been reduce for : " + std::to_string(reduceAvgFuelCon) );
        
    }
    
    
   
};

#endif
