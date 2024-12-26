General Store Management System

This project is a simple command-line program for managing a general store's inventory. It allows users to add, view, buy, delete, and update products in the store. The data is stored in a text file (data.txt), making it lightweight and easy to use. Below is an overview of the features and how they work.

Features

Add Product

Adds a new product to the inventory.

The user provides details like Product ID, Name, Quantity, and Price.

The data is saved in data.txt.

View Products

Displays a list of all available products in the store.

The details include Product ID, Name, Quantity, and Price.

Buy Product

Allows customers to purchase products.

The user enters the Product ID and Quantity to buy.

If sufficient quantity is available, the purchase amount is displayed, and the inventory is updated.

Supports continuous shopping until the user decides to exit.

Delete Product

Removes a product from the inventory by its Product ID.

Updates the inventory file after deletion.

Update Product

Updates the details of an existing product (Name, Quantity, or Price).

The user provides the Product ID to locate the item and the new details.

Exit

Ends the program.

How It Works

Data Storage

All product data is stored in a text file named data.txt.

Each product is stored as a single line with the format: 
ProductID ProductName Quantity Price

File Handling

The program uses file streams (fstream) to read and write data.

Temporary files (temp.txt) are used for operations like delete and update to ensure data integrity.

User Interaction

The program is menu-driven, providing clear options for the user.

Input validation ensures proper functioning (e.g., checking if a product exists before performing operations). 

Example Scenarios

Adding a Product:

Input: Product ID: P001, Name: Soap, Quantity: 50, Price: 30

Output: "Product added successfully!"

Viewing Products:

Output:
Product ID    Product Name         Quantity   Price
--------------------------------------------------------
P001          Soap                 50         30 

Buying a Product:

Input: Product ID: P001, Quantity: 5

Output: 
--- Payment Bill ---
Total Purchase Amount: 150 

Deleting a Product:

Input: Product ID: P001

Output: "Product deleted successfully!"

Updating a Product:

Input: Product ID: P001, New Name: Shampoo, New Quantity: 40, New Price: 60

Output: "Product updated successfully!"

Conclusion

This project is an easy-to-use system for managing a small store's inventory. It demonstrates key concepts of file handling, class design, and menu-driven user interaction in C++.
