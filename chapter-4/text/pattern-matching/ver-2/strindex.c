// Find the first match of a given pattern within a text.
int strindex(char text[], char pattern[]) {
    int i, j, k;
    for (i = 0; text[i] != '\0'; i++) {
        for (j = i, k = 0; pattern[k] != '\0' && text[j] == pattern[k]; j++, k++);
        if (k > 0 && pattern[k] == '\0') {
            return i;
        }
    }
    return -1;
}
