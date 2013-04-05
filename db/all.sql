-- --------------------------------------------------------
-- Host:                         192.169.11.182
-- Server version:               5.5.24-0ubuntu0.12.04.1 - (Ubuntu)
-- Server OS:                    debian-linux-gnu
-- HeidiSQL version:             7.0.0.4053
-- Date/time:                    2012-08-07 00:08:34
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET FOREIGN_KEY_CHECKS=0 */;

-- Dumping database structure for udf
DROP DATABASE IF EXISTS `udf`;
CREATE DATABASE IF NOT EXISTS `udf` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `udf`;


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


-- Dumping structure for table udf.categories
DROP TABLE IF EXISTS `categories`;
CREATE TABLE IF NOT EXISTS `categories` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `dance` int(10) unsigned NOT NULL,
  `liga` int(10) NOT NULL,
  `gender` tinyint(4) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK__liga` (`liga`),
  KEY `FK_categories_dance_types` (`dance`),
  KEY `FK_categories_gender` (`gender`),
  CONSTRAINT `FK_categories_dance_types` FOREIGN KEY (`dance`) REFERENCES `dance_types` (`id`),
  CONSTRAINT `FK_categories_gender` FOREIGN KEY (`gender`) REFERENCES `gender` (`id`),
  CONSTRAINT `FK__liga` FOREIGN KEY (`liga`) REFERENCES `liga` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.categories: ~0 rows (approximately)
DELETE FROM `categories`;
/*!40000 ALTER TABLE `categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `categories` ENABLE KEYS */;


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


