#ifndef PROFILEOBJECT_H
#define PROFILEOBJECT_H

#include <QString>
class ProfileObject
{
private:
    bool isActivated;
    static int incrementID;
public:
    ProfileObject(const QString &name, int type);

    enum BanType{
        black = 0,
        white = 1
    };

    int listType;
    QString profileName;
    int profileID;

    bool checkActivated(){return isActivated;}
    void toggleActivation(int id);
};
#endif // PROFILEOBJECT_H
