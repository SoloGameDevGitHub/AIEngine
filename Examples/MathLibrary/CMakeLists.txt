add_definitions(-D MATHLIBRARY_EXPORTS)

# list of source files
set(FILES
        MathLibrary.cpp
        )

# shared and static libraries built from the same object files
add_library(MathLibraryShared SHARED ${FILES})
add_library(MathLibraryStatic STATIC ${FILES})

# rename output name of DLL and LIB files
set_target_properties(MathLibraryShared PROPERTIES OUTPUT_NAME MathLibrary)
set_target_properties(MathLibraryStatic PROPERTIES OUTPUT_NAME MathLibrary)
