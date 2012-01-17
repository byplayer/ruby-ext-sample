# -*- coding: utf-8 -*-
require 'rubygems'
require 'rake'

if File.exist?(File.expand_path('Gemfile', File.dirname(__FILE__)))
  require 'bundler/setup'
end

begin
  require 'rdoc/task'
rescue LoadError
  require 'rake/rdoctask'
end

begin
  require 'rspec/core'
  require 'rspec/core/rake_task'
rescue LoadError
  puts "no rspec"
else
  RSpec::Core::RakeTask.new(:spec) do |t|
    t.ruby_opts=""
    t.rcov = false
  end
  task :default => :spec
end

RDOC_OPTIONS = [
                '--line-numbers',
                '--inline-source',
                "--main", "README",
                "-c UTF-8",
               ]

Rake::RDocTask.new("doc") { |rdoc|
  rdoc.rdoc_dir = 'doc'
  rdoc.title = "ROMA documents"
  rdoc.options.concat RDOC_OPTIONS
  rdoc.rdoc_files.include('lib/**/*.rb')
  rdoc.rdoc_files.include("README")
  rdoc.rdoc_files.include("CHANGELOG")
}

