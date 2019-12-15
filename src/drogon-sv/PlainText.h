#pragma once

#include <drogon/HttpSimpleController.h>
#include <vector>
#include <thread>

using namespace drogon;

class PlainText : public drogon::HttpSimpleController<PlainText> {
public:
    virtual void
    asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) override;

    PATH_LIST_BEGIN
        //list path definitions here;
        //PATH_ADD("/path","filter1","filter2",HttpMethod1,HttpMethod2...);
        PATH_ADD("/hello", Get);
    PATH_LIST_END

private:
    std::vector<std::thread> threads;
    std::vector<std::future<void>> futures;
};
