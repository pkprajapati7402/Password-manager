#include "storage.h"
#include <fstream>
#include <sstream>
#include <unordered_map>

const std::string FILENAME = "passwords.txt";

void Storage::savePassword(const std::string &username, const std::string &password) {
    std::unordered_map<std::string, std::string> data;

    // Load existing data
    std::ifstream infile(FILENAME);
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string u, p;
        if (iss >> u >> p) {
            data[u] = p;
        }
    }
    infile.close();

    // Add new data
    data[username] = password;

    // Save all data
    std::ofstream outfile(FILENAME);
    for (const auto &pair : data) {
        outfile << pair.first << " " << pair.second << "\n";
    }
    outfile.close();
}

std::string Storage::loadPassword(const std::string &username) {
    std::ifstream infile(FILENAME);
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string u, p;
        if (iss >> u >> p) {
            if (u == username) {
                return p;
            }
        }
    }
    return "";
}
