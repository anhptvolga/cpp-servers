//
// Created by anh.phan3 on 2019-10-21.
//

#ifndef CPP_SERVERS_COMPLEXCONTROLLER_H
#define CPP_SERVERS_COMPLEXCONTROLLER_H

#include <drogon/HttpController.h>
using namespace drogon;


class ComplexController : public HttpController<ComplexController, false> {
public:
    METHOD_LIST_BEGIN
        //use METHOD_ADD to add your custom processing function here;
        METHOD_ADD(ComplexController::getInfo, "/{id}", Get);                  //path is /api/v1/ComplexController/{arg1}
        METHOD_ADD(ComplexController::getDetailInfo, "/{id}/detailinfo", Get);  //path is /api/v1/ComplexController/{arg1}/detailinfo
        METHOD_ADD(ComplexController::newComplexController, "/{name}", Post);                 //path is /api/v1/ComplexController/{arg1}
    METHOD_LIST_END
    //your declaration of processing function maybe like this:
    void getInfo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int ComplexControllerId) const;
    void getDetailInfo(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int ComplexControllerId) const;
    void newComplexController(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string &&ComplexControllerName);
public:
    ComplexController()
    {
        LOG_DEBUG << "ComplexController constructor!";
    }

};


#endif //CPP_SERVERS_COMPLEXCONTROLLER_H
