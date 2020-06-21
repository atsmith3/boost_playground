add_library(module
  cpu.h
  cpu.cc
)
target_include_directories(module PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(module LINK_PUBLIC base)
