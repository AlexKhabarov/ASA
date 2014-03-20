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

#define $sl$loc(name) ->get##name##Loc()
#define $sl$loc$start ->getLocStart()
#define $sl$loc$end   ->getLocEnd()

SSGL_BEGIN

$obj(relation_retriever, base_i)
$interface
    $obj(relation, base_i)
    $interface
        relation(SourceLocation $in begin, SourceLocation $in end, SourceManager $in source_manager) :
            range_{begin, end},
            distance_{source_manager.getFileOffset(end) - source_manager.getFileOffset(begin)}
        {}

        $def_s(cref(range_),    range)
        $def_s(cref(distance_), distance)

    $internal
        SourceRange range_;
        unsigned    distance_;
    $end

    explicit relation_retriever(SourceManager $in sm) : source_manager_{sm} {}

    auto$ex operator[] (string$in val)
        $returning(data_[val])

// $internal
    SourceManager $in                  source_manager_;
    map<string, map<string, relation>> data_;
    // data["ForStmt"]["LParen-Init"] = relation_retriever::relation{lparenloc, initloc, $builder.compiler_.getSourceManager()}; data["ForStmt"]["Ex-Start"] "Start-LParen";
    // ForStmt: Start LParen Init# Cond# Inc# RParen Body# End
    // ((\\w\\s?):\\s?(\\w\\s?)+)
$end

SSGL_END

#endif


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"