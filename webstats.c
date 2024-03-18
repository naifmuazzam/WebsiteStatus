#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	    // ANSI escape code for blue color
    printf("\033[0;34m"); 
    
    // Printing the text in blue color
    printf("Hello, WebStats!\n");
    
    // Resetting color to default
    printf("\033[0m"); 
    
	 char site[100];

	// Check Internet Connection
	if(system("ping -c 2 www.google.com > /dev/null 2>&1") == 0) {
		printf("Internet Working\n\n");
	} else {
		printf("No Internet Connection\n\n");
	return 0;
	}

	// Prompt user to enter the website
	printf("Enter website: ");
	scanf("%s", site);

   	 // Construct the ping command
    	char ping_command[150];
    	sprintf(ping_command, "ping -c 1 %s", site);

    	// Execute the ping command and capture output
    	FILE *ping_output = popen(ping_command, "r");
    	if (ping_output == NULL) {
    		printf("Error executing ping command.\n");
    		return 1;
    	}

	// Read the output of ping commands
	char buffer[256];
	double response_time = -1;  // Initialize response time to a negative value
	while (fgets(buffer, sizeof(buffer), ping_output) != NULL) {
		// Search for response time in the output
		char *token = strstr(buffer, "time=");
		if (token != NULL) {
		sscanf(token + 5, "%lf", &response_time); // Extract response time
		break;
		}
	}
	// Close the ping output stream
	pclose(ping_output);

    	// Check the response time and display the result
    	if (response_time >=  0) {
        	printf("Website %s is UP. Response time: %.2f ms\n\n", site, response_time);
    	}
	 else {
        	printf("Website %s is DOWN.\n\n", site);
    	}

return 0;
}
