#ifndef IZ1_OOP_APHORISM_H
#define IZ1_OOP_APHORISM_H

#include "wisdom_entry.h"

#include <memory>
#include <string>

class Aphorism : public WisdomEntry {
public:
    Aphorism(std::string author, std::string content);

    std::string TypeName() const override;
    std::string OriginLabel() const override;
    const std::string& Origin() const override;

    static std::unique_ptr<WisdomEntry> Create(const std::string& author, const std::string& content);

private:
    std::string author_;
};

#endif // IZ1_OOP_APHORISM_H
