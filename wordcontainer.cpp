#include "wordcontainer.h"

wordContainer::wordContainer(QObject *parent):QObject(parent)
{
    readFlag = wordContainer::NOT_READ;
}


void wordContainer::readin(QString _fileName)
{
    QFile fileObj;
    //fileObj.open(_fileName,QIODevice::ReadOnly);
    while(!fileObj.atEnd())
    {
        //fileObj.readLine()
    }
    readFlag = wordContainer::HAVE_READ;
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
