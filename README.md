# ИЗ-1: «Кладезь мудрости» — Homework 06

Шестая версия добавляет мультиметод: программа перебирает все пары элементов контейнера и формирует отдельный отчёт. Обработчики пар регистрируются в новых единицах компиляции, поэтому расширение не требует переписывать существующие файлы.

## Структура каталога
```text
./
├── procedural/
├── oop/
├── tests/
└── README.md
```

## Сборка и запуск
Команды выполняются в корне каталога.

```bash
# процедурная версия
c++ -std=c++17 procedural/main.cpp procedural/wisdom.cpp procedural/multimethod*.cpp -o procedural/procedural_app
./procedural/procedural_app tests/input3.txt tests/output_proc.txt tests/output_proc_aphorisms.txt tests/output_proc_pairs.txt

# объектно-ориентированная версия
c++ -std=c++17 oop/*.cpp -o oop/oop_app
./oop/oop_app tests/input3.txt tests/output_oop.txt tests/output_oop_aphorisms.txt tests/output_oop_pairs.txt

# пример с загадкой (для мультиметода пока доступны только базовые комбинации)
./procedural/procedural_app tests/input6.txt tests/output_proc_riddle.txt tests/output_proc_riddle_aphorisms.txt tests/output_proc_riddle_pairs.txt
./oop/oop_app tests/input6.txt tests/output_oop_riddle.txt tests/output_oop_riddle_aphorisms.txt tests/output_oop_riddle_pairs.txt
```

## Формат входного файла
Строки соответствуют спецификации Homework04:
```
<type> "<origin>" "<content>" "<keeper>"
```

## Аргументы командной строки
Программа принимает четыре аргумента: входной файл, полный вывод, файл для афоризмов и файл для результатов мультиметода. Отчет о длинах по-прежнему выводится в стандартный поток.

## Метрики
| Версия | Файлов | Примерно строк кода |
| --- | --- | --- |
| Процедурная | 3 | 294 |
| Объектно-ориентированная | 15 | 572 |

## Тестовые данные
| Файл | Назначение |
| --- | --- |
| `input1.txt` … `input6.txt` | Набор сценариев, использовавшийся в предыдущих версиях. |
| `output_proc.txt`, `output_oop.txt` | Полные результаты обработки. |
| `output_proc_aphorisms.txt`, `output_oop_aphorisms.txt` | Выборочный вывод только с афоризмами. |
| `output_proc_pairs.txt`, `output_oop_pairs.txt` | Вывод мультиметода на примере `input3.txt`. |
| `output_proc_riddle_aphorisms.txt`, `output_oop_riddle_aphorisms.txt` | Демонстрация фильтрации на наборе с загадкой. |
| `output_proc_riddle_pairs.txt`, `output_oop_riddle_pairs.txt` | Поведение мультиметода на наборе с загадкой (комбинации с загадками пока не поддерживаются). |

Эти файлы подтверждают корректность нового функционала и сохраняют совместимость с прежними проверками.
