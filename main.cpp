/* Name: Alejandro_Rodriquez, 2001889172, AS5
* Description: Frog_boundries_game
* Input: Seed_Value/Directions
* Output: Frog_field_and_position
*/
//use proper libraries
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <cctype>
//declaration of nessessary values for game config
std::string game_Info(short max_jumps,short jumps,short frogX,short frogY);
void field(short width, short height, short frogX, short frogY, short exit_col);
void move_frog(char choice,short distance, short& frogX,short& frogY);
void print_menu();
int main(){
//nessecery constant variables
    const int max_jumps =10; //limit on jumps
    const int max_dist = 5; //distance limit
    const int height = 5; //height of playing field
    const int width = 14; //width of playing field
    int exit_col =width/2;
    std::string game_info; //string containing game header
    short frogX,frogY; //frogs
    char choice;
    char silent;
    short jumps;
    short distance;
    unsigned int seed; //unsigned int
/*part 1 containing game configuration */
   //title head string
    std::cout << "GAME CONFIGURATION:"<<std::endl;
    std::cout << "enter seed value (0=time(NULL)): ";
    std::cin >> seed;
    std::cout << "silent mode? (y/n): ";
    std::cin >> silent;
 
//declare random number generator depending on seed value
    if(seed == 0)
        srand((time(NULL)));
    else
        srand(seed);
//variable containing random number generator
    frogX = rand()%width+1;
    frogY = rand()%height+1;
    jumps = 0;
//while counting jump iteration in menu
    while(jumps < max_jumps)
    {
//game info display
            std::cout << game_Info(frogX, frogY, jumps, max_jumps);
            jumps++; // increment jumps by 1
//if statement checking userInput for silent mode
    if(silent == 'n'){
        field(width, height, frogX, frogY, exit_col);
        print_menu();
        }
//prompt user for choice
    std::cout << "Enter selection: ";
    std::cin >> choice;
    choice = tolower(choice); //to lowercase
//variable containing distance
    distance = rand()%max_dist + 1; 
    std::cout << "distance=" << distance << std::endl;
//move frog according to userinput
    move_frog(choice, distance, frogX, frogY); 
//read input
    if(frogY > height && frogY == exit_col){
        std::cout << "WIN in " << jumps<< " jumps" << std::endl;
        exit(0);
        }
//boundaries
        else if(frogY < 1 || frogY > height || frogX < 1 || frogX > width){
        std::cout << "GAME OVER: out of field" << std::endl;
        exit(0);
        }       
    }
        // out of jumps
        std::cout << "GAME OVER: out of jumps" << std::endl;
        exit(0);
}
// function to create and return a string containing the current information of the game
    std::string game_Info(short frogX, short frogY, short jumps, short max_Jumps){
    std::string game_Info =std::string(16,'#') + "\n" + "GAME INFO:\n";
        game_Info = game_Info + "frog_x=" + std::to_string(frogX) + " frog_y=" + std::to_string(frogY) + "\n";
        game_Info = game_Info + "jumps=" + std::to_string(jumps) + "/" + std::to_string(max_Jumps) +"\n";
        return game_Info;
    }
// function to display the current configuration of the field
void field(short width, short height, short frogX, short frogY, short exit_col){
    std::cout << std::endl;
    std::cout << "|" << std::setw(width) << std::setfill('*') << "" << "|" << std::endl;
    for(int i=1;i<=height;i++)
    {
    if(frogY != i)
    std::cout << "|" << std::setw(width) << std::setfill('-') << "" << "|";
    else
    std::cout << "|" << std::setw(frogX-1) << std::setfill('-') << "" << "X" << std::setw(width-frogX) << std::setfill('-') << "" << "|";
    std::cout << std::endl;
    }
    std::cout << "|" << std::setw(exit_col-1) << std::setfill('*') << "" << " " << std::setw(width-exit_col) << std::setfill('*') << "" << "|" << std::endl;
    }
//menu control option display
    void print_menu(){
    std::cout << std::endl << "MENU" << std::endl;
    std::cout << "w: UP" << std::endl;
    std::cout << "a: LEFT" << std::endl;
    std::cout << "s: DOWN" << std::endl;
    std::cout << "d: RIGHT" << std::endl;
    }
//function to update the position of the frog based on choice and distance
void move_frog(char choice, short distance, short& frogX, short& frogY){
//swtch statment based on user choice outputs distance jumped
switch(choice){
        case 'w':
            std::cout << "jumping UP by " << distance << std::endl;
            frogY -= distance;
            break;
        case 'a':
            std::cout << "jumping LEFT by " << distance << std::endl;
            frogX -= distance;
            break;
        case 's':
            std::cout << "jumping DOWN by " << distance << std::endl;
            frogY += distance;
            break;
        case 'd':
            std::cout << "jumping RIGHT by " << distance << std::endl;
            frogX += distance;
            break;
        }
}
