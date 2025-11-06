# 🎬 Movie Booking System

A simple **C-based Movie Booking System** that allows users to manage movies, showtimes, and seat bookings.  
This project demonstrates the use of **structures**, **file handling**, and **interactive console menus** in C programming.

---

## 📖 Features

- 🎞️ Add and display movie details  
- ⏰ Manage multiple showtimes per movie  
- 💺 Book and cancel movie tickets  
- 📂 Store and retrieve booking data using binary files  
- ⚙️ Prevent overbooking by checking seat availability  
- 🧾 View all bookings and show details  

---

## 🧠 Concepts Used

- Structures in C  
- File handling (`fopen`, `fwrite`, `fread`, etc.)  
- Arrays and loops  
- Conditional statements and functions  
- Menu-driven program design  

---

## 🖥️ How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/movie-booking-system.git
2. Navigate to the project folder:
   cd movie-booking-system
3. Compile the program:
   gcc *.c
4. Run the executable:
   ./a.out
   

📂 File Structure

movie-booking-system/
│
├── main.c                # Main program file
├── header.h              # Header file (function declarations, structures)
├── functions.c           # Function definitions
├── movies_data.out       # Stored movie data (binary file)
├── bookings_data.out     # Stored booking data (binary file)
└── README.md             # Project documentation

🧾 Example Functions

add_movie() → Add new movies to the system
add_show() → Assign showtimes for a movie
display_movies() → View all available movies
make_booking() → Book seats for a selected movie and show
view_bookings() → Display all booking records

💡 Future Enhancements

Add color-based seat display (available/booked)
Implement user login system
Add GUI using C++ or Python for better user experience

👨‍💻 Author
Kannan D S
