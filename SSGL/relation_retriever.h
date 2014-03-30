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

auto stmt2str = [](auto start, auto end, auto compiler){
    auto sm = compiler->getSourceManager();
    return std::string{sm->getCharacterData(start), static_cast<unsigned>(std::distance(sm->getCharacterData(start), sm->getCharacterData(clang::Lexer::getLocForEndOfToken(end, 0, sm, compiler->getLangOpts()))))};
};

$obj(relation_retriever, base_i)
$interface
    $obj(relation, base_i)
    $interface
        relation(SourceLocation $in begin, SourceLocation $in end, SourceManager $in source_manager) :
            range_{begin, end},
            text_{source_manager.getCharacterData(begin),
                  static_cast<unsigned>(std::distance(source_manager.getCharacterData(begin), source_manager.getCharacterData(end)))} // TODO: Optimize
        {}

        $def_s(cref(range_),    range)

    $internal
        SourceRange range_;
        string      text_;
    $end

    explicit relation_retriever(SourceManager $in sm) : source_manager_{sm} {}
    ~relation_retriever() {}

    auto$ex operator[] (string$in val)
        $returning(data_[val])

// $internal
    SourceManager $in                  source_manager_;
    map<string, std::vector<std::vector<relation>>> data_;
$end

SSGL_END

#endif


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"