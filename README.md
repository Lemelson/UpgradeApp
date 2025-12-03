# ИЗ-1: «Кладезь мудрости» — Homework 07

Седьмая версия программы демонстрирует полную реализацию мультиметода с поддержкой всех комбинаций альтернатив (афоризм, пословица, загадка). Архитектура основана на паттерне «регистрация обработчиков», что позволяет расширять функциональность без изменения существующего кода.

## Структура каталога
```text
./
├── procedural/          # процедурная реализация
│   ├── wisdom.{h,cpp}   # базовая функциональность
│   ├── multimethod.{h,cpp}              # ядро мультиметода
│   ├── multimethod_handlers_basic.cpp   # обработчики афоризм/пословица
│   ├── multimethod_handlers_riddle.cpp  # обработчики с загадкой
│   └── main.cpp
├── oop/                 # объектно-ориентированная реализация
│   ├── wisdom_*.{h,cpp} # классы и фабрика
│   ├── aphorism.*, proverb.*, riddle.*  # альтернативы
│   ├── multimethod.{h,cpp}              # ядро мультиметода
│   ├── multimethod_handlers_basic.cpp   # обработчики афоризм/пословица
│   ├── multimethod_handlers_riddle.cpp  # обработчики с загадкой
│   └── main.cpp
├── tests/               # тестовые данные и эталоны
├── CHANGES.md           # история изменений с анализом
└── README.md
```

## Сборка и запуск

Команды выполняются в корне каталога.

```bash
# процедурная версия
c++ -std=c++17 procedural/main.cpp procedural/wisdom.cpp procedural/multimethod*.cpp \
    -o procedural/procedural_app
./procedural/procedural_app tests/input3.txt tests/output_proc.txt \
    tests/output_proc_aphorisms.txt tests/output_proc_pairs.txt

# объектно-ориентированная версия
c++ -std=c++17 oop/*.cpp -o oop/oop_app
./oop/oop_app tests/input3.txt tests/output_oop.txt \
    tests/output_oop_aphorisms.txt tests/output_oop_pairs.txt

# пример с загадкой
./procedural/procedural_app tests/input6.txt tests/output_proc_riddle.txt \
    tests/output_proc_riddle_aphorisms.txt tests/output_proc_riddle_pairs.txt
```

## Формат входного файла
```
<type> "<origin>" "<content>" "<keeper>"
```
- `type`: `aphorism`, `proverb` или `riddle`
- `origin`: автор (афоризм), страна (пословица) или ответ (загадка)
- `content`: текст мудрости
- `keeper`: хранитель (автор кладези или «народ»)

## Аргументы командной строки
1. Входной файл с данными
2. Файл полного вывода
3. Файл только с афоризмами
4. Файл результатов мультиметода

Отчёт о длинах содержимого выводится в стандартный поток.

## Архитектура мультиметода

### Паттерн «Регистрация обработчиков»
Вместо классической двойной диспетчеризации применён подход с регистрацией обработчиков:

```cpp
// Каждый обработчик — отдельная функция
bool AphorismThenProverb(const Wisdom& first, const Wisdom& second, std::string& phrase) {
    if (first.type == WisdomType::Aphorism && second.type == WisdomType::Proverb) {
        phrase = "Афоризм задаёт тон пословице.";
        return true;
    }
    return false;
}

// Регистрация при старте программы
RegisterPairHandler(&AphorismThenProverb);
```

### Преимущества подхода
1. **Расширяемость**: новые комбинации добавляются в отдельных файлах
2. **Модульность**: обработчики не зависят друг от друга
3. **Open/Closed**: существующий код не изменяется при добавлении новых типов

## Метрики
| Версия | Файлов | Строк кода |
| --- | --- | --- |
| Процедурная | 6 | ~400 |
| Объектно-ориентированная | 18 | ~700 |

## Тестовые данные
| Файл | Назначение |
| --- | --- |
| `input1.txt` – `input6.txt` | Тестовые сценарии |
| `output_*_pairs.txt` | Результаты мультиметода |
| `output_*_riddle_pairs.txt` | Комбинации с загадкой |
| `output_*_aphorisms.txt` | Выборочный вывод афоризмов |
