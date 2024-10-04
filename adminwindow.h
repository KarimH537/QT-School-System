#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);

private slots:
    void addStudent();
    void addTeacher();
    void addSubject();
    void removePerson();
    void modifyPerson();

};

#endif
