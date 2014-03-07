
#include <dump.h>
#include <spaceaccount.h>

dump::dump(){
    this->init();
}

void dump::init(){
    spaceAccount::initMap();
    ROWNUM = 34;
    rowMark.append("A");
    rowMark.append("B");
    rowMark.append("C");
    rowMark.append("D");
    rowMark.append("E");
    rowMark.append("F");
    rowMark.append("G");
    rowMark.append("H");
    rowMark.append("I");
    rowMark.append("J");
    rowMark.append("K");
    rowMark.append("L");
    rowMark.append("M");
    rowMark.append("N");
    rowMark.append("O");
    rowMark.append("P");
    rowMark.append("Q");
    rowMark.append("R");
    rowMark.append("S");
    rowMark.append("T");
    rowMark.append("U");
    rowMark.append("V");
    rowMark.append("W");
    rowMark.append("X");
    rowMark.append("Y");
    rowMark.append("Z");
    rowMark.append("AA");
    rowMark.append("AB");
    rowMark.append("AC");
    rowMark.append("AD");
    rowMark.append("AE");
    rowMark.append("AF");
    rowMark.append("AG");
    rowMark.append("AH");
    rowName.append("航空公司");
    rowName.append("政策代码");
    rowName.append("起飞城市");
    rowName.append("到达城市");
    rowName.append("航班限制");
    rowName.append("航班号");
    rowName.append("班期限制");
    rowName.append("适用舱位");
    rowName.append("票面价类型");
    rowName.append("票面价/折扣");
    rowName.append("返点");
    rowName.append("留钱");
    rowName.append("销售起始日期");
    rowName.append("销售结束日期");
    rowName.append("旅行起始日期");
    rowName.append("旅行结束日期");
    rowName.append("航班起飞时间");
    rowName.append("最晚提前出票时限");
    rowName.append("最早提前出票时限");
    rowName.append("退改签说明");
    rowName.append("舱位说明");
    rowName.append("是否允许直接支付");
    rowName.append("是否生成PNR");
    rowName.append("进行PAT:A校验");
    rowName.append("搭桥office号");
    rowName.append("是否提供行程单");
    rowName.append("退票规则");
    rowName.append("改期规则");
    rowName.append("是否允许签转");
    rowName.append("是否提供常旅客积分");
    rowName.append("证件类型");
    rowName.append("最大购买年龄");
    rowName.append("最小购买年龄");
    rowName.append("特殊票务说明");
    spaceCode.append("A");
    spaceCode.append("B");
    spaceCode.append("C");
    spaceCode.append("D");
    spaceCode.append("E");
    spaceCode.append("F");
    spaceCode.append("G");
    spaceCode.append("H");
    spaceCode.append("I");
    spaceCode.append("J");
    spaceCode.append("K");
    spaceCode.append("L");
    spaceCode.append("M");
    spaceCode.append("N");
    spaceCode.append("O");
    spaceCode.append("P");
    spaceCode.append("Q");
    spaceCode.append("R");
    spaceCode.append("S");
    spaceCode.append("T");
    spaceCode.append("U");
    spaceCode.append("V");
    spaceCode.append("W");
    spaceCode.append("X");
    spaceCode.append("Y");
    spaceCode.append("Z");
    spaceCode.append("A1");
    spaceCode.append("B1");
    spaceCode.append("C1");
    spaceCode.append("D1");
    spaceCode.append("E1");
    spaceCode.append("F1");
    spaceCode.append("G1");
    spaceCode.append("H1");
    spaceCode.append("I1");
    spaceCode.append("J1");
    spaceCode.append("K1");
    spaceCode.append("L1");
    spaceCode.append("M1");
    spaceCode.append("N1");
    spaceCode.append("O1");
    spaceCode.append("P1");
    spaceCode.append("Q1");
    spaceCode.append("R1");
    spaceCode.append("S1");
    spaceCode.append("T1");
    spaceCode.append("U1");
    spaceCode.append("V1");
    spaceCode.append("W1");
    spaceCode.append("X1");
    spaceCode.append("Y1");
    spaceCode.append("Z1");

}

