#pragma once

#include <string>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <filesystem>
#include "Sudoku9x9.h"

namespace fs = std::filesystem;

/*!
 * \brief The FileManager struct provides functionality for loading and saving Sudoku games to files.
 */
struct FileManager {

    /*!
     * \brief Load a Sudoku game from a file.
     *
     * \param board Reference to a Sudoku9x9 object where the loaded game will be stored.
     * \param filename Reference to a string containing the name of the file to load from.
     * \return True if the load operation is successful, false otherwise.
     */
    static bool loadFromFile(Sudoku9x9 &board, std::string &filename) noexcept;

    /*!
     * \brief Save a Sudoku game to a file.
     *
     * \param board Reference to a Sudoku9x9 object containing the game to be saved.
     * \param filename Reference to a string containing the name of the file to save to.
     * \return True if the save operation is successful, false otherwise.
     */
    static bool saveToFile(Sudoku9x9 &board, std::string &filename) noexcept;

private:

    /*!
     * \brief Create a new file.
     *
     * \param savefile Reference to a string containing the name of the file to create.
     * \return True if the file creation is successful, false otherwise.
     */
    static bool createFile(std::string &savefile) noexcept;
};
