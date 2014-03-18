//
//  main.cpp
//  SWL
//
//  Created by Alex Khabarov on 3/13/14.
//  Copyright (c) 2014 Khabarov Inc. All rights reserved.
//

#include "$.h"

$def(a + b, add, a, b)

class sin {};

$obj(hell, sin)
    $aliasing
        $constructor_inherit(parent)

    $interface
        $def(a + b, add, $in a, $in b)
$end

int main()
{
    $def_local(a + b, ladd, $in a, $in b)
    
    using namespace $;
    
    auto str = "pizza"s;
    
    cout << str + " yeah!";
    
    cout << ladd(55.1, 6);
}

#include "undef.h"