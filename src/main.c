#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "constants.h"

int main() {
  // Setting contacts location based on operating system
  if (isWindows) {
    strcpy(filePath, "C:\\kinky-contacts.csv");
    strcpy(tempFilePath, "C:\\kinky-contacts.csv.bak");
  } else {
    sprintf(filePath, "%s/kinky-contacts.csv", getenv("HOME"));
    sprintf(tempFilePath, "%s/kinky-contacts.csv.bak", getenv("HOME"));
  }

  handleMenu();
  return 0;
}
