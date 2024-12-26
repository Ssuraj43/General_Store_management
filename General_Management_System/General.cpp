#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class GeneralStore {
    string itemID, itemName;
    int itemQuantity, itemPrice;
    fstream file, tempFile;
    int totalAmount, quantity, itemRate;
    string search;
    string choice;

public:
    void addProduct();
    void viewProduct();
    void buyProduct();
    void deleteProduct();
    void updateProduct();
} obj;

int main() {
    char choice;
    while (true) {
        cout << "\n--- General Store Management System ---\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Buy Product\n";
        cout << "4. Delete Product\n";
        cout << "5. Update Product\n";
        cout << "0. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            obj.addProduct();
            break;
        case '2':
            obj.viewProduct();
            break;
        case '3':
            obj.buyProduct();
            break;
        case '4':
            obj.deleteProduct();
            break;
        case '5':
            obj.updateProduct();
            break;
        case '0':
            exit(0);
        default:
            cout << "Invalid Selection! Please try again.\n";
            break;
        }
    }
    return 0;
}

void GeneralStore::addProduct() {
    cout << "Enter Product ID: ";
    cin >> itemID;
    cout << "Enter Product Name: ";
    cin >> itemName;
    cout << "Enter Product Quantity: ";
    cin >> itemQuantity;
    cout << "Enter Per Product Price: ";
    cin >> itemPrice;

    file.open("data.txt", ios::out | ios::app);
    file << itemID << " " << itemName << " " << itemQuantity << " " << itemPrice << endl;
    file.close();

    cout << "Product added successfully!\n";
}

void GeneralStore::viewProduct() {
    file.open("data.txt", ios::in);
    if (!file) {
        cout << "No products found!\n";
        return;
    }

    cout << "\n--- Product List ---\n";
    cout << left << setw(15) << "Product ID" << setw(20) << "Product Name" << setw(10) << "Quantity" << "Price\n";
    cout << "----------------------------------------------\n";

    while (file >> itemID >> itemName >> itemQuantity >> itemPrice) {
        cout << left << setw(15) << itemID << setw(20) << itemName << setw(10) << itemQuantity << itemPrice << endl;
    }
    file.close();
}

void GeneralStore::buyProduct() {
    choice = "y";
    while (choice == "y" || choice == "Y") {
        file.open("data.txt", ios::in);
        tempFile.open("temp.txt", ios::out | ios::app);

        cout << "Enter Product ID: ";
        cin >> search;
        cout << "Enter Quantity: ";
        cin >> quantity;

        bool found = false;
        totalAmount = 0;

        while (file >> itemID >> itemName >> itemQuantity >> itemPrice) {
            if (itemID == search) {
                found = true;
                if (itemQuantity >= quantity) {
                    itemQuantity -= quantity;
                    itemRate = quantity * itemPrice;
                    totalAmount += itemRate;
                    cout << "\n--- Payment Bill ---\n";
                    cout << "Total Purchase Amount: " << totalAmount << endl;
                } else {
                    cout << "Not enough quantity available!\n";
                }
            }
            tempFile << itemID << " " << itemName << " " << itemQuantity << " " << itemPrice << endl;
        }
        if (!found) {
            cout << "Product not found!\n";
        }

        file.close();
        tempFile.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");

        cout << "Continue shopping? (Y / N): ";
        cin >> choice;
    }
}

void GeneralStore::deleteProduct() {
    cout << "Enter Product ID to delete: ";
    cin >> search;

    file.open("data.txt", ios::in);
    tempFile.open("temp.txt", ios::out | ios::app);

    bool found = false;
    while (file >> itemID >> itemName >> itemQuantity >> itemPrice) {
        if (itemID != search) {
            tempFile << itemID << " " << itemName << " " << itemQuantity << " " << itemPrice << endl;
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found) {
        cout << "Product deleted successfully!\n";
    } else {
        cout << "Product not found!\n";
    }
}

void GeneralStore::updateProduct() {
    cout << "Enter Product ID to update: ";
    cin >> search;

    file.open("data.txt", ios::in);
    tempFile.open("temp.txt", ios::out | ios::app);

    bool found = false;
    while (file >> itemID >> itemName >> itemQuantity >> itemPrice) {
        if (itemID == search) {
            found = true;
            cout << "Enter new Product Name: ";
            cin >> itemName;
            cout << "Enter new Quantity: ";
            cin >> itemQuantity;
            cout << "Enter new Price: ";
            cin >> itemPrice;
        }
        tempFile << itemID << " " << itemName << " " << itemQuantity << " " << itemPrice << endl;
    }

    file.close();
    tempFile.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found) {
        cout << "Product updated successfully!\n";
    } else {
        cout << "Product not found!\n";
    }
}
