#ifndef IZ1_OOP_WISDOM_COLLECTION_H
#define IZ1_OOP_WISDOM_COLLECTION_H

#include <list>
#include <memory>
#include <ostream>

#include "wisdom_entry.h"

// Контейнер для хранения мудростей (использует std::list по требованию варианта).
class WisdomCollection {
public:
    void Add(std::unique_ptr<WisdomEntry> entry);

    std::size_t Size() const;

    void PrintSummary(std::ostream& out) const;
    void PrintDetails(std::ostream& out) const;
    void PrintContentLengths(std::ostream& out) const;
    void PrintAphorisms(std::ostream& out) const;

    const std::list<std::unique_ptr<WisdomEntry>>& Items() const;

private:
    std::list<std::unique_ptr<WisdomEntry>> items_;
};

#endif // IZ1_OOP_WISDOM_COLLECTION_H
