#ifndef PROFILEOBJECT_H
#define PROFILEOBJECT_H

#include <QString>
#include <QMetaType>
class ProfileObject
{   
private:
    bool isActivated;
    //static int incrementID;
public:
    ProfileObject(const QString &name, int type);
    enum BanType{
        black = 0,
        white = 1
    };

    int listType;
    QString profileName;
    void activate() {isActivated=true;}
    void deactivate(){isActivated=false;}
    bool checkActivated(){return isActivated;}
};
//Q_DECLARE_METATYPE(ProfileObject);
#endif // PROFILEOBJECT_H
