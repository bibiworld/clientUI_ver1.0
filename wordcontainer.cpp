#include "wordcontainer.h"
#include <QTextStream>
#include <QMessageBox>

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

QVector<Word> & wordContainer::getWords()
{
    return wordList;
}

void wordContainer::addWord(QWidget* parent,Word _word)//static
{
    QFile fileObj("wordBook.txt");
    if ( fileObj.open( QIODevice::WriteOnly | QIODevice::Append ) ) 
    {
        QTextStream stream( &fileObj );
        QString line = _word.getWord() + "|" + _word.getMeaning() + "\n";
        stream >> line;
        fileObj.close();
    }    
    else
    {
        QMessageBox::warning(parent,"添加到单词本失败","未能添加到本地的单词本文件wordBook.txt，请检查文件是否完好",QMessageBox::Ok);
        //QMessageBox::
    }
}

void wordContainer::recvMessage(QVector<Word>)
{
    //to be added
}
