//
//  ExchangeRate.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/21.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _ExchangeRate
#define _ExchangeRate

/*
    the class control the exchange rate between food, fuel, money, tradable goods
 */

class ExchangeRate{
    
    
    public :
    
    // money-based rate
    static double ONE_MONEY_TO_FOOD_RATE;
    
    static double ONE_MONEY_TO_FUEL_RATE;
    
    static double ONE_MONEY_TO_GOODS_RATE;
    
    
    // reverse rete
    static double ONE_GOODS_TO_MONEY_RATE;
    
    static double ONE_FOOD_TO_MOENY_RATE;
    
    static double ONE_FUEL_TO_MONEY_RATE;
    
    
    //  ------------------------    current support trading ----------------
    
    // 1. buying food by money
    static double buyingFoodByMoney(double money){
        
        return money*ONE_MONEY_TO_FOOD_RATE;
    }
    
    // 2. buying fuel by oney
    static double buyingFuelBYMoney(double money){
        
        return money*ONE_MONEY_TO_FUEL_RATE;
        
    }
    
    //  3. sale goods to money
    static double buyingMoneyByGoods(double goods){
        
        return goods*ONE_GOODS_TO_MONEY_RATE;
        
    }
    
    // 4. computer need, not actual
    static double buyingMoneyByFoods(double _foods){
        return _foods * ONE_FOOD_TO_MOENY_RATE;
    }
    
    // 5. computer need, not actual
    static double buyingMoneyByFuel(double _fuel){
        return _fuel * ONE_FUEL_TO_MONEY_RATE;
    }
    
    
    
    
    
};

// def
double ExchangeRate::ONE_MONEY_TO_FOOD_RATE = 2;
double ExchangeRate::ONE_MONEY_TO_FUEL_RATE = 3;
double ExchangeRate::ONE_MONEY_TO_GOODS_RATE = 1;
double ExchangeRate::ONE_GOODS_TO_MONEY_RATE = (double)1/ExchangeRate::ONE_MONEY_TO_GOODS_RATE;
double ExchangeRate::ONE_FOOD_TO_MOENY_RATE =  (double)1/ExchangeRate::ONE_MONEY_TO_FOOD_RATE;
double ExchangeRate::ONE_FUEL_TO_MONEY_RATE =  (double)1/ExchangeRate::ONE_MONEY_TO_FUEL_RATE;


#endif
