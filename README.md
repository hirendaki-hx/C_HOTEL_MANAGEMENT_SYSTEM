# Hotel Management System

![C Language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Built with C](https://img.shields.io/badge/Built%20with-C-00599C?style=flat-square&logo=c)

A command-line based hotel management system built in **C** that handles customer management, table reservations, and waiting queues with role-based authentication.

## 🛠️ Tech Stack

**Language:** ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

**Features:**
- File I/O Operations
- Linked Lists
- Data Structures
- Role-based Authentication
- CSV Data Management

## 📁 Project Structure
```
hotel-management-system/
├── AUTHENTICATION/
│ └── Security.c
├── CUSTOMER/
│ ├── TABLES/
│ │ ├── Table.c
│ │ └── Tables.csv
│ ├── Customer.c
│ ├── Customers.csv
│ ├── Queue.c
│ └── Waiting.csv
├── Main.c
├── DFD.txt
├── LICENSE
└── README.md
```

## 🚀 Features

### 🔐 Authentication System
- **Role-based login** with different access levels
- **Admin Role**: Full access to view customers, queues, and tables
- **Reception Role**: Customer management and table assignments

### 👥 Customer Management
- Add new customers with auto-generated IDs
- Edit existing customer information
- Search customers by ID
- Display all customers in formatted tables
- Real-time CSV data persistence

### 🪑 Table Management
- 12 pre-configured tables with varying capacities (4, 8, 12 persons)
- Real-time table status tracking (Dining/Not Dining)
- Automatic table assignment based on customer party size
- Visual table status display

### ⏳ Waiting Queue System
- Automatic queue management when tables are full
- Waiting list persistence in CSV format
- Queue display functionality
- First-come-first-served table assignment

## 🛠️ Installation & Setup

### Prerequisites
- GCC Compiler
- Basic C development environment

### Compilation
```bash
gcc -o hotel_system Main.c AUTHENTICATION/Security.c CUSTOMER/Customer.c CUSTOMER/Queue.c CUSTOMER/TABLES/Table.c

./hotel_system
```
### Login Credentials
```
Role	     Password 	Access Level
Admin	     admin123  	Full system access
Reception	  desc123	  Customer operations
```
### Data Files
- Customers.csv: Stores all customer records
- Tables.csv: Manages table status and assignments
- Waiting.csv: Maintains waiting queue
