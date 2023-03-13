#include "mainwindowfile.h"
#include "ui_mainwindowfile.h"
#include <QtDebug>


int j;

//Конструктор
MainWindowFile::MainWindowFile(QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::MainWindowFile)

{
    ui->setupUi(this);

    // Настройка диалоговых окон
    diagWindows();


    // Настройка модели
    Tablemodel = new TableModel;
    proxy = new QSortFilterProxyModel(this);
    proxy->setSourceModel(Tablemodel);
    ui->tableView->setSortingEnabled(true);
    proxy->filterCaseSensitivity();
    proxy->isRecursiveFilteringEnabled();
    this->ui->tableView->setModel(proxy);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setAcceptDrops(true);

    // Настройка функий
    FuncSetting();

    // Настройка имени окна
    WindowNameSetting();

    // Настройка ширины стобцов
    for (int i = 0; i < 7 ; i++){
    ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
    }

    // Настройка D&D
    ui->comboBoxMimeTypeCustomTable->addItems(Tablemodel->mimeTypes());
    connect(ui->comboBoxMimeTypeCustomTable, &QComboBox::currentTextChanged,
            this, &MainWindowFile::changeBox);

    connect(Tablemodel, &TableModel::enableDelimiterChange,
            [=](bool state)
    {
        // Так как есть необходимость переводить компоненты
        // в включение состояние и обратно в выключенное,
        // то лучше это сделать через использование переменной state
        ui->comboBoxColumnDelimiterCustomTable->setEnabled(state);
        ui->comboBoxRowDelimiterCustomTable->setEnabled(state);
        ui->checkBoxQuotesMark->setEnabled(state);
        // Сбросим текущие значения компонентов на значения по умолчанию
        ui->comboBoxColumnDelimiterCustomTable->setCurrentIndex(0);
        ui->comboBoxRowDelimiterCustomTable->setCurrentIndex(0);
        ui->checkBoxQuotesMark->setChecked(true);
    });


    connect(ui->comboBoxMimeTypeCustomTable, &QComboBox::currentTextChanged,
            Tablemodel, &TableModel::setMimeType);
    connect(ui->comboBoxColumnDelimiterCustomTable, QOverload<int>::of(&QComboBox::currentIndexChanged),
            Tablemodel, &TableModel::setColumnDelimiter);
    connect(ui->comboBoxRowDelimiterCustomTable, QOverload<int>::of(&QComboBox::currentIndexChanged),
            Tablemodel, &TableModel::setRowDelimiter);
    connect(ui->checkBoxQuotesMark, &QCheckBox::clicked,
            Tablemodel, &TableModel::setQuotes);
}

// Деструктор
MainWindowFile::~MainWindowFile()
{
    writeSettings();

    delete ui;
}

// Новое окно
void MainWindowFile::newFile()
{
    MainWindowFile *mainWindow = new MainWindowFile;
    mainWindow->show();
}

// Сохранить
bool MainWindowFile::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(currentFileName);
    }
}

// Загрузка
void MainWindowFile::loadFile(const QString &fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,
                             tr("Aplication"),
                             tr("Cannot read file %1:\n%2")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    while (!in.atEnd()) {
        QStringList Readstr;
        Post* post = new Post;
        Readstr = in.readLine().split(";", QString::SkipEmptyParts);
        post->setId(Readstr[0].toInt());
        post->setName(Readstr[1]);
        post->setIndex(Readstr[2].toInt());
        post->setAdress(Readstr[3]);
        post->setTime(Readstr[4]);
        post->setTel(Readstr[5]);
        post->setWorkers(Readstr[6].toInt());
        Mlist.append(post);
    }
    Tablemodel->setPost(Mlist);
    QApplication::restoreOverrideCursor();
    ui->actionShow->setEnabled(true);
    ui->actionSave->setEnabled(true);
    ui->actionSave_as->setEnabled(true);
}

// Загрузка
void MainWindowFile::load()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr ("Open File"),
                                                    "",tr("DataBase (*.db)"));

    if (!fileName.isEmpty())
        loadFile(fileName);
    setCurrentFile(fileName);


}

// Открытие
void MainWindowFile::on_actionOpen_file_triggered()
{
    Mlist.clear();
    Tablemodel->clear();
    this->load();
}

