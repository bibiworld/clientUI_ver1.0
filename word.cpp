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

QString Word::getWord()
{
    return word;
}

QString Word::getSoundmark()
{
    return soundmark;
}

QString Word::getMeaning()
{
    return meaning;
}

QString Word::getExample()
{
    return example;
}
