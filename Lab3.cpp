#include <getopt.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    const char *help_options = "Usage:\n"
                           "[-p[<int value>, ...]],[--print=[<int value>, ...]]    - Print array of values\n"
                           "[-v],[--version],                                      - Current version of program\n"
                           "[-h],[--help]                                          - Help for program\n";
    const char *version = "1.0.0";
    const char *optionStrings = "hvp:";
    struct option longopts[] = {
        {"print", required_argument, 0, 'p'},
        {"version", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0},
    };
    bool h, v, p = false;
    int longindex, opt;
    while ((opt = getopt_long(argc, argv, optionStrings, longopts, &longindex)) != -1)
    {
        switch (opt)
        {
            case 'h':
            {
                if (!h)
                {
                    h = true;
                    printf("%s\n", help_options);
                }
                break;
            }
            case 'p':
            {
                if (!p)
                {
                    char *args;
                    printf("List of options:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL)
                    {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    p = true;
                }
                break;
            }
            case 'v':
            {
                if (!v)
                {
                    v = true;
                    printf("Current version: %s\n", version);
                }
                break;
            }
            default:
            {
                printf("Received unknown option\n");
            }
        }
    }
    return 0;
}