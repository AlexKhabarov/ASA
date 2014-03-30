//
//  SGMatchFinder.h
//  Gatherer
//
//  Created by Alex Khabarov on 2/26/14.
//  Copyright (c) 2014 Heaven Inc. All rights reserved.
//

#ifndef SGGL_analysis_builder_h
#define SGGL_analysis_builder_h

#include "analyzer.h"
#include "relation_retriever.h"
#include "../../SWL/SWL/$.h"

SSGL_BEGIN

namespace analysis {

$obj(builder, MatchFinder, base_i) // TODO: Add multiple files support
$interface
    CompilerInstance    compiler_;
    CommonOptionsParser options_parser_;
    ClangTool           tool_;
    
    relation_retriever  retriever_;
    
    builder(int$ex argc, char const** argv) :
        options_parser_{argc, argv},
        tool_          {options_parser_.getCompilations(),
                        options_parser_.getSourcePathList()},
        retriever_     {({
                        compiler_.createDiagnostics();
                        compiler_.setFileManager     (&tool_.getFiles());
                        compiler_.createSourceManager( tool_.getFiles());
                        compiler_.InitializeSourceManager(FrontendInputFile(options_parser_.getSourcePathList()[0], IK_PreprocessedCXX));
                        ref(compiler_);
                       })}
    {}
    
    $def  (addMatcher(a.matcher_, &a.printer_);       $self$ex, add_analyzer, $ex  a)
    $def_s(tool_.run(newFrontendActionFactory(this)); $self$ex, run)
    $def_s(run(),                                               operator())
    $def  (add_analyzer(a),                                     operator(),   $exr a)
    $def  (add_analyzer(a),                                     operator(),   $ex  a)
$end

} // namespace analysis
    
SSGL_END

#endif


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"