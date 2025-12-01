# ИЗ-1: «Кладезь мудрости» — Homework 04

Четвертая версия добавляет для всех альтернатив общее поле «Кладезь», в котором хранится источник высказывания. Формат входного файла расширен до четырех кавычечных блоков, вывод также содержит новое поле.

## Структура каталога
```text
Homework04/
├── procedural/
├── oop/
├── tests/
└── README.md
```

## Сборка и запуск
Команды выполняются в каталоге `Homework04/`.

```bash
# процедурная версия
c++ -std=c++17 procedural/main.cpp procedural/wisdom.cpp -o procedural/procedural_app
./procedural/procedural_app tests/input3.txt tests/output_proc.txt

# объектно-ориентированная версия
c++ -std=c++17 oop/*.cpp -o oop/oop_app
./oop/oop_app tests/input3.txt tests/output_oop.txt

# пример с расширенным вводом
./procedural/procedural_app tests/input6.txt tests/output_proc_riddle.txt > tests/console_proc_lengths.txt
./oop/oop_app tests/input6.txt tests/output_oop_riddle.txt > tests/console_oop_lengths.txt
```

## Формат входного файла
```
<type> "<origin>" "<content>" "<keeper>"
```
Поле `keeper` содержит информацию о том, кем зафиксировано высказывание.

## Аргументы командной строки
Набор аргументов не изменился: входной файл и файл с полным выводом. Отчет о длинах остается в стандартном потоке.

## Метрики
| Версия | Файлов | Примерно строк кода |
| --- | --- | --- |
| Процедурная | 3 | 272 |
| Объектно-ориентированная | 15 | 555 |

## Тестовые данные
Все входные файлы обновлены и содержат поле `keeper`. Эталонные выводы (`output_*`) отражают новое поле. Остальные сценарии (пустой файл, ошибки формата и т.д.) продолжают использоваться без изменений.
