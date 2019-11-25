//
//  GameManager.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/20.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _GameManager
#define _GameManager

#include <string>
#include <iostream>

/**
 our game managerr
 */



class GameManager{
    
    public :
    
    /*
        game end with normal reason
     */
    static void gameFail(std::string msg){
        
        std::cout<< msg << std::endl;
        
        exit(0);
    }
    
    
    /*
        game end with unexcepted error
     */
    static void gameError(std::string msg){
        
        
        std::cout<< msg << std::endl;
        
        exit(0);
        
        
        
    }
    
    
    
};


#endif
