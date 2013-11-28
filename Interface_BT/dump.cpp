
#include <dump.h>


dump::dump(){
}

void dump::init(){
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
   rowName.append("航班号	");
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


}

QVector<QStringList> dump::dumpFromB2Q(QSqlTableModel *model,QString moneyKeep,QString memo,QString latestPreticketTimeLimit,QString policyCode,QString canPayDirectly,QString pnr,QString pat,QString suppierCode,QString isItinerarySupplied){
    QVector<QStringList> v;
    QString airlineCode,departureCityCodes, arrivalCityCodes,applicableFlight,timetableRestriction,applicableSpaceCode,rebateRate,ticketingDateLimitStart,ticketingDateLimitEnd;
    QString flightRestriction="所有",priceType="Y舱折扣",departureTime="0000-2359",earliestPreticketTimeLimit="0",price ="0";
    QString remarkInfo="不可改签、不可改期、不可退票",spaceInfo="预付产品";
    QStringList departureCityList,arrivalCityList;
    for(int i = 0;i<model->rowCount();i++)
    {
        airlineCode = model->record(i).value("airlineCode").toString();
        //policyCode = model->record(i).value(1).toString() + "lh";
        departureCityCodes = model->record(i).value("departureCityCodes").toString();
        arrivalCityCodes = model->record(i).value("arrivalCityCodes").toString();
        departureCityList = departureCityCodes.split(",");
        arrivalCityList = arrivalCityCodes.split(",");
        applicableFlight = model->record(i).value("applicableFlight").toString();
        ticketingDateLimitStart = model->record(i).value("ticketingDateLimitStart").toString();
        ticketingDateLimitEnd = model->record(i).value("ticketingDateLimitEnd").toString();
        timetableRestriction = model->record(i).value("timetableRestriction").toString();
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

        for(int m = 0; m < departureCityList.count();m++)
            for(int n = 0; n < arrivalCityList.count();n++){
                QStringList list;
                list.append(airlineCode);
                list.append(policyCode);
                list.append(departureCityList.at(m));
                list.append(arrivalCityList.at(n));
                list.append(flightRestriction);
                list.append(applicableFlight);
                list.append(timetableRestriction);
                list.append(applicableSpaceCode);
                list.append(priceType);
                list.append(price);
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
                v.append(list);
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
void dump::exportXls(QString querys)
{
    //QString xlsFilePath=QFileDialog::getSaveFileName(this,QObject::tr("Save orbit"),".",QObject::tr("Microsoft Office 2003 (*.xls)"));
    //QString xlsFilePath = "/home/daniel/Desktop/test.xls";
    //QString xlsFilePath = "/Users/xiaosb/Documents/test.xls";
    QString xlsFilePath = "d:/aa.xls";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","excelexport");
    if (!db.isValid()) {
        QMessageBox::information(NULL, QObject::tr("Info："), QObject::tr("connect ODBC driver failed!"));
        return;
    }
    QString dsn = QString("DRIVER={Microsoft Excel Driver (*.xls)};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").arg(xlsFilePath).arg(xlsFilePath);
    db.setDatabaseName(dsn);
    if (!db.open()) {
        QMessageBox::information(NULL, QObject::tr("Info:"), QObject::tr("Excel open failed！"));
        qDebug()<<db.lastError();
        return;
    }

    QSqlQuery query(db);

    QString strSql = QString("CREATE TABLE qunarTable(`airlineCode` varchar(20) COLLATE gb2312_bin NOT NULL,`policyCode` varchar(100) NOT NULL,`departureCityCodes` varchar(100) COLLATE gb2312_bin NOT NULL,`arrivalCityCodes` varchar(100) COLLATE gb2312_bin NOT NULL,`flightRestriction` enum('所有','适用') COLLATE gb2312_bin NOT NULL DEFAULT'所有',`flightNumber` varchar(20) COLLATE gb2312_bin,`timetableRestriction` varchar(45) COLLATE gb2312_bin NOT NULL DEFAULT '',`applicableSpaceCode` varchar(45) COLLATE gb2312_bin NOT NULL,`priceType` varchar(45)  COLLATE gb2312_bin NOT NULL DEFAULT 'Y舱折扣',`price` double NOT NULL,`rebateRate` double NOT NULL,`keepMoney` int(11) NOT NULL DEFAULT 0,`ticketingDateLimitStart` date NOT NULL,`ticketingDateLimitEnd` date NOT NULL,`travellingDateStart` date NOT NULL,`travellingDateEnd` date NOT NULL,`departureTime` varchar(20) NOT NULL DEFAULT '0000-2359',`latestPreticketTimeLimit` date,`earlistPreticketingTimeLimit` date,`remarkInfo` varchar(50) COLLATE gb2312_bin NOT NULL DEFAULT '不可改签、不可改期、不可退票',`spaceInfo` varchar(50) COLLATE gb2312_bin NOT NULL DEFAULT '预付产品',`canPayDirectly` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',`isPNRGenerated` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',`isPAT:AChecked` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',`supplierCode` varchar(45) COLLATE gb2312_bin,`isItinerarySupplied` tinyint(4) NOT NULL DEFAULT 1,`refundRule` int NOT NULL DEFAULT 0,`remarkRule` int NOT NULL DEFAULT 0,`canSign` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '否',`isCreditsupplied` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',`certifyID` enum('0','1','2','3','4','5') COLLATE gb2312_bin NOT NULL,`maxAge` tinyint(4) DEFAULT 99,`minAge` tinyint(4) DEFAULT 2,`memo` varchar(200) COLLATE gb2312_bin NOT NULL DEFAULT '') ENGINE=InnoDB DEFAULT CHARSET=gb2312 COLLATE=gb2312_bin;");
    query.exec(strSql);
    query.exec(querys);
    db.commit();
    db.close();
    QSqlDatabase::removeDatabase("excelexport");
    qDebug()<<"this ok"<<endl;
}


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
                            qDebug() << it->at(i);
                        QString temp = it->at(i);
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

