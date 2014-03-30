//
//  relation_retriever.h
//  SSGL
//
//  Created by Alex Khabarov on 3/20/14.
//  Copyright (c) 2014 Khabarov Inc. All rights reserved.
//

#ifndef SSGL_relation_retriever_h
#define SSGL_relation_retriever_h

#include "def.h"
#include "../../SWL/SWL/$.h"

SSGL_BEGIN

auto stmt2str = [](auto start, auto end, auto$in compiler, bool forced_advance = false){
    auto$in sm = compiler.getSourceManager();
    auto    true_start = forced_advance? clang::Lexer::getLocForEndOfToken(start, 0, sm, compiler.getLangOpts()) : start;
    return std::string{sm.getCharacterData(true_start), static_cast<unsigned>(std::distance(sm.getCharacterData(true_start), sm.getCharacterData(end)))};
};

$obj(relation_retriever, base_i)
$interface
    $obj(relation, base_i)
    $interface
        relation(SourceLocation $in begin, SourceLocation $in end, CompilerInstance $in compiler, bool forced_advance = false) :
            range_{begin, end},
            text_{stmt2str(begin, end, compiler, forced_advance)} // TODO: Optimize
        {}

        $def_s(cref(range_),    range)

    $internal
        SourceRange range_;
        string      text_;
    $end

    explicit relation_retriever(CompilerInstance $in sm) : compiler_{sm} {}
    ~relation_retriever() {}

    auto$ex operator[] (string$in val)
        $returning(data_[val])

// $internal
    CompilerInstance $in                        compiler_;
    map<string, std::vector<std::vector<relation>>> data_;
$end

SSGL_END

#endif


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"