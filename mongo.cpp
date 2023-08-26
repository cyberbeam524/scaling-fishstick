#include <cstdint>
#include <iostream>
#include <vector>
# include <fstream>  
# include <stdio.h>  
# include <string.h>  
// custom header file:
# include "mongodbobjects.h"  

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::impl::takes_array;
using bsoncxx::builder::basic::make_document;

using namespace std;  

int main()
{

    mongocxx::instance instance{};
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);
    auto db = client["mydb"];
    auto collection = db["inventory"];
    int option = 0;

    while (option != 6 ) {  
    // This prints out all the available options in the DB
    cout << " \n Available operations: \n1. Add New "  
            "Students \n2 . "  
        << "Student Login \n3 . Faculty Login \n4 . "  
            "Proctor Login \n5 . Admin View \n "  
        << "6. Exit\nEnter option: " ;  
    cin >> option ;  

    while(!cin){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please re-enter a valid option: "; 
        cin >> option;
    }

    if (option == 1) {
    {
        string name; string expiryName; int quantity;
        cout << "Item Name: ";
        cin >> name ;  
        cout << "Quantity: "; 
        cin >> quantity;
        while(!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please re-enter quantity: "; 
            cin >> quantity;
        }
        cout << "Expiration Date: ";  
        cin >> expiryName ;  
        auto insert_one_result = collection.insert_one(
            make_document(kvp("Item Name", name),
                        kvp("Expiration Date", expiryName),
                        kvp("Quantity", quantity)));
        assert(insert_one_result);  // Acknowledged writes return results.
        auto doc_id = insert_one_result->inserted_id();
        assert(doc_id.type() == bsoncxx::type::k_oid);
    }

    }else if(option == 2){
        //  Print All Documents in a Collection
    {
        // @todo:sort by columns?
        // @todo:print the first few of the resulting dataframe?
        auto cursor_all = collection.find({});
        std::cout << "collection " << collection.name()
                  << " contains these documents:" << std::endl;
        for (auto doc : cursor_all) {
            std::cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
        }
        std::cout << std::endl;
    }
    }else if(option == 3){
    // // Delete a Single Document
    {
        string itemName;
        cout << "Item Name to delete:";  
        cin >> itemName ;  

        auto find_one_filtered_result = collection.find_one(make_document(kvp("Item Name", itemName)));
        if (find_one_filtered_result) {
            cout << "Deleted: ";
            std::cout << bsoncxx::to_json(*find_one_filtered_result, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
            auto delete_one_result = collection.delete_one(make_document(kvp("Item Name", itemName)));
            assert(delete_one_result);
            assert(delete_one_result->deleted_count() == 1);
        }else{
            cout << "This item cannot be found to be deleted";
        }
    }
    }
    }
    return 0;
}

// @todo: need totemplate function for comparing objectss with same parent -- only way of polymorphism for mehtods