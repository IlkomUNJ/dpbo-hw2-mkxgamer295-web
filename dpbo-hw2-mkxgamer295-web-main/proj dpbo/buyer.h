#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>


class BankCustomer {
public:
    BankCustomer(int id, const std::string& name) {}
};

#ifndef BUYER_H
#define BUYER_H

#include <cstddef>
#include <string>
#include <vector>

class Buyer {
private:
    int id;
    std::string name;
    BankCustomer &account;

    struct BuyerData {
        std::string username;
        std::string password;
    };

    std::vector<BuyerData> buyer_data_list;

public:
    Buyer(int id, const std::string& name, BankCustomer &account0)
        : id(id), name(name), account(account0) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    BankCustomer& getAccount() { return account; }

    void setId(int newId) { id = newId; }
    void setName(const std::string& newName) { name = newName; }

    void addBuyerData(const std::string& username, const std::string& password) {
        buyer_data_list.push_back({username, password});
    }

    // Method to serialize buyer data to a file
    void serialize(const std::string& filename) const {
        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
            return;
        }

        for (const auto& data : buyer_data_list) {
            outFile << data.username << " " << data.password << std::endl;
        }

        outFile.close();
        std::cout << "Data serialized successfully to " << filename << std::endl;
    }

    
    void deserialize(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            std::cerr << "Error: Could not open file for reading: " << filename << std::endl;
            return;
        }

        buyer_data_list.clear(); 
        std::string username, password;
        while (inFile >> username >> password) {
            addBuyerData(username, password);
        }

        inFile.close();
        std::cout << "Data deserialized successfully from " << filename << std::endl;
    }

    
    void printBuyerData() const {
        std::cout << "\n--- Buyer Data List ---" << std::endl;
        if (buyer_data_list.empty()) {
            std::cout << "No data available." << std::endl;
        } else {
            for (const auto& data : buyer_data_list) {
                std::cout << "Username: " << data.username << ", Password: " << data.password << std::endl;
            }
        }
        std::cout << "-----------------------\n" << std::endl;
    }
};

#endif // BUYER_H