# ARGV[0] = "/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SWL/SWL/"
# ARGV[1] = "$.h"
# ARGV[2] = "undef.h"
# ARGV[3] = 'SWL_$_h' # in order to skip header guard

raise 'Directory does not exist'   unless File.directory? ARGV[0].to_s

raise 'No input file passed'       unless ARGV[1]
input_path = ARGV[0] + ARGV[1]
raise 'Input file does not exist'  unless File.exists? input_path

raise 'No output file passed'      unless ARGV[2]
output_path = ARGV[0] + ARGV[2]
raise 'Output file does not exist' unless File.exists? output_path

raise 'No header guard'            unless ARGV[3]

input, output = File.open(input_path, 'r'), File.open(output_path, 'w')

input.read.scan(/#define ([[[:graph:]]&&[^\(]]+)/) {|m| output.write "#undef #{m[0]}\n" unless m[0] == ARGV[3]}