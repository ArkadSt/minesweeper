#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <QAbstractTableModel>

class GameModel : public QAbstractTableModel
{
    int size = 30;
    int row = 30;
    int column = 30;

public:
    QList<QList<char>> board;
    QList<QPair<int, int>> mineLocations;
    QList<char> oneRow;
    bool isClicked = false;

    enum Values{
        Hidden,
        Revealed
    };

    GameModel();
    int rowCount(const QModelIndex & = QModelIndex()) const override;

    int columnCount(const QModelIndex & = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    void createBoard();
};

#endif // GAMEMODEL_H
