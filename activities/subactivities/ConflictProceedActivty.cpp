//
//  ConflictProceedActivty.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/23.
//  Copyright © 2019年 ark. All rights reserved.
//
#ifndef _ConflictProceedActivty
#define _ConflictProceedActivty



#include "../Activity.cpp"

/*
 
    for the conflict proceed
 
    1. 
 
 */
class ConflictProceedActivty : public Activity{
    
    
    
    private :
        
        SpaceShip Alien;
    
    
    public :
    
    /* constructor */
    ConflictProceedActivty(){
        

    }
    
    
    void start(){
        
        
        /* init alien */
        initAlien();
        
        /* start conflict */
        startConflict();
        
        
        
        
        
    }
    
    void initAlien(){
        
        SpaceshipFactory spaceshipFactory;
        
        int AlienType = SpaceshipType::getRandomSpaceshipType();
        int AlienCiv = SpaceshipType::getRandomAlienSpaceshipCiv();
        
        /* alien comes !!!*/
        Alien = spaceshipFactory.buileSpaceship(AlienType, AlienCiv);
        GameLogger::stdOut("Opps, you encounter the alien !!! which is : " + SpaceshipType::getSpaceshipCivByType(AlienCiv));
    }
    
    
    
    void startConflict(){
        
        /* Alien */
        int alienCombatAptitude = Alien.getCombatAptitude();
        int myCombatAptitude = spaceShipDAO.getCombatAptitude();
        
        if(myCombatAptitude > alienCombatAptitude){
            // win
            winConflict();
            GameLogger::stdOut("You win in a conflict");
        }else{
            // fail
            failConflict();
            GameLogger::stdOut("You fail in a conflict");
        }
        
        return;   
    }
    
    /* win in this conflict */
    void winConflict(){
        
        /* acquire food, fuel, goods */
        
        /* food */
        std::pair<int, int> acquireFoodRange = std::pair<int, int>(0, Alien.getResource().getLeftFood());
        
        /* fuel */
        std::pair<int, int> acquireFuelRange = std::pair<int, int>(0, Alien.getResource().getLeftFuel());
        
        /* goods */
        std::pair<int, int> acquireGoodsRange = std::pair<int, int>(0, Alien.getResource().getTradableGoods());
        
        /* our Trophy */
        int acquireFood = GameTimer::getRandomByRange(acquireFoodRange);
        int acquireFuel = GameTimer::getRandomByRange(acquireFuelRange);
        int acquireGoods= GameTimer::getRandomByRange(acquireGoodsRange);
        spaceShipDAO.incResourceFood(acquireFood);
        spaceShipDAO.incResourceFuel(acquireFuel);
        spaceShipDAO.incResourceGoods(acquireGoods);
        
        /* inc our Prestige */
        std::pair<int, int> acquirePrestigeRange = std::pair<int, int>(0, Alien.getPrestige());
        int acquirePrestige = GameTimer::getRandomByRange(acquirePrestigeRange);
        spaceShipDAO.incPrestige(acquirePrestige);
        
        /* inc our combatAptitude*/
        std::pair<int, int> acquireCombatAptitudeRange = std::pair<int, int>(0, Alien.getCombatAptitude());
        int acquireCombatAptitude = GameTimer::getRandomByRange(acquireCombatAptitudeRange);
        spaceShipDAO.incCombatAptitude(acquireCombatAptitude);
        
    }
    
    /* fail in this conflict*/
    void failConflict(){
        
        /* lost food, fuel, goods */
        /* food */
        std::pair<int, int> lostFoodRange = std::pair<int, int>(0, spaceShipDAO.getLeftFood());
        
        /* fuel */
        std::pair<int, int> lostFuelRange = std::pair<int, int>(0, spaceShipDAO.getLeftFuel());
        
        /* goods */
        std::pair<int, int> lostGoodsRange = std::pair<int, int>(0, spaceShipDAO.getLeftGoods());
        
        int lostFood = GameTimer::getRandomByRange(lostFoodRange);
        int lostFuel = GameTimer::getRandomByRange(lostFuelRange);
        int lostGoods= GameTimer::getRandomByRange(lostGoodsRange);
        
        
        /* dec */
        spaceShipDAO.decResourceFood(lostFood);
        spaceShipDAO.decResourceFuel(lostFuel);
        spaceShipDAO.decResourceGoods(lostGoods);
        
        
    }
    
    
};



#endif
