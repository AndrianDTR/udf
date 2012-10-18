-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               5.5.24-0ubuntu0.12.04.1 - (Ubuntu)
-- Server OS:                    debian-linux-gnu
-- HeidiSQL version:             7.0.0.4053
-- Date/time:                    2012-10-19 00:21:28
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
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `code` int(10) unsigned NOT NULL DEFAULT '0',
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.age_category: ~11 rows (approximately)
DELETE FROM `age_category`;
/*!40000 ALTER TABLE `age_category` DISABLE KEYS */;
INSERT INTO `age_category` (`id`, `code`, `name`) VALUES
	(2, 5, 'Діти до 5 років'),
	(3, 7, 'Діти до 7 років'),
	(4, 9, 'Діти до 9 років'),
	(5, 1, 'Діти до 11 років'),
	(6, 2, 'Юніори 12-15 років'),
	(7, 6, 'Молодь 16-19 років'),
	(8, 3, 'Дорослі 16-30 рокі'),
	(9, 3, 'Дорослі-1 20-30 років'),
	(10, 4, 'Дорослі-2 31-49 років'),
	(11, 8, 'Сеньйори від 50 років'),
	(12, 0, 'Професіонали');
/*!40000 ALTER TABLE `age_category` ENABLE KEYS */;


-- Dumping structure for table udf.categories
DROP TABLE IF EXISTS `categories`;
CREATE TABLE IF NOT EXISTS `categories` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `dance` int(10) unsigned NOT NULL,
  `liga` int(10) NOT NULL,
  `age_category` int(10) unsigned NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `short_name` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK__liga` (`liga`),
  KEY `FK_categories_dance_types` (`dance`),
  KEY `FK_categories_gender` (`age_category`),
  CONSTRAINT `FK_categories_age_category` FOREIGN KEY (`age_category`) REFERENCES `age_category` (`id`),
  CONSTRAINT `FK_categories_dance_types` FOREIGN KEY (`dance`) REFERENCES `dance_types` (`id`),
  CONSTRAINT `FK__liga` FOREIGN KEY (`liga`) REFERENCES `liga` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.categories: ~6 rows (approximately)
DELETE FROM `categories`;
/*!40000 ALTER TABLE `categories` DISABLE KEYS */;
INSERT INTO `categories` (`id`, `dance`, `liga`, `age_category`, `name`, `short_name`) VALUES
	(8, 1, 2, 2, 'Діти до 5 років, ССоло дебют, ХІП-ХОП', 'Соло дебют < 5, хіп-хоп'),
	(9, 2, 2, 2, 'df  kdas', ' afda  l as'),
	(10, 3, 2, 2, 'sdfjsdh  s', ' fjksd lsfk'),
	(13, 3, 1, 2, 'ksdfl sdlkfsdlksd', ' sdfkll   ldfdkl'),
	(20, 1, 2, 2, '   sdk  sddkf', '   akjsdk sdkjdfsd'),
	(21, 1, 2, 2, 'f liksdsd ', 's slfksdlf');
/*!40000 ALTER TABLE `categories` ENABLE KEYS */;


-- Dumping structure for table udf.championship
DROP TABLE IF EXISTS `championship`;
CREATE TABLE IF NOT EXISTS `championship` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `type` int(10) unsigned NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `additional_info` text,
  `city` int(10) unsigned NOT NULL,
  `address` text,
  `date` date DEFAULT NULL,
  `reg_open` date DEFAULT NULL,
  `reg_close` date DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_championship_cities` (`city`),
  KEY `FK_championship_championship_type` (`type`),
  CONSTRAINT `FK_championship_championship_type` FOREIGN KEY (`type`) REFERENCES `championship_type` (`id`),
  CONSTRAINT `FK_championship_cities` FOREIGN KEY (`city`) REFERENCES `cities` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship: ~4 rows (approximately)
