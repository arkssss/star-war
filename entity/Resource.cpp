//
//  Resource.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _Resource
#define _Resource



/**
 
 The require resource of a spacehip
 
 */
class Resource{
    
    private:
    
        // require food
        double leftFood;
    
        // require fuel
        double leftFuel;
    
        // require money
        double leftMoney;
    
        // reqire tradable goods
        double tradableGoods;
    
    
    
    public :
    Resource(){}
    
    Resource(double _leftFood, double _leftFuel, double _leftMoney, double _tradableGoods){
        
        // init
        leftFood = _leftFood;
        leftFuel = _leftFuel;
        leftMoney = _leftMoney;
        tradableGoods = _tradableGoods;
        
    }
    
    
    // getter and setter 
    double getLeftFood(){
        
        return leftFood;
        
    }
    
    void setLeftFood(double _leftFood){
        
        leftFood = _leftFood;
        
    }
    
    double getLeftFuel(){
        
        return leftFuel;
        
    }
    
    void setLeftFuel(double _leftFuel){
        
        leftFuel = _leftFuel;
        
    }
    
    
    double getLeftMoney(){
        
        return leftMoney;
        
    }
    
    void setleftMoney(double _money){
        
        leftMoney = _money;
        
    }
    
    double getTradableGoods(){
        
        return tradableGoods;
        
    }
    
    void setLeftGoods(double _goods){
        
        tradableGoods = _goods;
        
    }

    
    
    
};
#endif
