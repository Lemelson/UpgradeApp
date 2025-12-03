#include "multimethod.h"

#include "aphorism.h"
#include "proverb.h"
#include "riddle.h"

namespace {

bool AphorismThenRiddle(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Aphorism*>(&first) && dynamic_cast<const Riddle*>(&second)) {
        phrase = "Афоризм задаёт загадке направление ответа.";
        return true;
    }
    return false;
}

bool RiddleThenAphorism(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Riddle*>(&first) && dynamic_cast<const Aphorism*>(&second)) {
        phrase = "Загадка испытывает терпение афоризма.";
        return true;
    }
    return false;
}

bool ProverbThenRiddle(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Proverb*>(&first) && dynamic_cast<const Riddle*>(&second)) {
        phrase = "Пословица шепчет подсказку загадке.";
        return true;
    }
    return false;
}

bool RiddleThenProverb(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Riddle*>(&first) && dynamic_cast<const Proverb*>(&second)) {
        phrase = "Загадка проверяет мудрость пословицы.";
        return true;
    }
    return false;
}

bool TwoRiddles(const WisdomEntry& first, const WisdomEntry& second, std::string& phrase) {
    if (dynamic_cast<const Riddle*>(&first) && dynamic_cast<const Riddle*>(&second)) {
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
