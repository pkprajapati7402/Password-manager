#ifndef STORAGE_H
#define STORAGE_H

#include <string>

class Storage {
public:
    static void savePassword(const std::string &username, const std::string &password);
    static std::string loadPassword(const std::string &username);
};

#endif // STORAGE_H
