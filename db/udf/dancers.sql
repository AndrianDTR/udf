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

-- Dumping structure for table udf.dancers
DROP TABLE IF EXISTS `dancers`;
CREATE TABLE IF NOT EXISTS `dancers` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `club_id` bigint(20) unsigned NOT NULL,
  `trener_id` bigint(20) unsigned NOT NULL,
  `reg_book_num` varchar(10) DEFAULT NULL,
  `name` varchar(70) DEFAULT NULL,
  `raiting` bigint(20) unsigned NOT NULL,
  `liga` int(10) NOT NULL,
  `bd` date DEFAULT NULL,
  `gender` enum('M','W') DEFAULT NULL,
  `city` int(10) unsigned NOT NULL,
  `pay_date` date DEFAULT NULL,
  `expire_date` date DEFAULT NULL,
  `reg_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `FK_dancers_clubs` (`club_id`),
  KEY `FK_dancers_treners` (`trener_id`),
  KEY `FK_dancers_liga` (`liga`),
  KEY `FK_dancers_cities` (`city`),
  CONSTRAINT `FK_dancers_cities` FOREIGN KEY (`city`) REFERENCES `cities` (`id`),
  CONSTRAINT `FK_dancers_clubs` FOREIGN KEY (`club_id`) REFERENCES `clubs` (`id`),
  CONSTRAINT `FK_dancers_liga` FOREIGN KEY (`liga`) REFERENCES `liga` (`id`),
  CONSTRAINT `FK_dancers_treners` FOREIGN KEY (`trener_id`) REFERENCES `treners` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.dancers: ~0 rows (approximately)
DELETE FROM `dancers`;
/*!40000 ALTER TABLE `dancers` DISABLE KEYS */;
/*!40000 ALTER TABLE `dancers` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
