#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define RED     "\x1b[31m"
#define ORANGE  "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define GREEN   "\x1b[32m"
#define BLUE    "\x1b[34m"
#define INDIGO  "\x1b[95m"
#define VIOLET  "\x1b[35m"
#define COLOR_RESET   "\x1b[0m"

int main() {
    struct dirent *files;
    char COLORS[7][10] = {
                         RED,
                         ORANGE,
                         YELLOW,
                         GREEN,
                         BLUE,
                         INDIGO,
                         VIOLET
                     };
    DIR *dir = opendir("./");
    int num_colors = 7;
    int count = 0;

    if (dir == NULL) {
        fprintf(stderr, "Directory cannot be opened.");
        return 0;
    }

    while ((files = readdir(dir)) != NULL) {
        /*no padding for first file*/
        /*print out each letter of the string in rainbow*/
        auto int len = strlen(files->d_name);
        for (int i=0; i<len; i++) {
            printf("%s%c%s",COLORS[(i) % (num_colors - 1)],files->d_name[i],COLOR_RESET);
        }
        printf("    ");
        count = count + 1;
    }
    printf("\n");
    closedir(dir);
    return 0;
}
