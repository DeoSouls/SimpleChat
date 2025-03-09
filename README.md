# SimpleChat - Клиент-серверное приложение на Qt Widgets

## Описание проекта

SimpleChat - это клиент-серверное приложение для обмена сообщениями, разработанное на базе Qt Widgets. Приложение позволяет пользователям регистрироваться, авторизовываться, создавать чаты с другими пользователями и обмениваться текстовыми сообщениями и изображениями в реальном времени.

## Основные возможности

- **Регистрация и авторизация пользователей**
- **Создание и управление чатами**
- **Обмен текстовыми сообщениями**
- **Отправка и просмотр изображений**
- **Поиск сообщений в чате**
- **Отображение статуса пользователей (онлайн/оффлайн)**
- **Индикация непрочитанных сообщений**

## Технологии

- **Фреймворк**: Qt Widgets
- **Язык программирования**: C++
- **Сетевой протокол**: WebSocket (QWebSocket)
- **База данных**: PostgreSQL
- **Формат обмена данными**: JSON

# Архитектура приложения

## Серверная часть

- **ChatServer** - основной класс сервера, обрабатывающий подключения и сообщения
- Обработка регистрации и авторизации пользователей
- Управление чатами и сообщениями
- Хранение данных в PostgreSQL

## Клиентская часть

- **MainWindow** - главное окно приложения
- **LoginForm** - форма авторизации и регистрации
- **ChatForm** - основной интерфейс чата
- **SwitchChatContainer** - контейнер для переключения между чатами
- **ChatContent** - компонент отображения содержимого чата
- **MessageItemDelegate** - делегат для отображения сообщений

## Скриншоты

<img src="https://github.com/user-attachments/assets/93054047-6c0e-4387-b8b5-a973db969408" width="33%" />
<img src="https://github.com/user-attachments/assets/1fcb284d-9d67-43bd-b848-ca27058b66a0" width="33%" />
<img src="https://github.com/user-attachments/assets/0ea12b97-030d-43e7-855e-4e768ed0a0d9" width="33%" />
<img src="https://github.com/user-attachments/assets/77d33660-21aa-455d-9910-f705ddda0c57" width="33%" />
<img src="https://github.com/user-attachments/assets/9f821cd5-cb31-4eeb-bd0b-fe962d34d619" width="33%" />

# Установка и запуск

## Требования

- Qt 5.15 или выше
- PostgreSQL 12 или выше
- Компилятор с поддержкой C++17

## Настройка базы данных

1. Создайте базу данных PostgreSQL с именем `SimpleChat`
2. Используйте следующие параметры подключения (или измените их в файле `chatserver.cpp`):
    - Хост: localhost
    - Порт: 5432
    - Имя пользователя: postgres
    - Пароль: --------

# Сборка и запуск

 Клонируйте репозиторий
``` bash
git clone https://github.com/username/SimpleChat.git
```

2. Откройте проект в Qt Creator или соберите из командной строки
``` bash
cd SimpleChat
qmake
make
```

3. Запустите приложение
``` bash
./SimpleChat
```

## Структура проекта

``` text
SimpleChat/
├── main.cpp                  # Точка входа в приложение
├── chatserver.cpp/h          # Реализация сервера
├── MainWindow/
│   ├── mainwindow.cpp/h      # Главное окно приложения
├── LoginForm/
│   ├── loginform.cpp/h       # Форма авторизации
├── ChatForm/
│   ├── chatform.cpp/h        # Основной интерфейс чата
│   ├── SwitchChatContainer/  # Контейнер для переключения чатов
│   ├── UserChoiceContainer/  # Выбор пользователей для чата
├── ChatContent/
│   ├── chatcontent.cpp/h     # Содержимое чата
│   ├── messageitemdelegate.cpp/h # Делегат для отображения сообщений
└── resources/                # Ресурсы приложения (иконки, изображения)
```

## Особенности реализации

**WebSocket** для обмена сообщениями в реальном времени
- **Хеширование паролей** с использованием SHA-256
- **Пагинация** для загрузки истории сообщений
- **Поддержка изображений** с предварительным просмотром
- **Адаптивный интерфейс** с использованием QStackedWidget

## Планы по развитию

- Добавление групповых чатов
- Поддержка аудио и видео сообщений
- Редактирование и шифрование сообщений

## Лицензия

Проект распространяется под лицензией MIT [LICENCE](https://github.com/DeoSouls/SimpleChat/blob/main/LICENSE).
