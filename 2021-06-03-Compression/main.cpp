#include <QCoreApplication>

#include <QBuffer>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>

bool makeFile(QString filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly))
    {
        QByteArray data;
        for (int i = 0; i < 1000; i++)
        {
            data.append(QString::number(i).toUtf8() + "\r\n");
        }

        file.write(data);
        file.close();

        return true;
    }
    return false;
}

QByteArray getHeader()
{
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFile, QString newFile)
{
    QFile ofile(originalFile);
    QFile nfile(newFile);
    int chunkSize = 1024;

    QByteArray header = getHeader();

    if (!ofile.open(QIODevice::ReadOnly))
        return false;

    if (!nfile.open(QIODevice::WriteOnly))
        return false;

    ofile.seek(0);

    while (!ofile.atEnd())
    {
        // file.read(len) will move the cursor, i.e., mutating cursor position state of ofile,
        // while file.peek(len) do the same thing, but does not mutate the cursor position state
        nfile.write(header);

        QByteArray buffer = ofile.read(chunkSize);
        QByteArray compressed = qCompress(buffer, 1);

        nfile.write(compressed);
    }

    ofile.close();
    nfile.close();

    qInfo() << "Finished Compression";

    return true;
}

bool decompressFile(QString originalFile, QString newFile)
{
    QFile ofile(originalFile);
    QFile nfile(newFile);
    int chunkSize = 1024;

    QByteArray header = getHeader();

    if (!ofile.open(QIODevice::ReadOnly))
        return false;

    if (!nfile.open(QIODevice::WriteOnly))
        return false;

    QByteArray buffer = ofile.peek(chunkSize);
    if (!buffer.startsWith(header))
    {
        qCritical() << "We did not create this file!";
        ofile.close();
        nfile.close();
        return false;
    }

    ofile.seek(header.length());
    // now we start with the compressed content

    while (!ofile.atEnd())
    {
        // again, not moving the cursor yet
        buffer = ofile.peek(chunkSize);
        qint64 index = buffer.indexOf(header);
        qDebug() << "header found at" << index;

        if (index > -1)
        {
            qint64 maxbytes = index;
            qInfo() << "reading: " << maxbytes;
            // read from current position to just before the position of header
            buffer = ofile.read(maxbytes);
            // choice 1:
            ofile.seek(ofile.pos() + header.length());
            // choice 2:
            // file.read(header.length());
        }
        else
        {
            qInfo() << "read all, no header";
            buffer = ofile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        nfile.write(decompressed);
        nfile.flush();
    }

    ofile.close();
    nfile.close();

    return true;
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    QString originalFile = "original.txt";
    QString compressedFile = "compressed.txt";
    QString decompressedFile = "decompressed.txt";

    if (makeFile(originalFile))
    {
        qInfo() << "original file created";

        if (compressFile(originalFile, compressedFile))
        {
            qInfo() << "file compressed";
            if (decompressFile(compressedFile, decompressedFile))
            {
                qInfo() << "file decompressed";
            }
            else
            {
                qInfo() << "could not decompress file";
            }
        }
        else
        {
            qInfo() << "file not compressed";
        }
    }

    return a.exec();
}
