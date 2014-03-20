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

#define $va_each(args, code) \
    [](auto...){}(([&](auto&& $arg){code;}(args), 0)...);

namespace std {
    auto to_string(const char* s)
    {
        return std::string(s);
    }
    auto to_string(std::string $in s)
    {
        return s;
    }
}

int main()
{
    // $def_local(a + b, ladd, $in a, $in b)
    
    using namespace $;
    
    /*using std::to_string;

    cout << [](auto... args) // Polymorphic Variadic Lambda-Functions, yeah
    {
        
        auto str = "|"s;
        $va_each(args, str += to_string($arg) + "|"s)
        return str;
        
    }("ss"s, 1.99, "pizza", M_PI);
    
    //std::cout << x(5);
    
    //auto m = $map("pizza", 1)("google", 2);
    
    cout << "\n" << ladd(55.1, 6);*/
}

#include "undef.h"