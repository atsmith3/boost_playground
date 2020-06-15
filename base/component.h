#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "area.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

class Component {
  friend class boost::serialization::access;
  friend std::ostream & operator<<(std::ostream &os, const Component& gp);
  
  template<class Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar & area;
    ar & name;
  }

protected:
  Area area;
  std::string name;

public:
  Component();
  Component(const double h, const double w, const std::string name);
  Component(const Component& obj);
  virtual ~Component();

  virtual void compute(const double feature_size);
};

//BOOST_SERIALIZATION_ASSUME_ABSTRACT(Component);


#endif
