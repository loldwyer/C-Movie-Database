#include <iostream> //for cin and cout
#include <fstream>  //for file manipulation
#include <string>

using namespace std;

/*mode details struct*/
struct Movies {
    string name;
    string genre;
    string age;
    float rating = 0;
};

/*linked list node*/
struct Node {
    Movies key;
    Node* next;
};

/*linked list struct - used for the Add/Remove to/from My List section*/
struct LinkedList {
    Node* head;
    LinkedList() { //default constructor
        head = NULL;
    }
    LinkedList(Node* n) { //have head point to the node (the next Movie)
        head = n;
    }

    Node* keyAlreadyExists(Movies k) { //check if the node already exists using key
        Node* check = NULL; 
        Node* ptr = head; //top of the list
        while (ptr != NULL) {
            if (ptr->key.name == k.name) //check if the name of movie k already exists in the node element key
            {
                check = ptr; //if it already exists set the ptr to NULL
            }
            ptr = ptr->next; //if not set the next movie name in the linked list as the ptr (top of the list)
        }
        return check; //the movie name, inputted by the user, already exists in this location
    }

    void addMovie(Node* n) {
        if (keyAlreadyExists(n->key) != NULL) //if the movie is found in the linked list
        {
            cout << "----- movie Already exists : " << n->key.name << ". Add another movie  -----" << endl << endl;
        }
        else //if the movie doesn't already exist in the linked list
        {
            if (head == NULL) //
            {
                head = n;
                cout << "----- Movie Has Been Added -----" << endl << endl;
            }
            else //it doesn't alreayd exist, so add it to the list
            {
                Node* ptr = head; //make the pointer to the node the head of the list (the top of the list)
                while (ptr->next != NULL) //if there is and address in the next address
                {
                    ptr = ptr->next; //let ptr reference the next nodes address
                }
                ptr->next = n; //let the next node hold the value inputted by the user
                cout << "----- movie Has Been Added -----" << endl << endl; //addition is complete
            }
        }
    }


