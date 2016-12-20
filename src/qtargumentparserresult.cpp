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
#include "qtargumentparserresult.h"


QtArgumentParserResult::QtArgumentParserResult()
{
    m_error = QtArgumentParserError::NoError;
}

void QtArgumentParserResult::setError(QtArgumentParserError error, const QString &errorString)
{
    m_error = error;
    m_errorString = errorString;
}

void QtArgumentParserResult::appendRecord(const QtArgumentParserResultRecord &record)
{
    m_records.append(record);
}

void QtArgumentParserResult::appendRecords(const QList<QtArgumentParserResultRecord> &records)
{
    m_records.append(records);
}

void QtArgumentParserResult::appendUnused(const QString &value)
{
    m_unused.append(value);
}

void QtArgumentParserResult::appendUnused(const QStringList &values)
{
    m_unused.append(values);
}