DELETE FROM `championship`;
/*!40000 ALTER TABLE `championship` DISABLE KEYS */;
INSERT INTO `championship` (`id`, `type`, `name`, `additional_info`, `city`, `address`, `date`, `reg_open`, `reg_close`) VALUES
	(3, 4, 'jashdjs d ', 'd gdgd hfg ', 1, 'jhdj jfhas jh', '2012-08-28', '2012-08-28', '2012-08-29'),
	(4, 1, 'sdf d ddf ', ' diuk kjddl   dflgk ', 1, NULL, NULL, NULL, NULL),
	(7, 2, 'AAAAA', 'Additional AA', 2, 'Khreschatyk 22\n', '2012-09-06', '2012-08-28', '2012-09-04'),
	(8, 2, 'BBBB', 'Additional AA', 2, 'Khreschatyk 22\n', '2012-10-07', '2012-09-28', '2012-10-06');
/*!40000 ALTER TABLE `championship` ENABLE KEYS */;


-- Dumping structure for table udf.championship_categories
DROP TABLE IF EXISTS `championship_categories`;
CREATE TABLE IF NOT EXISTS `championship_categories` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `championship_id` bigint(20) unsigned NOT NULL,
  `category_id` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `category_id` (`category_id`),
  KEY `championship_id` (`championship_id`),
  CONSTRAINT `FK_championship_categories_categories` FOREIGN KEY (`category_id`) REFERENCES `categories` (`id`),
  CONSTRAINT `FK_championship_categories_championship` FOREIGN KEY (`championship_id`) REFERENCES `championship` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=40 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_categories: ~9 rows (approximately)
DELETE FROM `championship_categories`;
/*!40000 ALTER TABLE `championship_categories` DISABLE KEYS */;
INSERT INTO `championship_categories` (`id`, `championship_id`, `category_id`) VALUES
	(20, 4, 9),
	(21, 4, 10),
	(23, 7, 21),
	(26, 7, 10),
	(27, 7, 9),
	(36, 7, 8),
	(37, 3, 9),
	(38, 3, 13),
	(39, 3, 10);
/*!40000 ALTER TABLE `championship_categories` ENABLE KEYS */;


-- Dumping structure for table udf.championship_judges_mark
DROP TABLE IF EXISTS `championship_judges_mark`;
CREATE TABLE IF NOT EXISTS `championship_judges_mark` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `championship_id` bigint(20) unsigned NOT NULL,
  `tour_id` bigint(20) unsigned NOT NULL,
  `judge_id` bigint(20) unsigned NOT NULL,
  `team_id` bigint(20) unsigned NOT NULL,
  `mark` int(10) NOT NULL DEFAULT '-1',
  `order_num` bigint(20) unsigned DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `FK_championship_judges_mark_championship` (`championship_id`),
  KEY `judge_id` (`judge_id`),
  KEY `team_id` (`team_id`),
  KEY `FK_championship_judges_mark_championship_tours` (`tour_id`),
  CONSTRAINT `FK_championship_judges_mark_championship` FOREIGN KEY (`championship_id`) REFERENCES `championship` (`id`),
  CONSTRAINT `FK_championship_judges_mark_championship_judges_team` FOREIGN KEY (`judge_id`) REFERENCES `championship_judges_team` (`id`),
  CONSTRAINT `FK_championship_judges_mark_championship_team` FOREIGN KEY (`team_id`) REFERENCES `championship_team` (`id`),
  CONSTRAINT `FK_championship_judges_mark_championship_tours` FOREIGN KEY (`tour_id`) REFERENCES `championship_tours` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_judges_mark: ~0 rows (approximately)
DELETE FROM `championship_judges_mark`;
/*!40000 ALTER TABLE `championship_judges_mark` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship_judges_mark` ENABLE KEYS */;


