#include "wisdom_loader.h"

#include "wisdom_collection.h"
#include "wisdom_factory.h"

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
    ++pos;

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
            ++pos;
            destination = builder.str();
            return true;
        }
        builder << ch;
        ++pos;
    }
    return false;
}

bool ParseLine(std::string_view line_view,
               std::string& type,
               std::string& origin,
               std::string& content,
               std::string& error) {
    line_view = TrimView(line_view);
    if (line_view.empty()) {
        return true;
    }

    std::size_t pos = 0;
    while (pos < line_view.size() && !std::isspace(static_cast<unsigned char>(line_view[pos]))) {
        ++pos;
    }
    type = std::string(line_view.substr(0, pos));
    while (pos < line_view.size() && std::isspace(static_cast<unsigned char>(line_view[pos]))) {
        ++pos;
    }

    if (!ExtractQuoted(line_view, pos, origin)) {
        error = "Unable to parse quoted origin.";
        return false;
    }

    if (!ExtractQuoted(line_view, pos, content)) {
        error = "Unable to parse quoted content.";
        return false;
    }

    while (pos < line_view.size()) {
        if (!std::isspace(static_cast<unsigned char>(line_view[pos]))) {
            error = "Unexpected trailing characters.";
            return false;
        }
        ++pos;
    }

    return true;
}

} // namespace

bool LoadFromFile(const std::string& path, WisdomCollection& collection, std::string& error_message) {
    std::ifstream input(path);
    if (!input.is_open()) {
        error_message = "Unable to open input file: " + path;
        return false;
    }

    std::string line;
    std::size_t line_number = 0;
    while (std::getline(input, line)) {
        ++line_number;

        std::string type;
        std::string origin;
        std::string content;
        std::string parse_error;
        if (!ParseLine(line, type, origin, content, parse_error)) {
            if (!TrimView(line).empty()) {
                std::ostringstream builder;
                builder << "Error in line " << line_number << ": " << parse_error;
                error_message = builder.str();
                return false;
            }
            continue;
        }

        if (TrimView(line).empty()) {
            continue;
        }

        auto entry = WisdomFactory::Create(type, origin, content);
        if (!entry) {
            std::ostringstream builder;
            builder << "Error in line " << line_number << ": Unknown type '" << type << "'.";
            error_message = builder.str();
            return false;
        }

        collection.Add(std::move(entry));
    }

    return true;
}
