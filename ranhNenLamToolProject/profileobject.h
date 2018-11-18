#ifndef PROFILEOBJECT_H
#define PROFILEOBJECT_H

#include <QString>
class ProfileObject
{
private:
    bool isActivated;
    static int incrementID;
public:
    ProfileObject(const QString &name, const QString &owner);

    QString profileName;
    QString profileOwner;
    int profileID;

    bool checkActivated(){return isActivated;}
    void activate(){isActivated=true;}
    void deactivate(){isActivated=false;}
};
#endif // PROFILEOBJECT_H
