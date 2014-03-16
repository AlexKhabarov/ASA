//
//  main.cpp
//  SSL
//
//  Created by Alex Khabarov on 3/13/14.
//  Copyright (c) 2014 Khabarov Inc. All rights reserved.
//

#include <iostream>

#include "$.h"

int main(int argc, const char *argv[])
{
    $writeonly(x, 5, cout << "setting x\n")
    
    x = 6;
    
    // cout << x; // Error
    
    $readonly(y, 6, cout << "reading y\n")
    
    // y = 1; // Error
    
    cout << y << "\n";
    
    y$type a = 5; // Variable of the same type
    
    $readwrite(z, 99,,)
    
    z()++;
    
    cout << z << "\n";
}
