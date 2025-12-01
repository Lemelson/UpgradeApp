#include "wisdom_entry.h"

#include <utility>

WisdomEntry::WisdomEntry(std::string content, std::string keeper)
    : content_(std::move(content)), keeper_(std::move(keeper)) {}

const std::string& WisdomEntry::Content() const {
    return content_;
}

const std::string& WisdomEntry::Keeper() const {
    return keeper_;
}

const std::string& WisdomEntry::content() const {
    return content_;
}

void WisdomEntry::Print(std::ostream& out) const {
    out << "Тип: " << TypeName() << ", "
        << OriginLabel() << ": " << Origin() << ", "
        << "Содержание: " << Content() << ", "
        << "Кладезь: " << Keeper() << '\n';
}
