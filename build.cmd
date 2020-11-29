@ECHO OFF

REM /utf-8 - UTF-8 в качестве исходной кодировки и кодировки выполнения
REM /Fe - имя выходного файла
REM /EHsc - Обработчик исключений (убирает предупреждение C4530)
cl /std:c++17 /utf-8 /EHsc /FeTripleX src/main.cpp

DEL main.obj