// Добавление записи, вызов диалога
void MainWindowFile::on_pushButtonAdd_clicked()
{
    diagA->show();
}

// Добавление записи, добавление в модель
void MainWindowFile::addStr()
{
    QStringList Readstr = diagA->strAdd();
    Post* post = new Post;
    post->setId(Readstr[0].toInt());
    post->setName(Readstr[1]);
    post->setIndex(Readstr[2].toInt());
    post->setAdress(Readstr[3]);
    post->setTime(Readstr[4]);
    post->setTel(Readstr[5]);
    post->setWorkers(Readstr[6].toInt());
    Mlist.append(post);
    Tablemodel->setPost(Mlist);
    ui->actionShow->setEnabled(true);
    ui->actionSave->setEnabled(true);
    ui->actionSave_as->setEnabled(true);
}

// Удаление записи из модели
void MainWindowFile::delRow()
{
    int ind = diagD->del() - 1;
    Tablemodel->deletRow(ind);
    if (Tablemodel->rowK() == 0){
        ui->actionShow->setEnabled(false);
        ui->actionSave->setEnabled(false);
        ui->actionSave_as->setEnabled(false);
    }
    Mlist = Tablemodel->getPost();
}

// Редактирование записи в модели
void MainWindowFile::editRow()
{
    QStringList Readstr = diagE->edit();
    Mlist.removeAt(j);
    Post* post = new Post;
    post->setId(Readstr[0].toInt());
    post->setName(Readstr[1]);
    post->setIndex(Readstr[2].toInt());
    post->setAdress(Readstr[3]);
    post->setTime(Readstr[4]);
    post->setTel(Readstr[5]);
    post->setWorkers(Readstr[6].toInt());
    Mlist.insert(j,post);
    Tablemodel->setPost(Mlist);
}

// Добавление записи, вызов диалога
void MainWindowFile::AddRecord()
{
    diagA->show();
}

// Редактирование записи, вызов диалога
void MainWindowFile::EditRecord()
{
    QStringList Wrtiestr;
    int k = ui->tableView->selectionModel()->currentIndex().row();
    j=k;
    Wrtiestr << QString::number(Mlist.at(k)->getId());
    Wrtiestr << Mlist.at(k)->getName();
    Wrtiestr << QString::number(Mlist.at(k)->getIndex());
    Wrtiestr << Mlist.at(k)->getAdress();
    Wrtiestr << Mlist.at(k)->getTime();
    Wrtiestr << Mlist.at(k)->getTel();
    Wrtiestr << QString::number(Mlist.at(k)->getWorkers());
    diagE->refresh(Wrtiestr);
    diagE->show();
}

// Удаление записи, вызов диалога
void MainWindowFile::RemoveRecord()
{
    int row = ui->tableView->selectionModel()->currentIndex().row();
    if(row >= 0){

        if (QMessageBox::warning(this,
                                 (tr("Delet row")),
                                 (tr("Are you sure you want to delete this row?")),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        {
            return;
        } else {
            Tablemodel->deletRow(row);
        }
    }
}

// Контекстное меню
void MainWindowFile::MenuRequested(QPoint pos)
{

    QMenu * menu = new QMenu(this);
    QAction * addPost = new QAction((tr("Add")), this);
    QAction * editPost = new QAction((tr("Edit")), this);
    QAction * deletePost = new QAction((tr("Delete")), this);
    connect(addPost, SIGNAL(triggered()), this, SLOT(AddRecord()));
    connect(editPost, SIGNAL(triggered()), this, SLOT(EditRecord()));
    connect(deletePost, SIGNAL(triggered()), this, SLOT(RemoveRecord()));
    menu->addAction(addPost);
    menu->addAction(editPost);
    menu->addAction(deletePost);
    menu->popup(ui->tableView->viewport()->mapToGlobal(pos));
}

// Удаление записи, вызов диалога
void MainWindowFile::on_pushButtonDelete_clicked()
{
    diagD->show();
    diagD->refreshBox(Tablemodel->rowK());
}

// Редактирование записи, вызов диалога
void MainWindowFile::on_pushButtonEdit_clicked()
{
    QStringList Wrtiestr;
    int k = QInputDialog::getInt(this, tr("Edit row")
                                 ,tr("Which row to edit")
                                 ,1,1,Tablemodel->rowK())-1;
    j=k;
    Wrtiestr << QString::number(Mlist.at(k)->getId());
    Wrtiestr << Mlist.at(k)->getName();
    Wrtiestr << QString::number(Mlist.at(k)->getIndex());
    Wrtiestr << Mlist.at(k)->getAdress();
    Wrtiestr << Mlist.at(k)->getTime();
    Wrtiestr << Mlist.at(k)->getTel();
    Wrtiestr << QString::number(Mlist.at(k)->getWorkers());
    diagE->refresh(Wrtiestr);
    diagE->show();
}

// Обновление комбобокса
void MainWindowFile::changeBox()
{
    Tablemodel->setMimeType(ui->comboBoxMimeTypeCustomTable->currentText());
}

// Перевод ui
void MainWindowFile::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange) {
        ui->retranslateUi(this);
    }
}


