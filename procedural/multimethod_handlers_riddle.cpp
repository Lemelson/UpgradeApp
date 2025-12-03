#include "multimethod.h"

namespace {

bool AphorismThenRiddle(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Aphorism && second.type == WisdomType::Riddle) {
        phrase = "Афоризм задаёт загадке направление ответа.";
        return true;
    }
    return false;
}

bool RiddleThenAphorism(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Riddle && second.type == WisdomType::Aphorism) {
        phrase = "Загадка испытывает терпение афоризма.";
        return true;
    }
    return false;
}

bool ProverbThenRiddle(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Proverb && second.type == WisdomType::Riddle) {
        phrase = "Пословица шепчет подсказку загадке.";
        return true;
    }
    return false;
}

bool RiddleThenProverb(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Riddle && second.type == WisdomType::Proverb) {
        phrase = "Загадка проверяет мудрость пословицы.";
        return true;
    }
    return false;
}

bool TwoRiddles(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Riddle && second.type == WisdomType::Riddle) {
        phrase = "Две загадки переплетают тайные смыслы.";
        return true;
    }
    return false;
}

struct Registrar {
    Registrar() {
        RegisterPairHandler(&AphorismThenRiddle);
        RegisterPairHandler(&RiddleThenAphorism);
        RegisterPairHandler(&ProverbThenRiddle);
        RegisterPairHandler(&RiddleThenProverb);
        RegisterPairHandler(&TwoRiddles);
    }
};

Registrar registrar;

} // namespace
