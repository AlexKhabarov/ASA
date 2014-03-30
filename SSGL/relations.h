//
//  relations.h
//  SSGL
//
//  Created by Alex Khabarov on 3/26/14.
//  Copyright (c) 2014 Khabarov Inc. All rights reserved.
//

#ifndef SSGL_relations_h
#define SSGL_relations_h

$sl$analyzer(forStmt, ForStmt,
    $sl$relation(n->getLocStart(),          n->getLParenLoc())
    $sl$relation(n->getLParenLoc(),         n->getInit()->getLocStart())
    $sl$relation(n->getInit()->getLocEnd(), n->getCond()->getLocStart())
    $sl$relation(n->getCond()->getLocEnd(), n->getInc()->getLocStart())
    $sl$relation(n->getInc()->getLocEnd() ,  n->getRParenLoc())
    $sl$relation(n->getRParenLoc(),         n->getBody()->getLocStart())
    $sl$relation(n->getBody()->getLocEnd(), n->getLocEnd())
)

#endif


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"