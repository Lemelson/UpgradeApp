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

const std::list<std::unique_ptr<WisdomEntry>>& WisdomCollection::Items() const {
    return items_;
}
