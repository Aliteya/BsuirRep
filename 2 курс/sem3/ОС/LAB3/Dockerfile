# Используйте официальный образ Ubuntu как базовый образ
FROM ubuntu:latest

# Обновите пакеты и установите необходимые зависимости
RUN apt-get update && apt-get install -y \
    g++ \
    build-essential \
    libpthread-stubs0-dev

# Копируйте исходный код программы в образ
COPY . /app

# Установите рабочую директорию
WORKDIR /app

# Скомпилируйте программу (здесь нужно указать имя вашего исполняемого файла)
RUN g++ -o main main.cpp -lpthread

# Запустите программу при запуске контейнера
CMD ["./main"]
