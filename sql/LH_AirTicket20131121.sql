CREATE DATABASE  IF NOT EXISTS `LH_AirTicket` /*!40100 DEFAULT CHARACTER SET gb2312 COLLATE gb2312_bin */;
USE `LH_AirTicket`;
-- MySQL dump 10.13  Distrib 5.5.34, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: LH_AirTicket
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
-- Table structure for table `policyDescripition`
--

DROP TABLE IF EXISTS `policyDescripition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `policyDescripition` (
  `policy_id` int(11) NOT NULL AUTO_INCREMENT,
  `policy_uuid` varbinary(16) NOT NULL,
  `policyStatus` enum('PUBLISHED','UNPUBLISHED','DELETED','SUSPENDED') COLLATE gb2312_bin NOT NULL,
  `shouldChangePNR` tinyint(4) NOT NULL DEFAULT '0',
  `departureCityCodes` varchar(100) COLLATE gb2312_bin NOT NULL,
  `arrivalCityCodes` varchar(100) COLLATE gb2312_bin NOT NULL,
  `airlineCode` varchar(20) COLLATE gb2312_bin NOT NULL,
  `flightType` enum('ONEWAY','ROUNDTRIP','BOTH') COLLATE gb2312_bin NOT NULL,
  `applicableFlight` varchar(45) COLLATE gb2312_bin NOT NULL,
  `inapplicableFlight` varchar(45) COLLATE gb2312_bin NOT NULL,
  `timetableRestriction` varchar(45) COLLATE gb2312_bin NOT NULL DEFAULT '',
  `ticketType` enum('BSP-ET','B2B-ET','ALL') COLLATE gb2312_bin NOT NULL,
  `applicableSpaceCode` varchar(45) COLLATE gb2312_bin NOT NULL,
  `rebateRate` double NOT NULL,
  `ticketingDateLimitStart` date NOT NULL,
  `ticketingDateLimitEnd` date NOT NULL,
  `supplierTTLofficeAccount` varchar(45) COLLATE gb2312_bin NOT NULL,
  `policyEntryDatetime` datetime NOT NULL,
  `policyModifyDatetime` datetime NOT NULL,
  `supplierCode` varchar(45) COLLATE gb2312_bin NOT NULL,
  `memo` varchar(200) COLLATE gb2312_bin NOT NULL DEFAULT '',
  `autoTicketingEnabled` tinyint(4) NOT NULL DEFAULT '0',
  PRIMARY KEY (`policy_id`),
  UNIQUE KEY `policy_id_UNIQUE` (`policy_id`),
  UNIQUE KEY `policy_uuid_UNIQUE` (`policy_uuid`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312 COLLATE=gb2312_bin COMMENT='detailed description of every single policy provided.';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `policyDescripition`
--

LOCK TABLES `policyDescripition` WRITE;
/*!40000 ALTER TABLE `policyDescripition` DISABLE KEYS */;
/*!40000 ALTER TABLE `policyDescripition` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `supplierWorkTime`
--

DROP TABLE IF EXISTS `supplierWorkTime`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `supplierWorkTime` (
  `supplierWorkTime_id` int(11) NOT NULL AUTO_INCREMENT,
  `supplierCode` varchar(45) COLLATE utf8_bin NOT NULL,
  `supplierRegularWorkTimeMondayStart` time NOT NULL,
  `supplierRegularWorkTimeMondayEnd` time NOT NULL,
  `supplierRegularWorkTimeTuesdayStart` time NOT NULL,
  `supplierRegularWorkTimeTuesdayEnd` time NOT NULL,
  `supplierRegularWorkTimeWednesdayStart` time NOT NULL,
  `supplierRegularWorkTimeWednesdayEnd` time NOT NULL,
  `supplierRegularWorkTimeThursdayStart` time NOT NULL,
  `supplierRegularWorkTimeThursdayEnd` time NOT NULL,
  `supplierRegularWorkTimeFridayStart` time NOT NULL,
  `supplierRegularWorkTimeFridayEnd` time NOT NULL,
  `supplierRegularWorkTimeSaturdayStart` time NOT NULL,
  `supplierRegularWorkTimeSaturdayEnd` time NOT NULL,
  `supplierRegularWorkTimeSundayStart` time NOT NULL,
  `supplierRegularWorkTimeSundayEnd` time NOT NULL,
  `supplierVoidWorkTimeMondayStart` time NOT NULL,
  `supplierVoidWorkTimeMondayEnd` time NOT NULL,
  `supplierVoidWorkTimeTuesdayStart` time NOT NULL,
  `supplierVoidWorkTimeTuesdayEnd` time NOT NULL,
  `supplierVoidWorkTimeWednesdayStart` time NOT NULL,
  `supplierVoidWorkTimeWednesdayEnd` time NOT NULL,
  `supplierVoidWorkTimeThursdayStart` time NOT NULL,
  `supplierVoidWorkTimeThursdayEnd` time NOT NULL,
  `supplierVoidWorkTimeFridayStart` time NOT NULL,
  `supplierVoidWorkTimeFridayEnd` time NOT NULL,
  `supplierVoidWorkTimeSaturdayStart` time NOT NULL,
  `supplierVoidWorkTimeSaturdayEnd` time NOT NULL,
  `supplierVoidWorkTimeSundayStart` time NOT NULL,
  `supplierVoidWorkTimeSundayEnd` time NOT NULL,
  PRIMARY KEY (`supplierWorkTime_id`),
  UNIQUE KEY `supplierWorkTime_id_UNIQUE` (`supplierWorkTime_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `supplierWorkTime`
--

LOCK TABLES `supplierWorkTime` WRITE;
/*!40000 ALTER TABLE `supplierWorkTime` DISABLE KEYS */;
/*!40000 ALTER TABLE `supplierWorkTime` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `policyLifespan`
--

DROP TABLE IF EXISTS `policyLifespan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `policyLifespan` (
  `policyLifespan_id` int(11) NOT NULL AUTO_INCREMENT,
  `policy_uuid` varbinary(16) NOT NULL,
  `supplierCode` varchar(45) COLLATE utf8_bin NOT NULL,
  `policyValidDateStart` date NOT NULL,
  `policyValidDateEnd` varbinary(16) NOT NULL,
  PRIMARY KEY (`policyLifespan_id`),
  UNIQUE KEY `policy_uuid_UNIQUE` (`policy_uuid`),
  UNIQUE KEY `policyLifespan_id_UNIQUE` (`policyLifespan_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `policyLifespan`
--

LOCK TABLES `policyLifespan` WRITE;
/*!40000 ALTER TABLE `policyLifespan` DISABLE KEYS */;
/*!40000 ALTER TABLE `policyLifespan` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2013-11-21 21:49:58
