# Лабораторная работа 2
Постановка задачи: Реализовать программу, формирующую множество равное объединению произвольного количества исходных множеств (без учета повторных включений).

## Определения
Множество - простейшая информационная конструкция и математическая структура, позволяющая рассматривать какие-то объекты как целое, связывая их.

Объединение множеств - множество, содержащее все элементы всех объединяемых множеств.

## Алгоритм

Программа принимает в качестве первого аргумента путь к файлу (при отсутствии аргумента открывает test.txt в папке с приложением).

Каждая строка в файле есть запись множества.

Файл построчно считывается.

При считывании множеств в вектор они сортируются для дальнейшего сравнения и избежания повторов элементов.

Все считанные множества объединяются в одно и результат выводится на экран.

Программа завершает работу.

## Реализованные функции
<b> sortSet</b>
Рекурсивная функция, получает на вход строку-запись множества, сортирует элементы в нем.

<b>stringToSet</b>
Получает на вход строку, посимвольно обрабатывает ее и разбивает на множество строк (элементов), которые и формируют возвращаемое множество.

<b>readFromFile</b>
Считывает из файла вектор множеств. Использует предыдущую функцию для каждой ненулевой строки.

<b>uni_n</b>
Объединяет данный вектор множеств, возвращает множество-объединение

<b>showSet</b>
Выводит на экран данное множество

## Тесты
В файле test.txt даны множества:
![Снимок экрана (379)](https://user-images.githubusercontent.com/112986008/233844075-2fb97163-2593-4163-b3ec-38c93fe825bc.png)


Такой пример демонстрирует обработку подмножеств, повторяющихся элементов, пустых множеств.

## Выводы
Лабораторная работа позволила ознакомиться с структурой данных множество, работать с параметрами функции main.
