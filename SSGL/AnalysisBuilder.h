//
//  SGMatchFinder.h
//  Gatherer
//
//  Created by Alex Khabarov on 2/26/14.
//  Copyright (c) 2014 Heaven Inc. All rights reserved.
//

#ifndef SG_AnalysisBuilder_h
#define SG_AnalysisBuilder_h

#include "Analyzer.h"

SC_BEGIN

class AnalysisBuilder : public ast_matchers::MatchFinder
{
public:
    AnalysisBuilder(int &argc, const char **argv) :
        options_parser_{argc, argv},
        tool_          {options_parser_.getCompilations(),
                        options_parser_.getSourcePathList()}
    {}
    
    AnalysisBuilder& addAnalyzer(Analyzer &a)
    {
        addMatcher(a.matcher_, &a.printer_);
        
        return *this;
    }
    
    AnalysisBuilder& run()
    {
        result_ = tool_.run(newFrontendActionFactory(this));
        
        return *this;
    }
    
    AnalysisBuilder& operator()(Analyzer &&a)
    {
        return addAnalyzer(a); 
    }
    AnalysisBuilder& operator()(Analyzer &a)
    {
        return addAnalyzer(a);
    }
    
    AnalysisBuilder& operator()()
    {
        return run();
    }
    
private:
    CommonOptionsParser options_parser_;
    ClangTool tool_;
    int       result_{0};
};
    
SC_END

#endif