QVector<QVector<QStringList>* > dump::dumpFromB2Q(QSqlTableModel *model,QString moneyKeep,QString memo,QString latestPreticketTimeLimit,QString policyCode,QString canPayDirectly,QString pnr,QString pat,QString suppierCode,QString isItinerarySupplied,QString dep,QString arv,QVector<QString> spaceo){
    QVector<QVector<QStringList>* >v;
    QString airlineCode,departureCityCodes, arrivalCityCodes,applicableFlight,timetableRestriction,rebateRate,ticketingDateLimitStart,ticketingDateLimitEnd,applicableSpaceCode;
    QString flightRestriction="所有",priceType="Y舱折扣",departureTime="0000-2359",earliestPreticketTimeLimit="0",price ="0";
    QString remarkInfo="不可改签、不可改期、不可退票",spaceInfo="预付产品";
    QStringList departureCityList,arrivalCityList;
    int ttt = 10000;
    int vindex = -1;
    for(int i = 0;i<model->rowCount();i++)
    {
        QVector<QString> spacev,space;
        airlineCode = model->record(i).value("airlineCode").toString();
        //policyCode = model->record(i).value(1).toString() + "lh";
        if (dep.size() != 0)
            departureCityCodes = dep;
        else
            departureCityCodes = model->record(i).value("departureCityCodes").toString();
        if (arv.size()!=0)
            arrivalCityCodes = arv;
        else
            arrivalCityCodes = model->record(i).value("arrivalCityCodes").toString();
        departureCityList = departureCityCodes.split(",");
        arrivalCityList = arrivalCityCodes.split(",");
        applicableFlight = model->record(i).value("applicableFlight").toString();
        ticketingDateLimitStart = model->record(i).value("ticketingDateLimitStart").toString();
        ticketingDateLimitEnd = model->record(i).value("ticketingDateLimitEnd").toString();
        //timetableRestriction = model->record(i).value("timetableRestriction").toString();
        timetableRestriction = "1234567";
        applicableSpaceCode = model->record(i).value("applicableSpaceCode").toString();
        rebateRate = QString::number(100*(model->record(i).value("rebateRate").toDouble()),'f',2);

        flightRestriction="所有";
        if(applicableFlight != ""){
            // qDebug() << "适用" << endl;
            flightRestriction = "适用";
            QStringList row = applicableFlight.split(',');
            applicableFlight = "";
            // qDebug() << row.count() << " ";
            for(int i = 0; i < row.count()-1;i++){
                applicableFlight +=  airlineCode + QString::number(row.at(i).toLong(),10)+",";
            }
            applicableFlight +=  airlineCode + QString::number(row.at(row.count()-1).toLong(),10);
        }
        QString spaceString = applicableSpaceCode;
        for(int i = 0; i < spaceString.length();i++)
        {
            if(i < spaceString.length() - 1)
            {
                if(spaceString.at(i+1).isDigit())
                {
                    spacev.append(QString(spaceString.at(i))+spaceString.at(i+1));
                    i++;
                }
                else
                {
                    spacev.append(spaceString.at(i));
                }
            }
            else
            {
                spacev.append(spaceString.at(i));
            }
        }

        if (spaceo.empty())
            space = spacev;
        else
            space = spaceo;
        //       qDebug()<<space.size();

        for(int j = 0; j < space.size();j++)
            for(int k = 0; k < spacev.size();k++)
                if (space.at(j) == spacev.at(k) && spaceAccount::spaceMap.value(airlineCode+space.at(j))!="")
                    for(int m = 0; m < departureCityList.count();m++)
                        for(int n = 0; n < arrivalCityList.count();n++)
                        {
                            QStringList list;
                            list.append(airlineCode);
                            list.append(policyCode);
                            list.append(departureCityList.at(m));
                            list.append(arrivalCityList.at(n));
                            list.append(flightRestriction);
                            list.append(applicableFlight);
                            list.append(timetableRestriction);
                            list.append(space.at(j));
                            list.append(priceType);
                            list.append(spaceAccount::spaceMap.value(airlineCode+space.at(j)));
                            list.append(rebateRate);
                            list.append(moneyKeep);
                            list.append(ticketingDateLimitStart);
                            list.append(ticketingDateLimitEnd);
                            list.append(ticketingDateLimitStart);
                            list.append(ticketingDateLimitEnd);
                            list.append(departureTime);
                            list.append(latestPreticketTimeLimit);
                            list.append(earliestPreticketTimeLimit);
                            list.append(remarkInfo);
                            list.append(spaceInfo);
                            list.append(canPayDirectly);
                            list.append(pnr);
                            list.append(pat);
                            list.append(suppierCode);
                            list.append(isItinerarySupplied);
                            list.append("0");
                            list.append("0");
                            list.append("否");
                            list.append("是");
                            list.append("0");
                            list.append("99");
                            list.append("2");
                            list.append(memo);
                           // qDebug() << "tot:"<<ttt;
                            if(ttt == 10000 )
                            {
                                ttt = 0;
                                vindex++;
                                v.append(new QVector<QStringList>);
                            }
                            v.at(vindex)->append(list);
                            ttt = ttt+1;

                        }
    }
    qDebug() << "finished" << endl;
    return v;
}

void dump::save(){
           QString fileName = "./data.csv";
           if (fileName.isEmpty())

           return;

           //打开.csv文件

           QFile file(fileName);

           if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
               return;

           QTextStream out(&file);

           //获取数据

           QString query = "select * from qunarTable;";
           QSqlQuery q = btDatabase::instance()->querySQL(query,1);
           while(q.next()){
               for(int i = 0; i < 34;i++){
                   QString str1 = q.value(i).toString();
                   QByteArray ba = str1.toUtf8();
                   out << QObject::tr(ba.data())<< ",";
                   qDebug() << q.value(i).toString() << " "<<  ba.data()<<endl;
               }
           out << "\n";
           }
           qDebug() << "save successfully!";
           file.close();
}

