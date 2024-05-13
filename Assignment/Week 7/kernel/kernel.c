#include "../uart/uart1.h"
#include "mbox.h"
#include "framebf.h"
#include "pic.h"

void display(int stop)
{
    int index = (stop-50) * 800 + 1;
    int xFrame = 0;
        for (int x = (stop-50); x < stop; x++)
        {
            xFrame++;
            for (int y = 0; y < 800; y++)
                {
                    drawPixelARGB32(y,xFrame,pic[index]);
                    index++;
                    // uart_hex(temp[x,y]);
                    // uart_sendc('\n');
                }
                    // uart_sendc('\n');
}
}

void main()
{
    // set up serial console
    uart_init();
    // say hello
    uart_puts("\n\nHello World!\n");
    // Initialize frame buffer
    framebf_init();
    // Draw something on the screen
    //drawRectARGB32(100,100,400,400,0x00AA0000,1); //RED
    //drawRectARGB32(100,100,400,400, 0x002a2a2a,1); //RED
    //drawRectARGB32(110,110,390,390,0x0000BB00,0); //GREEN
    //drawRectARGB32(200,200,400,400,0x000000CC,1); //BLUE
    //drawRectARGB32(250,250,400,400,0x00FFFF00,1); //YELLOW
    //drawPixelARGB32(300, 300, 0x00FF0000); //RED
    int index = 0;
    int stop = 50;
    display(stop);
    while(1)
    {
        char c = uart_getc();
	    uart_sendc(c);

        if(c == 's')
        {
            

                drawRectARGB32(0,0,800,526,0x000000,1);
                if(stop > 476)
                {
                    stop = 476;
                }
                else
                {
                    stop +=50;
                }
                display(stop);


        }
        else if(c == 'w')
        {
            drawRectARGB32(0,0,800,526,0x000000,1);
                if(stop < 50)
                {
                    stop = 50;
                }
                else
                {
                    stop -=50;
                }
            display(stop);
        }
    }

}
