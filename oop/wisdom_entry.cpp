#include "wisdom_entry.h"

WisdomEntry::WisdomEntry(std::string content)
    : content_(std::move(content)) {}

const std::string& WisdomEntry::Content() const {
    return content_;
}

const std::string& WisdomEntry::content() const {
    return content_;
}

void WisdomEntry::Print(std::ostream& out) const {
    out << "Тип: " << TypeName() << ", "
        << OriginLabel() << ": " << Origin() << ", "
        << "Содержание: " << Content() << '\n';
}
