#include "proverb.h"

#include "wisdom_factory.h"

#include <utility>

Proverb::Proverb(std::string country, std::string content)
    : WisdomEntry(std::move(content)), country_(std::move(country)) {}

std::string Proverb::TypeName() const {
    return "Пословица";
}

std::string Proverb::OriginLabel() const {
    return "Страна";
}

const std::string& Proverb::Origin() const {
    return country_;
}

std::unique_ptr<WisdomEntry> Proverb::Create(const std::string& country, const std::string& content) {
    return std::make_unique<Proverb>(country, content);
}

namespace {
const bool registered = WisdomFactory::Register("proverb", &Proverb::Create);
} // namespace
