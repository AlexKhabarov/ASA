#include "analysis_builder.h"

#include "../../SWL/SWL/$.h"

// Nodes Dumper
// if (auto fs = $sl$node(ForStmt)) fs->dump()

$main
{
    using namespace ssgl;
    
    analysis::builder{$argc, $argv}
        $sl$analyzer
        (
             declStmt(),
             outs() << "declaration\n"
        )
        $sl$analyzer
        (
             forStmt(hasLoopInit(declStmt(hasSingleDecl(varDecl(hasInitializer(integerLiteral(equals(0)))))))) $sl$bind(ForStmt),
             outs() << "got for (int i = 0; ...; ...) ... " << $sl$node(ForStmt) << "\n"
        )
        $sl$analyzer
        (
             breakStmt(),
             outs() << "got break statement\n"
        )
    ();
}

// declStmt = int@varName@=@expr@;
// forStmt  = for@(@declStmt...@;@exprStmt@;@exprStmt@)@{@stmts@}
// ifStmt   = if@(@exprStmt@)@{@stmts@}

// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"