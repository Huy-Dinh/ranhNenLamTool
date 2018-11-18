#ifndef PROFILELISTMODEL_H
#define PROFILELISTMODEL_H

#include <QAbstractListModel>
#include <profileobject.h>

class ProfileListModel: public QAbstractListModel
{
    Q_OBJECT
public:
    enum ProfileRoles {
        IDRole = Qt::UserRole + 1,
        NameRole = Qt::UserRole + 2,
        OwnerRole = Qt::UserRole + 3,
    };

    ProfileListModel(QObject *parent);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    virtual ~ProfileListModel() {}

    void removeProfile(int id);
    void toggleActivation(int id);

private:
    QList<ProfileObject*> p_items;
    ProfileObject* getProfilebyID(int id);
    QList<ProfileObject*> getProfilebyName(QString name);
    QList<ProfileObject*> getProfilebyOwner(QString name);

};

#endif // PROFILEMODEL_H
