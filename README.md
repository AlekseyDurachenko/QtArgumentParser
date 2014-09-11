QtArgumentParser
================

About
-----

The QCoreApplication argument parser.

Website: https://github.com/AlekseyDurachenko/QtArgumentParser

Copyright (c) 2013-2014 Aleksey Durachenko (unless explicitly stated otherwise).

Usage
-----

Source code:
```cpp
#include <QtArgumentParser>
#include <QCoreApplication>
#include <iostream>

int main(int argc, char **argv)
{
    QCoreApplication args(argc, argv);

    QtArgumentParser parser(args.arguments());
    parser.insertKey("-i", QtArgumentParser::String);
    parser.insertKey("-o", QtArgumentParser::String);
    parser.insertKey("-n", QtArgumentParser::Integer);
    parser.insertKey("-d", QtArgumentParser::Double);
    parser.insertKey("-f", QtArgumentParser::Flag);
    parser.insertKey("-x", QtArgumentParser::Variant,
            QStringList() << "Variant" << "SomeCode" << "Unknow" << "None");

    bool ok;
    QVariantMap map = parser.parse(&ok);

    if (!ok)
    {
        std::cout << "can not parse the arguments" << std::endl;
        return -1;
    }

    if (!map.contains("-i") || !map.contains("-o") || !ok)
    {
        std::cout << "arguments \"-i\" and \"-o\" are required" << std::endl;
        return -1;
    }

    std::cout << "The arguments" << std::endl;
    std::cout << "  -i = " << map["-i"].toString().toStdString() << std::endl;
    std::cout << "  -o = " << map["-o"].toString().toStdString() << std::endl;
    std::cout << "  -n = " << map["-n"].toInt() << std::endl;
    std::cout << "  -d = " << map["-d"].toDouble() << std::endl;
    std::cout << "  -f = " << map["-f"].toBool() << std::endl;
    std::cout << "  -x = " << map["-x"].toString().toStdString() << std::endl;
    std::cout << "The unused" << std::endl;
    foreach (const QString &value, parser.unused())
        std::cout << "  * " << value.toStdString() << std::endl;

    return 0;
}

Usage:
```bash
you_app -i input_file.ext -o output_file.ext -n 10 -d 6.66 -f -x None unused_file_1 unused_file_2
```

License
-------

<a href="LICENSE">LGPLv2.1+</a>.
