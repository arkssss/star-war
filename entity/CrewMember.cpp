//
//  CrewMember.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//
#ifndef _CrewMember
#define _CrewMember

#include <cstdio>

/**
 This is a baisc class for all Crew
 */
class CrewMember{
private:
    int crewId;
    
public:
    
    int getCrewId(){
        
        return crewId;
    }
    
    void setCrewId(int _crewId){
    
        crewId = _crewId;
        return;
    }
    
};

#endif
