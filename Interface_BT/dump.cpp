#include <dump.h>


dump::dump(){
}

void dump::init(){
   btDatabase::instance()->init();
}

void dump::dumpFromB2Q(){
    QString query = "select airlineCode, curdate(),departureCityCodes, arrivalCityCodes,applicableFlight,timetableRestriction,applicableSpaceCode,rebateRate,ticketingDateLimitStart,ticketingDateLimitEnd from policyDescripition limit 10";
    QSqlQuery q = btDatabase::instance()->querySQL(query,1);
    QString airlineCode,policyCode,departureCityCodes, arrivalCityCodes,applicableFlight,timetableRestriction,applicableSpaceCode,rebateRate,ticketingDateLimitStart,ticketingDateLimitEnd;
    double price = 0;
    QString moneyKeep = "-10",CertificateID = "0";
    QString insert = "", value = "";
    QString flightRestriction="所有";
    while(q.next()){
        airlineCode = q.value(0).toString();
        policyCode = q.value(1).toString() + "lh";
        departureCityCodes = q.value(2).toString();
        arrivalCityCodes = q.value(3).toString();
        applicableFlight = q.value(4).toString();
        timetableRestriction = q.value(5).toString();
        applicableSpaceCode = q.value(6).toString();
        rebateRate = QString::number(100*(q.value(7).toDouble()),'f',2);
        ticketingDateLimitStart = q.value(8).toString();
        ticketingDateLimitEnd = q.value(9).toString();

        if(applicableFlight != ""){
            qDebug() << "适用" << endl;
            flightRestriction = "适用";
            QStringList row = applicableFlight.split(',');
            applicableFlight = "";
            qDebug() << row.count() << " ";
            for(int i = 0; i < row.count()-1;i++){
               applicableFlight +=  airlineCode + QString::number(row.at(i).toLong(),10)+",";
            }
            applicableFlight +=  airlineCode + QString::number(row.at(row.count()-1).toLong(),10);
        }

        value = "'" + airlineCode + "','" + policyCode + "','" + departureCityCodes + "','" + arrivalCityCodes + "','" +  flightRestriction + "','" + applicableFlight + "','" + timetableRestriction + "','"
                + applicableSpaceCode + "',default,'"+ price + "','" + rebateRate + "','"+ moneyKeep + "','" + ticketingDateLimitStart + "','" + ticketingDateLimitEnd + "','" +
                ticketingDateLimitStart + "','" + ticketingDateLimitEnd + "',default,'" + ticketingDateLimitStart + "','" + ticketingDateLimitEnd + "',default,default,default,default,default,'',default,default,default,default,default,'"
                +CertificateID + "',default,default,''";
        insert = "insert into qunarTable values(" + value + ");";
        btDatabase::instance()->execSQL(insert);
    }
    qDebug() << "finished" << endl;

}


