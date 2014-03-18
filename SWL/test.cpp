//
//  main.cpp
//  SWL
//
//  Created by Alex Khabarov on 3/13/14.
//  Copyright (c) 2014 Khabarov Inc. All rights reserved.
//

#include "$.h"

$def(a + b, add, a, b)

#define $obj_inheritance_routine(r, data, i, elem) \
    BOOST_PP_COMMA_IF(i) public elem
#define $obj_parent_aliasing_routine(r, data, i, elem) using BOOST_PP_CAT(parent, i) = elem; \

#define $obj(name, ...) \
    class name : BOOST_PP_SEQ_FOR_EACH_I($obj_inheritance_routine, ~, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)) { \
    public: \
        BOOST_PP_SEQ_FOR_EACH_I($obj_parent_aliasing_routine, ~, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)) \
        using parent = parent0; \
        $typedef_enable_generic_accessor(name)

#define $constructor_inherit(name) using name::name;

#define $aliasing  public:
#define $interface public:
#define $internal  private:
#define $protected protected:

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