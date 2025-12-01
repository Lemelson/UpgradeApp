#include "wisdom_collection.h"

#include "wisdom_entry.h"

void WisdomCollection::Add(std::unique_ptr<WisdomEntry> entry) {
    if (entry) {
        items_.push_back(std::move(entry));
    }
}

std::size_t WisdomCollection::Size() const {
    return items_.size();
}

void WisdomCollection::PrintSummary(std::ostream& out) const {
    out << "Объектов в контейнере: " << items_.size() << '\n';
}

void WisdomCollection::PrintDetails(std::ostream& out) const {
    for (const auto& entry : items_) {
        entry->Print(out);
    }
}

void WisdomCollection::PrintContentLengths(std::ostream& out) const {
    out << "Количество символов в содержании по каждому элементу:\n";
    std::size_t index = 1;
    for (const auto& entry : items_) {
        out << index++ << ". Тип: " << entry->TypeName()
            << " -> символов: " << entry->Content().size() << '\n';
    }
}

const std::list<std::unique_ptr<WisdomEntry>>& WisdomCollection::Items() const {
    return items_;
}
