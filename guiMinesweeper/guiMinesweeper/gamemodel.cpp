#include "gamemodel.h"

GameModel::GameModel()
{
    createBoard();
}

int GameModel::rowCount(const QModelIndex &) const
{
    return row;
}

int GameModel::columnCount(const QModelIndex &) const
{
    return column;
}

QVariant GameModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        return (QString)board.at(index.row()).at(index.column());//1;//QString("%1, %2").arg(index.column()).arg(index.row());
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> GameModel::roleNames() const
{
    return { {Qt::DisplayRole, "display"} };
}

void GameModel::createBoard()
{
    QList<char> oneRow;
    for (int i = 0; i < size; i++){
        oneRow.emplaceBack('-');
    }
    for (int i = 0; i < size; i++)
    {
        board.emplace_back(oneRow);
//        for (int j = 0; j < size; j++)
//        {
//            QList<char> line = {'-'};
//            board.at(j).emplaceBack('-');

//        }
    }
}
