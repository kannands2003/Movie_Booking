#include "header.h"

Movie movies[100]; 
int movie_count = 0;
Booking bookings[MAX_BOOKINGS];
int booking_count = 0;


int main()
{
    load_csv();

    printf("Booking Module Initialized\n");

    int choice;
    do
    {
        printf("\n=== Cinema Booking System ===\n");
        printf("1. Admin\n");
        printf("2. User\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: printf("Admin Module Selected\n\n");
                    admin_menu();
                    break;
            case 2: printf("User Module Selected\n\n");
                    user_menu();
                    break;
            case 3: printf("Exiting the system. Goodbye!\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    sleep(2);

    return 0;
}