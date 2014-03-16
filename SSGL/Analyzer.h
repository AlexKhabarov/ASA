//
//  Analyzer.h
//  Gatherer
//
//  Created by Alex Khabarov on 2/26/14.
//  Copyright (c) 2014 Heaven Inc. All rights reserved.
//

#ifndef SG_Analyzer_h
#define SG_Analyzer_h

#include "Def.h"
#include <functional>

SC_BEGIN

using std::function;

class Analyzer
{
    friend class AnalysisBuilder;
    
public:
    using matcher_type        = ast_matchers::StatementMatcher;
    using match_callback_type = ast_matchers::MatchFinder::MatchCallback;
    using match_result_type   = ast_matchers::MatchFinder::MatchResult;
    using callback_type       = function<void(const match_result_type& result)>;
    
    Analyzer(matcher_type &&matcher, callback_type &&callback) :
        matcher_ (matcher),
       callback_(callback),
        printer_ (callback)
    {}
    
private:
    matcher_type matcher_;
    callback_type callback_;
    class printer_type : public match_callback_type
    {
    public:
        printer_type(callback_type &callback) :
            callback_(callback)
        {}
        
    private:
        callback_type callback_;
        
        virtual void run(const match_result_type &result) override
        {
            callback_(result);
        }
    };
    
    printer_type printer_;
};

#define SC_ANALYZER(matcher_code, callback_code)        \
    (                                                   \
        Analyzer                                        \
        {                                               \
            matcher_code,                               \
                                                        \
            [&](const Analyzer::match_result_type& res) \
            {                                           \
                callback_code;                          \
            }                                           \
        }                                               \
    )

#define SC_NAME(name)                                        (#name)
#define SC_BIND(name)       .bind                     SC_NAME( name)
#define SC_NODE_NAMED(name) res.Nodes.getNodeAs<name> SC_NAME( name)
#define SC_DECL_NAMED(name) res.Nodes.getDeclAs<name> SC_NAME( name)
#define SC_STMT_NAMED(name) res.Nodes.getStmtAs<name> SC_NAME( name)
#define SC_CONTEXT          res.Context

#define SC_OUT              llvm::outs()

SC_END

#endif