-- Dumping structure for table udf.championship_judges_team
DROP TABLE IF EXISTS `championship_judges_team`;
CREATE TABLE IF NOT EXISTS `championship_judges_team` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `championship_id` bigint(20) unsigned NOT NULL,
  `judge_id` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_championship_judges_team_championship` (`championship_id`),
  KEY `FK_championship_judges_team_judges` (`judge_id`),
  CONSTRAINT `FK_championship_judges_team_championship` FOREIGN KEY (`championship_id`) REFERENCES `championship` (`id`),
  CONSTRAINT `FK_championship_judges_team_judges` FOREIGN KEY (`judge_id`) REFERENCES `judges` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=45 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_judges_team: ~10 rows (approximately)
DELETE FROM `championship_judges_team`;
/*!40000 ALTER TABLE `championship_judges_team` DISABLE KEYS */;
INSERT INTO `championship_judges_team` (`id`, `championship_id`, `judge_id`) VALUES
	(34, 7, 2),
	(35, 7, 3),
	(36, 7, 4),
	(37, 7, 5),
	(38, 4, 1),
	(40, 4, 3),
	(41, 4, 4),
	(42, 4, 5),
	(43, 3, 2),
	(44, 3, 4);
/*!40000 ALTER TABLE `championship_judges_team` ENABLE KEYS */;


-- Dumping structure for table udf.championship_team
DROP TABLE IF EXISTS `championship_team`;
CREATE TABLE IF NOT EXISTS `championship_team` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `championship_id` bigint(20) unsigned NOT NULL,
  `club_id` bigint(20) unsigned NOT NULL,
  `name` varchar(100) NOT NULL,
  `start_number` bigint(20) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_championship_team_championship` (`championship_id`),
  KEY `club_id` (`club_id`),
  CONSTRAINT `FK_championship_team_championship` FOREIGN KEY (`championship_id`) REFERENCES `championship` (`id`),
  CONSTRAINT `FK_championship_team_clubs` FOREIGN KEY (`club_id`) REFERENCES `clubs` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_team: ~9 rows (approximately)
DELETE FROM `championship_team`;
/*!40000 ALTER TABLE `championship_team` DISABLE KEYS */;
INSERT INTO `championship_team` (`id`, `championship_id`, `club_id`, `name`, `start_number`) VALUES
	(1, 3, 4, 'dfg dfdf dgf', 2),
	(2, 4, 3, ' fsd g gf', 0),
	(3, 3, 4, ' fgfgf fghfh fggfg ', 3),
	(4, 3, 2, 'AAAAAA', 1),
	(5, 7, 2, '1 team', 1),
	(9, 7, 3, '2 team1', 2),
	(12, 7, 2, 'AAAA', 0),
	(13, 8, 2, 'New team name', 0),
	(14, 7, 3, 'Team second', 0);
/*!40000 ALTER TABLE `championship_team` ENABLE KEYS */;


-- Dumping structure for table udf.championship_team_categories
DROP TABLE IF EXISTS `championship_team_categories`;
CREATE TABLE IF NOT EXISTS `championship_team_categories` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `team_id` bigint(20) unsigned NOT NULL,
  `category_id` bigint(20) unsigned NOT NULL,
  `composition_name` varchar(150) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `team_id` (`team_id`),
  KEY `category_id` (`category_id`),
  CONSTRAINT `FK_championship_team_categories_championship_categories` FOREIGN KEY (`category_id`) REFERENCES `championship_categories` (`id`),
  CONSTRAINT `FK_championship_team_categories_championship_team` FOREIGN KEY (`team_id`) REFERENCES `championship_team` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_team_categories: ~0 rows (approximately)
DELETE FROM `championship_team_categories`;
/*!40000 ALTER TABLE `championship_team_categories` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship_team_categories` ENABLE KEYS */;


-- Dumping structure for table udf.championship_team_dancers
DROP TABLE IF EXISTS `championship_team_dancers`;
CREATE TABLE IF NOT EXISTS `championship_team_dancers` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `team_id` bigint(20) unsigned DEFAULT '0',
  `dancer_id` bigint(20) unsigned DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `team_id` (`team_id`),
  KEY `dancer_id` (`dancer_id`),
  CONSTRAINT `FK_championship_team_dancers_championship_team` FOREIGN KEY (`team_id`) REFERENCES `championship_team` (`id`),
  CONSTRAINT `FK_championship_team_dancers_dancers` FOREIGN KEY (`dancer_id`) REFERENCES `dancers` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=latin1;

