#include "multimethod.h"

namespace {

bool AphorismThenProverb(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Aphorism && second.type == WisdomType::Proverb) {
        phrase = "Афоризм задаёт тон пословице.";
        return true;
    }
    return false;
}

bool ProverbThenAphorism(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Proverb && second.type == WisdomType::Aphorism) {
        phrase = "Пословица поддерживает афоризм.";
        return true;
    }
    return false;
}

bool TwoAphorisms(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Aphorism && second.type == WisdomType::Aphorism) {
        phrase = "Два афоризма спорят о смысле слов.";
        return true;
    }
    return false;
}

bool TwoProverbs(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Proverb && second.type == WisdomType::Proverb) {
        phrase = "Две пословицы сравнивают традиции.";
        return true;
    }
    return false;
}

struct Registrar {
    Registrar() {
        RegisterPairHandler(&AphorismThenProverb);
        RegisterPairHandler(&ProverbThenAphorism);
        RegisterPairHandler(&TwoAphorisms);
        RegisterPairHandler(&TwoProverbs);
    }
};

Registrar registrar;

} // namespace
