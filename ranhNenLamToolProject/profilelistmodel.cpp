#include "profilelistmodel.h"
#include <QHash>
#include <QMessageBox>

ProfileListModel::ProfileListModel(QObject *parent, QComboBox* p_combobox, QPushButton* p_activate, QPushButton* p_add, QPushButton* p_remove, QPushButton* p_edit)
    :QAbstractListModel (parent)
{
    // Create dummy data for the list
   ProfileObject *first = new ProfileObject(QString("Study mode"), black);
   ProfileObject *second = new ProfileObject(QString("Play mode"), black);
   ProfileObject *third = new ProfileObject(QString("Porn mode"), black);
   p_items.append(*first);
   p_items.append(*second);
   p_items.append(*third);

   ProfileCombobox = p_combobox;
   ProfileAddButton = p_add;
   ProfileRemoveButton = p_remove;
   ProfileEditButton = p_edit;
   ProfileActivateButton = p_activate;
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
    return roles;
}

QVariant ProfileListModel::data(const QModelIndex &index,
                                            int role) const {
    if (!index.isValid())
        return QVariant(); // Return Null variant if index is invalid
    if (index.row() > (p_items.size()-1) )
        return QVariant();

    ProfileObject dobj = p_items.at(index.row());
    switch (role) {
    case Qt::DisplayRole:
        if(dobj.checkActivated()) {return QVariant::fromValue(dobj.profileName + " - Activated");} // The default display role now displays the first name as well
    case NameRole:
        return QVariant::fromValue(dobj.profileName);
    default:
        return QVariant();
    }
}

bool ProfileListModel::addProfile(ProfileObject* p)
 {
    for(int i = 0 ; i < p_items.count(); i++){
        if(p_items[i].profileName == p->profileName){
            QMessageBox::warning(nullptr,"Existed profile name","Please input another profile name");
            return false;
        }
    }
     beginInsertRows(QModelIndex(), this->rowCount(), this->rowCount() + 1);
     p_items.append(*p);
     endInsertRows();
     return true;
 }

bool ProfileListModel::setProfile(int pos, ProfileObject* pnew)
 {
     p_items.replace(pos, *pnew);
     //emit(dataChanged(pos,pos));
     return true;
 }

void ProfileListModel::toggleActivation(int pos){
    for(int index = 0; index < p_items.count(); index++){
        if(index == pos && !p_items[index].checkActivated())
            p_items[index].activate();
        else
            p_items[index].deactivate();
    }
}

bool ProfileListModel::removeProfile(int pos){
    beginRemoveRows(QModelIndex(), pos, pos);
    p_items.removeAt(pos);
    endRemoveRows();
    return true;
}

QList<ProfileObject*> ProfileListModel::getProfilebyName(QString name){
    QList<ProfileObject*> result;
    for(int index = 0; index < p_items.count(); index++){
        if (p_items[index].profileName.contains(name))
            result.append(&p_items[index]);
    }
    return result;
}



void ProfileListModel::on_profileComboBox_currentIndexChanged(const QString &arg1)
{
    currentPos = ProfileCombobox->currentIndex();
    if(arg1.contains("Activated")) ProfileActivateButton->setText("Deactivate");
    else ProfileActivateButton->setText("Activate");
    ProfileActivateButton->update();
}

void ProfileListModel::on_profileRemoveButton_clicked()
{
    int pos = ProfileCombobox->currentIndex();
    this->removeProfile(pos);
    ProfileCombobox->setCurrentIndex(pos-1);
    ProfileCombobox->update();
}

void ProfileListModel::on_profileAddButton_clicked()
{
    ProfileDetailDialog ProfileDialog;
    connect(&ProfileDialog,SIGNAL(profileCreated(ProfileObject*,bool)),this,SLOT(on_profile_created(ProfileObject*,bool)));
    ProfileDialog.exec();
}

void ProfileListModel::on_profileEditButton_clicked()
{
    int pos = ProfileCombobox->currentIndex();
    ProfileDetailDialog ProfileDialog(&p_items[pos]);
    connect(&ProfileDialog,SIGNAL(profileEdited(ProfileObject*,bool)),this,SLOT(on_profile_edited(ProfileObject*,bool)));
    ProfileDialog.exec();
}

void ProfileListModel::on_profileActivateButton_clicked()
{
    int pos = ProfileCombobox->currentIndex();
    this->toggleActivation(pos);

    if(ProfileCombobox->currentText().contains("Activated")) ProfileActivateButton->setText("Deactivate");
    else ProfileActivateButton->setText("Activate");
    ProfileActivateButton->update();
    ProfileCombobox->update();
}


void ProfileListModel::on_profile_created(ProfileObject* p, bool activateNow){
    this->addProfile(p);
    if(activateNow) p_items[p_items.count()-1].activate();
    ProfileCombobox->update();
}

void ProfileListModel::on_profile_edited(ProfileObject* p, bool activateNow){
    this->setProfile(currentPos,p);
    if(activateNow) p_items[currentPos].activate();
    ProfileCombobox->update();
}
