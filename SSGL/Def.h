//
//  SGDef.h
//  Gatherer
//
//  Created by Alex Khabarov on 2/26/14.
//  Copyright (c) 2014 Heaven Inc. All rights reserved.
//

#ifndef SGGL_def_h
#define SGGL_def_h

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wshorten-64-to-32"
#endif

#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "llvm/Support/CommandLine.h"
#include "clang/Tooling/Tooling.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

#ifdef __clang__
#   pragma clang diagnostic pop
#endif

#define SSGL_BEGIN namespace ssgl {
#define SSGL_END   }

#include "../../SWL/SWL/$.h"

SSGL_BEGIN

class base_i {};

using namespace llvm;
using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace $;

SSGL_END

#endif


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"