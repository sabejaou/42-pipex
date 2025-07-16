# Pipex

Pipex est un projet du cursus 42 qui reproduit le comportement des pipes Unix (`|`) en C. Il permet d'exécuter des commandes en chaîne en redirigeant la sortie d'une commande vers l'entrée de la suivante, avec support pour les fichiers d'entrée et de sortie.

## Sommaire
- [Fonctionnalités](#fonctionnalités)
- [Arborescence](#arborescence)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Version Bonus](#version-bonus)
- [Exemples](#exemples)
- [Auteur](#auteur)

---

## Fonctionnalités
- Reproduction du comportement des pipes Unix
- Gestion des fichiers d'entrée et de sortie
- Support pour les commandes avec arguments
- Recherche automatique des commandes dans le PATH
- Gestion des erreurs et messages d'erreur appropriés
- Version bonus avec support pour here_doc et pipes multiples

---

## Arborescence

```
42-pipex/
├── includes/
│   ├── pipex.h
│   └── pipex_bonus.h
├── src/
│   ├── core/
│   │   ├── main.c
│   │   ├── parsing.c
│   │   └── pathing.c
│   └── bonus/
│       ├── main_bonus.c
│       ├── parsing_bonus.c
│       ├── pathing_bonus.c
│       ├── get_next_line.c
│       ├── get_next_line_utils.c
│       └── get_next_line.h
├── libft/
│   ├── libft.h
│   └── [tous les fichiers libft]
├── obj/
├── Makefile
└── README.md
```

---

## Installation

1. **Cloner le dépôt**  
   ```sh
   git clone https://github.com/sabejaou/42-pipex.git
   cd 42-pipex
   ```

2. **Compiler le projet**  
   ```sh
   # Version normale
   make
   
   # Version bonus
   make bonus
   
   # Compiler les deux versions
   make all bonus
   ```

---

## Utilisation

### Version Normale
```sh
./pipex file1 cmd1 cmd2 file2
```

**Paramètres :**
- `file1` : fichier d'entrée
- `cmd1` : première commande à exécuter
- `cmd2` : deuxième commande à exécuter
- `file2` : fichier de sortie

**Comportement :**
- Lit depuis `file1`
- Exécute `cmd1` avec l'entrée de `file1`
- Redirige la sortie de `cmd1` vers `cmd2`
- Écrit le résultat dans `file2`

### Version Bonus
```sh
./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2
```

**Fonctionnalités bonus :**
- Support pour un nombre variable de commandes
- Support pour here_doc : `./pipex_bonus here_doc LIMITER cmd1 cmd2 file`
- Gestion des pipes multiples

---

## Exemples

### Version Normale
```sh
# Compter les lignes d'un fichier et trier le résultat
./pipex input.txt "wc -l" "sort" output.txt

# Chercher un pattern et compter les occurrences
./pipex input.txt "grep 'pattern'" "wc -w" result.txt
```

### Version Bonus
```sh
# Multiple pipes
./pipex_bonus input.txt "cat" "grep 'test'" "wc -l" output.txt

# Here_doc
./pipex_bonus here_doc "EOF" "cat" "sort" output.txt
# Puis taper du texte et terminer par "EOF"
```

---

## Auteur

- **Sabejaou**  
  [sabejaou@student.42lyon.fr](mailto:sabejaou@student.42lyon.fr)