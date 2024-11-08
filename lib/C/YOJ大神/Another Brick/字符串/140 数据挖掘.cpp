#include <stdio.h>

int main() {
    char intro[200];
    char major[100];
    int birthYear;

    // Assuming the input is taken from the user
    fgets(intro, sizeof(intro), stdin);
    int i=0;
    while(intro[i]!=EOF) i++;
    
    // Extracting the birth year and major from the introduction
    sscanf(intro, "My name is %*[^,], born in %d, from %*[^.]. My major is %[^.].", &birthYear, major);

    printf("%d, %s\n", birthYear, major);

    printf("%d",i);
    return 0;
}