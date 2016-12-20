// Copyright (C) 2016, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
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
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
#include "test_qtargumentparserargument.h"
#include "qtargumentparserargument.h"


Test_QtArgumentParserArgument::Test_QtArgumentParserArgument(QObject *parent)
    : QObject(parent)
{
}

void Test_QtArgumentParserArgument::test_defaultConstructor()
{
    QtArgumentParserArgument arg;
    QCOMPARE(arg.isValid(), false);
    QCOMPARE(arg.key(), QString());
    QCOMPARE(arg.keyType(), QtArgumentParserArgument::Flag);
    QCOMPARE(arg.required(), false);
}

void Test_QtArgumentParserArgument::test_constructor()
{
    QtArgumentParserArgument arg(QString("keyName"), QtArgumentParserArgument::String, true);
    QCOMPARE(arg.isValid(), true);
    QCOMPARE(arg.key(), QString("keyName"));
    QCOMPARE(arg.keyType(), QtArgumentParserArgument::String);
    QCOMPARE(arg.required(), true);
}

void Test_QtArgumentParserArgument::test_setGet()
{
    QtArgumentParserArgument arg;
    arg.setKey(QString("keyName"));
    arg.setKeyType(QtArgumentParserArgument::String);
    arg.setRequired(true);
    QCOMPARE(arg.isValid(), true);
    QCOMPARE(arg.key(), QString("keyName"));
    QCOMPARE(arg.keyType(), QtArgumentParserArgument::String);
    QCOMPARE(arg.required(), true);
}

void Test_QtArgumentParserArgument::test_isValid()
{
    QtArgumentParserArgument arg;
    QCOMPARE(arg.isValid(), false);
    arg.setKey(QString("keyName"));
    QCOMPARE(arg.isValid(), true);
}
