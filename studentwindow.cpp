#include "studentwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>

StudentWindow::StudentWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->resize(500, 300);

    QPushButton *viewProfileBtn = new QPushButton("View Profile", this);
    QPushButton *registerCourseBtn = new QPushButton("Register for a Course", this);

    layout->addWidget(viewProfileBtn);
    layout->addWidget(registerCourseBtn);

    connect(viewProfileBtn, &QPushButton::clicked, this, &StudentWindow::viewProfile);
    connect(registerCourseBtn, &QPushButton::clicked, this, &StudentWindow::registerCourse);

    setLayout(layout);
}

void StudentWindow::viewProfile()
{
    QString firstName = "Ahmed";
    QString lastName = "Kalbaz";
    QString studentId = "1";
    QString email = "AhmedKalbaz@gamal.com";
    QString age = "20";
    QString gender = "Male";
    QString registeredCourse = "Mathematics";

    QString profileInfo = "First Name: " + firstName + "\n"
                                                       "Last Name: " + lastName + "\n"
                                       "Student ID: " + studentId + "\n"
                                        "Email: " + email + "\n"
                                    "Age: " + age + "\n"
                                  "Gender: " + gender + "\n"
                                     "Registered Course: " + registeredCourse;

    QMessageBox::information(this, "Student Profile", profileInfo);
}

void StudentWindow::registerCourse()
{
    QStringList courses;
    courses << "Mathematics" << "Physics" << "Chemistry" << "Biology" << "Computer Science";

    QString selectedCourse = QInputDialog::getItem(this, "Register for a Course", "Select a course:", courses);

    if (!selectedCourse.isEmpty()) {
        QMessageBox::information(this, "Course Registration", "You have been registered for " + selectedCourse + ".");
    } else {
        QMessageBox::warning(this, "Course Registration", "You must select a course to register.");
    }
}
