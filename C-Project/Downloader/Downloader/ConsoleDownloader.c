#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 512

int FileDownload(char *url , char *filename){
	char url[MAX_LINE] = url;
	char destination[MAX_LINE] = filename;
	char buffer[MAX_LINE];

	HRESULT    dl;

	typedef HRESULT(WINAPI * URLDownloadToFileA_t)(LPUNKNOWN pCaller, LPCSTR szURL, LPCSTR szFileName, DWORD dwReserved, void * lpfnCB);
	URLDownloadToFileA_t xURLDownloadToFileA;
	xURLDownloadToFileA = (URLDownloadToFileA_t)GetProcAddress(LoadLibraryA("urlmon"), "URLDownloadToFileA");

	dl = xURLDownloadToFileA(NULL, url, destination, 0, NULL);

	sprintf(buffer, "Downloading File From: %s, To: %s", url, destination);

	if (dl == S_OK)
	{
		sprintf(buffer, "File Successfully Downloaded To: %s", destination);
		printf(buffer);
	}
	else if (dl == E_OUTOFMEMORY)
	{
		sprintf(buffer, "Failed To Download File Reason: Insufficient Memory");
		printf(buffer);
		return 0;
	}
	else
	{
		sprintf(buffer, "Failed To Download File Reason: Unknown");
		printf(buffer);
		return 0;
	}
}

typedef struct UrlData{

	char *url;
	char *name;

}URLDATA;

void printUsage(){
	printf("Example usage : \n");
	printf("\tjin list\n");
	printf("\tjin info\n");
	printf("\tjin update\n");
	printf("\tjin download [name]\n");
}
int main(){

	puts("        ....                               +.");
	puts("     =@@#**%@                        +@   .%=");
	puts("    .@+                              +@");
	puts("     %@+         %@#*%@:             +@   .@=  .@*##*%@*");
	puts("      .*@@#:    @+    :@:            +@   .@:   @#    .@=");
	puts("          =@@  *@#%%%%#%= .%%%%%.    =@   .@:   @=     @+");
	puts("            @+ :@:                   #@   .@:   @=     @+");
	puts("    :@%***#@*   =@%+=+##         .#*%@.   .@=  .@=     @+");
	puts("      .:::         :::            ::       .    .      .");
	puts("============================================================");

	char command[100];
	char *jin = "0", *cmd = "0", *name = "0";

	for (;;){

		gets(command);

		if (command[0] != '\0'){
			jin = strtok(command, " ");
			cmd = strtok(NULL, " ");
			name = strtok(NULL, " ");
		}

		if (strcmp(jin, "jin") != 0 && strcmp(jin, "\n") != 0){
			printUsage();
			printf("\tERROR: UnKnown command : %s \n", jin);
		}

		if (strcmp(jin, "jin") == 0){

			if (strcmp(cmd, "-download") == 0)
			{
				if (strcmp(name, "") == 0){}
			}


			if (strcmp(cmd, "-list") == 0)
			{

			}


			if (strcmp(cmd, "-info") == 0)
			{
				puts("Made by Sejin");
			}

			if (strcmp(cmd, "-update") == 0)
			{
				puts("Made by Sejin");
			}




		}// if jin

	}// for

}//main