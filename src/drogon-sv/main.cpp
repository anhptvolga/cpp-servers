#include <iostream>

#include <drogon/drogon.h>

#include "PlainText.h"

#include "ComplexController.h"

void printInfo();

int main() {

    drogon::app().addListener("0.0.0.0",80);
    //Load config file
    drogon::app().loadConfigFile("config.json");
    //Run HTTP framework,the method will block in the internal event loop

    auto xx = std::make_shared<ComplexController>();

    drogon::app()
    .registerController(xx)
    .registerHttpSimpleController("/", "PlainText");

    printInfo();

    drogon::app().run();
    return 0;

}

void printInfo() {
    // Output information of all handlers
    auto handlerInfo = app().getHandlersInfo();
    for (auto &info : handlerInfo)
    {
        std::cout << std::get<0>(info);
        switch (std::get<1>(info))
        {
            case Get:
                std::cout << " (GET) ";
                break;
            case Post:
                std::cout << " (POST) ";
                break;
            case Delete:
                std::cout << " (DELETE) ";
                break;
            case Put:
                std::cout << " (PUT) ";
                break;
            case Options:
                std::cout << " (OPTIONS) ";
                break;
            case Head:
                std::cout << " (Head) ";
                break;
            default:
                break;
        }
        std::cout << std::get<2>(info) << std::endl;
    }
}