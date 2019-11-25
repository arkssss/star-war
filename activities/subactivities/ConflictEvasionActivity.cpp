//
//  ConflictEvasionActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/23.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _ConflictEvasionActivity
#define _ConflictEvasionActivity


#include "../Activity.cpp"


/*
    evasion in a conflict
 
    1. Only a little loss : fuel, food.
 
 */
class ConflictEvasionActivity : public Activity{
    
    
    private :
    
    std::pair<int, int> FUEL_LOSS_RANGE;

    std::pair<int, int> FOOD_LOSS_RANGE;
    
    
    
    
    public :
    
    /* contructor */
    ConflictEvasionActivity(){
        
        FUEL_LOSS_RANGE = RuntimeParameter::CONFLICT_EVASION_FUEL_LOSS_RANGE;
        FOOD_LOSS_RANGE = RuntimeParameter::CONFLICT_EVASION_FOOD_LOSS_RANGE;
    }
    
    void start(){
        
        /* fuel */
        fuelLoss();
        /* food */
        fuelLoss();
        
        
        GameLogger::stdOut("evasion successful in a conflict, be careful next time");
    }
    
    
    void fuelLoss(){
        
        int leftFuel = spaceShipDAO.getLeftFuel();
        int evasionLossFuel = GameTimer::getRandomByRange(FUEL_LOSS_RANGE);
        
        /* loss fuel must small then the left */
        int actFuelLoss = leftFuel > evasionLossFuel ? evasionLossFuel: leftFuel;
        
        
        /* fuel loss */
        spaceShipDAO.decResourceFuel(actFuelLoss);
        
        GameLogger::stdOut("Thanks God, you evasion successful in a conflict, you just loss fuel : "+ std::to_string(actFuelLoss) );
        
    }
    
    void foodLoss(){
        
        int leftFood = spaceShipDAO.getLeftFood();
        int evasionLossFood = GameTimer::getRandomByRange(FOOD_LOSS_RANGE);
        
        /* loss fuel must small then the left */
        int actFoodLoss = leftFood > evasionLossFood ? evasionLossFood: leftFood;
        
        
        /* fuel loss */
        spaceShipDAO.decResourceFood(actFoodLoss);
        
        GameLogger::stdOut("Thanks God, you evasion successful in a conflict, you just loss food : "+ std::to_string(actFoodLoss) );
    }
    
    
    
};

#endif
