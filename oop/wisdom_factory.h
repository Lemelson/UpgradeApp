#ifndef IZ1_OOP_WISDOM_FACTORY_H
#define IZ1_OOP_WISDOM_FACTORY_H

#include <functional>
#include <memory>
#include <string>
#include <string_view>

class WisdomEntry;

// Фабрика для создания экземпляров мудростей по строковому идентификатору.
class WisdomFactory {
public:
    using Creator = std::function<std::unique_ptr<WisdomEntry>(const std::string& origin, const std::string& content)>;

    static bool Register(std::string type_name, Creator creator);
    static std::unique_ptr<WisdomEntry> Create(std::string_view type_name,
                                               const std::string& origin,
                                               const std::string& content);
};

#endif // IZ1_OOP_WISDOM_FACTORY_H
