# ARGV[0] = '/Users/alexkhabarov/Dropbox/Programming/Xcode/Workspaces/ASA/Projects/SSGL/SSGL/'
# ARGV[1] = '../../SWL/SWL/undef.h'

raise 'Directory does not exist'  unless File.directory? ARGV[0].to_s

raise 'No undef file passed'      unless ARGV[1]
undef_path  = ARGV[0] + ARGV[1]
include_str =  "#include \"#{undef_path}\""
raise 'Undef file does not exist' unless File.exists? undef_path

Dir.foreach(ARGV[0]) { |name|
  next if name == '.' or name == '..' or !(%w(.c .cpp .h .hpp).include? File.extname name)
  path = ARGV[0] + name
  File.open(path, 'a').write("\n\n// Automatically generated undef includes: \n" + include_str) unless `tail -n 1 #{path}` == include_str
}