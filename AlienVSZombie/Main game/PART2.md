# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://www.youtube.com/watch?v=zEpa2YtSvnM).

## Minimum Requirements

1. Game play menu
2. Game board generation
3. Alien generated in the middle
4. Random Zombie position
5. Alien control command
6. Game object interaction 
7. Arrow direction control command 
8. Save function
9. Load function
10. Alien movement

### Completed

1. Game Main menu
2. Game play menu (Game Board Setting)
3. Game board generation (default)
4. Game board generation (custom)
5. Control page 
6. Quit option
7. Save function
8. Alien generated in the middle
9. Alien movement 
10. Arrow direction control command
11. Load function

## Additional Features
Describe the additional features that has been implemented.
1. Zombie has a lifesteal effect where, the damage done to the Alien will restore the Zombie health.

## Contributions

List down the contribution of each group members.

### Chua Li En

1. Randomly generate gameboard.
2. Alien generation
3. Randomly generate Zombie position
4. save function
5. Load function
6. Game testing and bugs fixing

### Muhammad Afiq Ikhwan Bin Aminuddin

1. Game main menu
2. Game play menu (game setting)
3. Controls in menu and during game
4. Quit function
5. Alien movement
6. Game objection interaction
7. lifesteal effect

## Problems Encountered & Solutions

Describe the problems encountered and provide the solutions / plan for the solutions.
1. Arrow changing function will interupt with other game objects and changed them.
  - Added if statement to check the object(<,>,^,v) in the map then change the arrow once the condition is satisfied.
 
2. Cout warning in load function(when file doesn't exist) doesn't show up in the program.
  - Added Pause() after cout statement.

3. Zombies will be covered by game objects.
  - Initialize the gameboard once user go into the menu to clear out all the items inside vector and set the map.
