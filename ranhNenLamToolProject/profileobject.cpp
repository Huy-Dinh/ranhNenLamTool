#include "profileobject.h"

int ProfileObject::incrementID = 0;
ProfileObject::ProfileObject(const QString &name, int type)
{
    profileID = incrementID + 1;
    profileName = name;
    isActivated = false;
    listType = type;
    incrementID++;
}

void ProfileObject::toggleActivation(int id){
    if (profileID==id && !isActivated)
        isActivated = true;
    else
        isActivated = false;
}
