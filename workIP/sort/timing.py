
import subprocess

# Chemin vers le répertoire contenant les programmes et les fichiers texte
directory = "./sort"

# Fichier de sortie pour enregistrer les résultats de time
output_file = "timing_results.txt"

# Supprimer le fichier de sortie s'il existe déjà
open(output_file, 'w').close()

# Liste des programmes et des fichiers texte
programs = ["sort1", "sort2", "sort3"]
text_files = [
    "random5000.txt", "random10000.txt", "random50000.txt",
    "reversed5000.txt", "reversed10000.txt", "reversed50000.txt",
    "sorted5000.txt", "sorted10000.txt", "sorted50000.txt"
]

# Boucle sur chaque programme et chaque fichier texte
for program in programs:
    for text_file in text_files:
        # Construire la commande à exécuter
        command = ["/usr/bin/time", "-p", f"{directory}/{program}", f"{directory}/{text_file}"]

        # Exécuter la commande et capturer la sortie d'erreur (où time écrit ses résultats)
        result = subprocess.run(command, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, text=True)

        # Écrire les résultats dans le fichier de sortie
        with open(output_file, 'a') as f:
            f.write(f"Results for {program} with {text_file}:\n")
            f.write(result.stderr)
            f.write("\n")

print(f"Les résultats de time ont été enregistrés dans {output_file}")
