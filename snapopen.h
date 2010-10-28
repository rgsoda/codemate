#ifndef SNAPOPEN_H
#define SNAPOPEN_H

#include <QDialog>

class QLineEdit;
class QTableWidget;
class QAbstractItemModel;
class QDir;
class QStringList;
class QTableWidgetItem;

class SnapOpen : public QDialog
{
    Q_OBJECT
public:
    explicit SnapOpen(QWidget *parent = 0);

public slots:
    void openSnapedFile(QTableWidgetItem* item);
    void clearFilter();

private slots:
    void fileNameInputChanged();
    void prepareWidgets();
signals:

private:
    void showFiles(const QDir &directory, const QString &filter);
    QLineEdit *fileNameInput;
    QTableWidget *filesTable;

};

#endif // SNAPOPEN_H
