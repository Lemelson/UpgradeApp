#include "proverb.h"

#include "wisdom_factory.h"

#include <utility>

Proverb::Proverb(std::string country, std::string content, std::string keeper)
    : WisdomEntry(std::move(content), std::move(keeper)), country_(std::move(country)) {}

std::string Proverb::TypeName() const {
    return "Пословица";
}

std::string Proverb::OriginLabel() const {
    return "Страна";
}

const std::string& Proverb::Origin() const {
    return country_;
}

std::unique_ptr<WisdomEntry> Proverb::Create(const std::string& country,
                                             const std::string& content,
                                             const std::string& keeper) {
    return std::make_unique<Proverb>(country, content, keeper);
}

namespace {
const bool registered = WisdomFactory::Register("proverb", &Proverb::Create);
} // namespace
