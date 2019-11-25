//
//  TradingActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/20.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _TradingActivity
#define _TradingActivity

#include "Activity.cpp"

/*
    The Activity when Trading happen
    1. Need ability : Captain
    2. Money buy all : food and fuel
    3. tradable good sales becomes money
 */
class TradingActivity : public Activity{
    
    private:
    
    
    /* every deal has a limit */
    
    /* the range for buying food in this plane */
    std::pair<int, int> buyingFoodLimitRange;
    
    /* the range for buying fuel in this plane */
    std::pair<int, int> buyingFuelLimitRange;
    
    /* the range for saling goods to money */
    std::pair<int, int> salingGoodsLimitRange;
    
    
    
    
    public :
    
    TradingActivity(){
        
        // range
        buyingFoodLimitRange = RuntimeParameter::TRADING_BUYING_FOOD_LIMIT_RANGE;
        buyingFuelLimitRange = RuntimeParameter::TRADING_BUYING_FUEL_LIMIT_RANGE;
        salingGoodsLimitRange= RuntimeParameter::TRADING_SALING_GOODS_LIMIT_RANGE;
        
        
        // init
        NEED_ABILITES.push_back(Abilities::ABILITY_CAPTAIN);
        
        
        
        
    }
    
    
    void start(SpaceShip &spaceShip){
        
        
        
        // check if can trade
        if(!TradingOK(spaceShip)) {GameLogger::stdOut("Sorry you cannot trading at this time!!"); return;}
        
        /* sale goods */
        salingGoods(spaceShip);
        
        /* buying food*/
        buyingFoods(spaceShip);
        
        /* buying fuel*/
        buyingFuel(spaceShip);
        
        
        return;
    }
    
    
    //------------------ helper func --------------
    void salingGoods(SpaceShip &spaceShip){
        
        int salingGoodsLimit = GameTimer::getRandomByRange(salingGoodsLimitRange);
        double leftGoods = spaceShipDAO.getLeftGoods();
        
        
        if(leftGoods > 0){
        
            
            /* acording to the law, the sale goods must small then the limit !!!*/
            double saleGoods = leftGoods > salingGoodsLimit ? salingGoodsLimit : leftGoods;
            
            /* earn money */
            double getMoney = ExchangeRate::buyingMoneyByGoods(saleGoods);
            
            /* sale */
            spaceShipDAO.incResourceMoney(getMoney);
            spaceShipDAO.decResourceGoods(saleGoods);
            
            
            GameLogger::stdOut("Saling Goods Success");
            GameLogger::stdOut("you have saled Goods : " + std::to_string(saleGoods));
            GameLogger::stdOut("you have earned money : " + std::to_string(getMoney));
        }else{
            
            GameLogger::stdOut("Sorry you don't have Goods to sale");
            
        }
        
        
        
    }
    

    void buyingFoods(SpaceShip &spaceShip){
        
        int buyingFoodLimit = GameTimer::getRandomByRange(buyingFoodLimitRange);
        int leftMoney = spaceShipDAO.getLeftMoney();
        
        if(leftMoney > 0){
            
            /* random buying */
            int planSpeedMoney = GameTimer::getRandomByRange(std::pair<int, int>(0, leftMoney));
            
            /* plan buying food*/
            int planBuyingFood = ExchangeRate::buyingFoodByMoney(planSpeedMoney);
            
            /* law */
            int actBuyingFood = planBuyingFood < buyingFoodLimit ? planBuyingFood : buyingFoodLimit;
            
            /* actual spend money*/
            int actSpendMoney = ExchangeRate::buyingMoneyByFoods(actBuyingFood);
            
            /* start buying */
            spaceShipDAO.decResourceMoney(actSpendMoney);
            spaceShipDAO.incResourceFood(actBuyingFood);
            
            /* log */
            GameLogger::stdOut("buying food Success");
            GameLogger::stdOut("you have spend money : " + std::to_string(actSpendMoney));
            GameLogger::stdOut("you have earned food : " + std::to_string(actBuyingFood));
            
        }else{
            
            GameLogger::stdOut("sorry you don't have money to buy food");
            
        }
        
        
    }
    
    void buyingFuel(SpaceShip &spaceShip){
        
        
        int buyingFuelLimit = GameTimer::getRandomByRange(buyingFuelLimitRange);
        int leftMoney = spaceShipDAO.getLeftMoney();
        
        if(leftMoney > 0){
            
            /* buying */
            int planSpeedMoney = leftMoney;
            
            /* plan buying fuel*/
            int planBuyingFuel = ExchangeRate::buyingFuelBYMoney(planSpeedMoney);
            
            /* law */
            int actBuyingFuel = planBuyingFuel < buyingFuelLimit ? planBuyingFuel : buyingFuelLimit;
            
            /* actual spend money*/
            int actSpendMoney = ExchangeRate::buyingMoneyByFuel(actBuyingFuel);
            
            /* start buying */
            spaceShipDAO.decResourceMoney(actSpendMoney);
            spaceShipDAO.incResourceFuel(actBuyingFuel);
            
            /* log */
            GameLogger::stdOut("buying fuel Success");
            GameLogger::stdOut("you have spend money : " + std::to_string(actSpendMoney));
            GameLogger::stdOut("you have earned fuel : " + std::to_string(actBuyingFuel));
            
        }else{
            
            GameLogger::stdOut("sorry you don't have money to buy fuel");
            
        }
        
        
    }
    
    
    bool TradingOK(SpaceShip spaceShip){
        
        
        // condition1 || condition2 || ....
        return activityAbilityOK(spaceShip);
    }
    
    
    
    
};

#endif
