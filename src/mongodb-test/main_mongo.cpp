//
// Created by anh.phan3 on 10/25/19.
//

#include <iostream>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

int main() {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{"mongodb://10.20.43.48:27017"}};

    bsoncxx::builder::stream::document document{};

    auto database = conn["tala"];
    auto collection = database["catalog_product"];


//    auto product = collection.find_one(document{} << "id" << 349732 << finalize);
    auto product = collection.find_one(make_document(kvp("id", 349732)));
    std::cout << bsoncxx::to_json(product.value()) << std::endl;
//    for (auto&& doc : cursor) {
//        std::cout << bsoncxx::to_json(doc) << std::endl;
//    }

    return 0;
}
