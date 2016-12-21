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
#include "test_qtargumentparser.h"
#include "qtargumentparser.h"


Test_QtArgumentParser::Test_QtArgumentParser(QObject *parent)
    : QObject(parent)
{
}

void Test_QtArgumentParser::test_defaultConstructor()
{
    QtArgumentParser parser;
    QCOMPARE(parser.unusedAllowed(), false);
}

void Test_QtArgumentParser::test_setGet()
{
    QtArgumentParser parser;
    parser.setUnusedAllowed(true);
    parser.insertArgument(QtArgumentParserArgument());
    parser.insertArguments(QList<QtArgumentParserArgument>() << QtArgumentParserArgument());
    QCOMPARE(parser.unusedAllowed(), true);
    QCOMPARE(parser.arguments().count(), 2);
}

void Test_QtArgumentParser::test_parse()
{
    QtArgumentParserArgument argFlag;
    argFlag.setKey("-b");
    argFlag.setKeyType(QtArgumentParserArgument::Flag);

    QtArgumentParserArgument argString;
    argString.setKey("-s");
    argString.setKeyType(QtArgumentParserArgument::String);

    QtArgumentParserArgument argInteger;
    argInteger.setKey("-i");
    argInteger.setKeyType(QtArgumentParserArgument::Integer);

    QtArgumentParserArgument argDouble;
    argDouble.setKey("-d");
    argDouble.setKeyType(QtArgumentParserArgument::Double);

    QtArgumentParserResult parseErrorResult;
    parseErrorResult.setError(QtArgumentParserError::ParseError);

    struct TestSetItem {
        QStringList cmdline;
        bool unusedAllowed;
        QList<QtArgumentParserArgument> arguments;
        QtArgumentParserResult result;
    } TestSet[] = {{
            QString("cmd -b -s string -i integer -d double -x").split(" "),
            false,
            {argFlag, argString, argInteger, argDouble},
            parseErrorResult
        }
    };

    for (unsigned int i = 0; i < sizeof(TestSet) / sizeof(TestSetItem); ++i) {
        QtArgumentParser parser;
        parser.setUnusedAllowed(TestSet[i].unusedAllowed);
        parser.insertArguments(TestSet[i].arguments);
        QtArgumentParserResult result = parser.parse(TestSet[i].cmdline);
        if (result.error() == QtArgumentParserError::NoError) {
            QCOMPARE(result.records().count(), TestSet[i].result.records().count());
            QCOMPARE(result.unused().count(), TestSet[i].result.unused().count());
            for (int i = 0; i < result.records().count(); ++i) {
                QCOMPARE(result.records().at(i).argument().key(), TestSet[i].result.records().at(i).argument().key());
            }
            for (int i = 0; i < result.unused().count(); ++i) {
                QCOMPARE(result.unused().at(i), TestSet[i].result.unused().at(i));
            }
        }
        else {
            QCOMPARE(result.error(), TestSet[i].result.error());
        }
    }
}
