#ifndef IZ1_OOP_WISDOM_LOADER_H
#define IZ1_OOP_WISDOM_LOADER_H

#include <string>

class WisdomCollection;

// Загружает коллекцию из файла. Возвращает true, если файл прочитан без ошибок.
bool LoadFromFile(const std::string& path, WisdomCollection& collection, std::string& error_message);

#endif // IZ1_OOP_WISDOM_LOADER_H
