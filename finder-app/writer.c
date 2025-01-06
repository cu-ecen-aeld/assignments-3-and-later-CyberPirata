#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);


    if (argc != 3) {
        syslog(LOG_ERR, "Error: Two arguments are required.");
        syslog(LOG_ERR, "Usage: %s <file> <string>", argv[0]);
        closelog();
        exit(1);
    }

    const char *file = argv[1];
    const char *string = argv[2];


    FILE *fp = fopen(file, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error: Failed to open file %s for writing.", file);
        closelog();
        exit(1);
    }


    fprintf(fp, "%s", string);
    fclose(fp);


    syslog(LOG_DEBUG, "Writing %s to %s", string, file);


    closelog();

    return 0;
}
