Гайд как запустить лабу на винде 10 и докере:
1. Создайте Dockerfile в директории D:/BSUIR/OS/lab2 с помощью текстового редактора или IDE. В Dockerfile необходимо указать базовый образ, который будет использоваться для запуска приложения, а также команды для установки необходимых зависимостей и запуска приложения. Например:


FROM gcc:latest
COPY . /app
WORKDIR /app
RUN gcc -o main main.c
CMD ["./main"]


2. Откройте терминал и перейдите в директорию D:/BSUIR/OS/lab2.

3. Запустите команду docker build для создания образа на основе Dockerfile:


docker build -t my-app .


где my-app - название образа.

4. После успешного создания образа можно запустить контейнер с помощью команды docker run:


docker run -it my-app


5. В контейнере откройте терминал и перейдите в директорию /app:


cd /app


6. Запустите приложение командой:


./main

Если вы получили сообщение об ошибке "the input device is not a TTY", то попробуйте запустить команду с префиксом 'winpty', например:


winpty docker run -it my-app
 

Это связано с тем, что команды в контейнере могут требовать TTY, а при использовании некоторых терминалов (например, mintty) это может вызвать проблемы. Префикс 'winpty' позволяет обойти эту проблему.


Теперь вы можете запустить файл main.c в Docker-контейнере.
