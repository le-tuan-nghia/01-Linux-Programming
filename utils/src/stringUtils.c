#include "utils.h"
#include <stdarg.h> 
#include <time.h>
#include<sys/time.h>

void writeLine(const char* str, ...)
{
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    
    struct timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    printf("%02d:%02d:%02d.%03d> ", tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec, milli);


    // initializing list pointer 
    va_list ptr; 
    va_start(ptr, str); 
  
    // char array to store token 
    char token[1000]; 
    // index of where to store the characters of str in 
    // token 
    int k = 0; 
  
    // parsing the formatted string 
    for (int i = 0; str[i] != '\0'; i++) { 
        token[k++] = str[i]; 
  
        if (str[i + 1] == '%' || str[i + 1] == '\0') { 
            token[k] = '\0'; 
            k = 0; 
            if (token[0] != '%') { 
                fprintf( 
                    stdout, "%s", 
                    token); // printing the whole token if 
                            // it is not a format specifier 
            } 
            else { 
                int j = 1; 
                char ch1 = 0; 
  
                // this loop is required when printing 
                // formatted value like 0.2f, when ch1='f' 
                // loop ends 
                while ((ch1 = token[j++]) < 58) { 
                } 
                // for integers 
                if (ch1 == 'i' || ch1 == 'd' || ch1 == 'u'
                    || ch1 == 'h') { 
                    fprintf(stdout, token, 
                            va_arg(ptr, int)); 
                } 
                // for characters 
                else if (ch1 == 'c') { 
                    fprintf(stdout, token, 
                            va_arg(ptr, int)); 
                } 
                // for float values 
                else if (ch1 == 'f') { 
                    fprintf(stdout, token, 
                            va_arg(ptr, double)); 
                } 
                else if (ch1 == 'l') { 
                    char ch2 = token[2]; 
  
                    // for long int 
                    if (ch2 == 'u' || ch2 == 'd'
                        || ch2 == 'i') { 
                        fprintf(stdout, token, 
                                va_arg(ptr, long)); 
                    } 
  
                    // for double 
                    else if (ch2 == 'f') { 
                        fprintf(stdout, token, 
                                va_arg(ptr, double)); 
                    } 
                } 
                else if (ch1 == 'L') { 
                    char ch2 = token[2]; 
  
                    // for long long int 
                    if (ch2 == 'u' || ch2 == 'd'
                        || ch2 == 'i') { 
                        fprintf(stdout, token, 
                                va_arg(ptr, long long)); 
                    } 
  
                    // for long double 
                    else if (ch2 == 'f') { 
                        fprintf(stdout, token, 
                                va_arg(ptr, long double)); 
                    } 
                } 
  
                // for strings 
                else if (ch1 == 's') { 
                    fprintf(stdout, token, 
                            va_arg(ptr, char*)); 
                } 
  
                // print the whole token 
                // if no case is matched 
                else { 
                    fprintf(stdout, "%s", token); 
                } 
            } 
        } 
    } 
  
    // ending traversal 
    va_end(ptr); 


    printf("\n");
}