#include <cstdint>
#include <iostream>
#include <vector>


#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
// #include <"/usr/local/include/mongocxx/v_noabi/mongocxx/uri.hpp">
// #include <"/usr/local/include/bsoncxx/v_noabi/bsoncxx">
// #include <"./mongo-cxx-driver-r3.8.0/src/bsoncxx/builder/basic/document.hpp">
// #include <"./mongo-cxx-driver-r3.8.0/src/mongocxx/client.hpp">
// #include <"./mongo-cxx-driver-r3.8.0/src/mongocxx/instance.hpp">
// #include <"./mongo-cxx-driver-r3.8.0/src/mongocxx/stdx.hpp">
// #include <"./mongo-cxx-driver-r3.8.0/src/mongocxx/uri.hpp">

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::impl::takes_array;
using bsoncxx::builder::basic::make_document;





int main()
{

    mongocxx::instance instance{}; // This should be done only once.
mongocxx::uri uri("mongodb://localhost:27017");
mongocxx::client client(uri);

    auto db = client["mydb"];
    auto collection = db["test"];

    // Create a Document
    {
        auto doc_value = make_document(
            kvp("name", "MongoDB"),
            kvp("type", "database"),
            kvp("count", 1),
            kvp("versions", make_array("v6.0", "v5.0", "v4.4", "v4.2", "v4.0", "v3.6")),
            kvp("info", make_document(kvp("x", 203), kvp("y", 102))));

        auto doc_view = doc_value.view();
        auto element = doc_view["name"];
        assert(element.type() == bsoncxx::type::k_string);
        auto name = element.get_string().value;  // For C++ driver version < 3.7.0, use get_utf8()
        assert(0 == name.compare("MongoDB"));
    }

     // Insert One Document: { "i": 0 }
    {
        auto insert_one_result = collection.insert_one(make_document(kvp("i", 0)));
        assert(insert_one_result);  // Acknowledged writes return results.
        auto doc_id = insert_one_result->inserted_id();
        assert(doc_id.type() == bsoncxx::type::k_oid);
    }


     // Print All Documents in a Collection
    {
        auto cursor_all = collection.find({});
        std::cout << "collection " << collection.name()
                  << " contains these documents:" << std::endl;
        for (auto doc : cursor_all) {
            std::cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
        }
        std::cout << std::endl;
    }



    return 0;
}

