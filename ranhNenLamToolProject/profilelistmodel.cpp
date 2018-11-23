#include "profilelistmodel.h"
#include <QHash>

ProfileListModel::ProfileListModel(QObject *parent, QComboBox* p_combobox, QPushButton* p_activate, QPushButton* p_add, QPushButton* p_remove, QPushButton* p_edit)
    :QAbstractListModel (parent)
{
    // Create dummy data for the list
   ProfileObject *first = new ProfileObject(QString("Study mode"), black);
   ProfileObject *second = new ProfileObject(QString("Play mode"), black);
   ProfileObject *third = new ProfileObject(QString("Porn mode"), black);
   p_items.append(first);
   p_items.append(second);
   p_items.append(third);

   ProfileCombobox = p_combobox;
   ProfileAddButton = p_add;
   ProfileRemoveButton = p_remove;
   ProfileEditButton = p_edit;
   ProfileActivateButton = p_activate;
   //ProfileDetailDialog = p_dialog;
   ProfileCombobox->setModel(this);

   connect(ProfileCombobox,SIGNAL(currentIndexChanged(const QString)),this,SLOT(on_profileComboBox_currentIndexChanged(const QString)));
   connect(ProfileAddButton,SIGNAL(clicked()),this,SLOT(on_profileAddButton_clicked()));
   connect(ProfileRemoveButton,SIGNAL(clicked()),this,SLOT(on_profileRemoveButton_clicked()));
   connect(ProfileActivateButton,SIGNAL(clicked()),this,SLOT(on_profileActivateButton_clicked()));
   connect(ProfileEditButton,SIGNAL(clicked()),this,SLOT(on_profileEditButton_clicked()));
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
    case IDRole:
        return QVariant::fromValue(dobj->profileID);
    default:
        return QVariant();
    }
}


void ProfileListModel::toggleActivation(int id){
    for(int index = 0; index < p_items.count(); index++){
        p_items[index]->toggleActivation(id);
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



void ProfileListModel::on_profileComboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1.contains("Activated")) ProfileActivateButton->setText("Deactivate");
    else ProfileActivateButton->setText("Activate");
    ProfileActivateButton->update();
}

void ProfileListModel::on_profileRemoveButton_clicked()
{
    int id = ProfileCombobox->itemData(ProfileCombobox->currentIndex(),this->IDRole).toInt();
    this->removeProfile(id);
    ProfileCombobox->update();
}

void ProfileListModel::on_profileAddButton_clicked()
{
    ProfileDialog.show();
}

void ProfileListModel::on_profileEditButton_clicked()
{

}

void ProfileListModel::on_profileActivateButton_clicked()
{
    int id = ProfileCombobox->itemData(ProfileCombobox->currentIndex(),this->IDRole).toInt();
    this->toggleActivation(id);

    if(ProfileCombobox->currentText().contains("Activated")) ProfileActivateButton->setText("Deactivate");
    else ProfileActivateButton->setText("Activate");
    ProfileActivateButton->update();
    ProfileCombobox->update();
}

