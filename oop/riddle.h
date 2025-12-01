#ifndef IZ1_OOP_RIDDLE_H
#define IZ1_OOP_RIDDLE_H

#include "wisdom_entry.h"

#include <memory>
#include <string>

class Riddle : public WisdomEntry {
public:
    Riddle(std::string answer, std::string content, std::string keeper);

    std::string TypeName() const override;
    std::string OriginLabel() const override;
    const std::string& Origin() const override;

    static std::unique_ptr<WisdomEntry> Create(const std::string& answer,
                                               const std::string& content,
                                               const std::string& keeper);

private:
    std::string answer_;
};

#endif // IZ1_OOP_RIDDLE_H
