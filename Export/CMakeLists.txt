add_definitions(-D_EXPORT_DLL_)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/dll)
add_library(DLL SHARED Exporter.cpp)
