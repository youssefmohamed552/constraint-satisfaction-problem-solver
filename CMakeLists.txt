cmake_minimum_required( VERSION 3.12)
project( csp )


add_definitions("-std=c++11")

include_directories(include)

add_library(
  csp
  src/csp_solver.cpp
  src/domain.cpp
)

add_library(
  nonogram
  src/nonogram_csp.cpp
  src/nonogram_constraint.cpp
  src/nonogram_variable.cpp
  src/nonogram_value.cpp
  src/nonogram.cpp
)

add_executable( app main.cpp )


target_link_libraries(
  app
  csp
  nonogram
)


