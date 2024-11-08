#include <stdio.h>

int main() {
    char intro[200];
    char major[100];
    int birthYear;

    fgets(intro, sizeof(intro), stdin);

    sscanf(intro, "My name is %*[^,], born in %d, from %*[^.]. My major is %[^.].", &birthYear, major);

    printf("%d, %s\n", birthYear, major);

    return 0;
}
