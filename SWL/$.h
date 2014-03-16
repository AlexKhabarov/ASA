//
//  $.h
//  SSL
//
//  Created by Alex Khabarov on 3/13/14.
//  Copyright (c) 2014 Khabarov Inc. All rights reserved.
//

#ifndef SSL_$_h
#define SSL_$_h

#define BOOST_PP_VARIADICS

#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/tuple/to_seq.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/type_traits.hpp>

#include <iostream>
#include <memory>
#include <functional>
#include <utility>

using std::cout;

// Syntax

// Routines

#define $repeat(times) for (int i = 0; i < times; i++)

// Preprocessor

// Variables

// Arguments

#define $move(unit) std::move(unit)
#define $send(unit) std::forward<typename std::remove_reference<decltype(unit)>::type>(unit)

#define $in  $inl
#define $ex  $exl
#define $inl const&
#define $exl &
#define $inr const&&
#define $exr &&

#define $arguments_enable_postfix_form(unit) \
    using unit##$in  = unit $in; \
    using unit##$ex  = unit $ex; \
    using unit##$inl = unit $inl; \
    using unit##$exl = unit $exl; \
    using unit##$inr = unit $inr; \
    using unit##$exr = unit $exr; \

$arguments_enable_postfix_form(bool)
$arguments_enable_postfix_form(char)
$arguments_enable_postfix_form(int)
$arguments_enable_postfix_form(unsigned)
$arguments_enable_postfix_form(signed)
$arguments_enable_postfix_form(float)
$arguments_enable_postfix_form(double)
$arguments_enable_postfix_form(wchar_t)

// Statements

#define $returning(code) {return code;}

// Typedef

#define $alias(lhs, rhs) \
    using lhs = rhs; \
    $arguments_enable_postfix_form(lhs)

#define $typedef_enable_generic_accessor(type) \
    $alias($class, type) \
    $alias($self$type, type)

// Type Traits

#define $type(unit) decltype(unit)

// Self

#define self$ *this

// Constructor

#define $constructor_argument_declaration_(r, data, i, elem)    BOOST_PP_COMMA_IF(i) decltype(BOOST_PP_CAT(elem, $))$inr elem
#define $constructor_argument_initialization_(r, data, i, elem) BOOST_PP_CAT(elem, $) = $send(elem);
#define $constructor(...) \
    (BOOST_PP_SEQ_FOR_EACH_I($constructor_argument_declaration_,    ~, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))) \
    {BOOST_PP_SEQ_FOR_EACH_I($constructor_argument_initialization_, ~, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))}
#undef $constructor_argument_declaration_
#undef $constructor_argument_initialization_

// Property

template <typename T>
struct base
{
    $arguments_enable_postfix_form(T);
    
    $alias(getter$type, typeof(std::function<T$ex(T$ex)>));
    $alias(setter$type, typeof(std::function<T$ex(T$ex, T$exr)>));
};

// Encapsulation

template <typename T>
struct getter_container : virtual public base<T>
{
    $typedef_enable_generic_accessor(getter_container);
    
    typename base<T>::getter$type getter$;
};

template <typename T>
struct setter_container : virtual public base<T>
{
    $typedef_enable_generic_accessor(setter_container);
    
    typename base<T>::setter$type setter$;
};

template <typename... Types> class mix : public Types... {};

template <typename T,
          bool const GetterEnabled = false,
          bool const SetterEnabled = false>
using property_base =
    typename boost::conditional < GetterEnabled,
        typename boost::conditional < SetterEnabled,
            mix<setter_container<T>, getter_container<T>>,
            getter_container<T>
        >::type,
        typename boost::conditional < SetterEnabled,
            setter_container<T>,
            base<T>
        >::type
    >::type;

template <typename T,
          bool const GetterEnabled = false,
          bool const SetterEnabled = false>
class property :
    public property_base<T, GetterEnabled, SetterEnabled>
{
public:
    $typedef_enable_generic_accessor(property);
    $arguments_enable_postfix_form(T);
    
    $alias(unit$type, T)
    $alias(parent$type, typeof(property_base<T, GetterEnabled, SetterEnabled>));
    
    template <bool const Enable = false>
    using unit$type$ex_checked = typename boost::conditional<Enable, unit$type$ex, void>::type;
    
private:
    unit$type   unit$;
    
public:
    property() {}
    property(unit$type$in unit) : unit${unit} {}
    property(unit$type$in unit, typename parent$type::getter$type$in getter) :
        unit${unit}
    {
        parent$type::getter$ = getter;
    }
    property(unit$type$in unit, typename parent$type::setter$type$in setter) :
    unit${unit}
    {
        parent$type::setter$ = setter;
    }
    property(unit$type$in unit, typename parent$type::getter$type$in getter, typename parent$type::setter$type$in setter) :
        unit${unit}
    {
        parent$type::getter$ = getter;
        parent$type::setter$ = setter;
    }
    property(unit$type$in unit, typename parent$type::setter$type$in setter, typename parent$type::getter$type$in getter) :
    unit${unit}
    {
        parent$type::getter$ = getter;
        parent$type::setter$ = setter;
    }
    
    inline unit$type$ex_checked<SetterEnabled> operator=(T$exr other)
        $returning(this->setter$(unit$, $send(other));)
    inline unit$type$ex_checked<SetterEnabled> operator()(T$exr other)
        $returning(this->setter$(unit$, $send(other)))
    
    inline operator unit$type$ex_checked<GetterEnabled>()
        $returning(this->getter$(unit$))
    inline unit$type$ex_checked<GetterEnabled> operator()()
        $returning(this->getter$(unit$))
};

#define $setter(type, code) \
    [](type $ex unit, type $exr other) -> type $ex {code; return unit = $send(other);}

#define $getter(type, code) \
    [](type $ex unit) -> type $ex {code; return unit;}

template <typename T>
using readonly  = property<T, true, false>;
template <typename T>
using readwrite = property<T, true, true>;

#define $writeonly(name, value, setter_code) property<decltype(value), false, true> name{value, $setter(decltype(value), setter_code)}; $alias(name##$type, decltype(name))
#define $readonly(name, value, getter_code)  property<decltype(value), true, false> name{value, $getter(decltype(value), getter_code)}; $alias(name##$type, decltype(name))

#define $readwrite(name, value, setter_code, getter_code) property<decltype(value), true, true> name{value, $setter(decltype(value), setter_code), $getter(decltype(value), getter_code)}; $alias(name##$type, decltype(name))

#endif