-- Dumping data for table udf.championship_team_dancers: ~3 rows (approximately)
DELETE FROM `championship_team_dancers`;
/*!40000 ALTER TABLE `championship_team_dancers` DISABLE KEYS */;
INSERT INTO `championship_team_dancers` (`id`, `team_id`, `dancer_id`) VALUES
	(1, 4, 3),
	(23, 5, 3),
	(26, 14, 8);
/*!40000 ALTER TABLE `championship_team_dancers` ENABLE KEYS */;


-- Dumping structure for table udf.championship_tours
DROP TABLE IF EXISTS `championship_tours`;
CREATE TABLE IF NOT EXISTS `championship_tours` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `cs_cat_id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `tour_id` bigint(20) unsigned NOT NULL,
  `limit` int(10) unsigned NOT NULL,
  `final` enum('Y','N') NOT NULL DEFAULT 'N',
  PRIMARY KEY (`id`),
  KEY `FK_championship_tours_championship_categories` (`cs_cat_id`),
  KEY `FK_championship_tours_tour_types` (`tour_id`),
  CONSTRAINT `FK_championship_tours_tour_types` FOREIGN KEY (`tour_id`) REFERENCES `tour_types` (`id`),
  CONSTRAINT `FK_championship_tours_championship_categories` FOREIGN KEY (`cs_cat_id`) REFERENCES `championship_categories` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=latin1;

-- Dumping data for table udf.championship_tours: ~0 rows (approximately)
DELETE FROM `championship_tours`;
/*!40000 ALTER TABLE `championship_tours` DISABLE KEYS */;
/*!40000 ALTER TABLE `championship_tours` ENABLE KEYS */;


-- Dumping structure for table udf.championship_type
DROP TABLE IF EXISTS `championship_type`;
CREATE TABLE IF NOT EXISTS `championship_type` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.championship_type: ~6 rows (approximately)
DELETE FROM `championship_type`;
/*!40000 ALTER TABLE `championship_type` DISABLE KEYS */;
INSERT INTO `championship_type` (`id`, `name`) VALUES
	(1, 'Обласні'),
	(2, 'Рейтингові'),
	(3, 'Belly dance'),
	(4, 'Latino bit'),
	(7, 'Latino'),
	(9, 'LatinoQQ');
/*!40000 ALTER TABLE `championship_type` ENABLE KEYS */;


-- Dumping structure for table udf.cities
DROP TABLE IF EXISTS `cities`;
CREATE TABLE IF NOT EXISTS `cities` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `country_id` int(10) unsigned NOT NULL,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_cities_countries` (`country_id`),
  CONSTRAINT `FK_cities_countries` FOREIGN KEY (`country_id`) REFERENCES `countries` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.cities: ~9 rows (approximately)
DELETE FROM `cities`;
/*!40000 ALTER TABLE `cities` DISABLE KEYS */;
INSERT INTO `cities` (`id`, `country_id`, `name`) VALUES
	(1, 1, 'Lviv'),
	(2, 1, 'Kyiv'),
	(3, 3, 'Moscow'),
	(4, 3, 'rostov na donu'),
	(7, 1, 'test 2'),
	(11, 2, 'test 6'),
	(12, 1, 'Ternopil'),
	(13, 1, 'Lutsk'),
	(14, 1, 'AAAA');
/*!40000 ALTER TABLE `cities` ENABLE KEYS */;


