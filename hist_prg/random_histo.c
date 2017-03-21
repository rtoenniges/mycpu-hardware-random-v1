#include <mycpu.h>
#include <mycpugfx.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//unsigned char *random;

unsigned char zahlen[256];
unsigned char *random;

int main(int argc, char* argv[])
{
    if (argc <= 1) {
		printf("Show a histogram.\n");
		printf("Syntax: random_histo [address]\n");
        printf("Example: random_histo 3000\n");
		
		return 0;
	}
    
    sscanf(argv[1], "%x", &random);

    gfx_setmode(GM_640X400M, 0);
    gfx_clear(0, 0);  
    gfx_setbgcolor(0);
    gfx_setcolor(15);
    gfx_text(170, 10, 2, 1, "Random histogram");
    gfx_text(200, 390, 1, 1, "Press any key to close...");
    gfx_text(50, 386, 1, 1, "0");
    gfx_text(566, 386, 1, 1, "255"); //X
    gfx_text(30, 122, 1, 1, "255"); //Y
    gfx_line(43, 381, 590, 381); //X
    gfx_line(62, 400, 62, 115); //Y
    
    while(!kbhit())
    {
        unsigned char zufall = *random;
        zahlen[zufall]++;
        if (zahlen[zufall] == 255) {
            break;
        }
        gfx_putpixel(64+zufall*2, 380-zahlen[zufall] , 15);
    }

    
    while(!kbhit())
    {
        ;
    }
    gfx_cleanup();
    
    return 0;
}

