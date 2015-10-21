#include "wordcontainer.h"
#include <QTextStream>

wordContainer::wordContainer(QObject *parent):QObject(parent)
{
    readFlag = wordContainer::NOT_READ;
}


void wordContainer::readin(QString _fileName)
{
    QFile fileObj( _fileName );
    wordList.clear();
    if ( fileObj.open( QIODevice::ReadOnly ) ) 
    {
        QTextStream stream( &fileObj );
        QString line;
        while ( !stream.atEnd() ) 
        {
            line = stream.readLine(); // 不包括“\n”的一行文本
            wordList.push_back(Word(line.split("|")[0],"",line.split("|")[1],""));
        }
        fileObj.close();
    }    
    readFlag = wordContainer::HAVE_READ;
    emit updateWordSignal();
}

void wordContainer::readin()
{
    readin("wordList.txt");
}

int wordContainer::checkRead()
{
    return readFlag;
}

QVector<Word> wordContainer::getWords()
{
    return wordList;
}

void wordContainer::addWord(Word _word)
{
    wordList.push_back(_word);
}

void wordContainer::deleteWord(int index)
{
    wordList.remove(index);
}

void wordContainer::recvMessage(QVector<Word>)
{
    //to be added
}
