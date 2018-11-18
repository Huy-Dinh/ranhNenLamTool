#include "profilelistmodel.h"
#include <QHash>

ProfileListModel::ProfileListModel(QObject *parent)
    :QAbstractListModel (parent)
{
    // Create dummy data for the list
   ProfileObject *first = new ProfileObject(QString("Study mode"), QString("Khoi"));
   ProfileObject *second = new ProfileObject(QString("Play mode"), QString("Huy"));
   ProfileObject *third = new ProfileObject(QString("Porn mode"), QString("Dat"));
   p_items.append(first);
   p_items.append(second);
   p_items.append(third);
}

int ProfileListModel::rowCount(const QModelIndex & /* parent */) const
{
    return p_items.count();
}

QHash<int, QByteArray> ProfileListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[OwnerRole] = "owner";
    roles[IDRole] = "ID";
    return roles;
}

QVariant ProfileListModel::data(const QModelIndex &index,
                                            int role) const {
    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid
    if (index.row() > (p_items.size()-1) )
        return QVariant();

    ProfileObject *dobj = p_items.at(index.row());
    switch (role) {
    case Qt::DisplayRole:
        if(dobj->checkActivated()) {return QVariant::fromValue(dobj->profileName + " - Activated");} // The default display role now displays the first name as well
    case NameRole:
        return QVariant::fromValue(dobj->profileName);
    case OwnerRole:
        return QVariant::fromValue(dobj->profileOwner);
    case IDRole:
        return QVariant::fromValue(dobj->profileID);
    default:
        return QVariant();
    }
}


void ProfileListModel::toggleActivation(int id){
    for(int index = 0; index < p_items.count(); index++){
        if (p_items[index]->profileID==id && !p_items[index]->checkActivated())
            p_items[index]->activate();
        else
            p_items[index]->deactivate();
    }
}

void ProfileListModel::removeProfile(int id){
    for(int index = 0; index < p_items.count(); index++){
        if (p_items[index]->profileID==id){
            delete p_items[index];
            p_items.removeAt(index);
        }
    }
}

ProfileObject* ProfileListModel::getProfilebyID(int id){
    for(int index = 0; index < p_items.count(); index++){
        if (p_items[index]->profileID==id)
            return p_items[index];
    }
}

QList<ProfileObject*> ProfileListModel::getProfilebyName(QString name){
    QList<ProfileObject*> result;
    for(int index = 0; index < p_items.count(); index++){
        if (p_items[index]->profileName.contains(name))
            result.append(p_items[index]);
    }
    return result;
}

QList<ProfileObject*> ProfileListModel::getProfilebyOwner(QString owner){
    QList<ProfileObject*> result;
    for(int index = 0; index < p_items.count(); index++){
        if (p_items[index]->profileName.contains(owner))
            result.append(p_items[index]);
    }
    return result;
}
