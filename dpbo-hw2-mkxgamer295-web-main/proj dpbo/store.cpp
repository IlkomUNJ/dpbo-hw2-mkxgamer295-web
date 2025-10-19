#include <iostream>
#include <limits>
#include "buyer.h"


// --- Enums for Menu Choices ---
enum MainMenuChoice { MAIN_EXIT, LOGIN_SELLER, LOGIN_BUYER, LOGIN_BANK, LOGIN_STORE };
enum BuyerMenuChoice { BUYER_BACK, PURCHASE_ITEM, BUYER_BANK_ACCOUNT, ORDERS };
enum BuyerBankMenuChoice { BUYER_BANK_BACK, TOP_UP, WITHDRAW, CHECK_CASH_FLOW, CHECK_SPENDING };
enum SellerMenuChoice { SELLER_BACK, SELLER_PURCHASE_ITEM, SELLER_BANK_ACCOUNT, SELLER_ORDERS, MANAGE_ITEMS, POPULAR_ITEMS, LOYAL_CUSTOMER };
enum ManageItemsChoice { MANAGE_ITEMS_BACK, REGISTER_NEW_ITEM, DELETE_ITEM, ADD_STOCK, UPDATE_PRICE };
enum BankMenuChoice { BANK_BACK, TRANSACTION_LIST, CUSTOMER_LIST, DORMANT_ACCOUNT, TOP_USER };
enum StoreMenuChoice { STORE_BACK, LIST_TRANSACTION, STORE_POPULAR_ITEM, ACTIVE_BUYER, ACTIVE_SELLER };
enum StoreTransactionChoice { STORE_TRANSACTION_BACK, LIST_ALL, LIST_PAID, LIST_COMPLETED };
using namespace std;

// --- Function Prototypes ---
int handle_buyer_bank_account();
int handle_buyer();
int handle_manage_items();
int handle_seller();
int handle_bank();
int handle_store_transactions();
int handle_store();

// --- Menu Implementations ---

int handle_buyer_bank_account() {
    int access_choice = -1;
    std::cout << "\n--- Bank Account Access ---\n";
    std::cout << "1. Login\n";
    std::cout << "2. Register\n";
    std::cout << "Enter choice: ";
    std::cin >> access_choice;

    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate error
    }

    if (access_choice == 1) {
        std::cout << "-> Logging into bank account...\n";
    } else if (access_choice == 2) {
        std::cout << "-> Registering new bank account...\n";

    } else {
        std::cout << "Invalid choice. Returning...\n";
        return 0;
    }

        int choice = -1;
        while (choice != BUYER_BANK_BACK) {
            std::cout << "\n--- Buyer Bank Account ---\n";
            std::cout << TOP_UP << ". Top Up\n";
            std::cout << WITHDRAW << ". Withdraw\n";
            std::cout << CHECK_CASH_FLOW << ". Check Cash Flow\n";
            std::cout << CHECK_SPENDING << ". Check Spending\n";
            std::cout << BUYER_BANK_BACK << ". Back\n";
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (static_cast<BuyerBankMenuChoice>(choice)) {
                case TOP_UP: std::cout << "-> Handling Top Up...\n"; break;
                case WITHDRAW: std::cout << "-> Handling Withdraw...\n"; break;
                case CHECK_CASH_FLOW: std::cout << "-> Handling Check Cash Flow...\n"; break;
                case CHECK_SPENDING: std::cout << "-> Handling Check Spending...\n"; break;
                case BUYER_BANK_BACK: std::cout << "-> Returning to buyer menu...\n"; break;
                default: std::cout << "Invalid choice. Please try again.\n"; break;
            }
        }
        return 0;
}

