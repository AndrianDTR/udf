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

-- Dumping structure for table udf.age_category
DROP TABLE IF EXISTS `age_category`;
CREATE TABLE IF NOT EXISTS `age_category` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `descr` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.age_category: ~11 rows (approximately)
DELETE FROM `age_category`;
/*!40000 ALTER TABLE `age_category` DISABLE KEYS */;
INSERT INTO `age_category` (`id`, `descr`) VALUES
	(2, 'Діти до 5 років'),
	(3, 'Діти до 7 років'),
	(4, 'Діти до 9 років'),
	(5, 'Діти до 11 років'),
	(6, 'Юніори 12-15 років'),
	(7, 'Молодь 16-19 років'),
	(8, 'Дорослі 16-30 рокі'),
	(9, 'Дорослі-1 20-30 років'),
	(10, 'Дорослі-2 31-49 років'),
	(11, 'Сеньйори від 50 років'),
	(12, 'Професіонали');
/*!40000 ALTER TABLE `age_category` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
