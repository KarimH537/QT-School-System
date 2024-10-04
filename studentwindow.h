#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include <QWidget>

class StudentWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWindow(QWidget *parent = nullptr);

private slots:
    void viewProfile();
    void registerCourse();

private:
    QString course;
};

#endif
