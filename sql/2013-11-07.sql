-- MySQL dump 10.13  Distrib 5.5.34, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: airTicketOnline
-- ------------------------------------------------------
-- Server version	5.5.34-0ubuntu0.12.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `AirportInfo`
--

DROP TABLE IF EXISTS `AirportInfo`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `AirportInfo` (
  `idAirportInfo` int(11) NOT NULL AUTO_INCREMENT,
  `airportName` varchar(100) COLLATE utf8_bin NOT NULL,
  `codeIATA` varchar(3) COLLATE utf8_bin NOT NULL,
  `codeICAO` varchar(4) COLLATE utf8_bin NOT NULL,
  `cityName` varchar(45) COLLATE utf8_bin NOT NULL,
  `provinceName` varchar(45) COLLATE utf8_bin NOT NULL,
  `countryName` varchar(45) COLLATE utf8_bin NOT NULL DEFAULT 'China',
  PRIMARY KEY (`idAirportInfo`),
  UNIQUE KEY `idAirportInfo_UNIQUE` (`idAirportInfo`)
) ENGINE=InnoDB AUTO_INCREMENT=513 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `AirportInfo`
--

LOCK TABLES `AirportInfo` WRITE;
/*!40000 ALTER TABLE `AirportInfo` DISABLE KEYS */;
INSERT INTO `AirportInfo` VALUES (1,'阿勒泰机场','AAT','ZWAT','阿勒泰市','null','中国\n'),(2,'五里铺机场','AKA','ZLAK','安康市','null','中国\n'),(3,'温宿机场','AKU','ZWAK','阿克苏市','null','中国\n'),(4,'大龙山机场','AQG','ZSAQ','安庆市','null','中国\n'),(5,'安阳机场','AYN','ZNNN','安阳市','null','中国\n'),(6,'二里半机场','BAV','ZBOW','包头市','null','中国\n'),(7,'福城机场','BHY','ZGBH','北海市','null','中国\n'),(8,'昌都马草机场','BPX','ZUBD','昌都市','null','中国\n'),(9,'保山机场','BSD','ZPBS','保山市','null','中国\n'),(10,'广州白云国际机场','CAN','ZGGG','广州市','null','中国\n'),(11,'桃花机场','CGD','ZGCD','常德市','null','中国\n'),(12,'新郑国际机场','CGO','ZHCC','郑州市','null','中国\n'),(13,'龙嘉国际机场','CGQ','ZYCC','长春市','null','中国\n'),(14,'朝阳机场','CHG','ZYCY','朝阳市','null','中国\n'),(15,'酒泉机场','CHW','ZNNN','酒泉市','null','中国\n'),(16,'土城子机场','CIF','ZBCF','赤峰市','null','中国\n'),(17,'王村机场','CIH','ZBCZ','长治市','null','中国\n'),(18,'重庆江北国际机场','CKG','ZUCK','重庆市','null','中国\n'),(19,'大长山岛机场','CNI','ZNNN','长海市','null','中国\n'),(20,'长沙黄花国际机场','CSX','ZGHA','长沙市','null','中国\n'),(21,'双流国际机场','CTU','ZUUU','成都市','null','中国\n'),(22,'常州奔牛机场','CZX','ZSCG','常州市','null','中国\n'),(23,'大同机场','DAT','ZBDT','大同市','null','中国\n'),(24,'河市霸机场','DAX','ZUDX','达州市','null','中国\n'),(25,'浪头机场','DDG','ZYDD','丹东市','null','中国\n'),(26,'迪庆香格里拉机场','DIG','ZPDQ','迪庆市','null','中国\n'),(27,'大连周水子国际机场','DLC','ZYTL','大连市','null','中国\n'),(28,'大理机场','DLU','ZPDL','大理市','null','中国\n'),(29,'敦煌机场','DNH','ZLDH','敦煌市','null','中国\n'),(30,'东营机场','DOY','ZNNN','东营市','null','中国\n'),(31,'张家界荷花机场','DYG','ZGDY','张家界','null','中国\n'),(32,'许家坪机场','ENH','ZHES','恩施市','null','中国\n'),(33,'二十里铺机场','ENY','ZLYA','延安市','null','中国\n'),(34,'西关机场','FUG','ZSFY','阜阳市','null','中国\n'),(35,'长乐国际机场','FOC','ZSFZ','福州市','null','中国\n'),(36,'可可托托海机场','FYN','ZWFY','富蕴市','null','中国\n'),(37,'广汉机场','GHN','ZUGH','广汉市','null','中国\n'),(38,'格尔木机场','GOQ','ZLGM','格尔木市','null','中国\n'),(39,'海口美兰国际机场','HAK','ZJHK','海口市','null','中国\n'),(40,'黑河机场','HEK','ZYHE','黑河市','null','中国\n'),(41,'白塔机场','HET','ZBHH','呼和浩特市','null','中国\n'),(42,'骆岗机场','HFE','ZSOF','合肥市','null','中国\n'),(43,'萧山国际机场','HGH','ZSHC','杭州市','null','中国\n'),(44,'东山机场','HLD','ZBLA','海拉尔市','null','中国\n'),(45,'乌兰浩特机场','HLH','ZBUL','乌兰浩特市','null','中国\n'),(46,'哈密机场','HMI','ZWHM','哈密市','null','中国\n'),(47,'衡阳机场','HNY','ZGHY','衡阳市','null','中国\n'),(48,'阎家岗国际机场','HRB','ZYHB','哈尔滨市','null','中国\n'),(49,'普陀山机场','HSN','ZSZS','舟山市','null','中国\n'),(50,'和田机场','HTN','ZWTN','和田市','null','中国\n'),(51,'路桥机场','HYN','ZSLQ','黄岩市','null','中国\n'),(52,'西关机场','HZG','ZLHZ','汉中市','null','中国\n'),(53,'河东机场','INC','ZLIC','银川市','null','中国\n'),(54,'且末机场','IQM','ZWCM','且末市','null','中国\n'),(55,'西峰镇机场','IQN','ZLQY','庆阳市','null','中国\n'),(56,'罗家机场','JDZ','ZSJD','景德镇市','null','中国\n'),(57,'嘉峪关机场','JGN','ZLJQ','嘉峪关市','null','中国\n'),(58,'井冈山机场','JGS','ZNNN','井冈山市','null','中国\n'),(59,'景洪机场','JHG','ZPJH','西双版纳市','null','中国\n'),(60,'二台子机场','JIL','ZYJL','吉林市','null','中国\n'),(61,'庐山机场','JIU','ZSJJ','九江市','null','中国\n'),(62,'晋江机场','JJN','ZSQZ','泉州市','null','中国\n'),(63,'东郊机场','JMU','ZYJM','佳木斯市','null','中国\n'),(64,'锦州小岭子机场','JNZ','ZYJZ','锦州市','null','中国\n'),(65,'衢州机场','JUZ','ZSJU','衢州市','null','中国\n'),(66,'九寨沟黄龙机场','JZH','ZNNN','九寨沟','null','中国\n'),(67,'库车机场','KCA','ZWKC','库车市','null','中国\n'),(68,'喀什机场','KHG','ZWSH','喀什市','null','中国\n'),(69,'昌北机场','KHN','ZSCN','南昌市','null','中国\n'),(70,'长水国际机场','KMG','ZPPP','昆明市','null','中国\n'),(71,'黄金机场','KOW','ZSGZ','赣州市','null','中国\n'),(72,'库尔勒机场','KRL','ZWKL','库尔勒市','null','中国\n'),(73,'克拉玛依机场','KRY','ZWKM','克拉玛依市','null','中国\n'),(74,'龙洞堡机场','KWE','ZUGY','贵阳市','null','中国\n'),(75,'两江国际机场','KWL','ZGKL','桂林市','null','中国\n'),(76,'冠豸山机场','LCX','ZNNN','龙岩市','null','中国\n'),(77,'中川机场','LHW','ZLLL','兰州市','null','中国\n'),(78,'三义机场','LJG','ZPLJ','丽江市','null','中国\n'),(79,'临沧机场','LNJ','ZPLC','临沧市','null','中国\n'),(80,'芒市','LUM','ZPMS','潞西市','机场','null'),(81,'贡嘎机场','LXA','ZULS','拉萨市','null','中国\n'),(82,'北郊机场','LYA','ZHLY','洛阳市','null','中国\n'),(83,'白塔埠机场','LYG','ZSLG','连云港市','null','中国\n'),(84,'临沂机场','LYI','ZSLY','临沂市','null','中国\n'),(85,'白莲机场','LZH','ZGZH','柳州市','null','中国\n'),(86,'蓝田机场','LZO','ZULZ','泸州市','null','中国\n'),(87,'海浪机场','MDG','ZYMD','牡丹江市','null','中国\n'),(88,'南郊机场','MIG','ZUMY','绵阳市','null','中国\n'),(89,'梅县机场','MXZ','ZGMX','梅县市','null','中国\n'),(90,'都尉坝机场','NAO','ZUNC','南充市','null','中国\n'),(91,'南苑机场','NAY','ZBNY','北京市','null','中国\n'),(92,'三家子机场','NDG','ZYQQ','齐齐哈尔市','null','中国\n'),(93,'栎社机场','NGB','ZSNB','宁波市','null','中国\n'),(94,'南京禄口国际机场','NKG','ZSNJ','南京市','null','中国\n'),(95,'吴圩机场','NNG','ZGNN','南宁市','null','中国\n'),(96,'姜营机场','NNY','ZHNY','南阳市','null','中国\n'),(97,'兴东机场','NTG','ZSNT','南通市','null','中国\n'),(98,'北京首都国际机场','PEK','ZBAA','北京市','null','中国\n'),(99,'浦东国际机场','PVG','ZSPD','上海市','null','中国\n'),(100,'攀枝花机场','PZI','ZNNN','攀枝花市','null','中国\n'),(101,'上海虹桥国际机场','SHA','ZSSS','上海市','null','中国\n'),(102,'桃仙机场','SHE','ZYTX','沈阳市','null','中国\n'),(103,'秦皇岛机场','SHP','ZBSH','山海关市','null','中国\n'),(104,'沙市','SHS','ZHSS','荆州市','机场','null'),(105,'正定机场','SJW','ZBSJ','石家庄市','null','中国\n'),(106,'揭阳潮汕机场','SWA','ZGOW','汕头市','null','中国\n'),(107,'思茅机场','SYM','ZPSM','思茅市','null','中国\n'),(108,'凤凰国际机场','SYX','ZGSY','三亚市','null','中国\n'),(109,'宝安国际机场','SZX','ZGSZ','深圳市','null','中国\n'),(110,'流亭国际机场','TAO','ZSQD','青岛市','null','中国\n'),(111,'塔城机场','TCG','ZWTC','塔城市','null','中国\n'),(112,'大兴机场','TEN','ZUTR','铜仁市','null','中国\n'),(113,'通辽机场','TGO','ZBTL','通辽市','null','中国\n'),(114,'遥墙国际机场','TNA','ZSJN','济南市','null','中国\n'),(115,'通化机场','TNH','ZYTN','通化市','null','中国\n'),(116,'天津滨海国际机场','TSN','ZBTJ','天津市','null','中国\n'),(117,'屯溪机场','TXN','ZSTX','黄山市','null','中国\n'),(118,'武宿机场','TYN','ZBYN','太原市','null','中国\n'),(119,'地窝堡国际机场','URC','ZWWW','乌鲁木齐市','null','中国\n'),(120,'西沙机场','UYN','ZLYL','榆林市','null','中国\n'),(121,'二十里铺机场','WEF','ZSWF','潍坊市','null','中国\n'),(122,'大水泊机场','WEH','ZSWH','威海市','null','中国\n'),(123,'永强机场','WNZ','ZSWZ','温州市','null','中国\n'),(124,'乌海机场','WUA','ZNNN','乌海市','null','中国\n'),(125,'武汉天河国际机场','WUH','ZHHH','武汉市','null','中国\n'),(126,'武夷山机场','WUS','ZSWY','武夷山市','null','中国\n'),(127,'苏南硕放国际机场','WUX','ZSWX','无锡市','null','中国\n'),(128,'长州岛机场','WUZ','ZGWZ','梧州市','null','中国\n'),(129,'万县机场','WXN','ZULP','万县市','null','中国\n'),(130,'刘集机场','XFN','ZHXF','襄樊市','null','中国\n'),(131,'青山机场','XIC','ZUXC','西昌市','null','中国\n'),(132,'锡林浩特','XIL','ZBXH','锡林浩特市','null','中国\n'),(133,'咸阳国际机场','XIY','ZLXY','西安市','null','中国\n'),(134,'高崎国际机场','XMN','ZSAM','厦门市','null','中国\n'),(135,'曹家堡机场','XNN','ZLXN','西宁市','null','中国\n'),(136,'观音机场','XUZ','ZSXZ','徐州市','null','中国\n'),(137,'菜坝机场','YBP','ZUYB','宜宾市','null','中国\n'),(138,'南洋机场','YHZ','null','盐城市','null','中国\n'),(139,'三峡机场','YIH','ZHYC','宜昌市','null','中国\n'),(140,'伊宁机场','YIN','ZWYN','伊宁市','null','中国\n'),(141,'义乌机场','YIW','ZSYW','义乌市','null','中国\n'),(142,'朝阳川机场','YNJ','ZYYJ','延吉市','null','中国\n'),(143,'莱山机场','YNT','ZSYT','烟台市','null','中国\n'),(144,'玉树巴塘机场','YUS','null','玉树县','null','中国\n'),(145,'昭通机场','ZAT','ZPZT','昭通市','null','中国\n'),(146,'湛江机场','ZHA','ZGZJ','湛江市','null','中国\n'),(147,'三灶机场','ZUH','ZGSD','珠海市','null','中国\n'),(148,'遵义机场','ZYI','ZUZY','遵义市','null','中国\n');
/*!40000 ALTER TABLE `AirportInfo` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `FlightPriceQuotation`
--

DROP TABLE IF EXISTS `FlightPriceQuotation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `FlightPriceQuotation` (
  `idFlightPriceQuotation` int(11) NOT NULL,
  `fightQuotationUUID` varbinary(16) NOT NULL,
  `flightNo` varchar(100) COLLATE utf8_bin NOT NULL,
  `isTransferred` tinyint(4) NOT NULL DEFAULT '0',
  `flightSequance` enum('FIRST','SECOND','THIRD') COLLATE utf8_bin NOT NULL DEFAULT 'FIRST',
  `airplaneType` varchar(100) COLLATE utf8_bin NOT NULL,
  `flightDate` date DEFAULT NULL,
  `departureTime` time NOT NULL,
  `arrivalTime` time NOT NULL,
  `departureAirport` varchar(100) COLLATE utf8_bin NOT NULL,
  `arrivalAirport` varchar(100) COLLATE utf8_bin NOT NULL,
  `lowestPrice` int(11) NOT NULL,
  `quotationSource` varchar(100) COLLATE utf8_bin NOT NULL,
  `accquiredTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`idFlightPriceQuotation`),
  UNIQUE KEY `idonlinePrice_UNIQUE` (`idFlightPriceQuotation`),
  UNIQUE KEY `fightUUID_UNIQUE` (`fightQuotationUUID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `FlightPriceQuotation`
--

LOCK TABLES `FlightPriceQuotation` WRITE;
/*!40000 ALTER TABLE `FlightPriceQuotation` DISABLE KEYS */;
/*!40000 ALTER TABLE `FlightPriceQuotation` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-11-07 22:06:16
