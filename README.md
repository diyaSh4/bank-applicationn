This is a **Bank Console Application** built in **C#** that allows users to interact with bank data stored in **files**. The application includes functionalities for adding, modifying, and deleting users, as well as viewing screens for both customers and administrators. Additionally, it features a currency conversion functionality.

## Features

- **User Management:** 
  - Add new users
  - Edit existing user details
  - Delete users from the system
- **Customer Screens:**
  - View account balance
  - Transfer funds between accounts
  - View transaction history
- **Administrator Screens:**
  - View and manage customer accounts
  - Add, edit, or delete customer information
- **Currency Conversion:** 
  - Convert between different currencies
  - Real-time currency exchange rates fetched from a file (static or dynamic).
  
## Technologies Used

- **C# Console Application**
- **File System for Data Storage**
- **Basic Currency Conversion Logic**

## Project Structure

The project is organized into the following components:

1. **User Management:**
   - Users are stored in a simple text file or a CSV file. Each user has attributes such as ID, Name, Account Balance, etc.
   - Users can be added, modified, or removed based on administrator commands.
   
2. **Customer Screen:**
   - Customers can interact with their account via a console interface. They can check their balance, transfer money, and view their transaction history.
   
3. **Administrator Screen:**
   - Admins can manage customer records, modify details, and add new customers to the system.
   
4. **Currency Conversion:**
   - A simple implementation of currency conversion, where the user can convert from one currency to another using static conversion rates stored in a file.
