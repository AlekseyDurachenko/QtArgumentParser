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
#include "qtargumentparser.h"

QtArgumentParser::QtArgumentParser(const QStringList& args)
{
    setArguments(args);
}

void QtArgumentParser::setArguments(const QStringList& args)
{
    m_Args = args;
}

void QtArgumentParser::insertKey(const QString &key, ArgumentType type, const QStringList &data)
{
    if (!m_Keys.contains(key))
    {
        m_Keys.push_back(key);
        m_KeyTypes.push_back(type);
        m_KeyVariantData.push_back(data);
    }
}

void QtArgumentParser::reset()
{
    m_Keys.clear();
    m_KeyTypes.clear();
    m_KeyVariantData.clear();
}

bool QtArgumentParser::parceArgument(const QStringList &args, int &index,
    const QString &name, ArgumentType type, QVariant &result, const QStringList variantData)
{
    if (type == Flag)
    {
        if (args[index] == name)
        {
            result = true;
            index += 1;
        }
    }
    else if (type == String)
    {
        if (args[index] == name)
        {
            index += 1;
            if (index >= args.count())
            {
                return false;
            }

            result = args[index];
            index += 1;
        }
    }
    else if (type == Integer)
    {
        if (args[index] == name)
        {
            index += 1;
            if (index >= args.count())
            {
                return false;
            }

            bool ok;
            result = args[index].toLongLong(&ok);
            index += 1;
            if(!ok)
            {
                return false;
            }
        }
    }
    else if (type == Double)
    {
        if (args[index] == name && index+1 < args.count())
        {
            if (args[index] == name)
            {
                index += 1;
                if (index >= args.count())
                {
                    return false;
                }

                bool ok;
                result = args[index].toDouble(&ok);
                index += 1;
                if(!ok)
                {
                    return false;
                }
            }
        }
    }
    else if (type == Variant)
    {
        if (args[index] == name)
        {
            index += 1;
            if (index >= args.count())
            {
                return false;
            }

            if (!variantData.contains(args[index]))
            {
                index += 1;
                return false;
            }

            result = args[index];
            index += 1;
        }
    }

    return true;
}

QVariantMap QtArgumentParser::parse(bool *ok)
{
    QVariantMap detectedArguments;

    m_Unused.clear();
    for (int index = 1; index < m_Args.count(); /**/)
    {
        for (int i = 0; i < m_Keys.count() && index < m_Args.count(); ++i)
        {
            QVariant value = QVariant();
            if (!parceArgument(m_Args, index, m_Keys[i], m_KeyTypes[i], value, m_KeyVariantData[i]))
            {
                if (ok) *ok = false;
                return QVariantMap();
            }
            if (!value.isNull())
            {
                detectedArguments[m_Keys[i]] = value;
            }
        }
        if (index < m_Args.count() && !m_Keys.contains(m_Args[index]))
        {
            m_Unused.push_back(m_Args[index]);
            index += 1;
        }
    }

    if (ok) *ok = true;
    return detectedArguments;
}
