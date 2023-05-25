add_library(dithering dithering.cpp include/dithering/dithering.hpp)
set_property(TARGET dithering PROPERTY CXX_STANDARD 20)
target_include_directories(dithering PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS dithering)