# C-Movie-Database
A C++-based Movie Management System that allows users to add, remove, search, sort, and rank movies, with file integration for persistent storage
Project Overview

The Movie Management System is a C++ program designed to allow users to store, manage, and interact with a list of movies. It provides functionalities such as adding, deleting, sorting, and searching for movies, as well as ranking the top movies based on ratings.

Features

Add and Remove Movies: Users can add new movies to the list and remove existing ones.

Movie Search: Search for movies by name.

Movie Sorting: Sort movies based on age rating or user-defined criteria.

Top 5 Movies Ranking: Display the top 5 movies based on ratings.

File Integration:

moviesIn.txt: Stores the list of available movies.

Top5.txt: Stores the top 5 movies ranked by rating.

Queue Implementation: Supports enqueueing and dequeueing movie entries.

Project Files

SDsem8.cpp: Contains the core C++ code for managing the movie database.

SDsem8.vcxproj / SDsem8.vcxproj.filters / SDsem8.vcxproj.user: Visual Studio project files.

moviesIn.txt: Input file containing initial movie data.

Top5.txt: Output file storing the top 5 ranked movies.

Technologies Used

C++: Core programming language.

File Handling: Uses input and output text files to manage movie records.

Linked Lists & Queues: Implements dynamic storage and management of movie data.

How to Use

Running the Program

Compile the C++ file

g++ SDsem8.cpp -o movie_manager
./movie_manager

Or use Visual Studio to open and build the SDsem8.vcxproj file.

Input Movie Data

The program reads from moviesIn.txt.

Users can manually add more movies through the interface.

Choose Actions from Menu

Add/Remove movies.

Sort movies by age rating.

View top 5 movies.

Search for a movie.

View Outputs

Movie details are displayed in the console.

The top 5 movies are saved in Top5.txt.

Future Improvements

Implement a Graphical User Interface (GUI) for better usability.

Expand database support to store movie data persistently.

Add API integration to fetch real-time movie ratings.

Author
loldwyer
