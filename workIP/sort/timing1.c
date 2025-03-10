
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void run_timing(const char *program, const char *file, FILE *output_file) {
  int pipe_fd[2];
  if (pipe(pipe_fd) == -1) {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  pid_t pid = fork();

  if (pid == 0) {
    // Rediriger stderr vers le tube
    dup2(pipe_fd[1], STDERR_FILENO);
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    // Fermer la sortie standard pour ignorer la sortie du programme
    freopen("/dev/null", "w", stdout);

    // Exécuter la commande time avec le programme et le fichier
    execl("/usr/bin/time", "time", "-p", program, file, (char *)NULL);

    // Si execl échoue
    perror("execl");
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    // Erreur de fork
    perror("fork");
    exit(EXIT_FAILURE);
  } else {
    // Fermer l'extrémité d'écriture du tube dans le parent
    close(pipe_fd[1]);

    // Lire la sortie de time depuis le tube
    char buffer[128];
    ssize_t bytes_read;
    while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1)) > 0) {
      buffer[bytes_read] = '\0';
      fprintf(output_file, "%s", buffer);
    }

    close(pipe_fd[0]);

    // Attendre la fin du processus enfant
    int status;
    waitpid(pid, &status, 0);
  }
}

int main() {
  const char *directory = "./sort";
  const char *output_filename = "timing_results.txt";

  // Ouvrir le fichier de sortie
  FILE *output_file = fopen(output_filename, "w");
  if (!output_file) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Liste des programmes et des fichiers texte
  const char *programs[] = {"sort1", "sort2", "sort3"};
  const char *text_files[] = {
      "random5000.txt",   "random10000.txt",   "random50000.txt",
      "reversed5000.txt", "reversed10000.txt", "reversed50000.txt",
      "sorted5000.txt",   "sorted10000.txt",   "sorted50000.txt"};

  // Boucle sur chaque programme et chaque fichier texte
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 9; j++) {
      char program_path[256];
      char file_path[256];
      snprintf(program_path, sizeof(program_path), "%s/%s", directory,
               programs[i]);
      snprintf(file_path, sizeof(file_path), "%s/%s", directory, text_files[j]);

      fprintf(output_file, "Results for %s with %s:\n", programs[i],
              text_files[j]);
      run_timing(program_path, file_path, output_file);
      fprintf(output_file, "\n");
    }
  }

  // Fermer le fichier de sortie
  fclose(output_file);

  printf("Les résultats de time ont été enregistrés dans %s\n",
         output_filename);
  return 0;
}
