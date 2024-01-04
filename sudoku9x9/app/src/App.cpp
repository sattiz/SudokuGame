#include "../headers/App.h"

// Constructor for the App class
App::App(int argc, char **argv) {
    std::cout << CLEAR;
    if (argc == 2) {
        // Load game from file if a filename is provided as a command-line argument
        filename = argv[1];
        if (!FileManager::loadFromFile(board, filename))
            throw std::runtime_error("Unable to load from file " + filename);
        std::cout << "Game is loaded from file " << filename << std::endl
                  << "To start loaded game choose '3. Continue game'" << std::endl;
        is_started = true;
    } else if (argc == 1) {
        // No filename provided, initialize an empty string
        filename = std::string();
    } else {
        // Invalid command line options
        throw std::runtime_error("Wrong command line options");
    }
}

// Run method to handle the main menu and user choices
void App::run() {
    int choose = 42;
    while (choose != 5) {
        // Display main menu options
        std::cout << "1. Start new game" << std::endl
                  << "2. Load game" << std::endl
                  << "3. Continue game" << std::endl
                  << "4. Save current session" << std::endl
                  << "5. Exit game" << std::endl;
        std::cout << "Enter key: ";
        getKey(choose);
        switch (choose) {
            case 1:
                std::cout << CLEAR;
                startNewGame();
                break;
            case 2:
                std::cout << CLEAR;
                loadGame();
                break;
            case 3:
                std::cout << CLEAR;
                if (is_started)
                    Game::run(board);
                else {
                    std::cout << CLEAR;
                    std::cout << "No game is started" << std::endl;
                }
                break;
            case 4:
                saveGame();
                break;
            case 5:
                break;
            default: {
                std::cout << CLEAR;
                std::cout << "Wrong input." << std::endl;
            }
        }
    }
    // Save the game before exiting, if a game is started
    if (is_started)
        saveGame();
    std::cout << "See you" << std::endl;
}

// Method to start a new game
void App::startNewGame() {
    if (is_started) {
        char choose;
        std::cout << "Previous session will be closed. Are you sure? y/n" << std::endl;
        std::cout << "Enter key: ";
        getKey(choose);
        if (choose != 'y') {
            std::cout << CLEAR;
            std::cout << "Operation cancelled." << std::endl;
            return;
        }
    }

    // Choose the difficulty level for the new game
    std::cout << "Choose difficulty:" << std::endl;
    int difficulty = 42;
    for (;;) {
        std::cout << "1. Easy" << std::endl
                  << "2. Medium" << std::endl
                  << "3. Hard" << std::endl
                  << "4. Very Hard" << std::endl
                  << "5. To main menu" << std::endl;
        std::cout << "Enter key: ";
        getKey(difficulty);
        if (difficulty < 1 || difficulty > 5) {
            std::cout << "Wrong Input";
        } else
            break;
    }

    // If the user chooses to go back to the main menu, cancel the operation
    if (difficulty == 5) {
        std::cout << CLEAR;
        std::cout << "Operation cancelled." << std::endl;
        return;
    }

    // Generate a new Sudoku board based on the chosen difficulty
    Sudoku9x9 newBoard = Sudoku9x9();
    SudokuSolver::generateBoard(newBoard, 10 * difficulty);
    board = newBoard;
    startGame();
}

// Method to load a game from a file
void App::loadGame() {
    std::cout << CLEAR;
    char choose;
    if (is_started) {
        std::cout << "Previous session will be closed. Are you sure? y/n" << std::endl;
        std::cout << "Enter key: ";
        getKey(choose);
        if (choose != 'y') {
            std::cout << CLEAR;
            std::cout << "Operation cancelled." << std::endl;
            return;
        }
    }

    // Prompt the user to enter the filename to load the game from
    std::cout << "Choose file: ";
    getFile();

    // Load the game from the specified file
    if (!FileManager::loadFromFile(board, filename)) {
        std::cout << CLEAR;
        std::cout << "Unable to load from file " + filename << std::endl;
        return;
    }
    std::cout << CLEAR;
    std::cout << "Game is loaded from file " << filename << std::endl;
    startGame();
}

// Method to save the current game state to a file
void App::saveGame() {
    std::cout << CLEAR;
    if (!is_started) {
        std::cout << "No game to save" << std::endl;
        return;
    }
    int choose = 42;
    std::cout << "Would you like to save game?" << std::endl;
    std::cout << "1. Save" << std::endl
              << "<any other key/keys +Enter> Do not save." << std::endl;
    std::cout << "Enter key: ";
    getKey(choose);
    if (choose != 1) {
        std::cout << CLEAR;
        std::cout << "Saving cancelled." << std::endl;
        return;
    }

    // Prompt the user to enter the filename to save the game to
    std::cout << "Choose file (Enter empty string to autogenerate name of the save): ";
    getFile();

    // Save the game to the specified file
    if (FileManager::saveToFile(board, filename)) {
        std::cout << CLEAR;
        std::cout << "Game is saved to file: " << filename << std::endl;
    }
    else {
        std::cout << CLEAR;
        std::cout << "Unable to save game" << std::endl;
    }
}

// Method to start the game
void App::startGame() {
    is_started = true;
    Game::run(board);
}

// Helper method to get a file name from the user
void App::getFile() {
    std::getline(std::cin, filename);
}
