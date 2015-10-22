#include "word.h"

Word::Word(QString _word, QString _soundmark, QString _meaning, QString _example)
{
    word = _word;
    soundmark = _soundmark;
    meaning = _meaning;
    example = _example;
}

Word::Word()
{
    word = "0";
}

QString Word::getWord() const
{
    return word;
}

QString Word::getSoundmark() const
{
    return soundmark;
}

QString Word::getMeaning() const
{
    return meaning;
}

QString Word::getExample() const
{
    return example;
}
