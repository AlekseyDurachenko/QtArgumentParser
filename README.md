QtArgumentParcer
================

The QCoreApplication argument parcer

Example
-------

    #include <QCoreApplication>
    #include <QtArgumentParser>
    #include <QDebug>
      
    int main(int argc, char *argv[])
    {
        QCoreApplication args(argc, argv);
      
        QtArgumentParser parser(args.arguments());
        parser.insertKey("-i", QtArgumentParser::String);
        parser.insertKey("-o", QtArgumentParser::String);
        parser.insertKey("-n", QtArgumentParser::Integer);
        parser.insertKey("-d", QtArgumentParser::Double);
        parser.insertKey("-f", QtArgumentParser::Flag);
        parser.insertKey("-x", QtArgumentParser::Variant, QStringList() << "Variant" << "None");
    
        bool ok;
        QVariantMap map = parser.parse(&ok);
        
        if (!map.contains("-i") || !map.contains("-o") || !ok)
        {
            /* usage(); */
            return -1;
        }
    
        qDebug() << map["-i"] << map["-o"] << map["-n"] << map["-d"] << map.contains("-f") << map["-x"];
        qDebug() << parser.unused();
    
        return 0;
    }
  
    // you_app -i input_file.ext -o output_file.ext -n 10 -d 6.66 -f -x None unused_file_1 unused_file_2