// Реализация поиска
void MainWindowFile::on_pushButtonFind_clicked()
{
    Mlist = Tablemodel->getPost();
    if(ui->lineEditFind->text()!=nullptr){
        QString str = ui->comboBoxColumn->currentText();
        if(str == tr("Id")){
            for(int i=0; i < Mlist.count(); i++){
                QString s = ui->lineEditFind->text();
                if(QString(Mlist.at(i)->getId()) == s.toInt()){
                    Tablemodel->setInd(i,0);
                }
            }
        }
        if(str == tr("Name"))
            for(int i = 0; i < Mlist.count(); i++){
                if(Mlist.at(i)->getName() == ui->lineEditFind->text()){
                    Tablemodel->setInd(i,1);
                }
            }
        if(str == tr("Index")){
            for(int i=0; i < Mlist.count(); i++){

                QString s = ui->lineEditFind->text();
                if(QString(Mlist.at(i)->getIndex()) == s.toInt()){
                    Tablemodel->setInd(i,2);
                }
            }
        }
        if(str == tr("Adress"))
            for(int i = 0; i < Mlist.count(); i++){
                if(Mlist.at(i)->getAdress() == ui->lineEditFind->text()){
                    Tablemodel->setInd(i,3);
                }
            }
        if(str == tr("Working Time"))
            for(int i = 0; i < Mlist.count(); i++){
                if(Mlist.at(i)->getTime() == ui->lineEditFind->text()){
                    Tablemodel->setInd(i,4);
                }
            }
        if(str == tr("Tel"))
            for(int i = 0; i < Mlist.count(); i++){
                if(Mlist.at(i)->getTel() == ui->lineEditFind->text()){
                    Tablemodel->setInd(i,5);
                }
            }
        if(str == tr("Amount of workers"))
            for(int i=0; i < Mlist.count(); i++){
                QString s = ui->lineEditFind->text();
                if(QString(Mlist.at(i)->getWorkers()) == s.toInt()){
                    Tablemodel->setInd(i,6);
                }
            }
    }

}

// Сохранение файла
bool MainWindowFile::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,
                             tr("Aplication"),
                             tr("Cannot write file %1:\n%2")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QStringList Readstr;
    QString str;
    Mlist = Tablemodel->getPost();
    for (int i = 0; i <Mlist.size(); i++){
        Readstr << QString::number(Mlist.at(i)->getId());
        Readstr << Mlist.at(i)->getName();
        Readstr << QString::number(Mlist.at(i)->getIndex());
        Readstr << Mlist.at(i)->getAdress();
        Readstr << Mlist.at(i)->getTime();
        Readstr << Mlist.at(i)->getTel();
        Readstr << QString::number(Mlist.at(i)->getWorkers());
        str = Readstr.join(";");
        out << str + "\n";
        Readstr.clear();
        str.clear();
    }
    setCurrentFile(fileName);
    return true;
    Tablemodel->clear();
    Mlist.clear();
}

// Название файла
void MainWindowFile::setCurrentFile(const QString &fileName)
{
    currentFileName = fileName;
    isUntitled = false;

    QString showName;

    if (currentFileName.isEmpty()) {
        showName = tr("untitled.txt");
        currentFileName = showName;
    }
    else
        showName = QFileInfo(currentFileName).fileName();

    setWindowTitle(tr("%1[*] - %2")
                   .arg(showName)
                   .arg(tr("Application pr-post")));
}



