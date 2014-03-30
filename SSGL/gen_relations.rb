# ARGV[0] = 'input/path'
# ARGV[1] = 'output/path'

input =
'
forStmt : ForStmt =
LocStart       LParenLoc;
LParenLoc      Init.LocStart;
Init.getLocEnd Cond.LocStart;
'