#ifndef QLINEEDIT
#define QLINEEDIT
#include <QLineEdit>
#include <QFont>

class myQLineEdit : public QLineEdit
{
public:
    myQLineEdit(QWidget *parent);
private:
    void focusInEvent(QFocusEvent*);
};

#endif // QLINEEDIT

