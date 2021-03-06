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
#include "test_qtargumentparserresult.h"
#include "qtargumentparserresult.h"


Test_QtArgumentParserResult::Test_QtArgumentParserResult(QObject *parent)
    : QObject(parent)
{
}

void Test_QtArgumentParserResult::test_defaultConstructor()
{
    QtArgumentParserResult result;
    QCOMPARE(result.error(), QtArgumentParserError::NoError);
    QCOMPARE(result.errorString(), QString());
    QCOMPARE(result.records().count(), 0);
    QCOMPARE(result.unused().count(), 0);
}

void Test_QtArgumentParserResult::test_setGet()
{
    QtArgumentParserResult result;
    result.setError(QtArgumentParserError::ParseError, QString("error test"));
    result.insertRecord(QtArgumentParserResultRecord());
    result.insertRecords(QList<QtArgumentParserResultRecord>() << QtArgumentParserResultRecord());
    result.insertUnused(QString());
    result.insertUnused(QStringList() << QString());
    QCOMPARE(result.error(), QtArgumentParserError::ParseError);
    QCOMPARE(result.errorString(), QString("error test"));
    QCOMPARE(result.records().count(), 2);
    QCOMPARE(result.unused().count(), 2);
}
