#ifndef __AREA_H__
#define __AREA_H__

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

class Area {
public:
  double height;
  double width;
  double area;

  Area();
  Area(const double h, const double w);
  Area(const Area& obj);
  ~Area();
private:
  void create(const double h, const double w);
  void destroy();

  friend class boost::serialization::access;
  friend std::ostream & operator<<(std::ostream &os, const Area& gp);
  
  template<class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar & height;
    ar & width;
    ar & area;
  }
};

#endif // __AREA_H__
