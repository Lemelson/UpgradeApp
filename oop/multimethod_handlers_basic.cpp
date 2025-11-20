#include "multimethod.h"

#include "aphorism.h"
#include "proverb.h"

namespace {

bool AphorismThenProverb(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Aphorism*>(&first) && dynamic_cast<const Proverb*>(&second)) {
        phrase = "Афоризм задаёт тон пословице.";
        return true;
    }
    return false;
}

bool ProverbThenAphorism(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Proverb*>(&first) && dynamic_cast<const Aphorism*>(&second)) {
        phrase = "Пословица поддерживает афоризм.";
        return true;
    }
    return false;
}

bool TwoAphorisms(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Aphorism*>(&first) && dynamic_cast<const Aphorism*>(&second)) {
        phrase = "Два афоризма спорят о смысле слов.";
        return true;
    }
    return false;
}

bool TwoProverbs(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Proverb*>(&first) && dynamic_cast<const Proverb*>(&second)) {
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
