#include "loginwindow.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include "adminwindow.h"
#include "teacherwindow.h"
#include "studentwindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();
    this->resize(500, 300);
    usernameInput = new QLineEdit(this);
    passwordInput = new QLineEdit(this);
    passwordInput->setEchoMode(QLineEdit::Password);

    QPushButton *loginButton = new QPushButton("Login", this);
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::login);

    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);

    setLayout(layout);
}

void LoginWindow::login()
{
    QString username = usernameInput->text();
    QString password = passwordInput->text();

    if (username == "admin" && password == "admin") {
        AdminWindow *adminWindow = new AdminWindow();
        adminWindow->show();
        this->close();
    }
    else if (username == "teacher" && password == "teacher") {
        TeacherWindow *teacherWindow = new TeacherWindow();
        teacherWindow->show();
        this->close();
    }
    else if (username == "student" && password == "student") {
        StudentWindow *studentWindow = new StudentWindow();
        studentWindow->show();
        this->close();
    }
    else {
        QMessageBox::warning(this, "Login Failed", "Invalid credentials. Please try again.");
    }
}
