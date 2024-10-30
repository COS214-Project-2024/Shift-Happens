#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include <iostream>

/**
 * @class Display
 * @brief  Handles the display and user interaction for various menu options in the game
 * 
 * 
 * The display class provides an interface for displaying menus, capturing user input, 
 * and managing visual elements such as intro,logo and load screen animations
 *.
 * 
 * @note this class is not usde directly.
 * 
 * @version 1.0
 * @date 2024-10-29
 * 
 */

//fuunction and then doxygen for function UNDER IT
using namespace std;
class Display {
public:
    /// @brief Constructor for the display class
    Display();

    /// @brief Destructor for the display class
    ~Display();


    void intro(); /// @brief Displays the introduction screen and awaits for the user to start
    void logo(); /// @brief Displays the game logo in ASCII art.
    void clear(); /// @brief Clears the console screen.
    void wait(int seconds); ///
    /**
     * @brief Pauses execution for a specified number of seconds.
     * @param seconds Number of seconds to wait.
     */

    void loadscreen();/// @brief Shows a loading screen animation
    int MainMenu();///
    
    /**
     * @brief Displays the main menu and returns the user's selection.
     * @return int User's menu selection as an integer.
     */

    
    void displayMenu(vector<string> options);///
     /**
     * @brief Displays a generic menu with provided options.
     * @param options Vector of options to display in the menu.
     */

    int GameMenu(); //for creation of buildings

    /**
     * @brief Displays the game menu options for building actions.
     * @return int User's selection as an integer.
     */

    int Utilitymenu();//options for specific creation
    /*
     * @brief Displays the menu options for creating a utility building.
     * @return int User's selection as an integer.
     */

    int Residentialmenu();///
    /**
     * @brief Displays the menu options for creating a residential building.
     * @return int User's selection as an integer.
     */

    int Commercialmenu();///
    /**
     * @brief Displays the menu options for creating a commercial building.
     * @return int User's selection as an integer.
     */
    int Industrialmenu();///

    /**
     * @brief Displays the menu options for creating an industrial building.
     * @return int User's selection as an integer.
     */

    int LandMarkmenu();///
     /**
     * @brief Displays the menu options for creating a landmark.
     * @return int User's selection as an integer.
     */
    int Infrastructuremenu();///
    /**
     * @brief Displays the menu options for creating an infrastructure.
     * @return int User's selection as an integer.
     */


    int buildingtypemenu();///
    /**
     * @brief Displays the menu options for selecting a building type.
     * @return int User's selection as an integer.
     */

    string getvariant();///
    
    /**
     * @brief Retrieves the current variant type selected.
     * @return std::string The current variant type.
     */

    void settype(const string& variant);///
    /**
     * @brief Sets the building-specifc type to a specified variant.
     * @param variant The variant type to set.
     */



private:
    // Add private members and methods as needed
    string variant;

};

#endif // DISPLAY_H