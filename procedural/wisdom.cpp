#include "wisdom.h"

#include <cctype>
#include <fstream>
#include <sstream>
#include <string_view>

namespace {

std::string_view TrimView(std::string_view value) {
    const auto begin = value.find_first_not_of(" \t\r\n");
    if (begin == std::string_view::npos) {
        return {};
    }
    const auto end = value.find_last_not_of(" \t\r\n");
    return value.substr(begin, end - begin + 1);
}

bool ExtractQuoted(std::string_view line, std::size_t& pos, std::string& destination) {
    while (pos < line.size() && std::isspace(static_cast<unsigned char>(line[pos]))) {
        ++pos;
    }
    if (pos >= line.size() || line[pos] != '"') {
        return false;
    }
    ++pos; // skip opening quote
    std::ostringstream builder;
    while (pos < line.size()) {
        const char ch = line[pos];
        if (ch == '\\') {
            if (pos + 1 >= line.size()) {
                return false;
            }
            const char next = line[pos + 1];
            if (next == '"' || next == '\\') {
                builder << next;
                pos += 2;
            } else {
                builder << next;
                pos += 2;
            }
            continue;
        }
        if (ch == '"') {
            ++pos; // skip closing quote
            destination = builder.str();
            return true;
        }
        builder << ch;
        ++pos;
    }
    return false; // closing quote not found
}

bool ParseLine(std::string_view line_view, Wisdom& entry, std::string& error_message) {
    line_view = TrimView(line_view);
    if (line_view.empty()) {
        return true; // skip empty lines silently
    }

    constexpr std::string_view aphorism_token = "aphorism";
    constexpr std::string_view proverb_token = "proverb";

    std::size_t pos = 0;
    WisdomType type;
    if (line_view.substr(0, aphorism_token.size()) == aphorism_token &&
        (line_view.size() == aphorism_token.size() || std::isspace(static_cast<unsigned char>(line_view[aphorism_token.size()])))) {
        type = WisdomType::Aphorism;
        pos = aphorism_token.size();
    } else if (line_view.substr(0, proverb_token.size()) == proverb_token &&
               (line_view.size() == proverb_token.size() || std::isspace(static_cast<unsigned char>(line_view[proverb_token.size()])))) {
        type = WisdomType::Proverb;
        pos = proverb_token.size();
    } else {
        error_message = "Unknown entry type. Expected 'aphorism' or 'proverb'.";
        return false;
    }

    std::string origin;
    if (!ExtractQuoted(line_view, pos, origin)) {
        error_message = "Unable to parse quoted origin (author or country).";
        return false;
    }

    std::string content;
    if (!ExtractQuoted(line_view, pos, content)) {
        error_message = "Unable to parse quoted content.";
        return false;
    }

    while (pos < line_view.size()) {
        if (!std::isspace(static_cast<unsigned char>(line_view[pos]))) {
            error_message = "Unexpected trailing characters after content.";
            return false;
        }
        ++pos;
    }

    entry.type = type;
    entry.origin = std::move(origin);
    entry.content = std::move(content);

    return true;
}

const char* TypeLabel(const Wisdom& item) {
    switch (item.type) {
        case WisdomType::Aphorism:
            return "Тип: Афоризм";
        case WisdomType::Proverb:
            return "Тип: Пословица";
    }
    return "Тип: Неизвестно"; // should never happen
}

const char* OriginLabel(const Wisdom& item) {
    switch (item.type) {
        case WisdomType::Aphorism:
            return "Автор";
        case WisdomType::Proverb:
            return "Страна";
    }
    return "Источник";
}

} // namespace

bool LoadWisdomList(const std::string& filename, WisdomList& list, std::string& error_message) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        error_message = "Unable to open input file: " + filename;
        return false;
    }

    list.items.clear();

    std::string line;
    std::size_t line_number = 0;
    while (std::getline(input, line)) {
        ++line_number;
        Wisdom item{};
        std::string parse_error;
        if (!ParseLine(line, item, parse_error)) {
            if (!TrimView(line).empty()) {
                std::ostringstream builder;
                builder << "Error in line " << line_number << ": " << parse_error;
                error_message = builder.str();
                return false;
            }
            continue;
        }
        if (!TrimView(line).empty()) {
            list.items.push_back(std::move(item));
        }
    }

    return true;
}

void PrintSummary(const WisdomList& list, std::ostream& out) {
    out << "Объектов в контейнере: " << list.items.size() << '\n';
}

void PrintDetails(const WisdomList& list, std::ostream& out) {
    for (const auto& item : list.items) {
        out << TypeLabel(item) << ", "
            << OriginLabel(item) << ": " << item.origin << ", "
            << "Содержание: " << item.content << '\n';
    }
}
