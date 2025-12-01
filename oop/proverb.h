#ifndef IZ1_OOP_PROVERB_H
#define IZ1_OOP_PROVERB_H

#include "wisdom_entry.h"

#include <memory>
#include <string>

class Proverb : public WisdomEntry {
public:
    Proverb(std::string country, std::string content, std::string keeper);

    std::string TypeName() const override;
    std::string OriginLabel() const override;
    const std::string& Origin() const override;

    static std::unique_ptr<WisdomEntry> Create(const std::string& country,
                                               const std::string& content,
                                               const std::string& keeper);

private:
    std::string country_;
};

#endif // IZ1_OOP_PROVERB_H
