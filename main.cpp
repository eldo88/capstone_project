/* 
Author: Lee Jones
11/19/2022
CSC 1060
M4 Capstone Project: Capstone Preparation

Requirements:
1. Algorithms
2. UML diagrams
3. Inputs and Output (I/O)-complete
4. Variables-complete
5. Arrays-complete
6. File I/O-complete
7. Iteration (loops)-complete
8. Interaction-complete
9. Control-complete
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

const int length = 4;       //size of array used for file input

//Inside and outside workout sub menus
void mainMenu();
void insideMenu();
void outsideMenu();

//functions that log the workouts to the file "log.txt"
void insideLogging(int menuChoice);
void outsideLogging(int menuChoice);

//menu that asks if user wants to log workout
void outsideLoggingMenu(int menuChoiceOutside);
void insideLoggingMenu(int menuChoiceInside);

//displays avg time spent working out and how many workouts have been completed
void metrics(int workoutCount);
//logs the time user spent workout out
void timeLogging(int time);
//counts number of logged workouts
void counter(int &workoutCount);

//structs for workouts
struct Workouts{
    string word1;
    string word2;
    int sets;
    int reps;
    string instructor;
    int time;
    string minutes;
    double distance;
    int pace;
    int reps1;
};

void weights(int menuChoiceInside);
void weightOutput(int menuChoice, Workouts weights[]);

void kettlebell(int menuChoiceInside);
void kettlebellOutput(int menuChoice, Workouts kettlebell[]);

void peloton(int menuChoice);
void pelotonOutput(int menuChoice, Workouts peloton[]);

void core(int menuChoiceInside);
void coreOutput(int menuChoice, Workouts core[]);

void run(int menuChoiceOutside);
void runOutput(int menuChoice, Workouts run[]);

void outdoorActivity(int menuChoiceOutside);
void outdoorActivityOutput(int menuChoice, Workouts outdoorActivity[]);

void activeRest(int menuChoiceOutside);
void activeRestOutput(int menuChoice, Workouts activeRest[]);

//main only calls starting menu and then exits program
int main(){
    mainMenu();
    return 0;
}

//main menu that controls the program controlled via do....while loop
void mainMenu(){
    fstream infile; 
    string menuOption;
    int menuChoice;
    int menuOptionNum; 
    bool end = false;

    do {
        cout << "\n\n_________________________________________________________________________\n";
        cout << "This program will choose a workout for you based on choices you make \n\n";
        cout << "1. Indoor workout \n";
        cout << "2. Outdoor workout \n";
        cout << "3. Exit program \n";
        cout << endl;
        cout << "What is your selection? : ";
        cin >> menuChoice;
    switch (menuChoice){
        case 1: insideMenu();
        break;
        case 2: outsideMenu();
        break;
        case 3: cout << "ending \n";
                end = true;
        break;
        default: cout << "Invalid Choice \n";
        }
    } while (!end);
}
//iside menu controlled via do...while loop
void insideMenu(){
    string menuOption;
    int menuOptionNum; 
    int menuChoiceInside;
    bool end = false;

    do {
        cout << "1. Lift weights \n";
        cout << "2. Kettlebell workout \n";
        cout << "3. Peloton ride \n";
        cout << "4. Core \n";
        cout << "5. Return to main menu \n";
        cout << endl;
        cout << "Please enter the number of your menu choice: ";
        cin >> menuChoiceInside;
    
    switch (menuChoiceInside){
        case 1: weights(menuChoiceInside);  
        break;
        case 2: kettlebell(menuChoiceInside);
        break;
        case 3: peloton(menuChoiceInside);
        break;
        case 4: core(menuChoiceInside);
        break;
        case 5: end = true;
        break;
        default: cout << "Selection invalid \n";
        }
    } while (!end);
}
// Outside menu contolled via do...while loop
void outsideMenu(){
    string menuOption;
    int menuChoiceOutside;
    int menuOptionNum; 
    bool end = false;

    do{
        cout << "1. Run \n";
        cout << "2. Activity \n";
        cout << "3. Active Rest Day \n";
        cout << "4. Return to main menu \n";
        cout << endl;
        cout << "Please enter the number of your menu choice: ";
        cin >> menuChoiceOutside;
    
    switch (menuChoiceOutside){
        case 1: run(menuChoiceOutside);
        break;
        case 2: outdoorActivity(menuChoiceOutside);
        break;
        case 3: activeRest(menuChoiceOutside);
        break;
        case 4: end = true;
        break;
        default: cout << "Selection invalid \n";
        }
    } while (!end);
}
/*might need to pass in menu choice to pass to other functions
function opens file and loads weights into array*/
void weights(int menuChoiceInside){
    ifstream infile;
    Workouts weights[length];
    char ch;
    bool end = false;

    infile.open("weights.txt");
        if (!infile){
            cerr << "weights.txt failed to open, exiting now \n";
            exit(1);
        }
        while (infile){
            for (int i = 0; i < length; i++){
                infile >> weights[i].word1
                       >> weights[i].word2
                       >> weights[i].sets
                       >> weights[i].reps;

            }
            infile.close();
        }
    weightOutput(menuChoiceInside, weights);
    insideLoggingMenu(menuChoiceInside);
}
//outputs contents of array to user
void weightOutput(int menuChoice, Workouts weights[]){  
    srand(time(NULL)); //seeds random number
    int randomNumber = (rand() % 4); //assigns random number to variable 

    cout << "\n___________________________________________\n";
    cout << "Workout: " << weights[randomNumber].word1
         <<  " " << weights[randomNumber].word2 << endl;
    cout << "Sets: "  << weights[randomNumber].sets << endl;
    cout << "Reps: "  << weights[randomNumber].reps << endl;
    
}
//loads file contents into array
void kettlebell(int menuChoiceInside){
    ifstream infile;
    Workouts kettlebell[length];
    char ch;

    infile.open("kettlebell.txt");
            if (!infile){
                cerr << "Kettlebell workout failed to open, exiting now \n";
                exit(1);
            }
        while (infile){
            for (int i = 0; i < length; i++){
                infile >> kettlebell[i].word1
                       >> kettlebell[i].word2
                       >> kettlebell[i].sets
                       >> kettlebell[i].reps;
            }
            infile.close();
        }
    kettlebellOutput(menuChoiceInside, kettlebell);
    insideLoggingMenu(menuChoiceInside);
}
//outputs workout to user
void kettlebellOutput(int menuChoice, Workouts kettlebell[]){
    srand(time(NULL)); //seeds random number
    int randomNumber = (rand() % 4);  //assigns random number to variable

    cout << "\n___________________________________________\n";
    cout << "Workout: " << kettlebell[randomNumber].word1
         << " " << kettlebell[randomNumber].word2 << endl;
    cout << "Sets: " << kettlebell[randomNumber].sets << endl;
    cout << "Reps: " << kettlebell[randomNumber].reps << endl;
}
//loads file contecnts into array
void peloton(int menuChoiceInside){

    ifstream infile;
    Workouts peloton[length];
    char ch;

    infile.open("peloton.txt");
            if (!infile){
                cerr << "Peloton workout failed to load, exiting now \n";
                exit(1);
            }
        while (infile){
            for (int i = 0; i < length; i++){
                infile >> peloton[i].instructor
                       >> peloton[i].time
                       >> peloton[i].minutes;
            }
            infile.close();
        }
    pelotonOutput(menuChoiceInside, peloton);
    insideLoggingMenu(menuChoiceInside);
}
//outputs Peloton workout to user
void pelotonOutput(int menuChoice, Workouts peloton[]){
    srand(time(NULL)); //seeds random number
    int randomNumber = (rand() % 4); //assigns random number to variable

    cout << "\n___________________________________________\n";
    cout << "Instructor: " << peloton[randomNumber].instructor << endl;
    cout << "Ride time: " << peloton[randomNumber].time 
         << " " << peloton[randomNumber].minutes << endl;
}
//loads file contents into array
void core(int menuChoiceInside){
    ifstream infile;
    Workouts core[length];
    char ch;

    infile.open("core.txt");
            if (!infile){
                cerr << "Core workout failed to load, exiting now \n";
                exit(1);
            }
        while (infile){
            for (int i = 0; i < length; i++){
                infile >> core[i].sets
                       >> core[i].word1
                       >> core[i].word2
                       >> core[i].reps1;
            }
            infile.close();
        }
    coreOutput(menuChoiceInside, core);
    insideLoggingMenu(menuChoiceInside);
}
//outputs core workout to user
void coreOutput(int menuChoice, Workouts core[]){
    srand(time(NULL));
    int randomNumber = (rand() % 4); 

    cout << "\n___________________________________________\n";
    cout << "Sets: " << core[randomNumber].sets << endl;
    cout << "Workout: " << core[randomNumber].word1
         << " " << core[randomNumber].word2 << endl;
    cout << "Reps: " << core[randomNumber].reps1 << endl;
}
//loads file contecnts into array
void run(int menuChoiceOutside){
    ifstream infile;
    Workouts run[length];
    char ch;

    infile.open("run.txt");
            if (!infile){
                cerr << "Running workout failed to open, exiting now \n";
                exit(1);
            }
        while (infile){
            for (int i = 0; i < length; i++){
                infile >> run[i].word1
                       >> run[i].distance
                       >> run[i].pace;
            }
            infile.close();
        }
    runOutput(menuChoiceOutside, run);
    outsideLoggingMenu(menuChoiceOutside);
}
//outputs run workout to user
void runOutput(int menuChoice, Workouts run[]){
    srand(time(NULL));
    int randomNumber = (rand() % 4); 

    cout << "\n___________________________________________\n";
    cout << "Run type: " << run[randomNumber].word1 << endl;
    cout << "Distance: " << run[randomNumber].distance << endl;
    cout << "Pace: " << run[randomNumber].pace << " miles a minute" << endl;
}
//loads file contents into array
void outdoorActivity(int menuChoiceOutside){
    ifstream infile;
    Workouts outdoorActivity[length];
    char ch;

    infile.open("outdoorActivity.txt");
            if (!infile){
                cerr << "Outdoor Activity failed to open, exiting now \n";
                exit(1);
            }
        while (infile){
            for (int i = 0; i < length; i++){
                getline(infile, outdoorActivity[i].word1);
            }
            infile.close();
        }
    outdoorActivityOutput(menuChoiceOutside, outdoorActivity);
    outsideLoggingMenu(menuChoiceOutside);
}
//outputs outdoor activity to user
void outdoorActivityOutput(int menuChoice, Workouts outdoorActivity[]){
    srand(time(NULL));
    int randomNumber = (rand() % 4); 

    cout << "\n___________________________________________\n";
    cout << outdoorActivity[randomNumber].word1 << endl;
}
//loads file contents into array
void activeRest(int menuChoiceOutside){
    ifstream infile;
    Workouts activeRest[length];
    char ch;

    infile.open("activeRest.txt");
            if (!infile){
                cerr << "Active rest day activity failed to load, exiting now \n";
                exit(1);
            }
        while (infile){
            for (int i = 0; i < length; i++){
                getline(infile, activeRest[i].word1);
            }
            infile.close();
        }
    activeRestOutput(menuChoiceOutside, activeRest);
    outsideLoggingMenu(menuChoiceOutside);
}
//outputs active rest workout to user
void activeRestOutput(int menuChoice, Workouts activeRest[]){
    srand(time(NULL));
    int randomNumber = (rand() % 4); 

    cout << "\n___________________________________________\n";
    cout << activeRest[randomNumber].word1 << endl;
}
//menu asking user if they want to log workout
void insideLoggingMenu(int menuChoiceInside){
    char ch;
    cout << "Would you like to log your workout? Enter Y/N \n";
    cin >> ch;
        switch (ch){
            case 'y': 
            case 'Y': insideLogging(menuChoiceInside);
            break;
            case 'n':
            case 'N': cout << "\n\nReturning to previous menu\n\n";
            break;
            default: cout << "you entered an invalid character";
        }
}
//logs inside workout to the file
void insideLogging(int menuChoice){
    int workoutTime;
    ofstream outfile;
    int workoutCount;
    int newCount;

    cout << "Enter how much time you spent working out in minutes: ";
    cin >> workoutTime;
    cout << "\n\n";

    timeLogging(workoutTime);

    outfile.open("log.txt", ios::app);
    if (!outfile){
        outfile.open("log.txt", ios::app|ios::out);
    }
    else {
        while (outfile){
        if (menuChoice == 1){
            outfile << "\n\n";
            outfile << "You completed a wight lifting workout \n";
            outfile << "Time of workout was " << workoutTime << " minutes\n";
        }
        else if (menuChoice == 2){
            outfile << "\n\n";
            outfile << "You completed a kettlebell workout \n";
            outfile << "Time of workout was " << workoutTime << " minutes\n";
        }
        else if (menuChoice == 3){
            outfile << "\n\n";
            outfile << "You completed a Peloton workout \n";
            outfile << "Time of workout was " << workoutTime << " minutes\n";
        }
        else {
            outfile << "\n\n";
            outfile << "You completed a core workout \n";
            outfile << "Time of workout was " << workoutTime << " minutes\n";
        }
    outfile.close();
        }
    }
    counter(workoutCount);
    newCount = workoutCount;
    metrics(newCount);
}
//menu asking if user wants to log workout
void outsideLoggingMenu(int menuChoiceOutside){
    char ch;
    cout << "Would you like to log your workout? Enter Y/N \n";
    cin >> ch;
        switch (ch){
            case 'y': 
            case 'Y': outsideLogging(menuChoiceOutside);
            break;
            case 'n':
            case 'N': cout << "\n\nReturning to previous menu\n\n";
            break;
            default: cout << "you entered an invalid character";
        }
}
//logs outside workout to the file 
void outsideLogging(int menuChoice){
    int workoutTime;
    ofstream outfile;
    int workoutCount;
    int newCount;

    cout << "Enter how much time you spent working out in minutes: ";
    cin >> workoutTime;
    cout << "\n\n";

    timeLogging(workoutTime);

    outfile.open("log.txt", ios::app);
    if (!outfile){
        outfile.open("log.txt", ios::app|ios::out);
    }
    else {
        while (outfile){
        if (menuChoice == 1){
            outfile << "\n\n";
            outfile << "You completed a run workout \n";
            outfile << "Time of workout was " << workoutTime << " minutes\n";
        }
        else if (menuChoice == 2){
            outfile << "\n\n";
            outfile << "You completed an outdoor activity as a workout \n";
            outfile << "Time of workout was " << workoutTime << " minutes\n";
        }
        else {
            outfile << "\n\n";
            outfile << "You took it easy with an active rest day today \n";
            outfile << "Time of workout was " << workoutTime << " minutes\n";
        }

    outfile.close();
        }
    }
    counter(workoutCount);
    newCount = workoutCount;
    metrics(newCount);
}
//logs the time to file the user spends working out
//file contents used to calculate average in metrics() because it also opens 
//"database.txt" and averages time spent working out
void timeLogging(int time){
    ofstream outfile;

    outfile.open("database.txt", ios::app);
    if (!outfile){
        cerr <<"database.txt failed to open\n";
        exit(1);
    }
    else {
        while (outfile){
        for (int i = 0; i < 1; i++){
            outfile << time << " ";
            }
            outfile.close();
        }
    }
}
//counts how many times function has been called, used as loop control variable and ultimately 
//output to the user when workout is logged. Also used in average calculation done in metrics()
//must have 0 value already in the file to make sure counting happens correctly if file is blank
void counter(int &workoutCounter){
    ofstream outfile;
    ifstream infile;

    infile.open("counter.txt");
    if(!infile){
        cerr << "counter.txt failed to open\n";
        exit(1);
    }
    else {
        while (infile){
            infile >> workoutCounter;
            infile.close();
        }
        workoutCounter++;
    }
    outfile.open("counter.txt");
    if (!outfile){
        cerr <<"database.txt failed to open\n";
        exit(1);
    }
    else {
        while (outfile){
            outfile << workoutCounter;
            outfile.close();
        }
    }
}
//displays avg time spent working out and how many workouts have been completed
void metrics(int workoutCount){
    ifstream infile;
    ofstream outfile;
    double time[workoutCount];
    double sum = 0;
    double avg;

    infile.open("database.txt");
    if (!infile) {
        cerr << "database.txt cout not open\n";
        exit(1);
    }
    else {
        while (infile){
            for (int i = 0; i < workoutCount; i++){
                infile >> time[i];
            }
            infile.close();
        }  
        for (int i = 0; i < workoutCount; i++){
            sum += time[i];
        }
    }
    avg = sum/workoutCount;
    cout << "\n\nYou have spent and average of " << avg << " minutes working out\n\n";
    cout << "You have worked out " << workoutCount << " times\n\n";
}


