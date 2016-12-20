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
#ifndef QTARGUMENTPARSERRESULT_H
#define QTARGUMENTPARSERRESULT_H


#include "qtargumentparsererror.h"
#include "qtargumentparserresultrecord.h"


class QtArgumentParserResult
{
public:
    QtArgumentParserResult();

    inline QtArgumentParserError error() const;
    inline const QString &errorString() const;
    void setError(QtArgumentParserError error, const QString &errorString = QString());

    inline const QList<QtArgumentParserResultRecord> &records() const;
    void appendRecord(const QtArgumentParserResultRecord &record);
    void appendRecords(const QList<QtArgumentParserResultRecord> &records);

    inline const QStringList &unused() const;
    void appendUnused(const QString &value);
    void appendUnused(const QStringList &values);

private:
    QtArgumentParserError m_error;
    QString m_errorString;
    QList<QtArgumentParserResultRecord> m_records;
    QStringList m_unused;
};

QtArgumentParserError QtArgumentParserResult::error() const
{
    return m_error;
}

const QString &QtArgumentParserResult::errorString() const
{
    return m_errorString;
}

const QList<QtArgumentParserResultRecord> &QtArgumentParserResult::records() const
{
    return m_records;
}

const QStringList &QtArgumentParserResult::unused() const
{
    return m_unused;
}


#endif // QTARGUMENTPARSERRESULT_H
