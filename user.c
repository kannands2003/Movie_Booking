#include "header.h"

void user_menu()
{
    sleep(2);
    system("clear");
    int choice;
    do
    {
        printf("\n--- User Menu ---\n");
        printf("1. Book Movies\n");
        printf("2. List Bookings\n");
        printf("3. Cancel Booking\n");
        printf("4. See Booking\n");
        printf("5. Back\n");
        printf("Choice: ");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1: book_movies();
                    break;
            case 2: see_booking();
                    break;
            case 3: cancel_booking();
                    break;
            case 4: display_booking();
                    break; 
            case 5: printf("Returning too main menu ...\n\n");
                    break;
            default:printf("Invalid choice. Please try again.\n");
        }
    }while(choice != 5);
    sleep(2);
    system("clear");
}