-- Dumping structure for table udf.clubs
DROP TABLE IF EXISTS `clubs`;
CREATE TABLE IF NOT EXISTS `clubs` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `city` int(10) unsigned NOT NULL,
  `login` varchar(50) DEFAULT NULL,
  `pass` varchar(150) DEFAULT NULL,
  `email` varchar(50) DEFAULT NULL,
  `contacts` text,
  `web` varchar(50) DEFAULT NULL,
  `additional_info` text,
  `director_name` varchar(50) DEFAULT NULL,
  `director_bd` date DEFAULT NULL,
  `director_phone` varchar(30) DEFAULT NULL,
  `director_email` varchar(50) DEFAULT NULL,
  `online` datetime DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_clubs_cities` (`city`),
  CONSTRAINT `FK_clubs_cities` FOREIGN KEY (`city`) REFERENCES `cities` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.clubs: ~4 rows (approximately)
DELETE FROM `clubs`;
/*!40000 ALTER TABLE `clubs` DISABLE KEYS */;
INSERT INTO `clubs` (`id`, `name`, `city`, `login`, `pass`, `email`, `contacts`, `web`, `additional_info`, `director_name`, `director_bd`, `director_phone`, `director_email`, `online`) VALUES
	(2, 'Клуб 1', 1, 'name1', 'pass1', 'Емейл 1', 'Адреса 1', 'ввв 1', 'Інфо 1', 'Test director1', '0000-00-00', 'Test dir ph1', 'Test dir em1', '2012-10-05 23:10:53'),
	(3, 'Клуб 2', 2, 'name2', 'pass2', 'Емейл 2', 'Адреса 2', 'ввв 2', 'Інфо 2', 'Test director1', '0000-00-00', 'Test dir ph1', 'Test dir em1', '2012-10-05 23:12:21'),
	(4, 'Клуб 3', 13, 'name3', 'pass3', 'Пошта 3', 'Адреса 3', 'немає 3', 'Додаткова інформація 3', 'Test director1', '0000-00-00', 'Test dir ph1', 'Test dir em1', NULL),
	(7, 'Клуб 4', 12, 'name4', 'pass4', 'Електронна пошта 4', 'Поштова Адреса 4', 'тирнет адреса.ком 4', 'Розширена інформація 4', 'Director 12', '2012-12-12', '+380674391881', 'A@A.com', NULL);
/*!40000 ALTER TABLE `clubs` ENABLE KEYS */;


-- Dumping structure for table udf.countries
DROP TABLE IF EXISTS `countries`;
CREATE TABLE IF NOT EXISTS `countries` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.countries: ~12 rows (approximately)
DELETE FROM `countries`;
/*!40000 ALTER TABLE `countries` DISABLE KEYS */;
INSERT INTO `countries` (`id`, `name`) VALUES
	(1, 'Ukraine'),
	(2, 'Pakistan'),
	(3, 'Russia'),
	(4, 'Romania'),
	(5, 'Iraq'),
	(6, 'Iran'),
	(7, 'Moldova'),
	(8, 'XXX'),
	(9, 'XXXXX'),
	(10, 'ZZZZ'),
	(11, 'AAAAA'),
	(12, 'ZZZZ1');
/*!40000 ALTER TABLE `countries` ENABLE KEYS */;


-- Dumping structure for table udf.dancers
DROP TABLE IF EXISTS `dancers`;
CREATE TABLE IF NOT EXISTS `dancers` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `club_id` bigint(20) unsigned NOT NULL,
  `trener_id` bigint(20) unsigned NOT NULL,
  `liga` int(10) NOT NULL,
  `gender` tinyint(4) unsigned NOT NULL,
  `reg_book_num` varchar(10) DEFAULT NULL,
  `name` varchar(70) DEFAULT NULL,
  `aditional_info` varchar(250) DEFAULT NULL,
  `raiting` bigint(20) unsigned DEFAULT NULL,
  `bd` date DEFAULT NULL,
  `reg_date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `FK_dancers_clubs` (`club_id`),
  KEY `FK_dancers_treners` (`trener_id`),
  KEY `FK_dancers_liga` (`liga`),
  KEY `FK_dancers_gender` (`gender`),
  CONSTRAINT `FK_dancers_clubs` FOREIGN KEY (`club_id`) REFERENCES `clubs` (`id`),
  CONSTRAINT `FK_dancers_gender` FOREIGN KEY (`gender`) REFERENCES `gender` (`id`),
  CONSTRAINT `FK_dancers_liga` FOREIGN KEY (`liga`) REFERENCES `liga` (`id`),
  CONSTRAINT `FK_dancers_treners` FOREIGN KEY (`trener_id`) REFERENCES `treners` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.dancers: ~8 rows (approximately)
