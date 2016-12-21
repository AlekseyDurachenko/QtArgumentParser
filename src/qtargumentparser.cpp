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
#include "qtargumentparser.h"


/*
QtArgumentParser::QtArgumentParser(const QStringList& args)
{
    setArgs(args);
}

void QtArgumentParser::setArgs(const QStringList& args)
{
    m_args = args;
}

void QtArgumentParser::add(const QString &key, ArgumentType type,
        const QStringList &data)
{
    if (!m_keys.contains(key))
    {
        m_keys.push_back(key);
        m_keyTypes.push_back(type);
        m_keyVariants.push_back(data);
    }
}

void QtArgumentParser::clear()
{
    m_keys.clear();
    m_keyTypes.clear();
    m_keyVariants.clear();
}

bool QtArgumentParser::parceArgument(const QStringList &args, int &index,
        const QString &name, ArgumentType type, const QStringList variants,
        QVariant &result, QString *reason)
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
                if (reason)
                    *reason = QObject::tr("\"%1\" must have a parameter").arg(name);

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
                if (reason)
                    *reason = QObject::tr("\"%1\" must have a parameter").arg(name);

                return false;
            }

            bool ok;
            result = args[index].toLongLong(&ok);
            index += 1;
            if(!ok)
            {
                if (reason)
                    *reason = QObject::tr("\"%1\" must be an integer").arg(name);
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
                    if (reason)
                        *reason = QObject::tr("\"%1\" must have a parameter").arg(name);

                    return false;
                }

                bool ok;
                result = args[index].toDouble(&ok);
                index += 1;
                if(!ok)
                {
                    if (reason)
                        *reason = QObject::tr("\"%1\" must be a real").arg(name);

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
                if (reason)
                    *reason = QObject::tr("\"%1\" must have a parameter").arg(name);

                return false;
            }

            if (!variants.contains(args[index]))
            {
                index += 1;

                if (reason)
                    *reason = QObject::tr("\"%1\" must have a value from the list (%2)")
                        .arg(name, variants.join(", "));

                return false;
            }

            result = args[index];
            index += 1;
        }
    }

    return true;
}

bool QtArgumentParser::parse()
{
    m_errorString.clear();
    m_result.clear();
    m_unused.clear();

    for (int index = 1; index < m_args.count(); )
    {
        for (int n = 0; n < m_keys.count() && index < m_args.count(); ++n)
        {
            QVariant value = QVariant();
            if (!parceArgument(m_args, index, m_keys[n], m_keyTypes[n],
                               m_keyVariants[n], value, &m_errorString))
                return false;

            if (!value.isNull())
                m_result[m_keys[n]] = value;
        }
        if (index < m_args.count() && !m_keys.contains(m_args[index]))
        {
            m_unused.push_back(m_args[index]);
            index += 1;
        }
    }

    return true;
}
*/

QtArgumentParser::QtArgumentParser()
{
    m_unusedAllowed = false;
}

void QtArgumentParser::setUnusedAllowed(bool allow)
{
    m_unusedAllowed = allow;
}

void QtArgumentParser::insertArgument(const QtArgumentParserArgument &argument)
{
    m_arguments.append(argument);
}

void QtArgumentParser::insertArguments(const QList<QtArgumentParserArgument> &arguments)
{
    m_arguments.append(arguments);
}

QtArgumentParserResult QtArgumentParser::parse(const QStringList &args) const
{
    QtArgumentParserResult result;




    return result;
}
