#include "aphorism.h"

#include "wisdom_factory.h"

#include <utility>

Aphorism::Aphorism(std::string author, std::string content)
    : WisdomEntry(std::move(content)), author_(std::move(author)) {}

std::string Aphorism::TypeName() const {
    return "Афоризм";
}

std::string Aphorism::OriginLabel() const {
    return "Автор";
}

const std::string& Aphorism::Origin() const {
    return author_;
}

std::unique_ptr<WisdomEntry> Aphorism::Create(const std::string& author, const std::string& content) {
    return std::make_unique<Aphorism>(author, content);
}

namespace {
const bool registered = WisdomFactory::Register("aphorism", &Aphorism::Create);
} // namespace
