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

-- Dumping structure for table udf.championship_team
DROP TABLE IF EXISTS `championship_team`;
CREATE TABLE IF NOT EXISTS `championship_team` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `dancer_id` bigint(20) unsigned NOT NULL,
  `championship_id` bigint(20) unsigned NOT NULL,
  `composition_name` varchar(100) NOT NULL,
  `start_number` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_championship_team_dancers` (`dancer_id`),
  KEY `FK_championship_team_championship` (`championship_id`),
  CONSTRAINT `FK_championship_team_championship` FOREIGN KEY (`championship_id`) REFERENCES `championship` (`id`),
  CONSTRAINT `FK_championship_team_dancers` FOREIGN KEY (`dancer_id`) REFERENCES `dancers` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_team: ~0 rows (approximately)
DELETE FROM `championship_team`;
/*!40000 ALTER TABLE `championship_team` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship_team` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
