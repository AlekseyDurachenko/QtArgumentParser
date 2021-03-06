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
#ifndef QTARGUMENTPARSERRESULTRECORD_H
#define QTARGUMENTPARSERRESULTRECORD_H


#include "qtargumentparserargument.h"


class QtArgumentParserResultRecord
{
public:
    QtArgumentParserResultRecord(const QtArgumentParserArgument &argument = QtArgumentParserArgument(),
                                 const QVariant &value = QVariant());

    inline bool isValid() const;

    inline const QtArgumentParserArgument &argument() const;
    void setArgument(const QtArgumentParserArgument &argument);

    inline const QVariant &value() const;
    void setValue(const QVariant &value);

private:
    QtArgumentParserArgument m_argument;
    QVariant m_value;
};

bool QtArgumentParserResultRecord::isValid() const
{
    return m_argument.isValid();
}

const QtArgumentParserArgument &QtArgumentParserResultRecord::argument() const
{
    return m_argument;
}

const QVariant &QtArgumentParserResultRecord::value() const
{
    return m_value;
}


#endif // QTARGUMENTPARSERRESULTRECORD_H