// Функция сохранить как
bool MainWindowFile::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save As"),
                                                    currentFileName);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

// Нажатие на кнопку закрытие
void MainWindowFile::on_actionBack_triggered()
{
    Tablemodel->clear();
    ui->actionShow->setEnabled(false);
    ui->actionSave->setEnabled(false);
    ui->actionSave_as->setEnabled(false);
    this->hide();
    emit firstWindow();
}

// Название окна
void MainWindowFile::NameWindow()
{
    currentFileName = QString(tr("untitled%1.txt")).arg(0);
    setWindowTitle(currentFileName + "[*]"  + tr(" - Application pr-post"));
}

// Чтение настроек окна
void MainWindowFile::readSettings()
{
    QSettings settingsMain("MGSY", "pr-post");
    settingsMain.beginGroup("MainWindowGeometry");
    resize(settingsMain.value("size", QSize(400,500)).toSize());
    move(settingsMain.value("pos", QPoint(200, 200)).toPoint());
    settingsMain.endGroup();
}

// Запись настроек окна
void MainWindowFile::writeSettings()
{
    QSettings settingsMain("MGSY", "pr-post");
    settingsMain.beginGroup("MainWindowGeometry");
    settingsMain.setValue("size", size());
    settingsMain.setValue("pos", pos());
    settingsMain.endGroup();
}

// Коннекты диалоговых окон
void MainWindowFile::diagWindows()
{
    diagA = new DialogAdd;
    connect(diagA, &DialogAdd::addsignal, this, &MainWindowFile::addStr);
    diagD = new DialogDel;
    connect(diagD, &DialogDel::delsignal, this, &MainWindowFile::delRow);
    diagE = new DialogEdit;
    connect(diagE, &DialogEdit::editsignal, this, &MainWindowFile::editRow);
}






// Настройка функий
void MainWindowFile::FuncSetting()
{
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(MenuRequested(QPoint)));
    connect(ui->actionNew, &QAction::triggered,
            this, &MainWindowFile::newFile);
    connect(ui->actionSave, &QAction::triggered,
            this, &MainWindowFile::save);
    connect(ui->actionSave_as, &QAction::triggered,
            this, &MainWindowFile::saveAs);
    connect(ui->actionExit, &QAction::triggered,
            qApp, &QApplication::closeAllWindows);
}

// Настройка имени окна
void MainWindowFile::WindowNameSetting()
{
    int static filenum = 0;
    currentFileName = QString(tr("untitled%1.txt")).arg(filenum++);
    setWindowTitle(currentFileName + "[*]"  + tr(" - Application pr-post"));
    setAttribute(Qt::WA_DeleteOnClose);
}

// График
void MainWindowFile::on_actionShow_triggered()
{
    QChart *chart = new QChart();
    chart->setTitle(tr("Time-to-employee chart"));
    QLineSeries *series = new QLineSeries();
    series->setName(tr("Working hours per number of employees"));
    chart->addSeries(series);

    QVector<int> intPoint(24);
    QStringList PointStr;
    QString s;

    int m = 0;

    Mlist = Tablemodel->getPost();
    for (int i = 0; i <24; i++){
        for (int j = 0; j < Mlist.size(); j++){
            s = Mlist.at(j)->getTime();
            PointStr = s.split("-", QString::SkipEmptyParts);
            int open,close;
            open = PointStr[0].toInt();
            close = PointStr[1].toInt();
            if ((i >=open) && (i<=close))
                intPoint[i] += Mlist.at(j)->getWorkers();
        }
        if(m < intPoint[i])
            m = intPoint[i];
        series->append(i, intPoint[i]);
    }


    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,23);
    axisX->setTitleText(tr("Working time"));
    axisX->setTickCount(24);


    QValueAxis *axisY = new QValueAxis;
    m = m + (50 - (m % 50));
    axisY->setRange(0,m);
    axisY->setTitleText(tr("Amount of Wokers"));
    axisY->setTickType(QValueAxis::TicksDynamic);
    axisY->setTickInterval(50);


    chart->addAxis(axisX,Qt::AlignBottom);
    chart->addAxis(axisY,Qt::AlignLeft);

    series->attachAxis(axisX);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setWindowTitle(tr("Graph"));
    chartView->resize(1400, 1200);
    chartView->show();
}

