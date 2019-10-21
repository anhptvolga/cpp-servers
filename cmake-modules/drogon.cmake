include(ExternalProject)

set(DROGON_PREFIX drogon)
ExternalProject_Add(${DROGON_PREFIX}
        PREFIX ${DROGON_PREFIX}

        GIT_REPOSITORY "https://github.com/an-tao/drogon"
        GIT_TAG "v1.4.2"
        SOURCE_DIR "${CMAKE_SOURCE_DIR}/third-party/drogon"

        CMAKE_CACHE_ARGS # -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_BINARY_DIR}/drogon
#        INSTALL_COMMAND ""

        )

#add_library(drogon SHARED IMPORTED)
