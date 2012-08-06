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

-- Dumping structure for table udf.championship_judges_mark
DROP TABLE IF EXISTS `championship_judges_mark`;
CREATE TABLE IF NOT EXISTS `championship_judges_mark` (
  `championship_id` bigint(20) unsigned NOT NULL,
  `judge_id` bigint(20) unsigned NOT NULL,
  `team_id` bigint(20) unsigned NOT NULL,
  `category_id` bigint(20) unsigned NOT NULL,
  `mark` int(10) NOT NULL,
  KEY `FK_championship_judges_mark_championship` (`championship_id`),
  KEY `judge_id` (`judge_id`),
  KEY `team_id` (`team_id`),
  KEY `category_id` (`category_id`),
  CONSTRAINT `FK_championship_judges_mark_championship` FOREIGN KEY (`championship_id`) REFERENCES `championship` (`id`),
  CONSTRAINT `FK_championship_judges_mark_championship_categories` FOREIGN KEY (`category_id`) REFERENCES `championship_categories` (`category_id`),
  CONSTRAINT `FK_championship_judges_mark_championship_judges_team` FOREIGN KEY (`judge_id`) REFERENCES `championship_judges_team` (`judge_id`),
  CONSTRAINT `FK_championship_judges_mark_championship_team` FOREIGN KEY (`team_id`) REFERENCES `championship_team` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_judges_mark: ~0 rows (approximately)
DELETE FROM `championship_judges_mark`;
/*!40000 ALTER TABLE `championship_judges_mark` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship_judges_mark` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
