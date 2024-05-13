#include "../uart/uart1.h"
#include "mbox.h"
#include "framebf.h"
#include "video.h"

const long unsigned int *video[] = {frame_001,frame_002,frame_003,frame_004,frame_005,frame_006,frame_007,frame_008,frame_009,frame_010};

void display(int num)
{       
    int index = 0;
        for (int x = 0; x < 240; x++)
        {
            for (int y = 0; y < 320; y++)
                {
                    drawPixelARGB32(y,x,video[num][index]);
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
    while (1)
    {
        for(int i = 0; i < 10; i++) {
            display(i);
        }
    }

}
