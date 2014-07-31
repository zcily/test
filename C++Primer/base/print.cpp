#include <stdio.h>

#define NONE         "\033[0m" 
#define RED          "\033[0;31m" 
#define LIGHT_RED    "\033[1;31m" 
#define GREEN        "\033[0;32m" 
#define LIGHT_GREEN  "\033[1;32m" 
#define BLUE         "\033[0;34m" 
#define LIGHT_BLUE   "\033[1;34m" 
#define DARY_GRAY    "\033[1;30m" 
#define CYAN         "\033[0;36m" 
#define LIGHT_CYAN   "\033[1;36m" 
#define PURPLE       "\033[0;35m" 
#define LIGHT_PURPLE "\033[1;35m" 
#define BROWN        "\033[0;33m" 
#define YELLOW       "\033[1;33m" 
#define LIGHT_GRAY   "\033[0;37m" 
#define WHITE        "\033[1;37m"
#define UNDER_LINE   "\033[4m"
#define FLICKER      "\033[5m"
#define REVEASER     "\033[7m"
#define HIDDEN       "\033[8m"

int main (int argc, char **argv)
{
    printf("%s%s red *****************************%s\n",RED,UNDER_LINE, NONE);
    printf("%s%s LIGHT_RED *****************************%s\n",LIGHT_RED,FLICKER,NONE);
    printf("%s%s green *****************************%s\n",GREEN,REVEASER,NONE);
    printf("%s%s LIGHT_GREEN *****************************%s\n",LIGHT_GREEN,HIDDEN, NONE);
    printf("%s blue*****************************%s\n",BLUE,NONE);
    printf("%s LIGHT_BLUE*****************************%s\n",LIGHT_BLUE,NONE);
    printf("%s DARY_GRAY*****************************%s\n",DARY_GRAY,NONE);
    printf("%s cyan*****************************%s\n",CYAN,NONE);
    printf("%s LIGHT_CYAN*****************************%s\n",LIGHT_CYAN,NONE);
    printf("%s PURPLE*****************************%s\n",PURPLE,NONE);
    printf("%s LIGHT_PURPLE*****************************%s\n",LIGHT_PURPLE,NONE);
    printf("%s brown*****************************%s\n",BROWN,NONE);
    printf("%s YELLOW*****************************%s\n",YELLOW,NONE);
    printf("%s LIGHT_GRAY*****************************%s\n",LIGHT_GRAY,NONE);
    printf("%s WHITE*****************************%s\n",WHITE,NONE);
}