DELETE FROM `dancers`;
/*!40000 ALTER TABLE `dancers` DISABLE KEYS */;
INSERT INTO `dancers` (`id`, `club_id`, `trener_id`, `liga`, `gender`, `reg_book_num`, `name`, `aditional_info`, `raiting`, `bd`, `reg_date`) VALUES
	(3, 2, 3, 1, 9, 'Test RB1', 'Танцівник 1', NULL, 1, '2001-12-30', '2012-08-21 00:00:00'),
	(5, 3, 3, 1, 9, 'Test RB1', 'Test name1', NULL, 1, '2001-12-30', '0000-00-00 00:00:00'),
	(6, 3, 3, 2, 9, 'Test RB2', 'Test name2', NULL, 1, '2001-12-30', '0000-00-00 00:00:00'),
	(7, 3, 3, 3, 9, 'Test RB3', 'Test name3', NULL, 1, '2001-12-30', '0000-00-00 00:00:00'),
	(8, 3, 3, 4, 10, 'Test RB4', 'Test name4', NULL, 1, '2001-12-30', '0000-00-00 00:00:00'),
	(9, 3, 3, 5, 10, 'Test RB5', 'Test name5', NULL, 1, '2002-12-30', '0000-00-00 00:00:00'),
	(10, 3, 3, 6, 10, 'Test RB6', 'Test name6', NULL, 1, '2001-12-30', '0000-00-00 00:00:00'),
	(11, 3, 3, 9, 9, 'Test RB7', 'Test name7', NULL, 1, '2001-12-30', '0000-00-00 00:00:00');
/*!40000 ALTER TABLE `dancers` ENABLE KEYS */;


-- Dumping structure for table udf.dance_types
DROP TABLE IF EXISTS `dance_types`;
CREATE TABLE IF NOT EXISTS `dance_types` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `code` int(10) unsigned NOT NULL,
  `name` varchar(50) CHARACTER SET latin1 NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=37 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.dance_types: ~35 rows (approximately)
DELETE FROM `dance_types`;
/*!40000 ALTER TABLE `dance_types` DISABLE KEYS */;
INSERT INTO `dance_types` (`id`, `code`, `name`) VALUES
	(1, 1, 'Hip-hop'),
	(2, 2, 'Disco'),
	(3, 11, 'Belly-dance classic'),
	(4, 20, 'Street show'),
	(5, 30, 'Dance show'),
	(6, 50, 'Latin bit'),
	(7, 4, 'Techno'),
	(8, 6, 'Electric-bugi'),
	(9, 7, 'House'),
	(10, 8, 'Tecktonik'),
	(11, 9, 'Popping'),
	(12, 10, 'Cramp'),
	(13, 21, 'Wacking'),
	(14, 3, 'Disco-freestyle'),
	(15, 5, 'Break-dance'),
	(16, 12, 'Belly-dance folk'),
	(17, 13, 'Belly-dance show'),
	(18, 14, 'Tabla Belly-dance'),
	(19, 15, 'Fusion Belly-dance'),
	(21, 18, 'Belly-dance improvisation'),
	(22, 19, 'Fitnes Belly-dance'),
	(23, 22, 'Jazz-funk'),
	(24, 23, 'Disco show'),
	(25, 27, 'Aerobic'),
	(26, 28, 'Tweerling'),
	(27, 29, 'Majoretki'),
	(28, 31, 'Freestyle'),
	(29, 32, 'Synchronous dances'),
	(30, 33, 'Step'),
	(31, 34, 'Irish dances'),
	(32, 35, 'Nation dance'),
	(33, 36, 'Stylised nation dance'),
	(34, 37, 'Bollywood'),
	(35, 38, 'Flamenco'),
	(36, 40, 'Salsa');
/*!40000 ALTER TABLE `dance_types` ENABLE KEYS */;


