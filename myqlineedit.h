#ifndef QLINEEDIT
#define QLINEEDIT
#include <QObject>
#include <QFocusEvent>
#include <QKeyEvent>
#include <QLineEdit>
#include <QFont>

class myQLineEdit : public QLineEdit
{
public:
    myQLineEdit(QWidget *parent);
private:
    void focusInEvent(QFocusEvent*);
    //void keyPressEvent(QKeyEvent*);
    //void pressEnterSignal();
};

#endif // QLINEEDIT

