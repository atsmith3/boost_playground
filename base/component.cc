#include "component.h"

#include "area.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

Component::Component() {
  this->area = Area();
  this->name = "";
}

Component::Component(const double h, const double w, const std::string name) {
  this->area = Area(h, w);
  this->name = name;
}

Component::Component(const Component& obj) {
  this->area = obj.area;
  this->name = obj.name;
}

Component::~Component() {
  this->name = "";
}

void
Component::compute(const double feature_size) {
  this->area.height = (this->area.height) * feature_size;
  this->area.width = (this->area.width) * feature_size;
  this->area.area = (this->area.width) * (this->area.height);
}

std::ostream & operator<<(std::ostream &os, const Component& c) {
  return os << c.area << " " << c.name;
}
