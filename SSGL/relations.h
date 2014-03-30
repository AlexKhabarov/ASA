//
//  relations.h
//  SSGL
//
//  Created by Alex Khabarov on 3/26/14.
//  Copyright (c) 2014 Khabarov Inc. All rights reserved.
//

#ifndef SSGL_relations_h
#define SSGL_relations_h

$sl$analyzer(forStmt, ForStmt, Statement,
    $sl$relation_n(n->getLocStart(),          n->getLParenLoc())
    $sl$relation_n(n->getLParenLoc(),         n->getInit()->getLocStart())
    $sl$relation_f(n->getInit()->getLocEnd(), n->getCond()->getLocStart())
    $sl$relation_f(n->getCond()->getLocEnd(), n->getInc()->getLocStart())
    $sl$relation_f(n->getInc()->getLocEnd(),  n->getRParenLoc())
    $sl$relation_n(n->getRParenLoc(),         n->getBody()->getLocStart())
)

#endif


// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"