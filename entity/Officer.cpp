//
//  Officer.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//

#ifndef _Officer
#define _Officer



#include "CrewMember.cpp"
#include <string>
/**
 A class for officer
 */
class Officer : public CrewMember{
    
    private :
    // name & age for officer
    std::string name;
    int age;
    
    
    // the abilty of the officer
    // init with the spaceship
    int abilityType;
    
    
    // init officer die, then new crew member becomes the officer, but the degree is lower then the old one
    int abilityDegree;
    
    
    
    public :
    
    //------------------------- getter and setter ---------------------
    void setName(std::string _name){
        name = _name;
    }
    void setAge(int _age){
        age = _age;
    }
    void setAbilityType(int _abilityType){
        abilityType = _abilityType;
    }
    void setAbilityDegree(int _abilityDegree){
        abilityDegree = _abilityDegree;
    }

    
    std::string getName(){
        return name;
    }

    int getAbilityType(){
        
        return abilityType;
    }

    
    
};

#endif
