# Документация программной системы

## Введение

Эта программная система представляет собой систему защиты диплома, включающую в себя различные классы для представления студентов, преподавателей, дипломов, презентаций и комиссий.

## Классы и методы

### Класс Human

Базовый класс для представления людей в системе.

#### Методы

- `__init__(self, name, age)`: Инициализация объекта класса Human.
- `get_name(self)`: Возвращает имя человека.
- `get_age(self)`: Возвращает возраст человека.

### Класс Teacher

Класс для представления преподавателей.

#### Методы

- `__init__(self, name, age, experience, degree)`: Инициализация объекта класса Teacher.
- `choose_question(self)`: Выбирает вопрос для студента.

### Класс Diploma

Класс для представления дипломов.

#### Методы

- `__init__(self, title, pages, sources)`: Инициализация объекта класса Diploma.
- `get_title(self)`: Возвращает название диплома.
- `get_pages(self)`: Возвращает количество страниц в дипломе.
- `get_count_sources(self)`: Возвращает количество источников в дипломе.
- `set_more_pages(self)`: Увеличивает количество страниц в дипломе.
- `set_more_sources(self)`: Увеличивает количество источников в дипломе.
- `get_checked(self)`: Возвращает статус проверки диплома.
- `set_checked_true(self)`: Устанавливает статус проверки диплома в "проверено".

### Класс Presentation

Класс для представления презентаций.

#### Методы

- `__init__(self, pres_title, author, content)`: Инициализация объекта класса Presentation.
- `get_pres_title(self)`: Возвращает название презентации.
- `get_author(self)`: Возвращает автора презентации.
- `get_content(self)`: Возвращает содержание презентации.
- `list_pages(self)`: Выводит сообщение "next page".

### Класс Student

Класс для представления студентов.

#### Методы

- `__init__(self, name, age, diploma)`: Инициализация объекта класса Student.
- `preparing_presentation_report(self)`: Подготовка отчета о презентации.
- `reviewing_correcting_report(self)`: Проверка и корректировка отчета.
- `conducting_defense_rehearsals(self, pres1)`: Проведение репетиций защиты.
- `answering(self, que1, que2, que3)`: Ответ на вопросы комиссии.

### Класс Supervisor

Класс для представления наставников.

#### Методы

- `__init__(self, name, age, experience, degree, students)`: Инициализация объекта класса Supervisor.
- `checking(self)`: Проверка дипломов студентов.
- `print_student_info(self)`: Вывод информации о студентах.

### Класс Comission

Класс для представления комиссий.

#### Методы

- `__init__(self, teacher1, teacher2, teacher3)`: Инициализация объекта класса Comission.
- `com_hello(self)`: Приветствие комиссии.
- `commission_asking(self)`: Задание вопросов комиссии студенту.
- `certification_grade(self, right_count)`: Оценка комиссии.

## Примеры использования

https://lucid.app/lucidchart/bd4cc242-d149-458c-8675-aa897fa257fc/edit?viewport_loc=-10%2C-226%2C1707%2C743%2C-csftKZJlNPR&invitationId=inv_47a73f9d-c881-4707-8f34-92ab4d2d760d

