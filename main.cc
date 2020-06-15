#include "cpu.h"
#include "component.h"
#include "options.h"
#include <math.h>
#include <iostream>
#include <fstream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

void save(const Component& s, const char * filename) {
  // Make an archive
  std::ofstream ofs(filename);
  boost::archive::text_oarchive oa(ofs);
  oa << s;
}

void restore(Component& s, const char * filename) {
  // Restore from the Archive
  std::ifstream ifs(filename);
  boost::archive::text_iarchive ia(ifs);
  ia >> s;
}

int main(int argc, char** argv) {
  Test::Options opt;
  if (!opt.parse(argc, argv)) {
    return 1;
  }

  Component A(50, 60, "Andrew");
  Component B(100, 70, "Finn");
  Component C;
  Component D;

  if(opt.serialization_create) {
    std::cout << "Saving to file\n";
    save(A, "test_a.txt");
    save(B, "test_b.txt");
    return 0;
  }
  if(opt.serialization_restore) {
    std::cout << "Restoring from file\n";
    restore(C, "test_a.txt");
    restore(D, "test_b.txt");
  }

  std::cout << A << " " << B << "\n";

  C.compute(14e-9);
  D.compute(7e-9);

  std::cout << C << " " << D << "\n";

  return 0;
}
