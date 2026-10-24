// write_file.cpp
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QList>
#include <QString>

#include "file_header.h"
  
int main(int argc, char *argv[])
{
  QFile file("temp.dat");
  file.open(QIODevice::WriteOnly);

  // treat the file as consuming a data stream
  QDataStream out(&file);

  // Write a header with a magic number and a version
  out << MAGIC;
  out << VERSION;

  // use a specific streaming format
  out.setVersion(QDataStream::Qt_5_0);
  
  // write some data
    QList<QString> messages;
    messages << "This is the first example string."
             << "This is the second string."
             << "This is the third string.";

    out << messages;

  
  // notify the user that we're finished
  qDebug() << "A data stream has been written to a file.";  
  
  return EXIT_SUCCESS;
}
