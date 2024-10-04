#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QWidget>

class TeacherWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = nullptr);

private slots:
    void viewProfile();
    void viewAssignedStudents();
};

#endif
