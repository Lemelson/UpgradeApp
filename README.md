# ИЗ-1: «Кладезь мудрости» — Homework 05

Пятая версия добавляет выборочный вывод: помимо основного файла формируется отдельный файл только с афоризмами. Это позволяет анализировать первую специализацию варианта без ручной фильтрации.

## Структура каталога
```text
Homework05/
├── procedural/
├── oop/
├── tests/
└── README.md
```

## Сборка и запуск
Команды выполняются в каталоге `Homework05/`.

```bash
# процедурная версия
c++ -std=c++17 procedural/main.cpp procedural/wisdom.cpp -o procedural/procedural_app
./procedural/procedural_app tests/input3.txt tests/output_proc.txt tests/output_proc_aphorisms.txt

# объектно-ориентированная версия
c++ -std=c++17 oop/*.cpp -o oop/oop_app
./oop/oop_app tests/input3.txt tests/output_oop.txt tests/output_oop_aphorisms.txt

# пример с загадкой
./procedural/procedural_app tests/input6.txt tests/output_proc_riddle.txt tests/output_proc_riddle_aphorisms.txt
./oop/oop_app tests/input6.txt tests/output_oop_riddle.txt tests/output_oop_riddle_aphorisms.txt
```

## Формат входного файла
Строки соответствуют спецификации Homework04:
```
<type> "<origin>" "<content>" "<keeper>"
```

## Аргументы командной строки
Программа принимает три аргумента: входной файл, полный вывод и файл для афоризмов. Отчет о длинах по-прежнему выводится в стандартный поток.

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
| `output_proc_riddle_aphorisms.txt`, `output_oop_riddle_aphorisms.txt` | Демонстрация фильтрации на наборе с загадкой. |

Эти файлы подтверждают корректность нового функционала и сохраняют совместимость с прежними проверками.
