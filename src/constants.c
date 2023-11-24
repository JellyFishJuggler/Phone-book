// check if operating system is Windows
#ifdef _WIN32
int isWindows = 1;
#else
int isWindows = 0;
#endif

const char *pass = "abcd";
const char menuOptions[][50] = {
  "List Contacts",
  "Add a Contact",
  "Edit a Contact",
  "Remove Contact",
  "Quit"
};
const int menuOptionCount = sizeof(menuOptions)/sizeof(menuOptions[0]);
char filePath[200];
char tempFilePath[200];
