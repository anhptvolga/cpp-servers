#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>

#include <drogon/drogon.h>

#include "PlainText.h"
#include "ComplexController.h"


int main() {

    drogon::app().addListener("0.0.0.0",80);
    //Load config file
    drogon::app().loadConfigFile("../src/config.json");
    //Run HTTP framework,the method will block in the internal event loop

    auto xx = std::make_shared<ComplexController>();

    drogon::app()
    .registerController(xx)
    .registerHttpSimpleController("/", "PlainText")
    .run();
    return 0;

}
