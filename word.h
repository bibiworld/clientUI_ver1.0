#ifndef WORD
#define WORD
#include <QString>
#include <QStringList>
class Recv;
class Word
{
public:
    Word(QString _word,QString _soundmark,QString _meaning,QString _example);
    Word();
    QString getWord();
    QString getSoundmark();
    QString getMeaning();
    QString getExample();
private:
    QString word;
    QString soundmark;
    QString meaning;  
    QString example;
};

#endif // WORD

