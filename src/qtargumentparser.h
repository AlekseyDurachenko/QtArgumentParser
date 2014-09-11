// Copyright (C) 2013-2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
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
#ifndef QTARGUMENTPARSER_H
#define QTARGUMENTPARSER_H

#include <QVariant>
#include <QStringList>

class QtArgumentParser
{
public:
    enum ArgumentType
    {
        Flag    = 0x10,
        String  = 0x20,
        Integer = 0x30,
        Double  = 0x40,
        Variant = 0x50
    };
public:
    explicit QtArgumentParser(const QStringList &args = QStringList());

    inline const QStringList &args() const;
    void setArgs(const QStringList &args);

    inline int count() const;
    inline const QStringList &keys() const;
    inline const QString &key(int index);
    inline ArgumentType type(int index);
    inline const QStringList &variants(int index);
    void add(const QString &key, ArgumentType type,
             const QStringList &variants = QStringList());
    void clear();

    bool parse();
    inline const QVariantMap &result() const;
    inline const QStringList &unused() const;
    inline const QString &errorString() const;
public:
    static bool parceArgument(const QStringList &args, int &index,
            const QString &name, ArgumentType type,
            const QStringList variants,
            QVariant &result, QString *reason = 0);
private:
    QStringList m_unused;
    QStringList m_args;
    QStringList m_keys;
    QList<ArgumentType> m_keyTypes;
    QList<QStringList> m_keyVariants;
    QVariantMap m_result;
    QString m_errorString;
};

const QStringList &QtArgumentParser::args() const
{
    return m_args;
}

int QtArgumentParser::count() const
{
    return m_keys.count();
}

const QStringList &QtArgumentParser::keys() const
{
    return m_keys;
}

const QString &QtArgumentParser::key(int index)
{
    return m_keys.at(index);
}

QtArgumentParser::ArgumentType QtArgumentParser::type(int index)
{
    return m_keyTypes.at(index);
}

const QStringList &QtArgumentParser::variants(int index)
{
    return m_keyVariants.at(index);
}

const QVariantMap &QtArgumentParser::result() const
{
    return m_result;
}

inline const QStringList &QtArgumentParser::unused() const
{
    return m_unused;
}

const QString &QtArgumentParser::errorString() const
{
    return m_errorString;
}

#endif // QTARGUMENTPARSER_H
