DROP TABLE IF EXISTS `qunarTable`;
CREATE TABLE qunarTable(
`airlineCode` varchar(20) COLLATE gb2312_bin NOT NULL,
`policyCode` varchar(100) NOT NULL,
`departureCityCodes` varchar(100) COLLATE gb2312_bin NOT NULL,
`arrivalCityCodes` varchar(100) COLLATE gb2312_bin NOT NULL,
`flightRestriction` enum('所有','适用') COLLATE gb2312_bin NOT NULL,
`flightNumber` varchar(20) COLLATE gb2312_bin,
`timetableRestriction` varchar(45) COLLATE gb2312_bin NOT NULL DEFAULT '',
`applicableSpaceCode` varchar(45) COLLATE gb2312_bin NOT NULL,
`priceType` varchar(45)  COLLATE gb2312_bin NOT NULL DEFAULT 'Y舱折扣',
`price` double NOT NULL,
`rebateRate` double NOT NULL,
`keepMoney` int(11) NOT NULL DEFAULT 0,
`ticketingDateLimitStart` date NOT NULL,
`ticketingDateLimitEnd` date NOT NULL,
`travellingDateStart` date NOT NULL,
`travellingDateEnd` date NOT NULL,
`departureTime` varchar(20) NOT NULL DEFAULT '0000-2359',
`latestPreticketTimeLimit` date,
`earlistPreticketingTimeLimit` date,
`remarkInfo` varchar(50) COLLATE gb2312_bin NOT NULL DEFAULT '不可改签、不可改期、不可退票',
`spaceInfo` varchar(50) COLLATE gb2312_bin NOT NULL DEFAULT '预付产品',
`canPayDirectly` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',
`isPNRGenerated` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',
`isPAT:AChecked` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',
`supplierCode` varchar(45) COLLATE gb2312_bin,
`isItinerarySupplied` tinyint(4) NOT NULL DEFAULT 1,
`refundRule` int NOT NULL DEFAULT 0,
`remarkRule` int NOT NULL DEFAULT 0,
`canSign` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',
`isCreditsupplied` enum('是','否') COLLATE gb2312_bin NOT NULL DEFAULT '是',
`certifyID` enum('0','1','2','3','4','5') COLLATE gb2312_bin NOT NULL,
`maxAge` tinyint(4) DEFAULT 99,
`minAge` tinyint(4) DEFAULT 2,
`memo` varchar(200) COLLATE gb2312_bin NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=gb2312 COLLATE=gb2312_bin;

LOCK TABLES `qunarTable` WRITE;

UNLOCK TABLES;

select * from policyDescripition;
