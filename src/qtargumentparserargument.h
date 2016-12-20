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
#ifndef QTARGUMENTPARSERARGUMENT_H
#define QTARGUMENTPARSERARGUMENT_H


#include <QVariantList>
#include <QStringList>


class QtArgumentParserArgument
{
public:
    enum KeyType {
        Flag    = 0x10,
        String  = 0x20,
        Integer = 0x30,
        Double  = 0x40
    };

public:
    QtArgumentParserArgument();
    QtArgumentParserArgument(const QString &keyName, KeyType keyType, bool required = false);

    bool isValid() const;

    inline const QString &key() const;
    void setKey(const QString &key);

    inline KeyType keyType() const;
    void setKeyType(KeyType keyType);

    inline bool required() const;
    void setRequired(bool required);

private:
    QString m_key;
    KeyType m_keyType;
    bool m_required;
};

const QString &QtArgumentParserArgument::key() const
{
    return m_key;
}

QtArgumentParserArgument::KeyType QtArgumentParserArgument::keyType() const
{
    return m_keyType;
}

bool QtArgumentParserArgument::required() const
{
    return m_required;
}


#endif // QTARGUMENTPARSERARGUMENT_H
