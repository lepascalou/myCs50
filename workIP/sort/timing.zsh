#!/bin/zsh

# Chemin vers le répertoire contenant les programmes et les fichiers texte
directory="./sort"

# Fichier de sortie pour enregistrer les résultats de time
output_file="timing_results.txt"

# Supprimer le fichier de sortie s'il existe déjà
if [[ -f $output_file ]]; then
    rm $output_file
fi

# Tableaux pour les programmes et les fichiers texte
programs=("sort1" "sort2" "sort3")
text_files=("random5000.txt" "random10000.txt" "random50000.txt" "reversed5000.txt" "reversed10000.txt" "reversed50000.txt" "sorted5000.txt" "sorted10000.txt" "sorted50000.txt")

# Boucle sur chaque programme et chaque fichier texte
for program in $programs; do
    echo "Running $program with $text_file" >> $output_file
    for text_file in $text_files; do
        # Exécuter le programme avec time et rediriger la sortie de time vers le fichier
        { /usr/bin/time -p $directory/$program $directory/$text_file &>/dev/null; } 2>> $output_file
        # Ajouter une ligne vide pour séparer les résultats
        echo "" >> $output_file
    done
done

echo "Les résultats de time ont été enregistrés dans $output_file"
