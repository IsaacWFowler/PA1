#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	char str1[100];
	printf("Enter URL:");
	scanf("%s", str1);
	
	char *protocol = strtok(str1, "://");
	char *domainAndPort = strtok(NULL, "/");
	char *filePath = strtok(NULL, "?");
	char *parameters = strtok(NULL, "");
	char str2[100];
	strcpy(str2, domainAndPort);
	char *domainWeb = strtok(str2, ":");
	char *port = strtok(NULL, "");
	char str3[100];
	strcpy(str3, filePath);
	char *filePathH = strtok(str3, ".");
	char *filePathT = strtok(NULL, "");	
	strcpy(str2, domainWeb);
	char *domainX = strtok(str2, ".");
	char *domainY = strtok(NULL, ".");
	char *domainZ = strtok(NULL, "");
	
	int errorTracker = 0;
	if(strcmp(protocol, "http") != 0 && strcmp(protocol, "https") != 0 && strcmp(protocol, "ftp") != 0 && strcmp(protocol, "ftps") != 0){
		errorTracker +=8;
}
	if(strcmp(domainZ, "com") != 0 && strcmp(domainZ, "net") != 0 && strcmp(domainZ, "edu") != 0 && strcmp(domainZ, "biz") != 0 && strcmp(domainZ, "gov") != 0){
		errorTracker +=4;
}
	if(port != NULL){
		if(atoi(port) < 1 || atoi(port) > 65535){
			errorTracker +=2;
		}
	}
	if(strcmp(filePathT, "html") != 0 && strcmp(filePathT, "htm") != 0){
		errorTracker +=1;
}

	//All error have been checked
	if(errorTracker > 0){
		printf("Invalid URL with the following erroneous components:\n");
		if(errorTracker > 7){
			printf("Protocol:\t%s is not a valid protocol.\n", protocol);	
			errorTracker -=8;	
		}
		if(errorTracker > 3){
			printf("Domain:\t%s is not a valid domain name.\n", domainZ);
			errorTracker -=4;
		}
		if(errorTracker > 1){
			printf("Port:\tport number must be between 1 and 65535\n");
			errorTracker -=2;
		}
		if(errorTracker > 0){
			printf("File path:\t%s is an invalid end to file path.\n", filePathT);
		}
	}
	else{
		printf("Protocol:\t%s\n", protocol);
		printf("Domain:\t\t%s.", domainX);
		printf("%s.", domainY);
		printf("%s\n", domainZ);
		printf("Port:\t\t%s\n", port);
		printf("File path:\t/%s", filePathH);
		printf(".%s\n", filePathT);
		printf("Parameters:\t%s\n", parameters);

	}
	return 0;
}
