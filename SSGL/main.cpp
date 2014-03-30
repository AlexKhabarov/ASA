#include "analysis_builder.h"

#include "../../SWL/SWL/$.h"

$main
{
    using namespace ssgl;

    analysis::builder $builder{$argc, $argv};
    $builder
        #include "relations.h"
    ();
}

// Automatically generated undef includes: 
#include "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/../../SWL/SWL/undef.h"