    void deleteMovie(Movies k) {
        if (head == NULL) //if there is no nodes in the list
        {
            cout << "----- movie list already empty. Cannot delete anymore -----" << endl << endl;
        }
        else if (head != NULL) { //there is something in the list
            if (head->key.name == k.name) { //if the inputted movie name matches the name stored in the key value of the head node
                head = head->next; //if true, make the next node in the list the new head
                cout << "----- Movie =  " << k.name << " deleted -----" << endl << endl; //affectively deleting the old head node
            }
            else {
                Node* temp = NULL;
                Node* prevptr = head; //previous pointer
                Node* currentptr = head->next; //current pointer
                while (currentptr != NULL) { //something in the next node
                    if (currentptr->key.name == k.name) { //check if the user inputted movie name matches the one stored in this node 
                        temp = currentptr; //if true, make currentptr the temp value
                        currentptr = NULL; //make it equal to NULL (deletes it)
                    }
                    else { //if the user input doesnt match the currentptr movie name value stored as key
                        prevptr = prevptr->next; //move on to the next node
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL) { //check if the node was deleted
                    prevptr->next = temp->next; //make th eprevious pointer point tot he node after the deleted node
                    cout << "----- Movie = " << k.name << " deleted -----" << endl << endl; 
                }
                else { //if the temo node hasn't been deleted
                    cout << "----- movie doesn't exist " << k.name << " -----" << endl << endl;
                }
            }
        }

    }

    void printMovies() {
        if (head == NULL) //if there is nothing in the lsit
        {
            cout << "----- No movies recorded in list -----";
        }
        else //if there is something in the list
        {
            cout << endl << "----- List of movies -----" << endl;
            Node* temp = head; 
            while (temp != NULL) //repeat until there is no next node
            {
                //print the key and data values of every node in the list
                cout << "Name: " << temp->key.name << " " << temp->key.genre << " " << temp->key.age << " " << temp->key.rating;
                temp = temp->next; //go to the next node and repeat this while loop
                cout << endl;
            }
        }
        cout << endl << endl;
    }
};
//Elmars
void remove_duplicate(Movies arrayM[], int NumMov); //removes movie name from movie array when it already exists on Netflix
void sortAge(Movies arrayM[], int len); //sort movies by age rating
 

//Lauren
void inMovies(Movies arrayM[], int* nom1); //takes movies from moviesIn text file and places them into an array
void DisplayT5(Movies arrayM2[], int q); //sort in descending order by the ratings out of 5 value from the Movies struct

void DisplayT5(Movies rankMovies[]);     //prints the top 5 to the console window and to a text file Top5.txt

//Ewere
void searchMovies(Movies arrayM4[], int len); //searches for a user inputted movies


//Elmars
inline void displayAll(Movies arrayM[], int Num = 1) { //displays all the movies in the array
    for (int i = 0; i < Num; i++) {
        cout << arrayM[i].name << " " << arrayM[i].genre << " " << " Age :  " << arrayM[i].age << endl;
    }
}

int main() {
    Movies MovieArray[10];
    Movies MovieArray_temp[10]; //used for categories
    string choice;  //initial prompt
    string choice2; //second prompt
    int NumMov;

    //Lauren- title - raw string literal, escape characters (\n, \t, etc.) not processed in this string so that it can be displayed better and more consistently
    cout << R"(     
            _   _      _    __ _ _      
           | \ | |    | |  / _| (_)     
           |  \| | ___| |_| |_| |___  __
           | . ` |/ _ \ __|  _| | \ \/ /
           | |\  |  __/ |_| | | | |>  < 
           |_| \_|\___|\__|_| |_|_/_/\_\     )" << '\n';


    inMovies(MovieArray, &NumMov); //read in from the moviesIn.txt

    do {
        //intial prompt
        cout << "Choose options 1-4" << endl; 
        cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << "(1) Add/Remove Movie (2) Categories (3) Top 5 (4) Search Movie" << endl;
        cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
        cout << "Input choice: "; 
        cin >> choice; //user input

        //can only choose between numbers 1-4 for this prompt
        //if anything else is inputted the prompt will be given again alongside a message stating the input was invalid
        while (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
            cout << "\n\nInvalid user input!Try again\n\n" << endl;
            cout << "Choose options 1-4" << endl;
            cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
            cout << "(1) Add/Remove Movie (2) Categories (3) Top 5 (4) Search Movie" << endl;
            cout << "= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =" << endl;
            cout << "Input choice: ";
            cin >> choice;

        }

        //Ewere - Add/Remove movies from my list
        if (choice == "1") {
            LinkedList mylist; //LinkedList struct, stores all the functions necessary for this section
            Movies nodekey; //relating the node struct to the movie struct
            fstream file;   
            string name; //movie name
            Movies id; //struct movie identifier
            int choicell; //user input choice for linked list section

            do {
                Node* node = new Node();
                cout << "1 - Add movie" << endl;
                cout << "2 - Remove movie" << endl;
                cout << "3 - Print all movies" << endl;
                cout << "4 - Exit Program" << endl << endl;

                cout << "Input Choice: "; 
                cin >> choicell; //user input
                cout << endl;

                switch (choicell) {  //between 1-4

                case 1:
                    //input movie details to be added
                    cout << "Add movie. Please enter the following:" << endl << "Input name: ";
                    cin >> id.name;
                    cout << "Input genre\n";
                    cin >> id.genre;
                    cout << "Input age\n";
                    cin >> id.age;
                    cout << "Input rating\n";
                    cin >> id.rating;
                    cout << endl;

                    //transform inputted values of the movies struct into values on the node struct
                    node->key.name = id.name;
                    node->key.genre = id.genre;
                    node->key.age = id.age;
                    node->key.rating = id.rating;

                    //add the new node key to the linked list called mylist
                    mylist.addMovie(node);
                    break; //end of case 1

                case 2:
                    //input movie name to be deleted
                    cout << "Delete movie\n";
                    cout << "Input name\n";
                    cin >> nodekey.name; //user input
                    cout << endl;

                    mylist.deleteMovie(nodekey); //delete node with the same name as the inputted movies name
                    break; //end case 2

                case 3:
                    mylist.printMovies(); //print all the movies in my list to the console window
                    break; //end case 3

                case 4:
                    cout << "Now closing program" << endl;
                    main(); //restart the main menu (show initial prompt)

                default:
                    cout << "Invalid Option, Enter Again:" << endl; //if user input is not 1-4, display this on the console window
                }

            } while (choicell != 10); ///?

        }
        //Elmars - Categories
        else if (choice == "2") {
            int select; //category selected
            int choice; //choose action
            int exit = 0;
            cout << "----------------------------------------------------" << endl;
            cout << "(1)Select Genre  (2)Display all Movies  " << endl;
            cout << "----------------------------------------------------" << endl;
            cout << "Input choice: ";
            cin >> choice; //user input

            if (choice == 1) {
                cout << "------------------------" << endl;
                remove_duplicate(MovieArray, NumMov); //remove any movies that are in the movies array more than once
                inMovies(MovieArray_temp, &NumMov);   //read in from the moviesIn.txt
                cout << "------------------------" << endl;

                cout << "Select a Category: "; //user input
                cin >> select;

                cout << "============ " << MovieArray[select - 1].genre << " ============" << endl;

                for (int i = 0; i < NumMov; i++) { //for all movies in the array
                    if (MovieArray_temp[i].genre == MovieArray[select - 1].genre) { //in the user inputted genre matches the genre of the stored movies in the array
                        //print the movies of the inputted genre
                        cout << " Name: " << MovieArray_temp[i].name << " Genre: " << MovieArray_temp[i].genre << " Age : " << MovieArray[i].age << "  Rating: " << MovieArray_temp[i].rating << endl;
                    }
                }
                cout << "================================" << endl;
            }
            else if (choice == 2) {
                cout << "------------------------" << endl;
                sortAge(MovieArray, NumMov); //sorts the age ratings of the movies in descending order (from 18 to 12)
                displayAll(MovieArray, NumMov); //inline function that displays all the movies in the array
                cout << "------------------------" << endl;
            }
        }

        //Lauren - Top5
        else if (choice == "3") {
            inMovies(MovieArray, &NumMov); //inputs movies from the moviesIn.txt
            DisplayT5(MovieArray, NumMov); //sorts the movies in order based on their ratings out of 5 value
            DisplayT5(MovieArray); //prints the sorted array to a text file Top5.txt
            //print to the console window
            for (int i = 0; i < 5; i++) {
                cout << "\n" << i + 1 << " " << MovieArray[i].name << " " << MovieArray[i].genre << " " << MovieArray[i].rating << " " << MovieArray[i].age << endl;
            }
        }
        //Ewere - Search Movies
        else if (choice == "4") {
            inMovies(MovieArray, &NumMov);  //inputs movies from the moviesIn.txt
            searchMovies(MovieArray, NumMov); //search the movies array for the user inputted movie and return if found or if not found
        }
    } while (1); //while the program is running

    return 0; //executes the code
}



//ELmars - Sorts the age (bubble sort)
void sortAge(Movies arrayM[], int len) {
    Movies temp; //temp value to allow for sorting
    for (int i = 0; i < len; i++) { //for all the elements of the array, sort in ascending order
        for (int j = 0; j + 1 < len - i; j++) { 
            if (arrayM[j].age > arrayM[j + 1].age) { //if the age rating of a movie is greater that the one in the next address
                temp = arrayM[j]; //swap values
                arrayM[j] = arrayM[j + 1];
                arrayM[j + 1] = temp;
            }
        }
    }
}

//Lauren --pass the value of number of movie (nom) by pass by pointer
void inMovies(Movies arrayM[], int* nom1) { //array name, number of movies
    ifstream ip("moviesIn.txt");
    ip >> *nom1; //number of movies is printed in the first line of the text file
    for (int nom = 0; nom < *nom1; nom++) { //for all the movies up to the nom value, print them to the console
        ip >> arrayM[nom].name >> arrayM[nom].genre >> arrayM[nom].age >> arrayM[nom].rating;
    }
    ip.close(); //close the input file
}

//Lauren- sorting arrays using struct (bubble sort)
void DisplayT5(Movies arrayM2[], int q) { //movie array, amount of movies in the array
    Movies temp; //temp value to allow for sorting
    for (int count = 0; count < q; count++)  //for all elements in the array, sort in descending order
        for (int n = 0; n + 1 < q - count; n++) {
            if (arrayM2[n + 1].rating > arrayM2[n].rating) { //compares each rating with the one in the previous movie address
                //execute swapping
                temp = arrayM2[n]; //stores a value in temp
                arrayM2[n] = arrayM2[n + 1]; //store the value of arrrayM2[n+1] into arrayM2[n]
                arrayM2[n + 1] = temp; //make arrayM2[n+1] equal to the original value of arrayM2[n]
            }
        }
}


//Lauren - manipulating file streams
void DisplayT5(Movies rankMovies[]) {
    ofstream op("Top5.txt"); //create an output file called Top5.txt
    int r = 5; //5 rankings
    op << r << endl; //output 5 values to the output file (op)

    for (int j = 0; j < r; j++) { //print all the details of the movies array
        op << "\n " << j + 1 << " " << rankMovies[j].name << " " << rankMovies[j].genre << " " << rankMovies[j].rating << " " << rankMovies[j].age << " " << endl;
    }
    op.close(); //close the text file
}

//Ewere- searching arrays with structs
void searchMovies(Movies arrayM4[], int len) {
    string title; //movie name
    int found = 0; //not found, initial state

    cout << "Search movie:"; //prompt to user
    cin >> title; //user input

    for (int t = 0; t < len; t++) { //for all the movies in the array (len)
        if (arrayM4[t].name == title) { //are any of them equal to the user inputted movie name
            found = 1;   //if true, movie is found
            cout << arrayM4[t].name << "\n" << endl; //
        }
    }
    if (found == 1) { 
        cout << "Movie found!" << endl;
    }
    else { //if arrayM4[t].name != title, movie not found, found=0
        cout << "Movie unavailable! Try Again" << endl;
        //Elmars - Recursive function 
        searchMovies(arrayM4, len); //recursive function -- run searchMovies function again
    }
}