-- Dumping structure for table udf.gender
DROP TABLE IF EXISTS `gender`;
CREATE TABLE IF NOT EXISTS `gender` (
  `id` tinyint(4) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.gender: ~2 rows (approximately)
DELETE FROM `gender`;
/*!40000 ALTER TABLE `gender` DISABLE KEYS */;
INSERT INTO `gender` (`id`, `name`) VALUES
	(9, 'M'),
	(10, 'W');
/*!40000 ALTER TABLE `gender` ENABLE KEYS */;


-- Dumping structure for table udf.judges
DROP TABLE IF EXISTS `judges`;
CREATE TABLE IF NOT EXISTS `judges` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `city` int(10) unsigned NOT NULL,
  `practicer` enum('Y','N') NOT NULL DEFAULT 'N',
  `attestation_info` text,
  `phone` varchar(20) DEFAULT NULL,
  `email` varchar(50) DEFAULT NULL,
  `additional_info` text,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.judges: ~5 rows (approximately)
DELETE FROM `judges`;
/*!40000 ALTER TABLE `judges` DISABLE KEYS */;
INSERT INTO `judges` (`id`, `name`, `city`, `practicer`, `attestation_info`, `phone`, `email`, `additional_info`) VALUES
	(1, 'Суддя 1', 1, 'Y', 'Test attestation inf1', '333', 'aa', '3333333'),
	(2, 'Суддя 2', 1, 'N', 'Test attestation inf1', 'телефон 2', 'пошта 2', 'Інфо 2'),
	(3, 'Суддя 3', 2, 'N', 'Test attestation inf1', 'тел 3', 'пошта 3', 'інформація 3'),
	(4, 'Суддя 4', 2, 'N', 'Test attestation inf1', NULL, NULL, NULL),
	(5, 'Суддя 5', 3, 'N', 'Test attestation inf1', 'телефон 5', 'почта 5', 'информация 5');
/*!40000 ALTER TABLE `judges` ENABLE KEYS */;


-- Dumping structure for table udf.judges_categories_have
DROP TABLE IF EXISTS `judges_categories_have`;
CREATE TABLE IF NOT EXISTS `judges_categories_have` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `judge_id` bigint(20) unsigned NOT NULL,
  `cat_id` int(10) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK__judges_categories_name` (`cat_id`),
  KEY `judge_id` (`judge_id`),
  CONSTRAINT `FK__judges` FOREIGN KEY (`judge_id`) REFERENCES `judges` (`id`),
  CONSTRAINT `FK__judges_categories_name` FOREIGN KEY (`cat_id`) REFERENCES `judges_categories_name` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.judges_categories_have: ~3 rows (approximately)
DELETE FROM `judges_categories_have`;
/*!40000 ALTER TABLE `judges_categories_have` DISABLE KEYS */;
INSERT INTO `judges_categories_have` (`id`, `judge_id`, `cat_id`) VALUES
	(1, 1, 3),
	(2, 1, 3),
	(3, 1, 3);
/*!40000 ALTER TABLE `judges_categories_have` ENABLE KEYS */;


-- Dumping structure for table udf.judges_categories_name
DROP TABLE IF EXISTS `judges_categories_name`;
CREATE TABLE IF NOT EXISTS `judges_categories_name` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.judges_categories_name: ~5 rows (approximately)
DELETE FROM `judges_categories_name`;
/*!40000 ALTER TABLE `judges_categories_name` DISABLE KEYS */;
INSERT INTO `judges_categories_name` (`id`, `name`) VALUES
	(3, 'Cart 1'),
	(4, 'osdfkl;sd '),
	(5, 'isdfj ksd'),
	(6, 'slfsdl sdfsd '),
	(7, ' sf dfs d');
/*!40000 ALTER TABLE `judges_categories_name` ENABLE KEYS */;


-- Dumping structure for table udf.liga
DROP TABLE IF EXISTS `liga`;
CREATE TABLE IF NOT EXISTS `liga` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `code` int(10) unsigned DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.liga: ~11 rows (approximately)
DELETE FROM `liga`;
/*!40000 ALTER TABLE `liga` DISABLE KEYS */;
INSERT INTO `liga` (`id`, `code`, `name`) VALUES
	(1, 4, 'Перші кроки'),
	(2, 9, 'Соло дебют'),
	(3, 0, 'Соло початок'),
	(4, 2, 'Соло 2 ліга'),
	(5, 1, 'Соло 1 ліга'),
	(6, 3, 'Соло вища ліга дівчата'),
	(7, 5, 'Соло вища ліга хлопці'),
	(8, 4, 'Дуети 2 ліга'),
	(9, 6, 'Дуети вища Ліга'),
	(10, 7, 'Мала група'),
	(11, 8, 'Формейшн');
/*!40000 ALTER TABLE `liga` ENABLE KEYS */;


-- Dumping structure for table udf.payment_history
DROP TABLE IF EXISTS `payment_history`;
CREATE TABLE IF NOT EXISTS `payment_history` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `person_id` bigint(20) unsigned NOT NULL,
  `type` enum('D','C','T','J') NOT NULL,
  `pay_date` date NOT NULL,
  `exp_date` date NOT NULL,
  `sum` float DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;

-- Dumping data for table udf.payment_history: ~9 rows (approximately)
DELETE FROM `payment_history`;
/*!40000 ALTER TABLE `payment_history` DISABLE KEYS */;
INSERT INTO `payment_history` (`id`, `person_id`, `type`, `pay_date`, `exp_date`, `sum`) VALUES
	(1, 3, 'C', '2012-03-12', '2013-03-12', 12),
	(2, 3, 'C', '2012-03-12', '2013-03-12', 14),
	(3, 3, 'C', '2012-03-12', '2013-03-12', 14.3),
	(4, 1, 'J', '2012-10-18', '2013-10-18', 12),
	(10, 5, 'J', '2006-10-18', '2007-10-18', 100),
	(11, 5, 'J', '2007-10-18', '2008-10-18', 120),
	(12, 5, 'J', '2008-10-18', '2009-10-18', 140),
	(13, 5, 'J', '2010-10-19', '2011-10-19', -1),
	(14, 5, 'J', '2009-10-18', '2010-10-18', 160);
/*!40000 ALTER TABLE `payment_history` ENABLE KEYS */;


-- Dumping structure for table udf.tour_types
DROP TABLE IF EXISTS `tour_types`;
CREATE TABLE IF NOT EXISTS `tour_types` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(40) DEFAULT NULL,
  `min` int(10) unsigned NOT NULL,
  `max` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.tour_types: ~7 rows (approximately)
DELETE FROM `tour_types`;
/*!40000 ALTER TABLE `tour_types` DISABLE KEYS */;
INSERT INTO `tour_types` (`id`, `name`, `min`, `max`) VALUES
	(1, 'Final', 1, 9),
	(2, '1/2', 10, 16),
	(3, '1/4', 17, 30),
	(4, '1/8', 31, 58),
	(5, '1/16', 59, 110),
	(6, '1/32', 111, 220),
	(7, '1/64', 221, 400);
/*!40000 ALTER TABLE `tour_types` ENABLE KEYS */;


-- Dumping structure for table udf.treners
DROP TABLE IF EXISTS `treners`;
CREATE TABLE IF NOT EXISTS `treners` (
  `id` bigint(20) unsigned NOT NULL AUTO_INCREMENT,
  `club_id` bigint(20) unsigned NOT NULL,
  `name` varchar(50) DEFAULT NULL,
  `bd` date DEFAULT NULL,
  `phone` varchar(30) DEFAULT NULL,
  `contact_info` varchar(150) DEFAULT NULL,
  `email` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_treners_clubs` (`club_id`),
  CONSTRAINT `FK_treners_clubs` FOREIGN KEY (`club_id`) REFERENCES `clubs` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

-- Dumping data for table udf.treners: ~4 rows (approximately)
DELETE FROM `treners`;
/*!40000 ALTER TABLE `treners` DISABLE KEYS */;
INSERT INTO `treners` (`id`, `club_id`, `name`, `bd`, `phone`, `contact_info`, `email`) VALUES
	(3, 3, 'Тренер 1', '2001-12-30', '+380674391881', 'інфо 1', 'пошта 1'),
	(4, 2, 'Тренер 1', '1970-01-01', 'телефон 1', 'інфо 1', 'пошта 1'),
	(5, 2, 'Тренер 2', '1970-12-30', 'телефон 2', 'інфо 2', 'пошта 2'),
	(6, 2, 'Test name1', '0000-00-00', 'Test ph1', 'Test contactinfo1', 'Test em1');
/*!40000 ALTER TABLE `treners` ENABLE KEYS */;
/*!40014 SET FOREIGN_KEY_CHECKS=1 */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
