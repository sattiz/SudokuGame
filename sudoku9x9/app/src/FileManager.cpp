#include "../headers/FileManager.h"

// Load a Sudoku board from a file
bool FileManager::loadFromFile(Sudoku9x9 &board, std::string &filename) noexcept {
    // Check if the file exists
    if (!fs::exists(filename))
        return false;

    // Open the file for reading
    std::ifstream saveFile(filename);

    // Check if the file is open
    if (!saveFile.is_open()) {
        return false;
    }

    // Read the file content into a stringstream
    std::stringstream dump;
    dump << saveFile.rdbuf();

    // Try to load the board from the file content
    try {
        board.loadBoard(dump.str());
    } catch (const std::exception &e) {
        // Loading failed, return false
        return false;
    }

    // Close the file and return true (success)
    saveFile.close();
    return true;
}

// Save a Sudoku board to a file
bool FileManager::saveToFile(Sudoku9x9 &board, std::string &filename) noexcept {
    std::string saveFilename = filename;

    // If the filename is empty, create a new file
    if (saveFilename.empty())
        if (!createFile(saveFilename))
            return false;

    // Open the file for writing
    std::ofstream saveFile(saveFilename, std::ios::out);
    std::string dump = board.dumpBoard();

    // Check if the file is open
    if (!saveFile.is_open()) {
        return false;
    }

    // Write the board content to the file
    saveFile << dump;
    saveFile.close();
    filename = saveFilename;
    return true;
}

// Create a new file with a generated name based on the current timestamp
bool FileManager::createFile(std::string &savefile) noexcept {
    std::string fileNamePrefix = "SUDOKU9x9SAVE_";
    std::string fileExtension = ".save";

    // Get the current time in milliseconds
    auto now = std::chrono::system_clock::now();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    // Format the time
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");

    // Generate a unique filename based on the timestamp
    std::string fileName = fileNamePrefix + oss.str() + fileExtension;

    // Create the file
    std::ofstream outputFile(fileName);

    // Check if the file is open
    if (outputFile.is_open()) {
        outputFile.close();
        savefile = fileName;
        return true;
    } else {
        // Failed to create the file, return false
        return false;
    }
}
