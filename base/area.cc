#include "area.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/assume_abstract.hpp>

Area::Area() {
  this->create(0,0);
}

Area::Area(const double h, const double w) {
  this->create(h,w);
}

Area::Area(const Area& obj) {
  this->destroy();
  this->create(obj.height, obj.width);
}

Area::~Area() {
  this->destroy();
}

void
Area::destroy() {

}

void
Area::create(const double h, const double w) {
  this->height = h;
  this->width = w;
  this->area = w*h;
}

std::ostream & operator<<(std::ostream &os, const Area& a) {
  return os << a.height << " " << a.width << " " << a.area;
}
