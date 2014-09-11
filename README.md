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
    parser.add("-i", QtArgumentParser::String);
    parser.add("-o", QtArgumentParser::String);
    parser.add("-n", QtArgumentParser::Integer);
    parser.add("-d", QtArgumentParser::Double);
    parser.add("-f", QtArgumentParser::Flag);
    parser.add("-x", QtArgumentParser::Variant,
            QStringList() << "Variant" << "SomeCode" << "Unknow" << "None");

    if (!parser.parse())
    {
        std::cout << "can not parse the arguments" << std::endl;
        std::cout << parser.errorString().toStdString() << std::endl;
        return -1;
    }

    QVariantMap map = parser.result();
    if (!map.contains("-i") || !map.contains("-o"))
    {
        std::cout << "arguments \"-i\" and \"-o\" are required" << std::endl;
        return -1;
    }

    std::cout << "The arguments:" << std::endl;
    foreach (const QString &key, map.keys())
    {
        switch (map.value(key).type())
        {
        case QVariant::String:
            std::cout << "  " << key.toStdString()
                      << " = "<< map.value(key).toString().toStdString()
                      << std::endl;
            break;
        case QVariant::Int:
        case QVariant::LongLong:
            std::cout << "  " << key.toStdString()
                      << " = "<< map.value(key).toLongLong()
                      << std::endl;
            break;
        case QVariant::Double:
            std::cout << "  " << key.toStdString()
                      << " = "<< map.value(key).toDouble()
                      << std::endl;
            break;
        case QVariant::Bool:
            std::cout << "  " << key.toStdString()
                      << " = "<< ((map.value(key).toBool())?("true"):("false"))
                      << std::endl;
            break;
        default: ;
        }
    }

    std::cout << "The unused values:" << std::endl;
    foreach (const QString &value, parser.unused())
        std::cout << "  * " << value.toStdString() << std::endl;

    return 0;
}
```

Usage:
```bash
you_app -i input_file.ext -o output_file.ext -n 10 -d 6.66 -f -x None unused_file_1 unused_file_2
```

License
-------

<a href="LICENSE">LGPLv2.1+</a>.
