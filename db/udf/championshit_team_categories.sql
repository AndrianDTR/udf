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

-- Dumping structure for table udf.championshit_team_categories
DROP TABLE IF EXISTS `championshit_team_categories`;
CREATE TABLE IF NOT EXISTS `championshit_team_categories` (
  `team_id` bigint(20) unsigned NOT NULL,
  `category_id` bigint(20) unsigned NOT NULL,
  KEY `team_id` (`team_id`),
  KEY `category_id` (`category_id`),
  CONSTRAINT `FK_championshit_team_categories_championship_categories` FOREIGN KEY (`category_id`) REFERENCES `championship_categories` (`category_id`),
  CONSTRAINT `FK_championshit_team_categories_championship_team` FOREIGN KEY (`team_id`) REFERENCES `championship_team` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championshit_team_categories: ~0 rows (approximately)
DELETE FROM `championshit_team_categories`;
/*!40000 ALTER TABLE `championshit_team_categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `championshit_team_categories` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
