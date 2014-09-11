// Copyright (C) 2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
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
