#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFSIZE 512
typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    int jpeg_counter = 0;
    char name[8];
    BYTE *buffer = malloc(512 * (sizeof(BYTE)));
    if (argc != 2)
    {
        printf("ERROR NOT CORRECT USAGE. EXITING..\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("ERROR OPENING IN FILE. EXITING..\n");
        return 1;
    }
    sprintf(name, "%03i.jpg", jpeg_counter);
    FILE *fp = NULL;
    while (fread(buffer, 512, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (jpeg_counter == 0)
            {
                sprintf(name, "%03i.jpg", jpeg_counter);
                fp = fopen(name, "w");
                fwrite(buffer, 512, 1, fp);
                jpeg_counter++;
            }
            else
            {
                fclose(fp);
                sprintf(name, "%03i.jpg", jpeg_counter);
                fp = fopen(name, "w");
                jpeg_counter++;
                fwrite(buffer, 512, 1, fp);
            }
        }
        else if (fp != NULL)
        {
            fwrite(buffer, 512, 1, fp);
        }
    }
    fclose(file);
    fclose(fp);
    free(buffer);
}
