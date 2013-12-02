#include "spaceaccount.h"

QMap<QString, QString> spaceMap;
spaceAccount::spaceAccount()
{
}

void spaceAccount::initMap()
{
    spaceMap.clear();

    spaceMap.insert("CZB","0.90");
    spaceMap.insert("CZM","0.80");
    spaceMap.insert("CZH","0.75");
    spaceMap.insert("CZK","0.70");
    spaceMap.insert("CZL","0.60");
    spaceMap.insert("CZE","0.50");
    spaceMap.insert("CZV","0.45");
    spaceMap.insert("CZZ","0.40");

    spaceMap.insert("G5T","0.90");
    spaceMap.insert("G5K","0.85");
    spaceMap.insert("G5H","0.80");
    spaceMap.insert("G5M","0.75");
    spaceMap.insert("G5G","0.70");
    spaceMap.insert("G5S","0.65");
    spaceMap.insert("G5L","0.60");
    spaceMap.insert("G5Q","0.55");
    spaceMap.insert("G5E","0.50");
    spaceMap.insert("G5V","0.45");
    spaceMap.insert("G5R","0.40");

    spaceMap.insert("EUT","0.90");
    spaceMap.insert("EUK","0.85");
    spaceMap.insert("EUH","0.80");
    spaceMap.insert("EUM","0.75");
    spaceMap.insert("EUG","0.70");
    spaceMap.insert("EUS","0.65");
    spaceMap.insert("EUL","0.60");
    spaceMap.insert("EUQ","0.55");
    spaceMap.insert("EUE","0.50");
    spaceMap.insert("EUV","0.45");
    spaceMap.insert("EUR","0.40");

    spaceMap.insert("3UT","0.90");
    spaceMap.insert("3UH","0.80");
    spaceMap.insert("3UM","0.75");
    spaceMap.insert("3UG","0.70");
    spaceMap.insert("3US","0.65");
    spaceMap.insert("3UL","0.60");
    spaceMap.insert("3UQ","0.55");
    spaceMap.insert("3UE","0.50");
    spaceMap.insert("3UV","0.45");
    spaceMap.insert("3UR","0.40");

    spaceMap.insert("NST","0.90");
    spaceMap.insert("NSH","0.80");
    spaceMap.insert("NSM","0.75");
    spaceMap.insert("NSG","0.70");
    spaceMap.insert("NSS","0.65");
    spaceMap.insert("NSL","0.60");
    spaceMap.insert("NSQ","0.55");
    spaceMap.insert("NSE","0.50");
    spaceMap.insert("NSV","0.45");
    spaceMap.insert("NSR","0.40");

    spaceMap.insert("CAB","0.90");
    spaceMap.insert("CAM","0.85");
    spaceMap.insert("CAH","0.80");
    spaceMap.insert("CAK","0.75");
    spaceMap.insert("CAL","0.70");
    spaceMap.insert("CAL1","0.65");
    spaceMap.insert("CAQ","0.60");
    spaceMap.insert("CAQ1","0.55");
    spaceMap.insert("CAG","0.50");
    spaceMap.insert("CAV","0.45");
    spaceMap.insert("CAV1","0.40");

    spaceMap.insert("ZH/VDB","0.90");
    spaceMap.insert("ZH/VDM","0.85");
    spaceMap.insert("ZH/VDH","0.80");
    spaceMap.insert("ZH/VDK","0.75");
    spaceMap.insert("ZH/VDL","0.70");
    spaceMap.insert("ZH/VDJ","0.65");
    spaceMap.insert("ZH/VDQ","0.60");
    spaceMap.insert("ZH/VDG","0.50");
    spaceMap.insert("ZH/VDV","0.45");
    spaceMap.insert("ZH/VDW","0.40");

    spaceMap.insert("SCB","0.90");
    spaceMap.insert("SCM","0.85");
    spaceMap.insert("SCH","0.80");
    spaceMap.insert("SCK","0.75");
    spaceMap.insert("SCL","0.70");
    spaceMap.insert("SCQ","0.60");
    spaceMap.insert("SCG","0.55");
    spaceMap.insert("SCV","0.50");
    spaceMap.insert("SCU","0.45");
    spaceMap.insert("SCZ","0.40");

    spaceMap.insert("HUB","0.90");
    spaceMap.insert("HUH","0.85");
    spaceMap.insert("HUK","0.80");
    spaceMap.insert("HUL","0.75");
    spaceMap.insert("HUM","0.70");
    spaceMap.insert("HUQ","0.60");
    spaceMap.insert("HUX","0.50");
    spaceMap.insert("HUU","0.45");
    spaceMap.insert("HUE","0.40");

    spaceMap.insert("CN/GSB","0.90");
    spaceMap.insert("CN/GSH","0.85");
    spaceMap.insert("CN/GSK","0.80");
    spaceMap.insert("CN/GSL","0.75");
    spaceMap.insert("CN/GSM","0.70");
    spaceMap.insert("CN/GSQ","0.60");
    spaceMap.insert("CN/GSX","0.50");
    spaceMap.insert("CN/GSU","0.45");
    spaceMap.insert("CN/GSE","0.40");

    spaceMap.insert("PNB","0.90");
    spaceMap.insert("PNH","0.85");
    spaceMap.insert("PNK","0.80");
    spaceMap.insert("PNL","0.75");
    spaceMap.insert("PNM","0.70");
    spaceMap.insert("PNQ","0.60");
    spaceMap.insert("PNX","0.50");
    spaceMap.insert("PNU","0.45");
    spaceMap.insert("PNE","0.40");

    spaceMap.insert("8LB","0.90");
    spaceMap.insert("8LH","0.85");
    spaceMap.insert("8LK","0.80");
    spaceMap.insert("8LL","0.75");
    spaceMap.insert("8LM","0.70");
    spaceMap.insert("8LQ","0.60");
    spaceMap.insert("8LX","0.50");
    spaceMap.insert("8LU","0.45");
    spaceMap.insert("8LE","0.40");

    spaceMap.insert("JDB","0.90");
    spaceMap.insert("JDH","0.85");
    spaceMap.insert("JDK","0.80");
    spaceMap.insert("JDL","0.75");
    spaceMap.insert("JDM","0.70");
    spaceMap.insert("JDP","0.65");
    spaceMap.insert("JDQ","0.60");
    spaceMap.insert("JDS","0.55");
    spaceMap.insert("JDX","0.50");
    spaceMap.insert("JDU","0.45");
    spaceMap.insert("JDE","0.40");

    spaceMap.insert("MFB","0.90");
    spaceMap.insert("MFH","0.85");
    spaceMap.insert("MFK","0.80");
    spaceMap.insert("MFL","0.75");
    spaceMap.insert("MFM","0.70");
    spaceMap.insert("MFN","0.65");
    spaceMap.insert("MFQ","0.60");
    spaceMap.insert("MFT","0.55");
    spaceMap.insert("MFV","0.50");
    spaceMap.insert("MFX","0.45");
    spaceMap.insert("MFR","0.40");

    spaceMap.insert("BKB","0.90");
    spaceMap.insert("BKH","0.85");
    spaceMap.insert("BKK","0.80");
    spaceMap.insert("BKM","0.75");
    spaceMap.insert("BKL","0.70");
    spaceMap.insert("BKN","0.65");
    spaceMap.insert("BKQ","0.60");
    spaceMap.insert("BKX","0.55");
    spaceMap.insert("BKE","0.50");
    spaceMap.insert("BKU","0.45");
    spaceMap.insert("BKT","0.40");

    spaceMap.insert("MUB","0.90");
    spaceMap.insert("MUM","0.85");
    spaceMap.insert("MUE","0.80");
    spaceMap.insert("MUH","0.75");
    spaceMap.insert("MUK","0.70");
    spaceMap.insert("MUL","0.65");
    spaceMap.insert("MUN","0.60");
    spaceMap.insert("MUR","0.55");
    spaceMap.insert("MUS","0.50");
    spaceMap.insert("MUV","0.45");
    spaceMap.insert("MUT","0.40");

    spaceMap.insert("KNB","0.90");
    spaceMap.insert("KNM","0.85");
    spaceMap.insert("KNE","0.80");
    spaceMap.insert("KNH","0.75");
    spaceMap.insert("KNK","0.70");
    spaceMap.insert("KNL","0.65");
    spaceMap.insert("KNN","0.60");
    spaceMap.insert("KNR","0.55");
    spaceMap.insert("KNS","0.50");
    spaceMap.insert("KNV","0.45");
    spaceMap.insert("KNT","0.40");

    spaceMap.insert("FMB","0.90");
    spaceMap.insert("FMM","0.85");
    spaceMap.insert("FME","0.80");
    spaceMap.insert("FMH","0.75");
    spaceMap.insert("FMK","0.70");
    spaceMap.insert("FML","0.65");
    spaceMap.insert("FMN","0.60");
    spaceMap.insert("FMR","0.55");
    spaceMap.insert("FMS","0.50");
    spaceMap.insert("FMV","0.45");
    spaceMap.insert("FMT","0.40");

    spaceMap.insert("JRB","0.90");
    spaceMap.insert("JRH","0.80");
    spaceMap.insert("JRL","0.75");
    spaceMap.insert("JRM","0.70");
    spaceMap.insert("JRN","0.65");
    spaceMap.insert("JRR","0.60");
    spaceMap.insert("JRS","0.55");
    spaceMap.insert("JRV","0.50");
    spaceMap.insert("JRT","0.45");
    spaceMap.insert("JRW","0.40");

    spaceMap.insert("HOB","0.90");
    spaceMap.insert("HOL","0.85");
    spaceMap.insert("HOM","0.80");
    spaceMap.insert("HOT","0.75");
    spaceMap.insert("HOE","0.70");
    spaceMap.insert("HOH","0.65");
    spaceMap.insert("HOV","0.60");
    spaceMap.insert("HOK","0.55");
    spaceMap.insert("HOW","0.50");
    spaceMap.insert("HOR","0.45");
    spaceMap.insert("HOQ","0.40");

    spaceMap.insert("TVB","0.90");
    spaceMap.insert("TVM","0.85");
    spaceMap.insert("TVH","0.80");
    spaceMap.insert("TVK","0.75");
    spaceMap.insert("TVL","0.70");
    spaceMap.insert("TVJ","0.65");
    spaceMap.insert("TVQ","0.60");
    spaceMap.insert("TVG","0.50");
    spaceMap.insert("TVV","0.45");
    spaceMap.insert("TVR","0.40");
}
