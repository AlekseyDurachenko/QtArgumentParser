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
