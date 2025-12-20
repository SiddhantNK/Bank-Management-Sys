#include <stdio.h>
#include <windows.h>
#include <shellapi.h>  // Required if you want to execute Shell cmds

void show_about_image() {
    // Opens an image file in the default image viewer

      ShellExecuteA(NULL, "open", "C:/Users/Siddhant Kale/Pictures/fordp.jpg", NULL, NULL, SW_SHOWNORMAL);
    
    printf("About The Person : \n"); // Right some thing youo think in few lines 
    printf("This is loid Forger and he is a spy in ostania \n");
    printf("Press any key to continue...\n");
    getchar(); // Wait for user input
}

int main() {
    printf("About Us \n\n");
    printf("Press Enter to show About image...\n");
    getchar(); // Wait for user input (kahi tari creative kar) 
    show_about_image(); // Calling the function 
    return 0;
}