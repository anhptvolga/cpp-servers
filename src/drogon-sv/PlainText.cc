#include "PlainText.h"
#include <chrono>
#include <unistd.h>

#include <spdlog/spdlog.h>

void foo(std::function<void(const HttpResponsePtr &)> && callback) {
    auto resp=HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("Hello World!");
    spdlog::info("sleeping long");
//    std::this_thread::sleep_for(std::chrono::seconds(1));
    sleep(1);
    spdlog::info("sleeping done");
    callback(resp);
}

void PlainText::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    //write your application logic here

    spdlog::info("processing abc");

//    app().getLoop()->queueInLoop([callback] {
//    trantor::EventLoop::getEventLoopOfCurrentThread()->queueInLoop([callback] {

//    auto callbackPtr =
//            std::make_shared<std::function<void(const HttpResponsePtr &)>>(
//                    std::move(callback));


    futures.push_back(std::async([callback=std::move(callback)] {
        auto resp=HttpResponse::newHttpResponse();
        resp->setStatusCode(k200OK);
        resp->setContentTypeCode(CT_TEXT_HTML);
        resp->setBody("Hello World!");
        spdlog::info("sleeping long");
//    std::this_thread::sleep_for(std::chrono::seconds(1));
        sleep(1);
        spdlog::info("sleeping done");
        callback(resp);
    }));

//    threads.emplace_back(foo, std::move(callback));

    spdlog::info("-------------");
}