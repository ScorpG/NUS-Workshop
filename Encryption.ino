
#include <stdio.h>

void caesarEncrypt(char* message, int shift) {
  char ch;
  int i;

  for (i = 0; message[i] != '\0'; i++) {
    ch = message[i];

    if (ch >= 'A' && ch <= 'Z') {
      ch = ((ch - 'A' + shift) % 26) + 'A'; // Encrypt uppercase letters
    } else if (ch >= 'a' && ch <= 'z') {
      ch = ((ch - 'a' + shift) % 26) + 'a'; // Encrypt lowercase letters
    }

    message[i] = ch;
  }
}

int main() {
  char message[100];
  int shift;

  printf("Enter a message: ");
  fgets(message, sizeof(message), stdin);

  printf("Enter the shift value: ");
  scanf("%d", &shift);

  caesarEncrypt(message, shift);

  printf("Encrypted message: %s\n", message);

  return 0;
}