#pragma once

#include "Sudoku9x9.h"
#include "FileManager.h"
#include "Game.h"
#include "SudokuSolver.h"

/*!
 * \brief Structure representing an application for playing Sudoku.
 *
 * Provides the main user interface and manages game sessions.
 */
struct App {

    /*!
     * \brief Constructor for the application.
     *
     * Takes command line arguments and initializes the application based on the provided parameters.
     *
     * \param argc The number of command line arguments.
     * \param argv An array of strings representing command line arguments.
     */
    App(int argc, char **argv);

    /*!
     * \brief Main method to run the application.
     *
     * Guides the user through the main menu and handles the user's choice, performing corresponding actions.
     */
    void run();

    /*!
     * \brief Destructor for the application.
     */
    ~App() = default;

private:

    /*!
     * \brief Method to start a new game.
     *
     * Allows the user to choose the difficulty level and starts a new game.
     */
    void startNewGame();

    /*!
     * \brief Method to load a game from a file.
     *
     * Allows the user to choose a file to load a saved game.
     */
    void loadGame();

    /*!
     * \brief Method to save the current game to a file.
     *
     * Allows the user to choose whether to save the current game and, if yes, specify the filename.
     */
    void saveGame();

    /*!
     * \brief Method to start a game session.
     *
     * Initiates a game session if one is not already started.
     */
    void startGame();

    /*!
     * \brief Method to read a string from input.
     *
     * Reads a string from standard input and stores it in the filename variable.
     */
    void getFile();

    /*!
     * \brief Method to read a single value from input.
     *
     * \tparam T Type of the value to be read.
     * \param choose Reference to the variable where the read value will be stored.
     */
    template<typename T>
    static void getKey(T &choose) {
        std::cin >> choose;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    Sudoku9x9 board; ///< Sudoku game board.
    std::string filename; ///< Filename for loading or saving the game.
    bool is_started{false}; ///< Flag indicating whether a game session is started.
};

