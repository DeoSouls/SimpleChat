#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QVBoxLayout>
#include "LoginButton.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>

class LoginForm : public QWidget {
        Q_OBJECT
    public:
        explicit LoginForm(QWidget* parent = nullptr);
        QList<QWidget*> temporaryWidgets;
        LoginButton* btn2ToChat;
        LoginButton* btnToChat;

        void removeLogupForm();

        ~LoginForm();
    public slots:
        void addLogupForm();
    private slots:
        void login();
        void connectToBaseData();
    private:
        QVBoxLayout* layoutLogin;
        QVBoxLayout* containedLayout;
};

#endif // LOGINFORM_H