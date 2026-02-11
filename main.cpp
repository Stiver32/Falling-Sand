//This is a visual simulation, but simplified. It uses a 2D array (grid) and basic gravity logic.
//- **The Goal:** Create a 10x10 grid of `.` (empty air). Place a `#` (sand) at the top. Every "frame" (loop iteration), 
//the sand moves down one row *unless* the space below it is blocked.

#include <iostream>
#include <vector>

int main()
{
    const int ROWS = 10;
    const int COLUMNS = 10;

    std::vector<std::vector<char>> grid (ROWS, std::vector<char>(COLUMNS, '.')); // Create a 10x10 grid filled with '.'
    

    //place sand at top
    grid[0][5] = '#'; // Place sand at the top middle

    for (int frame = 0; frame < 11; frame++)
    {
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Frame: " << frame << std::endl;

        for(int r=0; r < ROWS; r++)
        {
            for(int c=0; c < COLUMNS; c++)
            {
                std::cout << grid[r][c] << " ";
            }
            std::cout << "\n" << std::endl;
        }
    }


    //iterate through the grid and move sand down

    // std::cout << "Initial Grid:" << std::endl;

    // for (const auto& row : grid)
    // {
    //     for (const auto& cell : row)
    //     {
    //         std::cout << cell << " ";
    //     }
    //     std::cout << std::endl;
    // }



}