-- Dumping structure for table udf.championship_categories
DROP TABLE IF EXISTS `championship_categories`;
CREATE TABLE IF NOT EXISTS `championship_categories` (
  `championship_id` bigint(20) unsigned NOT NULL,
  `category_id` bigint(20) unsigned NOT NULL,
  KEY `championship_id` (`championship_id`),
  KEY `category_id` (`category_id`),
  CONSTRAINT `FK__categories` FOREIGN KEY (`category_id`) REFERENCES `categories` (`id`),
  CONSTRAINT `FK__championship` FOREIGN KEY (`championship_id`) REFERENCES `championship` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_categories: ~0 rows (approximately)
DELETE FROM `championship_categories`;
/*!40000 ALTER TABLE `championship_categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship_categories` ENABLE KEYS */;


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


-- Dumping structure for table udf.championship_judges_team
DROP TABLE IF EXISTS `championship_judges_team`;
CREATE TABLE IF NOT EXISTS `championship_judges_team` (
  `championship_id` bigint(20) unsigned NOT NULL,
  `judge_id` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`championship_id`),
  KEY `FK_championship_judges_team_judges` (`judge_id`),
  CONSTRAINT `FK_championship_judges_team_championship` FOREIGN KEY (`championship_id`) REFERENCES `championship` (`id`),
  CONSTRAINT `FK_championship_judges_team_judges` FOREIGN KEY (`judge_id`) REFERENCES `judges` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_judges_team: ~0 rows (approximately)
DELETE FROM `championship_judges_team`;
/*!40000 ALTER TABLE `championship_judges_team` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship_judges_team` ENABLE KEYS */;


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


-- Dumping structure for table udf.championship_type
DROP TABLE IF EXISTS `championship_type`;
CREATE TABLE IF NOT EXISTS `championship_type` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_type: ~0 rows (approximately)
DELETE FROM `championship_type`;
/*!40000 ALTER TABLE `championship_type` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship_type` ENABLE KEYS */;


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


-- Dumping structure for table udf.cities
DROP TABLE IF EXISTS `cities`;
CREATE TABLE IF NOT EXISTS `cities` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `country_id` int(10) unsigned NOT NULL,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_cities_countries` (`country_id`),
  CONSTRAINT `FK_cities_countries` FOREIGN KEY (`country_id`) REFERENCES `countries` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.cities: ~4 rows (approximately)
DELETE FROM `cities`;
/*!40000 ALTER TABLE `cities` DISABLE KEYS */;
INSERT INTO `cities` (`id`, `country_id`, `name`) VALUES
	(1, 1, 'Lviv'),
	(2, 1, 'Kyiv'),
	(3, 2, 'Moscow'),
	(4, 2, 'rostov na donu');
/*!40000 ALTER TABLE `cities` ENABLE KEYS */;


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


-- Dumping structure for table udf.countries
DROP TABLE IF EXISTS `countries`;
CREATE TABLE IF NOT EXISTS `countries` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.countries: ~2 rows (approximately)
DELETE FROM `countries`;
/*!40000 ALTER TABLE `countries` DISABLE KEYS */;
INSERT INTO `countries` (`id`, `name`) VALUES
	(1, 'Ukraine'),
	(2, 'Russia');
/*!40000 ALTER TABLE `countries` ENABLE KEYS */;


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


-- Dumping structure for table udf.dance_types
DROP TABLE IF EXISTS `dance_types`;
CREATE TABLE IF NOT EXISTS `dance_types` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(50) CHARACTER SET latin1 NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.dance_types: ~0 rows (approximately)
DELETE FROM `dance_types`;
/*!40000 ALTER TABLE `dance_types` DISABLE KEYS */;
/*!40000 ALTER TABLE `dance_types` ENABLE KEYS */;


-- Dumping structure for table udf.gender
DROP TABLE IF EXISTS `gender`;
CREATE TABLE IF NOT EXISTS `gender` (
  `id` tinyint(4) NOT NULL AUTO_INCREMENT,
  `name` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.gender: ~0 rows (approximately)
DELETE FROM `gender`;
/*!40000 ALTER TABLE `gender` DISABLE KEYS */;
/*!40000 ALTER TABLE `gender` ENABLE KEYS */;


-- Dumping structure for table udf.judges
DROP TABLE IF EXISTS `judges`;
CREATE TABLE IF NOT EXISTS `judges` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `country` int(10) unsigned NOT NULL,
  `city` int(10) unsigned NOT NULL,
  `club` bigint(20) unsigned NOT NULL,
  `attestation_info` varchar(100) DEFAULT NULL,
  `pay_date` date DEFAULT NULL,
  `expire_date` date DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.judges: ~0 rows (approximately)
DELETE FROM `judges`;
/*!40000 ALTER TABLE `judges` DISABLE KEYS */;
/*!40000 ALTER TABLE `judges` ENABLE KEYS */;


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


-- Dumping structure for table udf.judges_categories_name
DROP TABLE IF EXISTS `judges_categories_name`;
CREATE TABLE IF NOT EXISTS `judges_categories_name` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.judges_categories_name: ~0 rows (approximately)
DELETE FROM `judges_categories_name`;
/*!40000 ALTER TABLE `judges_categories_name` DISABLE KEYS */;
/*!40000 ALTER TABLE `judges_categories_name` ENABLE KEYS */;


-- Dumping structure for table udf.liga
DROP TABLE IF EXISTS `liga`;
CREATE TABLE IF NOT EXISTS `liga` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.liga: ~0 rows (approximately)
DELETE FROM `liga`;
/*!40000 ALTER TABLE `liga` DISABLE KEYS */;
/*!40000 ALTER TABLE `liga` ENABLE KEYS */;


-- Dumping structure for table udf.treners
DROP TABLE IF EXISTS `treners`;
CREATE TABLE IF NOT EXISTS `treners` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `club_id` bigint(20) unsigned NOT NULL,
  `name` varchar(50) DEFAULT NULL,
  `bd` date DEFAULT NULL,
  `city` int(20) unsigned NOT NULL,
  `phone` varchar(30) DEFAULT NULL,
  `cantact_info` varchar(150) DEFAULT NULL,
  `email` varchar(50) DEFAULT NULL,
  `pay_date` date DEFAULT NULL,
  `expire_date` date DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_treners_clubs` (`club_id`),
  KEY `FK_treners_cities` (`city`),
  CONSTRAINT `FK_treners_cities` FOREIGN KEY (`city`) REFERENCES `cities` (`id`),
  CONSTRAINT `FK_treners_clubs` FOREIGN KEY (`club_id`) REFERENCES `clubs` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.treners: ~0 rows (approximately)
DELETE FROM `treners`;
/*!40000 ALTER TABLE `treners` DISABLE KEYS */;
/*!40000 ALTER TABLE `treners` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
