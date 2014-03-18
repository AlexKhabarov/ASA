//
//  SGMatchFinder.h
//  Gatherer
//
//  Created by Alex Khabarov on 2/26/14.
//  Copyright (c) 2014 Heaven Inc. All rights reserved.
//

#ifndef SG_AnalysisBuilder_h
#define SG_AnalysisBuilder_h

#include "analyzer.h"
#include "../../SWL/SWL/$.h"

SSGL_BEGIN

namespace analysis {

$obj(builder, MatchFinder, base_i)
$interface
    builder(int$ex argc, char const** argv) :
        options_parser_{argc, argv},
        tool_          {options_parser_.getCompilations(),
                        options_parser_.getSourcePathList()}
    {}

    $def  (addMatcher(a.matcher_, &a.printer_);       $self$ex, add_analyzer, $ex  a)
    $def_s(tool_.run(newFrontendActionFactory(this)); $self$ex, run)
    $def_s(run(),                                               operator())
    $def  (add_analyzer(a),                                     operator(),   $exr a)
    $def  (add_analyzer(a),                                     operator(),   $ex  a)
    
$internal
    CommonOptionsParser options_parser_;
    ClangTool           tool_;
$end

} // namespace analysis
    
SSGL_END

#endif


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"