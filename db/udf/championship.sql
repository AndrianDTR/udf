-- --------------------------------------------------------
-- Host:                         192.169.11.182
-- Server version:               5.5.24-0ubuntu0.12.04.1 - (Ubuntu)
-- Server OS:                    debian-linux-gnu
-- HeidiSQL version:             7.0.0.4053
-- Date/time:                    2012-08-07 00:07:53
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- Dumping structure for table udf.championship
DROP TABLE IF EXISTS `championship`;
CREATE TABLE IF NOT EXISTS `championship` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `type` int(10) unsigned NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `additional_info` varchar(250) DEFAULT NULL,
  `city` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_championship_cities` (`city`),
  KEY `FK_championship_championship_type` (`type`),
  CONSTRAINT `FK_championship_championship_type` FOREIGN KEY (`type`) REFERENCES `championship_type` (`id`),
  CONSTRAINT `FK_championship_cities` FOREIGN KEY (`city`) REFERENCES `cities` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship: ~0 rows (approximately)
DELETE FROM `championship`;
/*!40000 ALTER TABLE `championship` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
