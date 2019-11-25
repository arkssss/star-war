//
//  RumtimeParameter.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/22.
//  Copyright © 2019年 ark. All rights reserved.
//


#ifndef _RuntimeParameter
#define _RuntimeParameter


/*
    this class to def the runtime parameter
    for example :
    1. PRESTIGE increase range with diplomactActivity happen
    2. .....
 
 */

#include "../util/GameManager.cpp"
#include "../util/GameTimer.cpp"


class RuntimeParameter {
    
    
    public :
    
    
    // ------------------------------- for game recorder-------------
    // current round of this game
    static int GAME_CURRENT_ROUND;
    static std::pair<int, int> RESOURCE_CONSUME_RANGE;
    
    
    // ------------------------------ for activity ----------------------
    // diplomacy PRESTIGE increase range
    static std::pair<int, int> DiPLOMACY_PRESTIGE_RANGE;
    
    

    // trading
    /* the range for buying food in this plane */
    static std::pair<int, int> TRADING_BUYING_FOOD_LIMIT_RANGE;

    /* the range for buying fuel in this plane */
    static std::pair<int, int> TRADING_BUYING_FUEL_LIMIT_RANGE;
    
    /* the range for saling goods to money */
    static std::pair<int, int> TRADING_SALING_GOODS_LIMIT_RANGE;

    
    // mining
    /* the range for mining material*/
    
    /* for limit the foods */
    static std::pair<int, int> MINING_FOODS_RANGE;
    /* for limit the fuel */
    static std::pair<int, int> MINING_FUEL_RANGE;
    /* for limit the goods */
    static std::pair<int, int> MINING_GOODS_RANGE;
    /* for limit the crew number */
    static std::pair<int, int> MINING_CREW_RANGE;
    
    // Travel eff
    /* the range for upgrading */
    /* speed */
    static std::pair<int, int> TRAVELEFF_SPEED_UPGREADING_RANGE;
    /* fuel */
    static std::pair<int, int> TRAVELEFF_FUEL_UPGREADING_RANGE;
    /* food */
    static std::pair<int, int> TRAVELEFF_FOOD_UPGREADING_RANGE;
    
    /* SystemRecovery */
    static std::pair<int, int> SYSTEMRECOVERY_HP_RANGE;
    
    
    // conflict
    /* evasion */
    
    /* fuel loss range */
    static std::pair<int, int> CONFLICT_EVASION_FUEL_LOSS_RANGE;
    /* food loss range */
    static std::pair<int, int> CONFLICT_EVASION_FOOD_LOSS_RANGE;
    
    
    // combat
    /* CombatManeuversActivity */
    static std::pair<int, int> COMBAT_MANEUVERRS_REDUCE_ORDCREW_RANGE;
    static std::pair<int, int> COMBAT_MANEUVERRS_REDUCE_OFFICER_RANGE;
    static std::pair<int, int> COMBAT_MANEUVERRS_ENHANCE_DEFENSE_RANGE;
    static std::pair<int, int> COMBAT_MUST_LOST_HP_RANGE;
    
    
    /* upgrad */
    static std::pair<int, int> UPGRAD_SYSTEM_COMBATATITU_RANGE;
    static std::pair<int, int> UPGRAD_SYSTEM_DEFENSE_RANGE;
    
    
    
    
    
    
    
    
};

/* current round of this game */
int RuntimeParameter::GAME_CURRENT_ROUND = 0;
std::pair<int, int> RuntimeParameter::RESOURCE_CONSUME_RANGE(10, 30);



/* diplomacy PRESTIGE increase range */
std::pair<int, int> RuntimeParameter::DiPLOMACY_PRESTIGE_RANGE(10, 30);

/* trading limit*/
std::pair<int, int> RuntimeParameter::TRADING_BUYING_FOOD_LIMIT_RANGE(30, 50);
/* of curese the fuel is hard to get then food*/
std::pair<int, int> RuntimeParameter::TRADING_BUYING_FUEL_LIMIT_RANGE(10, 20);
std::pair<int, int> RuntimeParameter::TRADING_SALING_GOODS_LIMIT_RANGE(40, 100);


/* Mining increase limit */
/* for limit the foods */
std::pair<int, int> RuntimeParameter::MINING_FOODS_RANGE(20, 50);
/* for limit the fuel */
std::pair<int, int> RuntimeParameter::MINING_FUEL_RANGE(10, 20);
/* for limit the goods */
std::pair<int, int> RuntimeParameter::MINING_GOODS_RANGE(50, 80);
/* for limit the crew number */
std::pair<int, int> RuntimeParameter::MINING_CREW_RANGE(1, 2);


/* travel eff limit */
/* the range for upgrading */
/* speed */
std::pair<int, int> RuntimeParameter::TRAVELEFF_SPEED_UPGREADING_RANGE(10, 20);
/* fuel */
std::pair<int, int> RuntimeParameter::TRAVELEFF_FUEL_UPGREADING_RANGE(5, 10);
/* food */
std::pair<int, int> RuntimeParameter::TRAVELEFF_FOOD_UPGREADING_RANGE(10, 20);


/* System Recovery */
std::pair<int, int> RuntimeParameter::SYSTEMRECOVERY_HP_RANGE(20, 30);



/* conflict evasion*/
/* fuel loss range */
std::pair<int, int> RuntimeParameter::CONFLICT_EVASION_FUEL_LOSS_RANGE(5, 10);
/* food loss range */
std::pair<int, int> RuntimeParameter::CONFLICT_EVASION_FOOD_LOSS_RANGE(2, 8);


// combat
/* CombatManeuversActivity */
std::pair<int, int> RuntimeParameter::COMBAT_MANEUVERRS_REDUCE_ORDCREW_RANGE(3, 6);
std::pair<int, int> RuntimeParameter::COMBAT_MANEUVERRS_REDUCE_OFFICER_RANGE(1, 3);
std::pair<int, int> RuntimeParameter::COMBAT_MANEUVERRS_ENHANCE_DEFENSE_RANGE(10, 20);
std::pair<int, int> RuntimeParameter::COMBAT_MUST_LOST_HP_RANGE(1, 10);

/* upgrad */
/* lots of possiblities */
std::pair<int, int> RuntimeParameter::UPGRAD_SYSTEM_COMBATATITU_RANGE(10, 100);
std::pair<int, int> RuntimeParameter::UPGRAD_SYSTEM_DEFENSE_RANGE(2, 20);


#endif
