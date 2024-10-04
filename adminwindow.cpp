#include "adminwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QStringList>
#include <QApplication>

AdminWindow::AdminWindow(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->resize(500, 300);

    QPushButton *addStudentBtn = new QPushButton("Add New Student", this);
    QPushButton *addTeacherBtn = new QPushButton("Add New Teacher", this);
    QPushButton *addSubjectBtn = new QPushButton("Add New Subject", this);
    QPushButton *removePersonBtn = new QPushButton("Remove Student/Teacher", this);
    QPushButton *modifyPersonBtn = new QPushButton("Modify Student/Teacher", this);

    layout->addWidget(addStudentBtn);
    layout->addWidget(addTeacherBtn);
    layout->addWidget(addSubjectBtn);
    layout->addWidget(removePersonBtn);
    layout->addWidget(modifyPersonBtn);

    connect(addStudentBtn, &QPushButton::clicked, this, &AdminWindow::addStudent);
    connect(addTeacherBtn, &QPushButton::clicked, this, &AdminWindow::addTeacher);
    connect(addSubjectBtn, &QPushButton::clicked, this, &AdminWindow::addSubject);
    connect(removePersonBtn, &QPushButton::clicked, this, &AdminWindow::removePerson);
    connect(modifyPersonBtn, &QPushButton::clicked, this, &AdminWindow::modifyPerson);

    setLayout(layout);
}

void AdminWindow::addStudent()
{
    QString firstName = QInputDialog::getText(this, "Add Student", "Enter student's first name:");
    if (firstName.isEmpty()) return;

    QString lastName = QInputDialog::getText(this, "Add Student", "Enter student's last name:");
    if (lastName.isEmpty()) return;

    QString email = QInputDialog::getText(this, "Add Student", "Enter student's email:");
    if (email.isEmpty()) return;

    QString age = QInputDialog::getText(this, "Add Student", "Enter student's age:");
    if (age.isEmpty()) return;

    if (!firstName.isEmpty() && !lastName.isEmpty() && !email.isEmpty() && !age.isEmpty()) {
        QMessageBox::information(this, "Student Added", "Student " + firstName + " " + lastName + " has been added successfully.");
    } else {
        QMessageBox::warning(this, "Input Error", "All fields are required to add a new student.");
    }
}

void AdminWindow::addTeacher()
{
    QString firstName = QInputDialog::getText(this, "Add Teacher", "Enter teacher's first name:");
    if (firstName.isEmpty()) return;

    QString lastName = QInputDialog::getText(this, "Add Teacher", "Enter teacher's last name:");
    if (lastName.isEmpty()) return;

    QString email = QInputDialog::getText(this, "Add Teacher", "Enter teacher's email:");
    if (email.isEmpty()) return;

    QString academicBackground = QInputDialog::getText(this, "Add Teacher", "Enter teacher's academic background:");
    if (academicBackground.isEmpty()) return;

    if (!firstName.isEmpty() && !lastName.isEmpty() && !email.isEmpty() && !academicBackground.isEmpty()) {
        QMessageBox::information(this, "Teacher Added", "Teacher " + firstName + " " + lastName + " has been added successfully.");
    } else {
        QMessageBox::warning(this, "Input Error", "All fields are required to add a new teacher.");
    }
}

void AdminWindow::addSubject()
{
    QString subject = QInputDialog::getText(this, "Add Subject", "Enter the name of the subject:");
    if (subject.isEmpty()) return;

    if (!subject.isEmpty()) {
        QMessageBox::information(this, "Subject Added", "Subject " + subject + " has been added successfully.");
    } else {
        QMessageBox::warning(this, "Input Error", "Subject name is required.");
    }
}

void AdminWindow::removePerson()
{
    QStringList personType;
    personType << "Student" << "Teacher";
    QString selected = QInputDialog::getItem(this, "Remove Person", "Select Student or Teacher to remove:", personType);
    if (selected.isEmpty()) return;

    if (selected == "Student") {
        QString studentId = QInputDialog::getText(this, "Remove Student", "Enter the student ID:");
        if (studentId.isEmpty()) return;

        if (!studentId.isEmpty()) {
            QMessageBox::information(this, "Student Removed", "Student with ID " + studentId + " has been removed.");
        } else {
            QMessageBox::warning(this, "Input Error", "Student ID is required to remove a student.");
        }
    } else if (selected == "Teacher") {
        QString teacherId = QInputDialog::getText(this, "Remove Teacher", "Enter the teacher ID:");
        if (teacherId.isEmpty()) return;

        if (!teacherId.isEmpty()) {
            QMessageBox::information(this, "Teacher Removed", "Teacher with ID " + teacherId + " has been removed.");
        } else {
            QMessageBox::warning(this, "Input Error", "Teacher ID is required to remove a teacher.");
        }
    }
}

void AdminWindow::modifyPerson()
{
    QStringList personType;
    personType << "Student" << "Teacher";
    QString selected = QInputDialog::getItem(this, "Modify Person", "Select Student or Teacher to modify:", personType);
    if (selected.isEmpty()) return;

    if (selected == "Student") {
        QString studentId = QInputDialog::getText(this, "Modify Student", "Enter the student ID to modify:");
        if (studentId.isEmpty()) return;

        QString newFirstName = QInputDialog::getText(this, "Modify Student", "Enter new first name:");
        if (newFirstName.isEmpty()) return;

        QString newLastName = QInputDialog::getText(this, "Modify Student", "Enter new last name:");
        if (newLastName.isEmpty()) return;

        if (!newFirstName.isEmpty() && !newLastName.isEmpty()) {
            QMessageBox::information(this, "Student Modified", "Student with ID " + studentId + " has been updated.");
        } else {
            QMessageBox::warning(this, "Input Error", "First and last name are required to modify a student.");
        }
    } else if (selected == "Teacher") {
        QString teacherId = QInputDialog::getText(this, "Modify Teacher", "Enter the teacher ID to modify:");
        if (teacherId.isEmpty()) return;

        QString newFirstName = QInputDialog::getText(this, "Modify Teacher", "Enter new first name:");
        if (newFirstName.isEmpty()) return;

        QString newLastName = QInputDialog::getText(this, "Modify Teacher", "Enter new last name:");
        if (newLastName.isEmpty()) return;

        if (!newFirstName.isEmpty() && !newLastName.isEmpty()) {
            QMessageBox::information(this, "Teacher Modified", "Teacher with ID " + teacherId + " has been updated.");
        } else {
            QMessageBox::warning(this, "Input Error", "First and last name are required to modify a teacher.");
        }
    }
}
