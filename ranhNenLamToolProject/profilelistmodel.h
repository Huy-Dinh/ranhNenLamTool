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
        IDRole = Qt::UserRole + 1,
        NameRole = Qt::UserRole + 2,
        OwnerRole = Qt::UserRole + 3,
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

    void addProfile(QString name);
    void removeProfile(int id);
    void toggleActivation(int id);

private slots:
    void on_profileComboBox_currentIndexChanged(const QString &arg1);
    void on_profileAddButton_clicked();
    void on_profileRemoveButton_clicked();
    void on_profileEditButton_clicked();
    void on_profileActivateButton_clicked();

private:
    QComboBox* ProfileCombobox;
    QPushButton* ProfileActivateButton;
    QPushButton* ProfileAddButton;
    QPushButton* ProfileRemoveButton;
    QPushButton* ProfileEditButton;
    QList<ProfileObject*> p_items;
    ProfileDetailDialog ProfileDialog;
    ProfileObject* getProfilebyID(int id);
    QList<ProfileObject*> getProfilebyName(QString name);
};

#endif // PROFILEMODEL_H
