include(FindPkgConfig)

pkg_check_modules(mongocxx
        REQUIRED
        IMPORTED_TARGET
        libmongocxx)

add_executable(cmongo main_mongo.cpp)
target_include_directories(cmongo PRIVATE PkgConfig::mongocxx)
target_link_libraries(cmongo PRIVATE PkgConfig::mongocxx)
target_compile_features(cmongo PUBLIC cxx_std_11)
