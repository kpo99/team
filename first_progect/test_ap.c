#include <stdio.h>
#include <conio.h>     
#include <locale.h>
#include <stdlib.h>

#define MAX_SPEED_FIRST 20

int main()
{
    setlocale(LC_ALL,"rus");
    char command;
    char com[10];
 
   int i=0;
        while(1)
        {
            command = getch();
            com[0] = command;
            
            switch (command) {
                case 'w':
                        i++;
                        printf("%i ", i);
                    break;
                    
                case 's':
                    i--;
                    printf("%i ", i);
                    break;
                    
                default:
                    break;
            }
        }
    
    
    return EXIT_SUCCESS;
}
