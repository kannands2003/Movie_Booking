#include "header.h"

void add_movie()
{
    if (movie_count >= MAX_MOVIES)
    {
        printf("Movie storage full!\n");
        return;
    }

    printf("Enter the movie name : ");
    scanf(" %[^\n]", movies[movie_count].movie_name);

    printf("Enter the duration (in hour): ");
    scanf("%f", &movies[movie_count].duration);
    printf("Movie '%s' added successfully!\n", movies[movie_count].movie_name);

    movie_count++;
    save_csv();

    sleep(3);
    system("clear");

    
}

void add_show()
{
    list_movies();
    int i, flag = 0;
    do
    {
        printf("Enter the movie name for which you want to add showtime: ");
        char movie[50];
        scanf(" %[^\n]", movie);

        for (i = 0; i < movie_count; i++)
        {
            if (strcmp(movies[i].movie_name, movie) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printf("Movie not found. Please try again.\n");
        }
    } while(flag == 0);

    if (movies[i].total_shows >= MAX_SHOWS)
    {
        printf("Maximum shows reached for this movie!\n");
        return;
    }

    char showtime[10];
    while(1)
    {
        printf("Enter the showtime (e.g., 06:30PM or 10:00AM): ");
        scanf("%9s", showtime);

        // Validate format: XX:XXAM or XX:XXPM (8 chars min)
        int len = strlen(showtime);
        if(len >= 7 &&
           showtime[2] == ':' &&
           (strcmp(&showtime[len-2], "AM") == 0 || strcmp(&showtime[len-2], "PM") == 0))
        {
            break;
        }
        printf("❌ Invalid format! Use HH:MMAM / HH:MMPM\n");
    }

    strcpy(movies[i].show_times[movies[i].total_shows], showtime);
    movies[i].total_shows++;

    printf("✅ Showtime '%s' added to movie '%s'\n", showtime, movies[i].movie_name);

    save_csv();

    sleep(3);
    system("clear");
}


void edit()
{
    printf("Edit / Delete the movies or show time.\n");

    int choice;
    do
    {
        printf("\n--- Edit / Delete Menu ---\n");
        printf("1. Edit Movie\n");
        printf("2. Delete Movie\n");
        printf("3. Edit Show Time\n");
        printf("4. Delete Show Time\n");
        printf("5. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: list_movies();
                    edit_movie();
                    break;
            case 2: list_movies();
                    delete_movie();
                    break;
            case 3: list_show();
                    edit_show();
                    break;
            case 4: list_show();
                    delete_show();
                    break;
            case 5: printf("Returning to Admin Menu.\n");
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }
    }while (choice != 5);

    save_csv();

    sleep(3);
    system("clear");
}


void edit_movie()
{
    int flag = 0, i;
    do{
        char movie_name[50];
        printf("Enter the movie name to edit: ");
        scanf(" %[^\n]", movie_name);

        for (i = 0; i < movie_count; i++)
        {
            if (strcmp(movies[i].movie_name, movie_name) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (i == movie_count)
        {
            printf("Movie not found. Please try again.\n");
        } 
    }while(flag == 0);


    printf("Enter new movie name: ");
    scanf(" %[^\n]", movies[i].movie_name);

    printf("Enter new duration (in hour): ");
    scanf("%f", &movies[i].duration);

    printf("Movie details updated successfully!\n");

    save_csv();

    sleep(3);
    system("clear");
}

void delete_movie()
{
    int flag = 0, i;
    do{
        char movie_name[50];
        printf("Enter the movie name to delete: ");
        scanf(" %[^\n]", movie_name);

        for (i = 0; i < movie_count; i++)
        {
            if (strcmp(movies[i].movie_name, movie_name) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (i == movie_count)
        {
            printf("Movie not found. Please try again.\n");
        } 
    }while(flag == 0);

    for (int j = i; j < movie_count - 1; j++)
    {
        movies[j] = movies[j + 1];
    }
    movie_count--;
    printf("Movie deleted successfully!\n");

    save_csv();

    sleep(3);
    system("clear");
}

void edit_show()
{
    int flag = 0, i;
    do{
        char movie_name[50];
        printf("Enter the movie name to edit show time: ");
        scanf(" %[^\n]", movie_name);

        for (i = 0; i < movie_count; i++)
        {
            if (strcmp(movies[i].movie_name, movie_name) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printf("Movie not found. Try again.\n");
        }
    } while(flag == 0);

    int show_index;
    do
    {
        printf("Enter show number to edit (1 to %d): ", movies[i].total_shows);
        scanf("%d", &show_index);

        if(show_index < 1 || show_index > movies[i].total_shows)
            printf("Invalid show number!\n");

    } while(show_index < 1 || show_index > movies[i].total_shows);

    char new_show[10];
    while(1)
    {
        printf("Enter new show time (e.g., 08:30PM): ");
        scanf("%9s", new_show);

        int len = strlen(new_show);
        if(len >= 7 &&
           new_show[2] == ':' &&
           (strcmp(&new_show[len-2], "AM") == 0 || strcmp(&new_show[len-2], "PM") == 0))
        {
            break;
        }
        printf("❌ Invalid format! Use HH:MMAM / HH:MMPM\n");
    }

    strcpy(movies[i].show_times[show_index - 1], new_show);
    printf("✅ Show time updated successfully!\n");

    save_csv();

    sleep(3);
    system("clear");
}

void delete_show()
{
    int flag = 0, i;
    do{
        char movie_name[50];
        printf("Enter the movie name to delete show time: ");
        scanf(" %[^\n]", movie_name);

        for (i = 0; i < movie_count; i++)
        {
            if (strcmp(movies[i].movie_name, movie_name) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (i == movie_count)
        {
            printf("Movie not found. Please try again.\n");
        } 
    }while(flag == 0);

    int show_index;
    do
    {
        printf("Enter the show number to delete (1 to %d): ", movies[i].total_shows);
        scanf("%d", &show_index);
        
        if (show_index < 1 || show_index > movies[i].total_shows)
        {
            printf("Invalid show number.\n");
        }
    }while (show_index < 1 || show_index > movies[i].total_shows);

    for (int j = show_index - 1; j < movies[i].total_shows - 1; j++)
    {
        strcpy(movies[i].show_times[j], movies[i].show_times[j + 1]);
    }
    movies[i].total_shows--;
    printf("Show time deleted successfully!\n");

    save_csv();

    sleep(3);
    system("clear");
}

void list_movies()
{
    if (movie_count == 0)
    {
        printf("No movies available.\n");
        return;
    }

    printf("\n--- List of Movies ---\n");
    for (int i = 0; i < movie_count; i++)
    {
        printf("Movie %d: %s, Duration: %.2f hours\n", i + 1, movies[i].movie_name, movies[i].duration);
    }

    printf("\n\n");
}

void list_show()
{
    if (movie_count == 0)
    {
        printf("No movies available to show times.\n");
        return;
    }

    printf("\n--- List of Shows ---\n");
    for (int i = 0; i < movie_count; i++)
    {
        printf("Movie: %s\n", movies[i].movie_name);
        for (int j = 0; j < movies[i].total_shows; j++)
        {
            printf("  Show %d: %s\n", j + 1, movies[i].show_times[j]);
        }
    }
    printf("\n\n");
}   

void book_movies()
{
    list_movies();
    if (movie_count == 0)
    {
        printf("No movies available to book.\n");
        return;
    }
    int choice;
    do
    {
        printf("Enter the movie number to book or 0 to go back: ");
        
        scanf("%d", &choice);  
        if (choice < 1 || choice > movie_count)
        {
            printf("Invalid movie number try again.\n");
        }
        if (choice == 0)
        {
            return;
        }
    }while (choice < 1 || choice > movie_count);

    int movie_index = choice - 1;
    list_showtimes(movie_index);

    int show_choice;
    do
    {
        printf("Enter the show number to book or 0 to go back: ");
        
        scanf("%d", &show_choice);  
        if (show_choice < 1 || show_choice > movies[movie_index].total_shows)
        {
            printf("Invalid show number try again.\n");
        }
        if (show_choice == 0)
        {
            return;
        }
    }while (show_choice < 1 || show_choice > movies[movie_index].total_shows);

    int show_index = show_choice - 1;
    make_booking(movie_index, show_index);

    save_csv();

    sleep(5);
    system("clear");

}

void make_booking(int movie_index, int show_index)
{
    if (booking_count >= MAX_BOOKINGS)
    {
        printf("Booking limit reached. Cannot make more bookings.\n");
        return;
    }

    display(movie_index, show_index);

    int seat_count, con;
    int seat_class;  // ✅ Store selected class (1=Gold, 2=Platinum)

    do
    {
        printf("How many seats do you want to book? ");
        scanf("%d", &seat_count);

        if(seat_count <= 0 || seat_count > 20)
        {
            printf("Invalid number of seats!\n");
            return;
        }

        int res;
        do
        {
            printf("Choose the class\n");
            printf("1. Gold (Front seats)\n");
            printf("2. Platinum (Rear seats)\n");
            scanf("%d", &seat_class);

            res = price(seat_count, seat_class);

        }while(res != 1);

        printf("Are you continue? If yes press 1 else 0(go back): ");
        scanf("%d", &con);

        if(con == 0) 
            return;
        else if(con != 1) 
            printf("Error give a valid input!\n");

    }while(con != 1);

    // ✅ Seat booking with class restriction
    for(int s = 0; s < seat_count; s++)
    {
        char seat[4];
        int row, col, index;

        while (1)
        {
            printf("Enter seat %d (e.g. A1, B5): ", s+1);
            scanf("%3s", seat);

            if (!isalpha(seat[0]) || !isdigit(seat[1]))
            {
                printf("❌ Invalid format! Use A1,B5 etc.\n");
                continue;
            }

            row = toupper(seat[0]) - 'A';
            col = atoi(&seat[1]) - 1;

            if (row < 0 || row >= 5 || col < 0 || col >= 10)
            {
                printf("❌ Invalid seat! Choose between A–E and 1–10.\n");
                continue;
            }

            index = row * 10 + col;

            // ✅ CLASS RESTRICTION CHECK
            // ✅ CLASS RESTRICTION CHECK (GOLD = first 30, PLATINUM = last 20)
            if(seat_class == 1 && index >= 30)  
            {
                printf("❌ This is a PLATINUM seat. Gold seats are first 30 seats.\n");
                continue;
            }
            if(seat_class == 2 && index < 30)
            {
                printf("❌ This is a GOLD seat. Platinum seats are last 20 seats.\n");
                continue;
            }

            if (movies[movie_index].seats[show_index][index] == 1)
            {
                printf("⚠️ Seat already booked! Pick another.\n");
            }
            else
            {
                movies[movie_index].seats[show_index][index] = 1;

                Booking new_booking;
                new_booking.booking_id = (booking_count > 0) ? 
                    bookings[booking_count - 1].booking_id + 1 : 1;

                new_booking.movie_index = movie_index;
                new_booking.show_index = show_index;
                new_booking.seat_row = row;
                new_booking.seat_col = col;

                bookings[booking_count++] = new_booking;

                printf("✅ Seat %c%d booked!\n", 'A' + row, col + 1);
                break;
            }
        }
    }

    system("clear");

    printf("\n✅ All seats booked successfully!\n");
    printf("🎬 Movie: %s\n", movies[movie_index].movie_name);
    printf("🕒 Show: %s\n\n", movies[movie_index].show_times[show_index]);

    display(movie_index, show_index);

    save_csv();
}

int price(int number, int class)
{
    if(class == 1)
    {
        printf("💰 Price for %d GOLD ticket(s) = %d Rs\n", number, number * 150);
    }
    else if(class == 2)
    {
        printf("💰 Price for %d PLATINUM ticket(s) = %d Rs\n", number, number * 200);
    }
    else
    {
        printf("Invalid Class selected\n");
        return 0;
    }
    return 1;
}

void see_booking()
{
    if (booking_count == 0)
    {
        printf("No bookings found.\n");
        return;
    }

    printf("\n--- List of Bookings ---\n");
    for (int i = 0; i < booking_count; i++)
    {
        Booking b = bookings[i];
        printf("Booking ID: %d, Movie: %s, Show Time: %s, Seat: %c%d\n", b.booking_id, movies[b.movie_index].movie_name, movies[b.movie_index].show_times[b.show_index],'A' + b.seat_row, b.seat_col + 1);
    }

}

void cancel_booking()
{
    if (booking_count == 0)
    {
        printf("No bookings to cancel.\n");
        return;
    }

    int booking_id;
    printf("Enter Booking ID to cancel: ");

    if (scanf("%d", &booking_id) != 1) {
        printf("Invalid input. Booking ID must be a number.\n");
        while(getchar() != '\n');
        return;
    }

    int found = 0;
    for (int i = 0; i < booking_count; i++)
    {
        if (bookings[i].booking_id == booking_id)
        {
            found = 1;

            // **** FREE THE SEAT BACK ****
            int m = bookings[i].movie_index;
            int s = bookings[i].show_index;
            int r = bookings[i].seat_row;
            int c = bookings[i].seat_col;

            int index = r * 10 + c;
            movies[m].seats[s][index] = 0;  // mark seat as free

            // Shift records to fill gap
            for (int j = i; j < booking_count - 1; j++)
            {
                bookings[j] = bookings[j + 1];
            }
            booking_count--;

            printf("✅ Booking ID %d cancelled successfully. Seat %c%d is now free.\n",
                   booking_id, 'A' + r, c + 1);


            break;
        }
    }

    if (!found)
    {
        printf("❌ Booking ID %d not found.\n", booking_id);
    }

    save_csv();

    sleep(3);
    system("clear");
}



void list_showtimes(int movie_index)
{
    printf("\nShowtimes for %s:\n", movies[movie_index].movie_name);
    for (int j = 0; j < movies[movie_index].total_shows; j++)
    {
        printf("  Show %d: %s\n", j + 1, movies[movie_index].show_times[j]);
    }

    printf("\n\n");
}


void display(int movie_index, int show_index)
{
    // ANSI Color Codes
    #define GREEN   "\x1b[32m"
    #define RED     "\x1b[31m"
    #define BLUE    "\x1b[34m"
    #define MAGENTA "\x1b[35m"
    #define RESET   "\x1b[0m"

    int totalSeats = 50;
    int goldSeats = 30;       // first 30 seats gold
    int platinumSeats = 20;   // last 20 seats platinum
    
    int bookedGold = 0, bookedPlatinum = 0;

    printf("\n================ CINEMA SEAT LAYOUT ================\n");
    printf("                 📽️ SCREEN THIS SIDE\n\n");

    int rows = 5, cols = 10;

    // Column numbers
    printf("      ");
    for (int c = 1; c <= cols; c++) printf("%2d ", c);
    printf("\n");

    for (int r = 0; r < rows; r++)
    {
        printf(" %c |  ", 'A' + r);

        for (int c = 0; c < cols; c++)
        {
            int index = r * cols + c;
            int booked = movies[movie_index].seats[show_index][index];

            // GOLD seats first 30
            if (index < 30)
            {
                if (booked) { printf(RED "g  " RESET); bookedGold++; }
                else printf(GREEN "G  " RESET);
            }
            else // PLATINUM seats last 20
            {
                if (booked) { printf(MAGENTA "p  " RESET); bookedPlatinum++; }
                else printf(BLUE "P  " RESET);
            }
        }
        printf("\n");
    }

    int availableGold = 30 - bookedGold;
    int availablePlatinum = 20 - bookedPlatinum;

    printf("\nLegend:\n");
    printf(GREEN " G " RESET "= Gold Available     ");
    printf(RED " g " RESET "= Gold Booked\n");
    printf(BLUE " P " RESET "= Platinum Avail     ");
    printf(MAGENTA " p " RESET "= Platinum Booked\n");

    printf("-----------------------------------------------------\n");
    printf("Gold seats (0–29):     Total: 30 | Available: %d | Booked: %d\n",
           availableGold, bookedGold);
    printf("Platinum seats (30–49):Total: 20 | Available: %d | Booked: %d\n",
           availablePlatinum, bookedPlatinum);
    printf("=====================================================\n\n");
}


void display_booking()
{
    list_movies();
    if (movie_count == 0)
    {
        printf("No movies available to view booking.\n");
        return;
    }
    int movieindex, showindex;
    printf("Enter Movie Index: ");
    scanf("%d", &movieindex);
    movieindex--; // convert to array index ✅

    list_showtimes(movieindex);
    printf("Enter Show Index: ");
    scanf("%d", &showindex); 
    showindex--; // convert to array index ✅

    display(movieindex, showindex);
}

