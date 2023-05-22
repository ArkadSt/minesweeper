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

QVariant GameModel::data(const QModelIndex &index, int value) const
{
    switch (value) {
    case Revealed:
        return (QString)board.at(index.row()).at(index.column());
    case Hidden:
        return "1";
    default:
        break;
    }

    return QVariant();
}

QHash<int, QByteArray> GameModel::roleNames() const
{
    QHash<int, QByteArray> values;
    values[Revealed] = "revealed";
    values[Hidden] = "hidden";
    return values;
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
