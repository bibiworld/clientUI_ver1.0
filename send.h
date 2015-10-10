//class to send message to server
//according to protocol
#ifndef SEND
#define SEND
#include <QString>
#include <QTcpSocket>

class Send
{
public:
    static void B_search(QTcpSocket* socket,QString word);
    static void B_fuzzysearch(QTcpSocket* socket,QString word,int len = 0);
    static void B_similar(QTcpSocket* socket,QString word);
    static void B_quit(QTcpSocket* socket);
};

#endif // SEND

