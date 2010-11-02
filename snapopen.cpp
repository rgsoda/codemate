#include <QtGui>
#include "snapopen.h"
#include <iostream>
#include "mainwindow.h"


SnapOpen::SnapOpen(QWidget *parent) :
    QDialog(parent)
{
    this->setModal(true);
    prepareWidgets();
    setWindowTitle(tr("SnapOpen"));
    resize(400, 400);

}
void SnapOpen::fileNameInputChanged() {
    filesTable->setRowCount(0);
    QString filter = fileNameInput->text()+"*";
    showFiles(QDir::currentPath(),filter);
}
void SnapOpen::clearFilter() {
    fileNameInput->setText("");
}

void SnapOpen::showFiles(const QDir &directory, const QString &filter)
{
    if(filter!="*") {
        QDirIterator directory_walker(directory.currentPath(),QStringList(filter),
                                      QDir::Files | QDir::NoSymLinks,
                                      QDirIterator::Subdirectories);
        while(directory_walker.hasNext()) {
            directory_walker.next();

            QTableWidgetItem *fileNameItem = new QTableWidgetItem(directory_walker.fileName());
            fileNameItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            fileNameItem->setFlags(Qt::ItemIsEnabled);
            QString _dirName = "";
            _dirName = directory_walker.filePath().remove(QDir::currentPath()).
                       remove(directory_walker.fileName());
            QTableWidgetItem *dirNameItem = new QTableWidgetItem(_dirName);
            dirNameItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
            dirNameItem->setFlags(Qt::ItemIsEnabled);

            QTableWidgetItem *fullpath = new QTableWidgetItem(directory_walker.fileInfo().absoluteFilePath());
            dirNameItem->setFlags(Qt::ItemIsEnabled);

            int row = filesTable->rowCount();
            filesTable->insertRow(row);
            filesTable->setItem(row, 0, fileNameItem);
            filesTable->setItem(row, 1, dirNameItem);
            filesTable->setItem(row, 2, fullpath);

        }
    } else {
        filesTable->clearContents();
    }
}

void SnapOpen::prepareWidgets()
{
    filesTable = new QTableWidget(0, 2);
    QStringList labels;
    labels << tr("File") << tr("Dir");
    filesTable->setHorizontalHeaderLabels(labels);
    filesTable->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    filesTable->verticalHeader()->hide();
    filesTable->setShowGrid(false);

    fileNameInput = new QLineEdit();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(fileNameInput);
    mainLayout->addWidget(filesTable);

    setLayout(mainLayout);

    connect(fileNameInput,SIGNAL(textChanged(QString)),
            this,SLOT(fileNameInputChanged()));

    connect(filesTable,SIGNAL(itemPressed(QTableWidgetItem*)),
            this,SLOT(openSnapedFile(QTableWidgetItem*)));
    connect(filesTable,SIGNAL(itemActivated(QTableWidgetItem*)),
            this,SLOT(openSnapedFile(QTableWidgetItem*)));

}


void SnapOpen::openSnapedFile(QTableWidgetItem *item) {
    int row = filesTable->row(item);
    QString fileName = filesTable->item(row,2)->text();
    dynamic_cast<MainWindow*>(this->parentWidget())->openFile(fileName);
    this->hide();
}
