//
//  Analyzer.h
//  Gatherer
//
//  Created by Alex Khabarov on 2/26/14.
//  Copyright (c) 2014 Heaven Inc. All rights reserved.
//

#ifndef SGGL_analyzer_h
#define SGGL_analyzer_h

#include "def.h"
#include "../../SWL/SWL/$.h"

SSGL_BEGIN

namespace analysis {

$obj(analyzer, base_i)
$interface
    friend class builder;

    $alias(matcher_type,        StatementMatcher)
    $alias(match_callback_type, MatchFinder::MatchCallback)
    $alias(match_result_type,   MatchFinder::MatchResult)
    $alias(callback_type,       function<void(match_result_type$in)>)

    $obj(printer_type, match_callback_type)
        printer_type(callback_type$in callback) :
            callback_{callback}
        {}

    $internal
        callback_type$in callback_;

        void run(match_result_type$in result) override
        {
            callback_(result);
        }
    $end
    
    analyzer(matcher_type$in matcher, callback_type$in callback) :
        matcher_ {matcher},
        callback_{callback},
        printer_ {callback}
    {}
    
$internal
    matcher_type  matcher_;
    callback_type callback_;
    printer_type  printer_;
$end

} // namespace analysis

SSGL_END

#define $sl$analyzer$basic(matcher_code, ...)                       \
    (                                                               \
        ssgl::analysis::analyzer                                    \
        {                                                           \
            matcher_code,                                           \
                                                                    \
            [&](ssgl::analysis::analyzer::match_result_type$in res) \
            {                                                       \
                __VA_ARGS__;                                        \
            }                                                       \
        }                                                           \
    )

#define $sl$relation(begin, end) \
    ( \
        relation_retriever::relation{begin, end, $builder.retriever_.source_manager_} \
    )

#define $sl$analyzer(name, type, ...) \
    $sl$analyzer$basic(name()$sl$bind(type), \
        if (auto n = $sl$node(type)) \
            push_back($builder.retriever_[#type])(list_of __VA_ARGS__); \
    )

#define $sl$name(name)                                   (#name)
#define $sl$bind(name) .bind                     $sl$name( name)
#define $sl$node(name) res.Nodes.getNodeAs<name> $sl$name( name)
#define $sl$decl(name) res.Nodes.getDeclAs<name> $sl$name( name)
#define $sl$stmt(name) res.Nodes.getStmtAs<name> $sl$name( name)
#define $sl$context    res.Context

#endif



// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"