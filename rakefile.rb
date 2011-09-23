require 'rake/clean'

CLOBBER.include([
	'**/Makefile*',
	'**/release',
	'**/debug',
	'**/ui_*'
])

APP_NAME = 'bshuffle'
APP_EXT = '.exe'
LIB_EXT = '.dll'

ARTIFACTS = [
	"bshuffle/$release-type/bshuffle#{APP_EXT}",
	"libs/bshuffle-session/$release-type/bshuffle-session#{LIB_EXT}",
	"libs/print-settings/$release-type/print-settings#{LIB_EXT}"
]

def copy_artifacts(release_type)
	artifacts = ARTIFACTS.map{|t| t.sub('$release-type',release_type) }
	if not File.directory?(release_type)
		Dir.mkdir(release_type)
	end
	artifacts.each do |src|
		cp src, release_type, :verbose => true
	end
end

task :default => [:release]
task :release => [:qmake, :make_release]
task :debug => [:qmake, :make_debug]

task :qmake do
	sh 'qmake'
end

task :make_release do
	sh 'make release'
	copy_artifacts('release')
end

task :launch_release do
	sh "release/#{APP_NAME}#{APP_EXT}"
end

task :make_debug do
	sh 'make debug'
	copy_artifacts('debug')
end

task :launch_debug do
	sh "debug/#{APP_NAME}#{APP_EXT}"
end
