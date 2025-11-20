#include "riddle.h"

#include "wisdom_factory.h"

#include <utility>

Riddle::Riddle(std::string answer, std::string content, std::string keeper)
    : WisdomEntry(std::move(content), std::move(keeper)), answer_(std::move(answer)) {}

std::string Riddle::TypeName() const {
    return "Загадка";
}

std::string Riddle::OriginLabel() const {
    return "Ответ";
}

const std::string& Riddle::Origin() const {
    return answer_;
}

std::unique_ptr<WisdomEntry> Riddle::Create(const std::string& answer,
                                            const std::string& content,
                                            const std::string& keeper) {
    return std::make_unique<Riddle>(answer, content, keeper);
}

namespace {
const bool registered = WisdomFactory::Register("riddle", &Riddle::Create);
} // namespace
