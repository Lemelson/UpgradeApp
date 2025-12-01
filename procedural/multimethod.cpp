#include "multimethod.h"

#include <vector>

namespace {

std::vector<ProceduralPairHandler>& Handlers() {
    static std::vector<ProceduralPairHandler> handlers;
    return handlers;
}

std::string DescribePair(const Wisdom& first, const Wisdom& second) {
    for (const auto handler : Handlers()) {
        std::string phrase;
        if (handler && handler(first, second, phrase)) {
            return phrase;
        }
    }
    return "Нет зарегистрированного обработчика для этой комбинации.";
}

const char* SimpleTypeName(WisdomType type) {
    switch (type) {
        case WisdomType::Aphorism:
            return "Афоризм";
        case WisdomType::Proverb:
            return "Пословица";
        case WisdomType::Riddle:
            return "Загадка";
    }
    return "Неизвестно";
}

} // namespace

void RegisterPairHandler(ProceduralPairHandler handler) {
    if (handler) {
        Handlers().push_back(handler);
    }
}

void PrintPairReport(const WisdomList& list, std::ostream& out) {
    if (list.items.size() < 2) {
        out << "Недостаточно элементов для мультиметода.\n";
        return;
    }

    std::size_t index = 1;
    for (auto first = list.items.begin(); first != list.items.end(); ++first) {
        auto second = first;
        ++second;
        for (; second != list.items.end(); ++second) {
            out << "Пара " << index++ << ":\n";
            out << "  Первый: " << SimpleTypeName(first->type)
                << " — \"" << first->content << "\" (" << first->keeper << ")\n";
            out << "  Второй: " << SimpleTypeName(second->type)
                << " — \"" << second->content << "\" (" << second->keeper << ")\n";
            out << "  Фраза: " << DescribePair(*first, *second) << "\n\n";
        }
    }
}
