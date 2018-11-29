#ifndef PROFILELISTMODEL_H
#define PROFILELISTMODEL_H

#include <QAbstractListModel>
#include <profileobject.h>
#include <QtWidgets>
#include "profiledetaildialog.h"
class ProfileListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum ProfileRoles {
        NameRole = Qt::UserRole + 1,
    };

    enum BanType{
        black = 0,
        white = 1
    };

    ProfileListModel(QObject *parent, QComboBox* p_combobox, QPushButton* p_activate, QPushButton* p_add, QPushButton* p_remove, QPushButton* p_edit);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;        
    virtual ~ProfileListModel() {}

    QList<ProfileObject> getProfileList() {return p_items; }
    bool setProfile(int pos, ProfileObject* pnew);
    bool addProfile(ProfileObject* p);
    bool removeProfile(int pos);
    void toggleActivation(int pos);

private slots:
    void on_profileComboBox_currentIndexChanged(const QString &arg1);
    void on_profileAddButton_clicked();
    void on_profileRemoveButton_clicked();
    void on_profileEditButton_clicked();
    void on_profileActivateButton_clicked();
    void on_profile_created(ProfileObject* p, bool activateNow);
    void on_profile_edited(ProfileObject* p, bool activateNow);
private:
    QComboBox* ProfileCombobox;
    QPushButton* ProfileActivateButton;
    QPushButton* ProfileAddButton;
    QPushButton* ProfileRemoveButton;
    QPushButton* ProfileEditButton;
    QList<ProfileObject> p_items;
    //ProfileDetailDialog ProfileDialog;
    ProfileObject* getProfilebyID(int id);
    QList<ProfileObject*> getProfilebyName(QString name);
    int currentPos;
};

#endif // PROFILEMODEL_H
