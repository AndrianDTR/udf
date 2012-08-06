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

-- Dumping structure for table udf.judges_categories_have
DROP TABLE IF EXISTS `judges_categories_have`;
CREATE TABLE IF NOT EXISTS `judges_categories_have` (
  `judge_id` bigint(20) unsigned NOT NULL,
  `cat_id` int(10) NOT NULL,
  PRIMARY KEY (`judge_id`,`cat_id`),
  KEY `FK__judges_categories_name` (`cat_id`),
  CONSTRAINT `FK__judges` FOREIGN KEY (`judge_id`) REFERENCES `judges` (`id`),
  CONSTRAINT `FK__judges_categories_name` FOREIGN KEY (`cat_id`) REFERENCES `judges_categories_name` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.judges_categories_have: ~0 rows (approximately)
DELETE FROM `judges_categories_have`;
/*!40000 ALTER TABLE `judges_categories_have` DISABLE KEYS */;
/*!40000 ALTER TABLE `judges_categories_have` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