/*
void dump::saveAsExcel(QString filepath,QVector<QStringList> v){
       // QString filepath=QFileDialog::getSaveFileName(this,QObject::tr("Save orbit"),".",QObject::tr("Microsoft Office 2007 (*.xlsx)"));//获取保存路径
        qDebug() << filepath << endl;
        // QString filepath = "C:/Users/Liao Ni/Desktop/alpaca/excel.xlsx";
        if(!filepath.isEmpty()){
            //QApplication::CoInitialize();
            QAxObject *excel = new QAxObject("Excel.Application");
           // QAxObject *excel = new QAxObject("this");
            excel->setControl("Excel.Application");//连接Excel控件
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示

            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheets = workbook->querySubObject("Sheets");//获取工作表集合
            QAxObject *worksheet = worksheets->querySubObject("Item(int)",1);//获取工作表集合的工作表1，即sheet1
            QAxObject *cellX;


            for(int i = 0; i < ROWNUM;i++){
                QByteArray ba = rowName.at(i).toUtf8();
                QString X= rowMark.at(i)+QString::number(1);//设置要操作的单元格，如A1
                cellX = worksheet->querySubObject("Range(QVariant, QVariant)",X);//获取单元格
              //  qDebug() << ba.data() << endl;
                cellX->dynamicCall("SetValue(const QVariant&)",QVariant(QObject::trUtf8(ba.data())));//设置单元格的值
               // cellY->dynamicCall("SetValue(const QVariant&)",QVariant(2));
            }
            //QString query = "select * from qunarTable;";
            //QSqlQuery q = btDatabase::instance()->querySQL(query,1);
            QVector<QStringList>::ConstIterator it;
            int row_count = 1;
            for (it =v.begin(); it!=v.end();it++)
            {
                    row_count++;
                    for(int i = 0; i < ROWNUM;i++){
                        if(i == 1)
                            qDebug() << row_count;
                        QString temp ="'" + it->at(i);
                        QByteArray ba = temp.toUtf8();
                        QString X= rowMark.at(i)+QString::number(row_count+1);//设置要操作的单元格，如A1
                        cellX = worksheet->querySubObject("Range(QVariant, QVariant)",X);//获取单元格
                        cellX->dynamicCall("SetValue(const QVariant&)",QVariant(temp));//设置单元格的值
                       // cellY->dynamicCall("SetValue(const QVariant&)",QVariant(2));
                }
            }

            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(filepath));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;
            qDebug() << "finish" << endl;
        }
}
*/
void dump::xlsByODBC(QString filepath,QVector<QStringList>* v)
{
    qDebug()<<filepath;
    QString sheetName = "Sheet1";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","excelexport");
    if( !db.isValid())
        return;   //! type error
    QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};"
            "DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").arg(filepath).arg(filepath);
    db.setDatabaseName(dsn);
    qDebug()<<db.open();
    // open connection
    if( !db.open())
    {
        qDebug()<<"error";
        qDebug()<<db.lastError().text();
        return;  //! db error
    }
    QSqlQuery query(db);
    QString sSql;
    bool state;
    // drop the table if it's already exists
    sSql = QString("DROP TABLE [%1]").arg(sheetName);
    query.exec( sSql);
    //create the table (sheet in Excel file)
    sSql = QString("CREATE TABLE [%1] (").arg(sheetName);
    sSql +="[" + rowName.at(0) + "] varchar";
    for (int i = 1; i< rowName.size();i++)
    {
        sSql += ",[" + rowName.at(i)+"] varchar";
    }
    sSql += ")";
    state = query.prepare( sSql);
    if( !query.exec()) {
        qDebug()<<query.lastError()<<endl;
        goto CLOSE; //! create failed
    }
    //insert a record
    sSql = QString("INSERT INTO [%1] ").arg( sheetName);
    sSql+="(`" + rowName.at(0);
    for (int i = 1; i< rowName.size();i++)
    {
        sSql += "`,`" + rowName.at(i);
    }
    sSql += "`)";
    sSql +=" VALUES(:data1, :data2, :data3, :data4, :data5, :data6, :data7, :data8, :data9, :data10, :data11, :data12, :data13, :data14, :data15, :data16, :data17, :data18, :data19, :data20, :data21, :data22, :data23, :data24, :data25, :data26, :data27, :data28, :data29, :data30, :data31, :data32, :data33, :data34)";
    state = query.prepare( sSql);
    //circle
    QVector<QStringList>::ConstIterator it;
    for(it = v->begin(); it != v->end(); it++) {
        for (int j = 0; j < 34; j++) {
            query.bindValue(QString(":data%1").arg(j+1), it->at(j));
        }
        //qDebug()<<query.lastQuery();
        if( !query.exec()) {
            qDebug()<< query.lastError()<<endl;
            //    goto CLOSE; //! insert failed
        }
    }
    //close connection
CLOSE:
    qDebug()<<"finish"<<endl;
    db.close();
}
