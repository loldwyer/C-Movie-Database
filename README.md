# C-Movie-Database March 2022
A C++-based Movie Management System that allows users to add, remove, search, sort, and rank movies, with file integration for persistent storage

## Project Overview
The **Movie Management System** is a C++ program designed to allow users to store, manage, and interact with a list of movies. It provides functionalities such as adding, deleting, sorting, and searching for movies, as well as ranking the top movies based on ratings.

## Features
- **Add and Remove Movies**: Users can add new movies to the list and remove existing ones.
- **Movie Search**: Search for movies by name.
- **Movie Sorting**: Sort movies based on age rating or user-defined criteria.
- **Top 5 Movies Ranking**: Display the top 5 movies based on ratings.
- **File Integration**:
  - `moviesIn.txt`: Stores the list of available movies.
  - `Top5.txt`: Stores the top 5 movies ranked by rating.
- **Queue Implementation**: Supports enqueueing and dequeueing movie entries.

## Project Files
- **`SDsem8.cpp`**: Contains the core C++ code for managing the movie database.
- **`SDsem8.vcxproj` / `SDsem8.vcxproj.filters` / `SDsem8.vcxproj.user`**: Visual Studio project files.
- **`moviesIn.txt`**: Input file containing initial movie data.
- **`Top5.txt`**: Output file storing the top 5 ranked movies.

## Technologies Used
- **C++**: Core programming language.
- **File Handling**: Uses input and output text files to manage movie records.
- **Linked Lists & Queues**: Implements dynamic storage and management of movie data.

## How to Use
### Running the Program
#### **Using g++ (Command Line Compilation)**
1. Compile the C++ file:
   ```sh
   g++ SDsem8.cpp -o movie_manager
   ./movie_manager
   ```

2. The program reads from `moviesIn.txt` and allows users to interact via the command-line interface.

#### **Using Visual Studio**
1. Open `SDsem8.vcxproj` in Visual Studio.
2. Build and run the project.

### Available Actions
- **Add/Remove Movies**: Manage the movie list dynamically.
- **Sort Movies by Age Rating**: View categorized movies.
- **View Top 5 Movies**: Displays top-rated movies.
- **Search for a Movie**: Look up a movie by its title.
- **File Storage**: Saves movie lists and rankings in text files.

## Author
**loldwyer**
