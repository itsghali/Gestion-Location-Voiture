#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Car {
    char brand[50];
    char model[50];
    int year;
    int available;
    char plate_number[20];
    struct Car* next;
    struct Car* prev;
};

struct Client {
    char first_name[50];
    char last_name[50];
    char phone_number[20];
    int ID_number;
    struct Client* next;
    struct Client* prev;
};

struct Reservation {
    int clientID;
    char carModel[50];
    char date[20];
    char time[20];
    struct Reservation* next;
    struct Reservation* prev;
};
struct Car* carList = NULL;
struct Client* clientList = NULL;
struct Reservation* reservationList = NULL;

// Function prototypes
void adminMenu();
void clientMenu();
void manageCarsMenu();
void manageClientsMenu();
void manageReservationsMenu();
void addCar();
void deleteCar();
void modifyCar();
void addClient();
void deleteClient();
void modifyClient();
void addReservation();
void deleteReservation();
void modifyReservation();
void displayAvailableCars();
void displayCar(struct Car* car);
void displayClient(struct Client* client);

void adminMenu() {
    int choice;
    do {
        printf("\nAdmin Menu\n");
        printf("1. Manage Cars\n");
        printf("2. Manage Clients\n");
        printf("3. Manage Reservations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                manageCarsMenu();
                break;
            case 2:
                manageClientsMenu();
                break;
            case 3:
                manageReservationsMenu();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void clientMenu() {
    int choice;
    do {
        printf("\nClient Menu\n");
        printf("1. Registration\n");
        printf("2. Manage Reservations\n");
        printf("3. See Available Cars\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerClient();
                break;
            case 2:
                manageClientReservations();
                break;
            case 3:
                displayAvailableCars();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void manageCarsMenu() {
    int choice;
    do {
        printf("\nManage Cars Menu\n");
        printf("1. Add a Car\n");
        printf("2. Delete a Car\n");
        printf("3. Modify a Car\n");
        printf("4. Back to Admin Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                deleteCar();
                break;
            case 3:
                modifyCar();
                break;
            case 4:
                printf("Returning to Admin Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void addCar() {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    if (newCar == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter brand: ");
    scanf("%s", newCar->brand);
    printf("Enter model: ");
    scanf("%s", newCar->model);
    printf("Enter year: ");
    scanf("%d", &newCar->year);
    printf("Is the car available? (1 for Yes, 0 for No): ");
    scanf("%d", &newCar->available);
    printf("Enter plate number: ");
    scanf("%s",newCar->plate_number);
    newCar->next = NULL;
    newCar->prev = NULL;
    if (carList == NULL) {
        carList = newCar;
    } else {
        struct Car* temp = carList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newCar;
        newCar->prev = temp;
    }

    printf("Car added successfully.\n");
}

void deleteCar() {
    if (carList == NULL) {
        printf("No cars to delete.\n");
        return;
    }
    char plateToDelete[20];
    printf("Enter the plate number of the car to delete: ");
    scanf("%s", plateToDelete);
    struct Car* current = carList;
    struct Car* prev = NULL;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->plate_number, plateToDelete) == 0) {
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (found) {
        if (prev == NULL) {
            carList = current->next;
            if (carList != NULL) {
                carList->prev = NULL;
            }
        } else {
            prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = prev;
            }
        }
        free(current);
        printf("Car with plate number %s deleted successfully.\n", plateToDelete);
    } else {
        printf("Car with plate number %s not found.\n", plateToDelete);
    }
}
void modifyCar() {
    if (carList == NULL) {
        printf("No cars to modify.\n");
        return;
    }
    char plateToModify[20];
    printf("Enter the plate number of the car to modify: ");
    if (scanf("%19s", plateToModify) != 1) {
        printf("Invalid input. Please enter a valid plate number.\n");
        return;
    }
    struct Car* current = carList;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->plate_number, plateToModify) == 0) {
            found = 1;
            break;
        }
        current = current->next;
    }
    if (found) {
        printf("Enter new brand: ");
        scanf("%s", current->brand);
        printf("Enter new model: ");
        scanf("%s", current->model);
        printf("Enter new year: ");
        scanf("%d", &current->year);
        printf("Is the car available? (1 for Yes, 0 for No): ");
        scanf("%d", &current->available);
        printf("Car details modified successfully.\n");
    } else {
        printf("Car with plate number %s not found.\n", plateToModify);
    }
}
void manageClientsMenu() {
    int choice;
    do {
        printf("\nManage Clients Menu\n");
        printf("1. Add a Client\n");
        printf("2. Delete a Client\n");
        printf("3. Modify a Client\n");
        printf("4. Back to Admin Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addClient();
                break;
            case 2:
                deleteClient();
                break;
            case 3:
                modifyClient();
                break;
            case 4:
                printf("Returning to Admin Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}
void manageReservationsMenu() {
    int choice;
    do {
        printf("\nManage Reservations Menu\n");
        printf("1. Add a Reservation\n");
        printf("2. Delete a Reservation\n");
        printf("3. Modify a Reservation\n");
        printf("4. Back to Admin Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addReservation();
                break;
            case 2:
                deleteReservation();
                break;
            case 3:
                modifyReservation();
                break;
            case 4:
                printf("Returning to Admin Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}
void addClient() {
    struct Client* newClient = (struct Client*)malloc(sizeof(struct Client));
    if (newClient == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter first name: ");
    scanf("%s", newClient->first_name);
    while (getchar() != '\n');
    printf("Enter last name: ");
    scanf("%s", newClient->last_name);
    while (getchar() != '\n');
    printf("Enter phone number: ");
    scanf("%s", newClient->phone_number);
    while (getchar() != '\n');
    printf("Enter ID number: ");
    scanf("%d", &newClient->ID_number);
    while (getchar() != '\n');
    newClient->next = NULL;
    newClient->prev = NULL;
    if (clientList == NULL) {
        clientList = newClient;
    } else {
        struct Client* temp = clientList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newClient;
        newClient->prev = temp;
    }
    printf("Client added successfully.\n");
}
void deleteClient() {
    if (clientList == NULL) {
        printf("No clients to delete.\n");
        return;
    }
    int idToDelete;
    printf("Enter the ID number of the client to delete: ");
    scanf("%d", &idToDelete);
    struct Client* current = clientList;
    struct Client* prev = NULL;
    int found = 0;
    while (current != NULL) {
        if (current->ID_number == idToDelete) {
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (found) {
        if (prev == NULL) {
            clientList = current->next;
            if (clientList != NULL) {
                clientList->prev = NULL;
            }
        } else {
            prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = prev;
            }
        }
        free(current);
        printf("Client with ID number %d deleted successfully.\n", idToDelete);
    } else {
        printf("Client with ID number %d not found.\n", idToDelete);
    }
}
void modifyClient() {
    if (clientList == NULL) {
        printf("No clients to modify.\n");
        return;
    }
    int idToModify;
    printf("Enter the ID number of the client to modify: ");
    if (scanf("%d", &idToModify) != 1) {
        printf("Invalid input. Please enter a valid ID number.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    struct Client* current = clientList;
    int found = 0;
    while (current != NULL) {
        if (current->ID_number == idToModify) {
            found = 1;
            break;
        }
        current = current->next;
    }
    if (found) {
        printf("Client found. Modify the client information:\n");
        printf("Enter new first name: ");
        scanf("%s", current->first_name);
        while (getchar() != '\n');
        printf("Enter new last name: ");
        scanf("%s", current->last_name);
        while (getchar() != '\n');
        printf("Enter new phone number: ");
        while (getchar() != '\n');
        printf("Client information modified successfully.\n");
    } else {
        printf("Client with ID number %d not found.\n", idToModify);
    }
}
void addReservation() {
    struct Reservation* newReservation = (struct Reservation*)malloc(sizeof(struct Reservation));
    if (newReservation == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter client ID number: ");
    scanf("%d", &newReservation->clientID);
    printf("Enter car model: ");
    scanf("%s", newReservation->carModel);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newReservation->date);
    printf("Enter time (HH:MM): ");
    scanf("%s", newReservation->time);
    newReservation->next = NULL;
    newReservation->prev = NULL;
    if (reservationList == NULL) {
        reservationList = newReservation;
    } else {
        struct Reservation* temp = reservationList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newReservation;
        newReservation->prev = temp;
    }
    printf("Reservation added successfully.\n");
}
void deleteReservation() {
    if (reservationList == NULL) {
        printf("No reservations to delete.\n");
        return;
    }
    int clientID;
    char carModel[50];
    char date[20];
    char time[20];
    printf("Enter client ID number: ");
    scanf("%d", &clientID);
    printf("Enter car model: ");
    scanf("%s", carModel);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter time (HH:MM): ");
    scanf("%s", time);
    struct Reservation* current = reservationList;
    struct Reservation* prev = NULL;
    int found = 0;
    while (current != NULL) {
        if (current->clientID == clientID && strcmp(current->carModel, carModel) == 0 &&
            strcmp(current->date, date) == 0 && strcmp(current->time, time) == 0) {
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (found) {
        if (prev == NULL) {
            reservationList = current->next;
            if (reservationList != NULL) {
                reservationList->prev = NULL;
            }
        } else {
            prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = prev;
            }
        }
        free(current);
        printf("Reservation deleted successfully.\n");
    } else {
        printf("Reservation not found.\n");
    }
}
void modifyReservation() {
    if (reservationList == NULL) {
        printf("No reservations to modify.\n");
        return;
    }
    int clientID;
    char carModel[50];
    char date[20];
    char time[20];
    printf("Enter client ID number of the reservation to modify: ");
    scanf("%d", &clientID);
    printf("Enter car model of the reservation to modify: ");
    scanf("%s", carModel);
    printf("Enter date (YYYY-MM-DD) of the reservation to modify: ");
    scanf("%s", date);
    printf("Enter time (HH:MM) of the reservation to modify: ");
    scanf("%s", time);
    struct Reservation* current = reservationList;
    int found = 0;
    while (current != NULL) {
        if (current->clientID == clientID && strcmp(current->carModel, carModel) == 0 &&
            strcmp(current->date, date) == 0 && strcmp(current->time, time) == 0) {
            found = 1;
            break;
        }
        current = current->next;
    }
    if (found) {
        // Input new reservation details
        printf("Enter new car model: ");
        scanf("%s", current->carModel);
        printf("Enter new date (YYYY-MM-DD): ");
        scanf("%s", current->date);
        printf("Enter new time (HH:MM): ");
        scanf("%s", current->time);
        printf("Reservation details modified successfully.\n");
    } else {
        printf("Reservation not found.\n");
    }
}
void displayAvailableCars() {
    if (carList == NULL) {
        printf("No cars available.\n");
        return;
    }

    printf("Available Cars:\n");
    struct Car* current = carList;
    while (current != NULL) {
        if (current->available == 1) {
            printf("Brand: %s\n", current->brand);
            printf("Model: %s\n", current->model);
            printf("Year: %d\n", current->year);
            printf("Plate Number: %s\n", current->plate_number);
            printf("\n");
        }
        current = current->next;
    }
}
void displayCar(struct Car* car) {
    printf("Brand: %s\n", car->brand);
    printf("Model: %s\n", car->model);
    printf("Year: %d\n", car->year);
    printf("Available: %s\n", car->available ? "Yes" : "No");
    printf("Plate Number: %s\n", car->plate_number);
}
void displayClient(struct Client* client) {
    printf("First Name: %s\n", client->first_name);
    printf("Last Name: %s\n", client->last_name);
    printf("Phone Number: %s\n", client->phone_number);
    printf("ID Number: %d\n", client->ID_number);
}
void registerClient() {
    struct Client* newClient = (struct Client*)malloc(sizeof(struct Client));
    if (newClient == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter first name: ");
    scanf("%s", newClient->first_name);
    printf("Enter last name: ");
    scanf("%s", newClient->last_name);
    printf("Enter phone number: ");
    scanf("%s", newClient->phone_number);
    printf("Enter ID number: ");
    scanf("%d", &newClient->ID_number);
    newClient->next = NULL;
    newClient->prev = NULL;
    if (clientList == NULL) {
        clientList = newClient;
    } else {
        struct Client* temp = clientList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newClient;
        newClient->prev = temp;
    }
    printf("Client registered successfully.\n");
}
void manageClientReservations() {
    int clientID;
    printf("Enter your client ID: ");
    scanf("%d", &clientID);
    struct Client* current = clientList;
    while (current != NULL) {
        if (current->ID_number == clientID) {
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Client not found.\n");
        return;
    }
    int choice;
    do {
        printf("\nManage Reservations\n");
        printf("1. Add Reservation\n");
        printf("2. Modify Reservation\n");
        printf("3. Delete Reservation\n");
        printf("4. Back to Client Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addReservation(clientID);
                break;
            case 2:
                modifyReservation(clientID);
                break;
            case 3:
                deleteReservation(clientID);
                break;
            case 4:
                printf("Returning to Client Menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}
void addReservationclient(int clientID) {
    struct Reservation* newReservation = (struct Reservation*)malloc(sizeof(struct Reservation));
    if (newReservation == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newReservation->clientID = clientID;
    printf("Enter car model: ");
    scanf("%s", newReservation->carModel);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newReservation->date);
    printf("Enter time (HH:MM): ");
    scanf("%s", newReservation->time);
    newReservation->next = NULL;
    newReservation->prev = NULL;
    if (reservationList == NULL) {
        reservationList = newReservation;
    } else {
        struct Reservation* temp = reservationList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newReservation;
        newReservation->prev = temp;
    }

    printf("Reservation added successfully.\n");
}
void modifyReservationClient(int clientID) {
    char carModel[50];
    char date[20];
    char time[20];
    printf("Enter car model of the reservation to modify: ");
    scanf("%s", carModel);
    printf("Enter date (YYYY-MM-DD) of the reservation to modify: ");
    scanf("%s", date);
    printf("Enter time (HH:MM) of the reservation to modify: ");
    scanf("%s", time);
    struct Reservation* current = reservationList;
    int found = 0;
    while (current != NULL) {
        if (current->clientID == clientID && strcmp(current->carModel, carModel) == 0 &&
            strcmp(current->date, date) == 0 && strcmp(current->time, time) == 0) {
            found = 1;
            break;
        }
        current = current->next;
    }
    if (found) {
        printf("Enter new car model: ");
        scanf("%s", current->carModel);
        printf("Enter new date (YYYY-MM-DD): ");
        scanf("%s", current->date);
        printf("Enter new time (HH:MM): ");
        scanf("%s", current->time);

        printf("Reservation details modified successfully.\n");
    } else {
        printf("Reservation not found.\n");
    }
}
void deleteReservationClient(int clientID) {
    char carModel[50];
    char date[20];
    char time[20];
    printf("Enter car model of the reservation to delete: ");
    scanf("%s", carModel);
    printf("Enter date (YYYY-MM-DD) of the reservation to delete: ");
    scanf("%s", date);
    printf("Enter time (HH:MM) of the reservation to delete: ");
    scanf("%s", time);
    struct Reservation* current = reservationList;
    struct Reservation* prev = NULL;
    int found = 0;
    while (current != NULL) {
        if (current->clientID == clientID && strcmp(current->carModel, carModel) == 0 &&
            strcmp(current->date, date) == 0 && strcmp(current->time, time) == 0) {
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (found) {
        if (prev == NULL) {
            reservationList = current->next;
            if (reservationList != NULL) {
                reservationList->prev = NULL;
            }
        } else {
            prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = prev;
            }
        }
        free(current);
        printf("Reservation deleted successfully.\n");
    } else {
        printf("Reservation not found.\n");
    }
}
int main() {
    int isAdmin;
    printf("Are you an admin? (1 for Yes, 0 for No): ");
    scanf("%d", &isAdmin);

    if (isAdmin) {
        adminMenu();
    } else {
        clientMenu();
    }

    return 0;
}
