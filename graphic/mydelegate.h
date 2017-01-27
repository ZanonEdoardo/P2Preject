#ifndef MYDELEGATE_H
#define MYDELEGATE_H
#include<QStyledItemDelegate>

class MyDelegate :public QAbstractItemDelegate
{
    public:
        MyDelegate(QObject *parent = 0);

        void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
        QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;

        virtual ~MyDelegate();

};

#endif // MYDELEGATE_H
