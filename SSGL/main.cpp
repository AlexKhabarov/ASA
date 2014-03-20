#include "analysis_builder.h"

#include "../../SWL/SWL/$.h"

$main
{
    using namespace ssgl;
    
#define $sl$relation(cell, begin, end) \
    (#cell, relation_retriever::relation{node begin, node end, $builder.retriever_.source_manager_})
#define $sl$relation_s(begin_name, end_name) \
    ( \
        #begin_name, \
        relation_retriever::relation{node $sl$loc(begin_name), node $sl$loc(end_name), $builder.retriever_.source_manager_} \
    )
    
#define $sl$analyzer(name, type, ...) $sl$analyzer$basic(name()$sl$bind(type), if (auto node = $sl$node(type)) insert($builder.retriever_[#type]) __VA_ARGS__)
    
    auto$exr $builder = analysis::builder{$argc, $argv};
    $builder
        $sl$analyzer(forStmt, ForStmt,
            $sl$relation(Start,  $sl$loc$start,          $sl$loc(LParen))
            $sl$relation(LParen, $sl$loc(LParen),        ->getInit()$sl$loc$start)
            $sl$relation(Init,   ->getInit()$sl$loc$end, ->getCond()$sl$loc$start)
        )
    ();
    
}

// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"