-- --------------------------------------------------------
-- Host:                         localhost
-- Server version:               10.4.11-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             9.4.0.5125
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Dumping database structure for kiosk
CREATE DATABASE IF NOT EXISTS `kiosk` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `kiosk`;

-- Dumping structure for table kiosk.items
CREATE TABLE IF NOT EXISTS `items` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `code` varchar(50) DEFAULT NULL,
  `name` varchar(50) DEFAULT NULL,
  `is_available` int(11) DEFAULT 1,
  `price` float(10,2) DEFAULT 0.00,
  `type` int(11) DEFAULT 1,
  PRIMARY KEY (`id`),
  UNIQUE KEY `code` (`code`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table kiosk.items: ~5 rows (approximately)
/*!40000 ALTER TABLE `items` DISABLE KEYS */;
INSERT INTO `items` (`id`, `code`, `name`, `is_available`, `price`, `type`) VALUES
	(1, 'F01', 'NASI GORENG MAMAK', 1, 5.50, 1),
	(2, 'F02', 'NASI GORENG KAMPUNG', 1, 6.00, 1),
	(3, 'D01', 'AIR KOSONG', 1, 0.30, 2),
	(4, 'D02', 'MILO AIS', 1, 2.50, 1),
	(5, 'D03', 'MILO PANAS', 1, 2.00, 1);
/*!40000 ALTER TABLE `items` ENABLE KEYS */;

-- Dumping structure for table kiosk.orders
CREATE TABLE IF NOT EXISTS `orders` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `price` float(10,2) DEFAULT 0.00,
  `status` int(11) DEFAULT 1,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table kiosk.orders: ~3 rows (approximately)
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` (`id`, `price`, `status`) VALUES
	(1, 6.00, 1),
	(2, 2.00, 1),
	(3, 8.00, 1);
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;

-- Dumping structure for table kiosk.order_items
CREATE TABLE IF NOT EXISTS `order_items` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `order_id` int(11) DEFAULT NULL,
  `item_id` int(11) DEFAULT NULL,
  `price` float(10,2) DEFAULT 0.00,
  `notes` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4;

-- Dumping data for table kiosk.order_items: ~6 rows (approximately)
/*!40000 ALTER TABLE `order_items` DISABLE KEYS */;
INSERT INTO `order_items` (`id`, `order_id`, `item_id`, `price`, `notes`) VALUES
	(1, 0, 1, 5.50, 'EX NOTES'),
	(2, 0, 2, 6.00, 'EX NOTES'),
	(3, 2, 1, 5.50, 'EX NOTES'),
	(4, 2, 5, 2.00, 'EX NOTES'),
	(5, 3, 2, 6.00, 'EX NOTES'),
	(6, 3, 5, 2.00, 'EX NOTES');
/*!40000 ALTER TABLE `order_items` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
