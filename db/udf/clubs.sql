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

-- Dumping structure for table udf.clubs
DROP TABLE IF EXISTS `clubs`;
CREATE TABLE IF NOT EXISTS `clubs` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `city` int(10) unsigned NOT NULL,
  `login` varchar(20) DEFAULT NULL,
  `pass` varchar(50) DEFAULT NULL,
  `email` varchar(50) DEFAULT NULL,
  `contacts` varchar(150) DEFAULT NULL,
  `web` varchar(50) DEFAULT NULL,
  `location` varchar(150) DEFAULT NULL,
  `pay_date` date DEFAULT NULL,
  `expire_date` date DEFAULT NULL,
  `director_name` varchar(50) DEFAULT NULL,
  `director_bd` date DEFAULT NULL,
  `director_phone` varchar(30) DEFAULT NULL,
  `director_email` varchar(50) DEFAULT NULL,
  `director_pay_date` date DEFAULT NULL,
  `director_expire_date` date DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_clubs_cities` (`city`),
  CONSTRAINT `FK_clubs_cities` FOREIGN KEY (`city`) REFERENCES `cities` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.clubs: ~0 rows (approximately)
DELETE FROM `clubs`;
/*!40000 ALTER TABLE `clubs` DISABLE KEYS */;
/*!40000 ALTER TABLE `clubs` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
