//
//  GameTimer.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/22.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _GameTimer
#define _GameTimer


/*
 
    The time controller of this game
    of course, it can generater the randomly seed

 */
#include <ctime>
#include <cstdlib>
#include <iostream>

class GameTimer{
    
    public :
    
    static bool hasInitSeed;
    
    
    /* generater the random number */
    static int _rand(){
        
        if(!hasInitSeed){
            unsigned seed = time(0);
            srand(seed);
            hasInitSeed = true;
        }
        
        return rand();
    }
    
    
    
    /* get random with a pair*/
    static int getRandomByRange(std::pair<int ,int> _range){
        
        if(_range.second - _range.first) return  _range.first;
        
        int randomSeed = _rand() % (_range.second - _range.first);
        
        return _range.first + randomSeed;
    }
    
};

bool GameTimer::hasInitSeed = false;



#endif
