#include <stdio.h>
#include <windows.h>

int main()
{
    DWORD        mode;          /* Preserved console mode */
    INPUT_RECORD event;         /* Input event */
    BOOL         done = FALSE;  /* Program termination flag */
    unsigned int counter = 0;   /* The number of times 'Esc' is pressed */

    /* Don't use binary for text files, OK?  ;-) */
    FILE* myfile = fopen( "example.txt", "w" );

    /* Get the console input handle */
    HANDLE hstdin = GetStdHandle( STD_INPUT_HANDLE );

    /* Preserve the original console mode */
    GetConsoleMode( hstdin, &mode );

    /* Set to no line-buffering, no echo, no special-key-processing */
    SetConsoleMode( hstdin, 0 );

    /* Give the user instructions */
    printf(
        "Press Escape as many times as you like.\n"
        "Press anything else to quit.\n\n"
        );

    while (!done)
    {
        if (WaitForSingleObject( hstdin, 0 ) == WAIT_OBJECT_0)  /* if kbhit */
        {
            DWORD count;  /* ignored */

            /* Get the input event */
            ReadConsoleInput( hstdin, &event, 1, &count );

            /* Only respond to key release events */
            if ((event.EventType == KEY_EVENT)
            &&  !event.Event.KeyEvent.bKeyDown)
                switch (event.Event.KeyEvent.wVirtualKeyCode)
                {
                    case VK_ESCAPE:
                        counter++;
                        fprintf( myfile, "Escape: %d\n", counter );
                        printf( "Button pressed!\n" );
                        break;
                    default:
                        done = TRUE;
                }
        }
    }

    /* All done! */
    printf( "You pressed the Escape key %d times\n", counter );
    fclose( myfile );
    SetConsoleMode( hstdin, mode );
    return 0;
}
