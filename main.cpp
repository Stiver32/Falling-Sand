//This is a visual simulation, but simplified. It uses a 2D array (grid) and basic gravity logic.
//- **The Goal:** Create a 10x10 grid of `.` (empty air). Place a `#` (sand) at the top. Every "frame" (loop iteration), 
//the sand moves down one row *unless* the space below it is blocked.

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>


int main()
{
    const int ROWS = 10;
    const int COLUMNS = 10;
    const int SETUP_TIME = 10;

    std::vector<std::vector<char>> grid (ROWS, std::vector<char>(COLUMNS, '.')); // Create a 10x10 grid filled with '.'
    
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> dis(0, COLUMNS - 1);
    

    for (int i=0; i < SETUP_TIME; ++i)
    {
        // Place random sand particles all over grid
        for(int j = 0; j < 5; ++j)
        {
            int random_col = dis(eng); // Generate a random column index between 0 and COLUMNS-1
            int random_row = dis(eng) % (ROWS - 1); // Generate a random row index between 0 and ROWS-2
            grid[random_row][random_col] = '#'; // Place sand at a random position
        }

    }


    //render current state
    //clear screen and print frame number

    for (int frame = 0; frame < 11; ++frame)
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Frame: " << frame << std::endl;

        for(int r=0; r < ROWS; ++r)
        {
            for(int c=0; c < COLUMNS; ++c)
            {
                std::cout << grid[r][c] << " ";
            }
            std::cout << "\n" << std::endl;
        }

        // Move sand down
        // swap sand with the cell below it if it's empty
        for(int r = ROWS - 2; r >= 0; --r)
        {
            for ( int c = 0; c < COLUMNS; ++c)
            {
                if(grid[r][c] == '#')
                {
                    // Check if the cell below is empty
                    if (grid[r+1][c] == '.')
                    {
                        //Move the sand down
                        grid[r+1][c] = '#'; //put sand in new spot
                        grid[r][c] = '.'; // remove sand from old spot
                    }
                }
            }
        }

        // Sleep for a short duration to create animation effect
        /* 
        NOTES
            - std::this thread - tells computer command is for current thread of execution
            - sleep_for(...) - tells command to pause executation for specified duration
            - std::chrono::milliseconds(500) - creates a duration of 500 milliseconds (half a second)
        */

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Pause for 500 milliseconds

    }

}