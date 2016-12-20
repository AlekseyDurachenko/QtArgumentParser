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
#include "test_qtargumentparserresultrecord.h"
#include "qtargumentparserresultrecord.h"


Test_QtArgumentParserResultRecord::Test_QtArgumentParserResultRecord(QObject *parent)
    : QObject(parent)
{
}

void Test_QtArgumentParserResultRecord::test_defaultConstructor()
{
    QtArgumentParserResultRecord rec;
    QCOMPARE(rec.isValid(), false);
    QCOMPARE(rec.argument().key(), QString());
    QCOMPARE(rec.value(), QVariant());
}

void Test_QtArgumentParserResultRecord::test_constructor()
{
    QtArgumentParserArgument arg(QString("keyName"), QtArgumentParserArgument::Integer, true);
    QtArgumentParserResultRecord rec(arg, QVariant(10));
    QCOMPARE(rec.isValid(), true);
    QCOMPARE(rec.argument().key(), QString("keyName"));
    QCOMPARE(rec.value(), QVariant(10));
}

void Test_QtArgumentParserResultRecord::test_setGet()
{
    QtArgumentParserArgument arg(QString("keyName"), QtArgumentParserArgument::Integer, true);
    QtArgumentParserResultRecord rec;
    rec.setArgument(arg);
    rec.setValue(QVariant(10));
    QCOMPARE(rec.isValid(), true);
    QCOMPARE(rec.argument().key(), QString("keyName"));
    QCOMPARE(rec.value(), QVariant(10));
}

void Test_QtArgumentParserResultRecord::test_isValid()
{
    QtArgumentParserArgument arg(QString("keyName"), QtArgumentParserArgument::Integer, true);
    QtArgumentParserResultRecord rec;
    QCOMPARE(rec.isValid(), false);
    rec.setArgument(arg);
    QCOMPARE(rec.isValid(), true);
}
