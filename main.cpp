//
//  main.cpp
//  apAss2_spaceship
//
//  Created by 方舟Ark on 2019/11/19.
//  Copyright © 2019年 ark. All rights reserved.
//

#include "beginer/Bootstrap.cpp"

 
int main(int argc, const char * argv[]) {

    /* read command */
    if(argc != 2) {
        std::cout << "please command like ./a.out X (X is the tot round of this game)" << std::endl;
        return 0;
    }
    int rounds = std::stoi(argv[1]);
    
    /* get start */
    Bootstrap::start(rounds);
    
}
