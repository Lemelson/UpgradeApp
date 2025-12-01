#ifndef IZ1_OOP_WISDOM_ENTRY_H
#define IZ1_OOP_WISDOM_ENTRY_H

#include <ostream>
#include <string>

// Базовый класс "мудрости" для объектно-ориентированного варианта.
class WisdomEntry {
public:
    explicit WisdomEntry(std::string content);
    virtual ~WisdomEntry() = default;

    const std::string& Content() const;

    virtual std::string TypeName() const = 0;
    virtual std::string OriginLabel() const = 0;
    virtual const std::string& Origin() const = 0;

    virtual void Print(std::ostream& out) const;

protected:
    const std::string& content() const;

private:
    std::string content_;
};

#endif // IZ1_OOP_WISDOM_ENTRY_H
