//
//  SGDef.h
//  Gatherer
//
//  Created by Alex Khabarov on 2/26/14.
//  Copyright (c) 2014 Heaven Inc. All rights reserved.
//

#ifndef SG_Def_h
#define SG_Def_h

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

#define SC_BEGIN namespace SC {
#define SC_END   }

SC_BEGIN

using namespace llvm;
using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;

SC_END

#endif
