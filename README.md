# 🚗 Car Rental Management System

## Overview

This project is a simple yet functional **Car Rental Management System** developed in **C**. It allows **administrators** to manage cars, clients, and reservations, and enables **clients** to register, view available cars, and manage their own reservations. The system uses **doubly linked lists** to store and manage dynamic data for cars, clients, and reservations.

---

## Features

### 🧑‍💼 Admin Functionalities
- **Manage Cars**
  - Add, modify, delete cars
  - Input: brand, model, year, availability, plate number
- **Manage Clients**
  - Add, modify, delete clients
  - Input: first name, last name, phone number, ID number
- **Manage Reservations**
  - Create, modify, delete reservations
  - Input: client ID, car model, date, time

### 🧑 Client Functionalities
- **Register as a new client**
- **View all available cars**
- **Manage personal reservations**
  - Add, modify, or delete their own reservations

---

## Data Structures

- **Car**:
  ```c
  struct Car {
      char brand[50];
      char model[50];
      int year;
      int available; // 1 = Yes, 0 = No
      char plate_number[20];
      struct Car* next;
      struct Car* prev;
  };
  ```

- **Client**:
  ```c
  struct Client {
      char first_name[50];
      char last_name[50];
      char phone_number[20];
      int ID_number;
      struct Client* next;
      struct Client* prev;
  };
  ```

- **Reservation**:
  ```c
  struct Reservation {
      int clientID;
      char carModel[50];
      char date[20];
      char time[20];
      struct Reservation* next;
      struct Reservation* prev;
  };
  ```

---

## File Structure

All code is contained in a single `main.c` file with the following components:

- `adminMenu()`, `clientMenu()` – Role-based entry points
- `manageCarsMenu()`, `manageClientsMenu()`, `manageReservationsMenu()` – Admin control panels
- `addCar()`, `modifyCar()`, `deleteCar()` – Car management
- `addClient()`, `modifyClient()`, `deleteClient()` – Client management
- `addReservation()`, `modifyReservation()`, `deleteReservation()` – Reservation management
- `displayAvailableCars()` – Show all available cars
- `registerClient()`, `manageClientReservations()` – Client reservation system

---

## How to Run

1. **Compile the code** using a C compiler:
   ```bash
   gcc -o car_rental main.c
   ```

2. **Run the program**:
   ```bash
   ./car_rental
   ```

3. **Choose your role** when prompted:
   - Enter `1` for Admin
   - Enter `0` for Client

---

## Example Usage

- Admin logs in and selects "Manage Cars"
- Adds a new car with brand/model/year/availability
- Client registers and sees available cars
- Client books a reservation by providing date and time
- Admin modifies or deletes existing records as needed

---

## Limitations & Future Improvements

- ❌ Data is not saved between sessions (no file or database support)
- 🔐 No authentication for admin or clients
- 📅 No date/time validation logic
- 🔄 Use of file I/O for persistence and real-world utility
- 🌐 Optionally, a graphical interface could enhance user experience

---

## Author

Developed as a C programming project for educational purposes. Suitable for students learning about:
- Linked lists
- Structures in C
- Menu-driven applications
- Memory management and modular functions

