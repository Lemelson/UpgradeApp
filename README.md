# ИЗ-1: «Кладезь мудрости» — Homework 03

Третья версия дополняет проект обработкой, которая рассчитывает длину содержания каждой записи. Основной вывод не изменился: дополнительные сведения печатаются в стандартный поток, при необходимости его можно перенаправить в файл.

## Структура каталога
```text
Homework03/
├── procedural/
├── oop/
├── tests/
└── README.md
```

## Сборка и запуск
Команды следует выполнять из каталога `Homework03/`.

```bash
# процедурная версия
c++ -std=c++17 procedural/main.cpp procedural/wisdom.cpp -o procedural/procedural_app
./procedural/procedural_app tests/input3.txt tests/output_proc.txt

# объектно-ориентированная версия
c++ -std=c++17 oop/*.cpp -o oop/oop_app
./oop/oop_app tests/input3.txt tests/output_oop.txt

# пример с перенаправлением отчета
./procedural/procedural_app tests/input6.txt tests/output_proc_riddle.txt > tests/console_proc_lengths.txt
./oop/oop_app tests/input6.txt tests/output_oop_riddle.txt > tests/console_oop_lengths.txt
```

## Формат входного файла
Структура строки совпадает с Homework02:
```
<type> "<origin>" "<content>"
```
Типы `aphorism`, `proverb`, `riddle` поддерживаются без изменений.

## Аргументы командной строки
По-прежнему используются два аргумента: входной файл и файл с полным выводом. Отчет о длинах выводится в стандартный поток.

## Метрики
| Версия | Файлов | Примерно строк кода |
| --- | --- | --- |
| Процедурная | 3 | 263 |
| Объектно-ориентированная | 15 | 523 |

## Тестовые данные
- `input1.txt` … `input5.txt` — прежние сценарии на пустой файл, минимальные данные и ошибки формата.
- `input6.txt` — расширенный набор с загадкой, афоризмом и пословицей.
- `console_proc_lengths.txt`, `console_oop_lengths.txt` — сохраненные отчеты функции подсчета.

Эти файлы позволяют проверить как основную функциональность, так и новый обработчик.
