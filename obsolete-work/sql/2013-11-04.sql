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
-- Table structure for table `onlinePrice`
--

DROP TABLE IF EXISTS `onlinePrice`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `onlinePrice` (
  `idonlinePrice` int(11) NOT NULL AUTO_INCREMENT,
  `flightNo` varchar(100) COLLATE utf8_bin NOT NULL,
  `airplaneType` varchar(100) COLLATE utf8_bin NOT NULL,
  `flightDate` date DEFAULT NULL,
  `departureTime` time NOT NULL,
  `arrivalTime` time NOT NULL,
  `departureAirport` varchar(100) COLLATE utf8_bin NOT NULL,
  `arrivalAirport` varchar(100) COLLATE utf8_bin NOT NULL,
  `accurateRate` varchar(50) COLLATE utf8_bin DEFAULT NULL,
  `averageDelayMins` varchar(50) COLLATE utf8_bin DEFAULT NULL,
  `lowestPrice` int(11) NOT NULL,
  `lowestAccount` varchar(50) COLLATE utf8_bin NOT NULL,
  `webSource` varchar(100) COLLATE utf8_bin NOT NULL,
  `accquiredTime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`idonlinePrice`),
  UNIQUE KEY `idonlinePrice_UNIQUE` (`idonlinePrice`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `onlinePrice`
--

LOCK TABLES `onlinePrice` WRITE;
/*!40000 ALTER TABLE `onlinePrice` DISABLE KEYS */;
/*!40000 ALTER TABLE `onlinePrice` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-11-04  3:14:19
