// This program uses a sentinel-controlled loop. It calculates the total
// number of points a soccer team has earned so far this season. The user
// enters the points earned for each game, then enters -1 when finished.
#include <iostream>
using namespace std;

int main()
{
    int game = 1,         // Game counter
        points,           // Holds number of points for a specific game
        total = 0;        // Accumulates total points for all games

    // Read in the points for game 1
    cout << "Enter the number of points your team earned for each\n";
    cout << "game so far this season. Then enter -1 when finished.\n\n";
    cout << "Enter the points for game " << game << ": ";
    cin  >> points;

    // Loop as long as the end sentinel has not yet been entered
    while (points != -1)
    {   // Add point just read in to the accumulator
        total += points;

       // Enter the points for the next game
        game++;
        cout << "Enter the points for game " << game << ": ";
        cin  >> points;
    }
    // Display the total points
    cout << "\nThe team has earned " << total << " points so far. \n";
    return 0;
}