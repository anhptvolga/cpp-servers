add_executable(drogon-sv main.cpp PlainText.h PlainText.cc ComplexController.cpp ComplexController.h demo_v1_User.h demo_v2_User.cc)
target_include_directories(drogon-sv PRIVATE drogon spdlog::spdlog)
target_link_libraries(drogon-sv PRIVATE drogon spdlog::spdlog)
