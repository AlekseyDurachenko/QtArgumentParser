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
#ifndef TEST_QTARGUMENTPARSERARGUMENT_H
#define TEST_QTARGUMENTPARSERARGUMENT_H


#include <QObject>
#include <QtTest/QtTest>


class Test_QtArgumentParserArgument : public QObject
{
    Q_OBJECT
public:
    explicit Test_QtArgumentParserArgument(QObject *parent = 0);

private slots:
    void test_defaultConstructor();
    void test_constructor();
    void test_setGet();
    void test_isValid();
};


#endif // TEST_QTARGUMENTPARSERARGUMENT_H
