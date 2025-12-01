#include "multimethod.h"

#include "wisdom_entry.h"

#include <vector>

namespace {

std::vector<OopPairHandler>& Handlers() {
    static std::vector<OopPairHandler> handlers;
    return handlers;
}

std::string DescribePair(const WisdomEntry& first, const WisdomEntry& second) {
    for (const auto handler : Handlers()) {
        std::string phrase;
        if (handler && handler(first, second, phrase)) {
            return phrase;
        }
    }
    return "Нет зарегистрированного обработчика для этой комбинации.";
}

} // namespace

void RegisterPairHandler(OopPairHandler handler) {
    if (handler) {
        Handlers().push_back(handler);
    }
}

void PrintPairReport(const WisdomCollection& collection, std::ostream& out) {
    const auto& items = collection.Items();
    if (items.size() < 2) {
        out << "Недостаточно элементов для мультиметода.\n";
        return;
    }

    std::size_t index = 1;
    for (auto first = items.begin(); first != items.end(); ++first) {
        auto second = first;
        ++second;
        for (; second != items.end(); ++second) {
            out << "Пара " << index++ << ":\n";
            out << "  Первый: " << (*first)->TypeName()
                << " — \"" << (*first)->Content() << "\" (" << (*first)->Keeper() << ")\n";
            out << "  Второй: " << (*second)->TypeName()
                << " — \"" << (*second)->Content() << "\" (" << (*second)->Keeper() << ")\n";
            out << "  Фраза: " << DescribePair(*(*first), *(*second)) << "\n\n";
        }
    }
}
