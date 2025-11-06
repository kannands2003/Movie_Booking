#include "header.h"

void admin_menu()
{
    do
    {
        printf("Enter the admin password: ");
        char pass[50];
        scanf("%s", pass);
        if (strcmp(pass, ADMIN_PASS) == 0)
        {
            printf("Access granted to Admin Menu.\n");
            // Here you can add more admin functionalities
            break;
        }
        else
        {
            printf("Incorrect password. Try again.\n");
        }
    }while (1);

    sleep(2);
    system("clear");

    int choice;
    do
    {
        printf("\n--- Admin Menu ---\n");
        printf("1. Add Movie\n");
        printf("2. Add Show\n");
        printf("3. List Movies\n");
        printf("4. List Shows\n");
        printf("5. Edit / Delete movie & show\n");
        printf("6. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1: add_movie();
                    break;
            case 2: add_show();
                    break;
            case 3: list_movies();
                    break;
            case 4: list_show();
                    break;
            case 5: edit();
                    break;
            case 6: printf("Returning to Main Menu.\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    sleep(2);
    system("clear");


}