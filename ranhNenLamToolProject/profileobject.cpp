#include "profileobject.h"

ProfileObject::ProfileObject(const QString &name, int type)
{
    profileName = name;
    isActivated = false;
    listType = type;
}

