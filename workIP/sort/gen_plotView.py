import pandas as pd
import matplotlib.pyplot as plt

# Lire les données depuis le fichier
file_path = "timing_results.txt"
with open(file_path, "r") as file:
    lines = file.readlines()

# Initialiser des listes pour stocker les données
programs = []
file_types = []
file_sizes = []
real_times = []
user_times = []
sys_times = []

# Analyser le contenu du fichier
current_program = None
current_file = None

for line in lines:
    if "Results for" in line:
        parts = line.split()
        current_program = parts[2]
        current_file = parts[4]
        file_size = "".join(filter(str.isdigit, current_file))
        file_type = "".join(filter(str.isalpha, current_file))
    elif "real" in line:
        real_times.append(float(line.split()[1]))
    elif "user" in line:
        user_times.append(float(line.split()[1]))
    elif "sys" in line:
        sys_times.append(float(line.split()[1]))
        programs.append(current_program)
        file_types.append(file_type)
        file_sizes.append(int(file_size))

# Créer un DataFrame
df = pd.DataFrame(
    {
        "Program": programs,
        "File Type": file_types,
        "File Size": file_sizes,
        "Real Time (s)": real_times,
        "User Time (s)": user_times,
        "Sys Time (s)": sys_times,
    }
)

# Calculer le temps réel moyen pour chaque programme et taille de fichier
mean_times = df.groupby(["File Size", "Program"])["Real Time (s)"].mean().unstack()

# Tracer les données
plt.figure(figsize=(12, 6))

# Tracer chaque programme
mean_times.plot(kind="bar", width=0.2, ax=plt.gca())

# Ajouter des étiquettes et un titre
plt.xlabel("File Size")
plt.ylabel("Mean Real Time (s)")
plt.title("Mean Execution Time of Sorting Algorithms")
plt.xticks(rotation=0)
plt.legend(title="Program")
plt.tight_layout()

# Afficher le graphique
plt.show()
