-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le :  ven. 26 juin 2020 à 11:09
-- Version du serveur :  5.7.30-0ubuntu0.18.04.1
-- Version de PHP :  7.2.24-0ubuntu0.18.04.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `annuaire`
--

-- --------------------------------------------------------

--
-- Structure de la table `personne`
--

CREATE TABLE `personne` (
  `id` int(255) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `contact` varchar(255) NOT NULL,
  `adresse` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `genre` varchar(25) NOT NULL,
  `date` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `personne`
--

INSERT INTO `personne` (`id`, `nom`, `prenom`, `contact`, `adresse`, `email`, `genre`, `date`) VALUES
(27, 'vanie', 'small vi', '66562', 'cocody', 'van@gmail.com', 'ami(e)', '2020-06-24 17:46:00'),
(28, 'kk', 'jjy', 'ih', 'jgu', 'uygy', 'ami(e)', '2020-06-24 17:50:27'),
(29, 'yh', 'h', 'b', 'b', 'l', 'famille', 'job'),
(30, 'kjhj', 'hjguih', 'ijlugyuf', 'iuhgugu', 'uguyff', 'job', '2020-06-24 17:54:35');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `personne`
--
ALTER TABLE `personne`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `personne`
--
ALTER TABLE `personne`
  MODIFY `id` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=31;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
