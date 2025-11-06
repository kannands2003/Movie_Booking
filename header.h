#ifndef HEADER_H
#define HEADER_H

#include <string.h>
#include <stdio.h>
#include <ctype.h>   // for toupper()
#include <stdlib.h>  // for atoi()
#include <unistd.h> // for sleep()



#define ADMIN_PASS "admin123"

#define MAX_MOVIES 100
#define MAX_SHOWS 5
#define MAX_SEATS 50
#define MAX_BOOKINGS 500

typedef struct
{
    char movie_name[50];
    float duration; 
    char show_times[MAX_SHOWS][10];
    int total_shows;
    int seats[MAX_SHOWS][MAX_SEATS];
} Movie;

typedef struct
{
    int booking_id;
    int movie_index;
    int show_index;
    int seat_row;
    int seat_col;
} Booking;

extern Movie movies[MAX_MOVIES];
extern int movie_count;

extern Booking bookings[MAX_BOOKINGS];
extern int booking_count;

// Admin functions
void admin_menu();
void add_movie();
void add_show();
void list_show();
void list_movies();
void delete_movie();
void edit_movie();
void delete_show();
void edit_show();
void edit();

// User functions
void user_menu();
void book_movies();
void list_showtimes(int);
void make_booking(int , int);
void see_booking();
void cancel_booking();
void display(int , int);
void display_booking();
int price(int , int );

// File functions
void save_csv();
void load_csv();


#endif
