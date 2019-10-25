add_executable(drogon-sv main.cpp PlainText.h PlainText.cc ComplexController.cpp ComplexController.h)
target_include_directories(drogon-sv PRIVATE drogon)
target_link_libraries(drogon-sv PRIVATE drogon)
