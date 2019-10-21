include(ExternalProject)

set(SPDLOG_PREFIX spdlog)
ExternalProject_Add(${SPDLOG_PREFIX}
        PREFIX ${SPDLOG_PREFIX}

        GIT_REPOSITORY "https://github.com/gabime/spdlog"
        GIT_TAG "master"
        SOURCE_DIR "${CMAKE_SOURCE_DIR}/third-party/spdlog"

        CMAKE_CACHE_ARGS -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_BINARY_DIR}/spdlog

        )

#add_library(spdlog SHARED IMPORTED)
