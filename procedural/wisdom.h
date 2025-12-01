#ifndef IZ1_PROCEDURAL_WISDOM_H
#define IZ1_PROCEDURAL_WISDOM_H

#include <list>
#include <ostream>
#include <string>

// Тип мудрости, используемый для выбора формата вывода.
enum class WisdomType {
    Aphorism,
    Proverb
};

// Структура для представления одного элемента "Кладезя мудрости".
struct Wisdom {
    WisdomType type;
    std::string origin;   // Автор (для афоризма) или страна (для пословицы).
    std::string content;  // Основное содержание.
};

// Обертка над контейнером, чтобы подчеркнуть процедурный стиль.
struct WisdomList {
    std::list<Wisdom> items;
};

// Загружает список мудростей из текстового файла. Возвращает true при успехе.
bool LoadWisdomList(const std::string& filename, WisdomList& list, std::string& error_message);

// Выводит краткую информацию о контейнере в поток (например, std::cout).
void PrintSummary(const WisdomList& list, std::ostream& out);

// Выводит содержимое контейнера в поток (например, файл).
void PrintDetails(const WisdomList& list, std::ostream& out);

#endif // IZ1_PROCEDURAL_WISDOM_H
