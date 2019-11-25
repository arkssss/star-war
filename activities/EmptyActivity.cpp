//
//  EmptyActivity.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/25.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _EmptyActivity
#define _EmptyActivity


#include "Activity.cpp"


/*
 
    Nothing happen
 
 */
class EmptyActivity : public Activity{
    
    
    public :
    
    
    void start(){
        
        GameLogger::stdOut("Opps, Nothing happen, keep moving !");
        
    }
    
    
};

#endif
