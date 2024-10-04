#include "teacherwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QListWidget>

TeacherWindow::TeacherWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->resize(500, 300);

    QPushButton *viewProfileBtn = new QPushButton("View Profile", this);
    QPushButton *viewStudentsBtn = new QPushButton("View Assigned Students", this);

    layout->addWidget(viewProfileBtn);
    layout->addWidget(viewStudentsBtn);

    connect(viewProfileBtn, &QPushButton::clicked, this, &TeacherWindow::viewProfile);
    connect(viewStudentsBtn, &QPushButton::clicked, this, &TeacherWindow::viewAssignedStudents);

    setLayout(layout);
}

void TeacherWindow::viewProfile()
{

    QString firstName = "Karim";
    QString lastName = "Karim";
    QString teacherId = "T123";
    QString email = "KarimKarim@gamal.com";
    QString gender = "Male";
    QString academicBackground = "PhD in Mathematics";
    QString address = "123 Haram";

    QString profileInfo = "First Name: " + firstName + "\n"
                                                       "Last Name: " + lastName + "\n"
                                       "Teacher ID: " + teacherId + "\n"
                                        "Email: " + email + "\n"
                                    "Gender: " + gender + "\n"
                                     "Academic Background: " + academicBackground + "\n"
                                                 "Address: " + address;

    QMessageBox::information(this, "Teacher Profile", profileInfo);
}

void TeacherWindow::viewAssignedStudents()
{
    QStringList students;
    students << "Ahmed (Student ID: 1)" << "Kalbaz (Student ID: 2)"
             << "Karim (Student ID: 11)";

    QListWidget *studentListWidget = new QListWidget(this);
    studentListWidget->addItems(students);

    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Assigned Students");
    msgBox->setText("List of students assigned to you:");
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    msgBox->setDefaultButton(QMessageBox::Ok);

    QString detailedText;
    for (int i = 0; i < studentListWidget->count(); ++i) {
        detailedText += studentListWidget->item(i)->text() + "\n";
    }

    msgBox->setDetailedText(detailedText);
    msgBox->exec();
}

