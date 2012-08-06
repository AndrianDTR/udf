-- --------------------------------------------------------
-- Host:                         192.169.11.182
-- Server version:               5.5.24-0ubuntu0.12.04.1 - (Ubuntu)
-- Server OS:                    debian-linux-gnu
-- HeidiSQL version:             7.0.0.4053
-- Date/time:                    2012-08-07 00:07:52
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- Dumping structure for table udf.age_code
DROP TABLE IF EXISTS `age_code`;
CREATE TABLE IF NOT EXISTS `age_code` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `descr` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.age_code: ~0 rows (approximately)
DELETE FROM `age_code`;
/*!40000 ALTER TABLE `age_code` DISABLE KEYS */;
/*!40000 ALTER TABLE `age_code` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
