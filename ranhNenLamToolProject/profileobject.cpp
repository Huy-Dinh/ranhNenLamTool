#include "profileobject.h"

int ProfileObject::incrementID = 0;
ProfileObject::ProfileObject(const QString &name, const QString &owner)
{
    profileID = incrementID + 1;
    profileName = name;
    profileOwner= owner;
    isActivated = false;
    incrementID++;
}
