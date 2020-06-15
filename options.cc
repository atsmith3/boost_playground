#include "options.h"

#include <boost/program_options.hpp>
#include <iostream>
#include <string>

bool Test::Options::parse(int argc, char **argv) {
  // clang-format off
  po::options_description desc("General Options");
  desc.add_options()
    ("help,h", "Display help message")
  ;

  po::options_description serialization("Serialization Options");
  serialization.add_options()
    ("serial_path", po::value<std::string>(&serialization_path), "Path/to/serialization")
    ("serial_create", po::value<bool>(&serialization_create)->default_value(false), "Create A Serialization Checkpoint") 
    ("serial_restore", po::value<bool>(&serialization_restore)->default_value(false), "Restore from a Serialization Checkpoint")
  ;
  // clang-format on

  po::options_description all_options;
  all_options.add(desc);
  all_options.add(serialization);

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, all_options), vm);
  po::notify(vm);

  if (vm.count("help")) {
    std::cout << all_options << "\n";
    return false;
  }
  return true;
}
