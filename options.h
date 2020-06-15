#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include <boost/program_options.hpp>
#include <iostream>
#include <string>

namespace Test {

namespace po = boost::program_options;

class Options {
public:
  // Serialization Options
  std::string serialization_path = "";
  bool serialization_create = false;
  bool serialization_restore = false;

  // Get Options from Command Line
  bool parse(int argc, char **argv);
}; // class Options

} // namespace Test

#endif // __OPTIONS_H__
