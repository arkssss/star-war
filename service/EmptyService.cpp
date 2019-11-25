//
//  EmptyService.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/25.
//  Copyright © 2019年 ark. All rights reserved.


#ifndef _EmptyService
#define _EmptyService

# include "Service.cpp"


class EmptyService : public Service{

    private :
    /* Nothing happen */
    EmptyActivity emptyActivity;
    
    
    
    public :
    
    
    void start(SpaceShip &spaceShip){
        
        
        GameLogger::stdOut("you are in empty selector in round : " + std::to_string(RuntimeParameter::GAME_CURRENT_ROUND + 1));
        
        emptyActivity.start();
        
    }
    
    
    
    
    
};


#endif


