-- phpMyAdmin SQL Dump
-- version 4.9.5deb2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : jeu. 06 août 2020 à 12:26
-- Version du serveur :  8.0.20-0ubuntu0.20.04.1
-- Version de PHP : 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `parking`
--

-- --------------------------------------------------------

--
-- Structure de la table `client`
--

CREATE TABLE `client` (
  `id_client` int NOT NULL,
  `nom_cli` varchar(255) NOT NULL,
  `prenom_cli` varchar(255) NOT NULL,
  `numero_cli` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Structure de la table `jour`
--

CREATE TABLE `jour` (
  `id_jour` int NOT NULL,
  `date` date NOT NULL,
  `somme` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Structure de la table `ocp`
--

CREATE TABLE `ocp` (
  `id_ocp` int NOT NULL,
  `id_clio` int NOT NULL,
  `id_placeo` int NOT NULL,
  `montant` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Structure de la table `place`
--

CREATE TABLE `place` (
  `id_place` int NOT NULL,
  `numero` int NOT NULL,
  `type` varchar(255) NOT NULL,
  `libre` int NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- --------------------------------------------------------

--
-- Structure de la table `utilisateur`
--

CREATE TABLE `utilisateur` (
  `id_utilisateur` int NOT NULL,
  `nom` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `numero` varchar(255) NOT NULL,
  `loging` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Déchargement des données de la table `utilisateur`
--

INSERT INTO `utilisateur` (`id_utilisateur`, `nom`, `prenom`, `numero`, `loging`, `password`) VALUES
(1, 'kouame', 'konan ghislain', '555', 'gigi', '1111');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `client`
--
ALTER TABLE `client`
  ADD PRIMARY KEY (`id_client`);

--
-- Index pour la table `jour`
--
ALTER TABLE `jour`
  ADD PRIMARY KEY (`id_jour`);

--
-- Index pour la table `ocp`
--
ALTER TABLE `ocp`
  ADD PRIMARY KEY (`id_ocp`);

--
-- Index pour la table `place`
--
ALTER TABLE `place`
  ADD PRIMARY KEY (`id_place`);

--
-- Index pour la table `utilisateur`
--
ALTER TABLE `utilisateur`
  ADD PRIMARY KEY (`id_utilisateur`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `client`
--
ALTER TABLE `client`
  MODIFY `id_client` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `jour`
--
ALTER TABLE `jour`
  MODIFY `id_jour` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `ocp`
--
ALTER TABLE `ocp`
  MODIFY `id_ocp` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `place`
--
ALTER TABLE `place`
  MODIFY `id_place` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `utilisateur`
--
ALTER TABLE `utilisateur`
  MODIFY `id_utilisateur` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
