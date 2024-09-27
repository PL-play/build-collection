//
// Created by ran on 2024/6/27.
// help from ChatGPT :)
//
#include "hashtable/sha256.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "rb");
  if (!file) {
    perror("File opening failed");
    return 1;
  }

  SHA256_CTX ctx;
  sha256_init(&ctx);

  uint8_t buffer[4096];
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) != 0)
    sha256_update(&ctx, buffer, bytes_read);

  uint8_t hash[32];
  sha256_final(&ctx, hash);

  printf("SHA-256 hash: ");

  print_hash(hash, sizeof(hash));

  char s[65];
  stringify_hash(hash, sizeof(hash), s);

  uint8_t hash1[32];
  sha256_file(file,hash1);
  char s1[65];
  stringify_hash(hash, sizeof(hash1), s1);
  printf("hash string1 : %s\n", s1);
  fclose(file);

  printf("hash string : %s\n", s);
  return 0;
}