int handle_buyer() {
    int choice = -1;
    while (choice != BUYER_BACK) {
        std::cout << "\n--- Buyer Menu ---\n";
        std::cout << PURCHASE_ITEM << ". Purchase Item\n";
        std::cout << BUYER_BANK_ACCOUNT << ". Bank Account\n";
        std::cout << ORDERS << ". Orders\n";
        std::cout << BUYER_BACK << ". Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (static_cast<BuyerMenuChoice>(choice)) {
            case PURCHASE_ITEM: std::cout << "-> Handling Purchase Item...\n"; break;
            case BUYER_BANK_ACCOUNT: handle_buyer_bank_account(); break;
            case ORDERS: std::cout << "-> Handling Orders...\n"; break;
            case BUYER_BACK: std::cout << "-> Logging out...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    }
    return 0;
}

int handle_manage_items() {
    int choice = -1;
    while (choice != MANAGE_ITEMS_BACK) {
        std::cout << "\n--- Manage Items ---\n";
        std::cout << REGISTER_NEW_ITEM << ". Register New Item\n";
        std::cout << DELETE_ITEM << ". Delete Item\n";
        std::cout << ADD_STOCK << ". Add Stock\n";
        std::cout << UPDATE_PRICE << ". Update Price\n";
        std::cout << MANAGE_ITEMS_BACK << ". Back\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (static_cast<ManageItemsChoice>(choice)) {
            case REGISTER_NEW_ITEM: std::cout << "-> Handling Register New Item...\n"; break;
            case DELETE_ITEM: std::cout << "-> Handling Delete Item...\n"; break;
            case ADD_STOCK: std::cout << "-> Handling Add Stock...\n"; break;
            case UPDATE_PRICE: std::cout << "-> Handling Update Price...\n"; break;
            case MANAGE_ITEMS_BACK: std::cout << "-> Returning to seller menu...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    }
    return 0;
}

int handle_seller() {
    int choice = -1;
    std::cout << "\n>>> Seller Login Successful <<<\n";
    while (choice != SELLER_BACK) {
        std::cout << "\n--- Seller Menu ---\n";
        std::cout << SELLER_PURCHASE_ITEM << ". Purchase Item\n";
        std::cout << SELLER_BANK_ACCOUNT << ". Bank Account\n";
        std::cout << SELLER_ORDERS << ". Orders\n";
        std::cout << MANAGE_ITEMS << ". Manage Items\n";
        std::cout << POPULAR_ITEMS << ". Popular Items\n";
        std::cout << LOYAL_CUSTOMER << ". Loyal Customer\n";
        std::cout << SELLER_BACK << ". Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (static_cast<SellerMenuChoice>(choice)) {
            case SELLER_PURCHASE_ITEM: std::cout << "-> Handling Purchase Item...\n"; break;
            case SELLER_BANK_ACCOUNT: handle_buyer_bank_account(); break;
            case SELLER_ORDERS: std::cout << "-> Handling Orders...\n"; break;
            case MANAGE_ITEMS: handle_manage_items(); break;
            case POPULAR_ITEMS: std::cout << "-> Handling Popular Items...\n"; break;
            case LOYAL_CUSTOMER: std::cout << "-> Handling Loyal Customer...\n"; break;
            case SELLER_BACK: std::cout << "-> Logging out...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    }
    return 0;
}

int handle_bank() {
    int choice = -1;
    std::cout << "\n>>> Bank Login Successful <<<\n";
    while (choice != BANK_BACK) {
        std::cout << "\n--- Bank Menu ---\n";
        std::cout << TRANSACTION_LIST << ". Transaction List\n";
        std::cout << CUSTOMER_LIST << ". Customer List\n";
        std::cout << DORMANT_ACCOUNT << ". Dormant Account\n";
        std::cout << TOP_USER << ". Top User\n";
        std::cout << BANK_BACK << ". Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (static_cast<BankMenuChoice>(choice)) {
            case TRANSACTION_LIST: std::cout << "-> Handling Transaction List...\n"; break;
            case CUSTOMER_LIST: std::cout << "-> Handling Customer List...\n"; break;
            case DORMANT_ACCOUNT: std::cout << "-> Handling Dormant Account...\n"; break;
            case TOP_USER: std::cout << "-> Handling Top User...\n"; break;
            case BANK_BACK: std::cout << "-> Logging out...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    }
    return 0;
}

int handle_store_transactions() {
    int choice = -1;
    while (choice != STORE_TRANSACTION_BACK) {
        std::cout << "\n--- List Transactions ---\n";
        std::cout << LIST_ALL << ". List All\n";
        std::cout << LIST_PAID << ". List Paid\n";
        std::cout << LIST_COMPLETED << ". List Completed\n";
        std::cout << STORE_TRANSACTION_BACK << ". Back\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (static_cast<StoreTransactionChoice>(choice)) {
            case LIST_ALL: std::cout << "-> Handling List All...\n"; break;
            case LIST_PAID: std::cout << "-> Handling List Paid...\n"; break;
            case LIST_COMPLETED: std::cout << "-> Handling List Completed...\n"; break;
            case STORE_TRANSACTION_BACK: std::cout << "-> Returning to store menu...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    }
    return 0;
}

int handle_store() {
    int choice = -1;
    std::cout << "\n>>> Store Login Successful <<<\n";
    while (choice != STORE_BACK) {
        std::cout << "\n--- Store Menu ---\n";
        std::cout << LIST_TRANSACTION << ". List Transaction\n";
        std::cout << STORE_POPULAR_ITEM << ". Popular Item\n";
        std::cout << ACTIVE_BUYER << ". Active Buyer\n";
        std::cout << ACTIVE_SELLER << ". Active Seller\n";
        std::cout << STORE_BACK << ". Back to Main Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (static_cast<StoreMenuChoice>(choice)) {
            case LIST_TRANSACTION: handle_store_transactions(); break;
            case STORE_POPULAR_ITEM: std::cout << "-> Handling Popular Item...\n"; break;
            case ACTIVE_BUYER: std::cout << "-> Handling Active Buyer...\n"; break;
            case ACTIVE_SELLER: std::cout << "-> Handling Active Seller...\n"; break;
            case STORE_BACK: std::cout << "-> Logging out...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    }
    return 0;
}

int main() {
    int choice = -1;

    while (choice != MAIN_EXIT) {
        std::cout << "\n====== Main Menu ======\n";
        std::cout << "Login as:\n";
        std::cout << LOGIN_SELLER << ". Seller\n";
        std::cout << LOGIN_BUYER << ". Buyer\n";
        std::cout << LOGIN_BANK << ". Bank\n";
        std::cout << LOGIN_STORE << ". Store\n";
        std::cout << MAIN_EXIT << ". Exit\n";
        std::cout << "=======================\n";
        std::cout << "Enter choice: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1; // Reset choice to avoid accidental exit
            continue;
        }

        switch (static_cast<MainMenuChoice>(choice)) {
            case LOGIN_SELLER:
                handle_seller();
                break;
            case LOGIN_BUYER:
                handle_buyer();
                break;
            case LOGIN_BANK:
                handle_bank();
                break;
            case LOGIN_STORE:
                handle_store();
                break;
            case MAIN_EXIT:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
