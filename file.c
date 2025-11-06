#include "header.h"

void save_csv()
{
    // Save Movies
    FILE *fp = fopen("movies.csv", "w");
    if(fp == NULL) return;

    fprintf(fp, "movie_name,duration,total_shows,show_times\n");

    for(int i = 0; i < movie_count; i++)
    {
        fprintf(fp, "%s,%.2f,%d", movies[i].movie_name, movies[i].duration, movies[i].total_shows);
        
        for(int j = 0; j < movies[i].total_shows; j++)
            fprintf(fp, ",%s", movies[i].show_times[j]);

        fprintf(fp, "\n");
    }
    fclose(fp);

    // Save Bookings
    fp = fopen("bookings.csv", "w");
    if(fp == NULL) return;

    fprintf(fp, "booking_id,movie,show,seat\n");

    for(int i = 0; i < booking_count; i++)
    {
        Booking b = bookings[i];

        fprintf(fp, "%d,%s,%s,%c%d\n",
            b.booking_id,
            movies[b.movie_index].movie_name,
            movies[b.movie_index].show_times[b.show_index],
            'A' + b.seat_row, b.seat_col + 1
        );
    }
    fclose(fp);
}


void load_csv()
{
    FILE *fp = fopen("movies.csv", "r");
    if(fp != NULL)
    {
        char line[256];
        fgets(line, 256, fp); // Skip header

        movie_count = 0;
        while(fgets(line, 256, fp))
        {
            char *token = strtok(line, ",");
            strcpy(movies[movie_count].movie_name, token);

            movies[movie_count].duration = atof(strtok(NULL, ","));
            movies[movie_count].total_shows = atoi(strtok(NULL, ","));

            for(int i = 0; i < movies[movie_count].total_shows; i++)
            {
                token = strtok(NULL, ",");
                token[strcspn(token, "\n")] = 0;
                strcpy(movies[movie_count].show_times[i], token);
            }

            // Initialize seat matrix to free
            for(int s = 0; s < 5; s++)
                for(int t = 0; t < 50; t++)
                    movies[movie_count].seats[s][t] = 0;

            movie_count++;
        }
        fclose(fp);
    }

    // Load bookings
    fp = fopen("bookings.csv", "r");
    if(fp != NULL)
    {
        char line[256];
        fgets(line, 256, fp); // Skip header

        booking_count = 0;

        while(fgets(line, 256, fp))
        {
            Booking b;
            char seat[10], movie[50], show[20];

            sscanf(line, "%d,%[^,],%[^,],%s",
                   &b.booking_id, movie, show, seat);

            // Map movie index
            for(int i = 0; i < movie_count; i++)
            {
                if(strcmp(movie, movies[i].movie_name) == 0)
                {
                    b.movie_index = i;

                    // Map show index
                    for(int j = 0; j < movies[i].total_shows; j++)
                    {
                        if(strcmp(show, movies[i].show_times[j]) == 0)
                            b.show_index = j;
                    }
                }
            }

            // Convert seat like A5 → row + col
            b.seat_row = seat[0] - 'A';
            b.seat_col = atoi(&seat[1]) - 1;

            bookings[booking_count] = b;

            // ✅ Restore seat matrix (5 rows × 10 seats = 50 seats)
            int seat_index = b.seat_row * 10 + b.seat_col;
            movies[b.movie_index].seats[b.show_index][seat_index] = 1;

            booking_count++;
        }

        fclose(fp);
    }
}
