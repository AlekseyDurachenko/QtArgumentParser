// Copyright (C) 2013, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
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
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#ifndef QTARGUMENTPARCER_H
#define QTARGUMENTPARCER_H

#include <QVariant>
#include <QStringList>

class QtArgumentParser
{
public:
    enum ArgumentType { Flag, String, Integer, Double, Variant };

    QtArgumentParser(const QStringList &args = QStringList());
    void setArguments(const QStringList &args);
    void insertKey(const QString &key, ArgumentType type, const QStringList &variantData = QStringList());
    void reset();
    QVariantMap parse(bool *ok = 0);
    inline const QStringList &unused() const;

public:
    static bool parceArgument(const QStringList &args, int &index, const QString &name,
            ArgumentType type, QVariant &result, const QStringList variantData = QStringList());

private:
    QStringList m_Unused;
    QStringList m_Args;
    QStringList m_Keys;
    QList<ArgumentType> m_KeyTypes;
    QList<QStringList> m_KeyVariantData;

};

inline const QStringList &QtArgumentParser::unused() const
{
    return m_Unused;
}

#endif
