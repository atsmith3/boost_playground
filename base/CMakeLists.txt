add_library(base
  area.h
  area.cc
  component.h
  component.cc
)
target_include_directories(base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
