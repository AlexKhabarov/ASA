#include "AnalysisBuilder.h"
#include "Analyzer.h"

// Nodes Dumper
// if (auto fs = SC_NODE_NAMED(ForStmt)) fs->dump()

int main(int argc, const char **argv) {
    using namespace SC;
    
    AnalysisBuilder{argc, argv}
        SC_ANALYZER
        (
            declStmt(),
            SC_OUT << "declaration\n"
        )
        SC_ANALYZER
        (
             forStmt(hasLoopInit(declStmt(hasSingleDecl(varDecl(hasInitializer(integerLiteral(equals(0)))))))) SC_BIND(ForStmt),
             SC_OUT << "got for (int i = 0; ...; ...) ... " << SC_NODE_NAMED(ForStmt) << "\n"
        )
        SC_ANALYZER
        (
             breakStmt(),
             SC_OUT << "got break statement\n"
        )
    ();
}

// declStmt = int@varName@=@expr@;
// forStmt  = for@(@declStmt...@;@exprStmt@;@exprStmt@)@{@stmts@}
// ifStmt   = if@(@exprStmt@)@{@stmts@}


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"