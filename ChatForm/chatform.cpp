#include "chatform.h"
#include "SwitchChatContainer/switchchatcontainer.h"
#include <QPropertyAnimation>
#include <QHBoxLayout>

ChatForm::ChatForm(int userId, QString userFirstname, QString userLastname, QWebSocket* m_client, QWidget *parent)
    : userId(userId), userFirstname(userFirstname), userLastname(userLastname), m_socket(m_client), QWidget{parent} {

    // Горизонтальное выравнивание формы чата
    layoutChat = new QHBoxLayout(this);
    layoutChat->setContentsMargins(0,0,0,0);
    layoutChat->setSpacing(0);

    // Контейнер с чатами пользователя
    sContainer = new SwitchChatContainer(userId, userFirstname, userLastname, m_client);

    layoutChat->addWidget(sContainer);
    layoutChat->addWidget(sContainer->switchChats);

    // Выдвижное меню с настройками
    menu = new QFrame(this);
    menu->setStyleSheet("QFrame { background-color: #222; color: white; border-right: 1px solid #444;} "
                        "QPushButton { border: none; border-top: 1px solid #333; font-size: 14px }"
                        "QPushButton:hover { background-color: #444 }");
    menu->setFixedWidth(200);
    menu->setGeometry(-200, 0, 200, height());
    menu->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    // Содержимое меню
    QVBoxLayout* menuLayout = new QVBoxLayout(menu);
    startChatting = new QPushButton("Start Chatting");
    startChatting->setFixedSize(150, 35);

    menuLayout->addWidget(startChatting);
    exitFromChat = new QPushButton("Exit");
    exitFromChat->setFixedSize(150, 35);

    menuLayout->addWidget(exitFromChat);
    menuLayout->setAlignment(Qt::AlignCenter);
    menuLayout->setSpacing(30);

    // Анимация выдвижения
    animation = new QPropertyAnimation(menu, "geometry", this);
    animation->setDuration(200);

    connect(sContainer->toggleButton, SIGNAL(clicked()), SLOT(toggleMenu()));

    layoutChat->setStretch(0,1);
    layoutChat->setStretch(1,3);

    setLayout(layoutChat);
}

// Метод реализует переключение видимости меню через анимацию
void ChatForm::toggleMenu() {
    if (animation->state() == QAbstractAnimation::Running) {
        return;
    }

    QRect startGeometry = menu->geometry();
    QRect endGeometry;

    if (menu->geometry().x() < 0) {
        endGeometry = QRect(0, 0, menu->width(), height());
    } else {
        endGeometry = QRect(-menu->width(), 0, menu->width(), height());
    }

    animation->setStartValue(startGeometry);
    animation->setEndValue(endGeometry);
    animation->start();
}

// Метод переопределяет обработчик события изменения размера,
// чтобы боковое меню всегда сохраняло правильную высоту при изменении размера окна.
// Это необходимо, поскольку меню использует абсолютное позиционирование через setGeometry()
void ChatForm::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);

    menu->setGeometry(menu->x(), 0, menu->width(), height());
}
