#ifndef QLINEEDIT
#define QLINEEDIT
#include <QLineEdit>

class myQLineEdit : public QLineEdit
{
public:
    myQLineEdit(QWidget *parent);
private:
    void focusInEvent(QFocusEvent*);
};

#endif // QLINEEDIT

